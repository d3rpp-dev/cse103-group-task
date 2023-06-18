#pragma once
#include "Common.h"
#include "Sha256.h"
#include <sys/stat.h>
#include <fstream>
#include <sstream>

struct Account {
	std::string account_name;
	std::string password_hash;
};

class Accounts
{
private:
	std::vector<Account> _accounts = {};

	inline bool load() {
		std::ifstream f("accounts.bin");

		if (!f.good()) {
			// file does not exist or couldn't be read
			return false;
		}

		for (std::string line; std::getline(f, line); ) {
			size_t pos = 0;
			std::vector<std::string> tokens{};

			Account acc{};

			while ((pos = line.find(",")) != std::string::npos) {
				tokens.push_back(line.substr(0, pos));
			}

			if (tokens.size() >= 2) {
				acc.account_name = tokens[0];
				acc.password_hash = tokens[1];
			}

			_accounts.push_back(acc);
		}

		f.close();

		return true;
	}

	inline bool save() {
		// open file with write and truncate mode	
		std::ofstream f("accounts.bin", std::ios::out | std::ios::trunc);

		if (!f.good()) {
			return false;
		}

		for (uint8_t i = 0; i < _accounts.size(); i++) {
			Account acc = _accounts.at(i); // get reference instead of value
			std::stringstream s;

			s << acc.account_name << "," << acc.password_hash;
			f << s.str() << std::endl;
		}

		f.close();
		return true;
	}

public:
	Accounts() {
		if (!load()) {
			std::cerr << "Warning: No Accounts loaded" << std::endl;
		}
	}

	// is this algorithm efficient? no
	// but does it work? probably
	Account* find_account(const std::string& account_name) {
		for (uint8_t i = 0; i < _accounts.size(); i++) {
			Account* a = &_accounts.at(i);
			if (a->account_name == account_name) return a;
		}

		return nullptr;
	}

	void add_account(std::string account_name, std::string password_raw) {
		Sha256 sha{};
		sha.update(password_raw);

		Account acc{
			account_name,
			Sha256::to_string(sha.digest())
		};

		_accounts.push_back(acc);
		save();
	}

	bool validate_password(const std::string& account_name, const std::string& password) {
		Account* acc = find_account(account_name);
		if (acc == nullptr) return false;

		Sha256 sha{};
		sha.update(password);

		return Sha256::to_string(sha.digest()) == acc->password_hash;
	}
};

