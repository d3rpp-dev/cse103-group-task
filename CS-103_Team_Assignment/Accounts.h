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
		std::ifstream f;
		f.open("accounts.bin");

		if (!f.good()) {
			// file does not exist or couldn't be read
			return false;
		}

		for (std::string line; std::getline(f, line); ) {
			size_t pos = 0;
			std::vector<std::string> tokens{};

			Account acc{};

			if ((pos = line.find(",")) != std::string::npos) {
				tokens.push_back(line.substr(0, pos));
				tokens.push_back(line.substr(pos + 1));
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
		std::ofstream f;
		f.open("accounts.bin", std::ios::out | std::ios::trunc);

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
		if (find_account(account_name) != nullptr) {
			std::cout << "Account already Exists" << std::endl;
			return;
		}

		Sha256 sha{};
		sha.update(password_raw);

		Account acc {
			account_name,
			Sha256::to_string(sha.digest())
		};

		_accounts.push_back(acc);
		save();
	}

	Account* validate_password(const std::string& account_name, const std::string& password) {
		Account* acc = find_account(account_name);
		if (acc == nullptr) return nullptr;

		Sha256 sha{};
		sha.update(password);

		return Sha256::to_string(sha.digest()) == acc->password_hash ? acc : nullptr;
	}
};

Account* login(Accounts* accts) {
	Account* acc_ = nullptr;
	std::string account_name = "";

	do {
		account_name = utils::get_line("Account Username");
		trim::trim(account_name);

		acc_ = accts->find_account(account_name);
		
		if (acc_ == nullptr) {
			std::cout << RED << "Unknown Account Name - " << RESET << "Please Try Again" << std::endl;
		}
	} while (acc_ == nullptr);

	int attempts = 0;
	Account* acc = nullptr;
	do {
		std::string password_attempt = utils::get_password("Account Password (it won't appear in console, but we will see it)");

		acc = accts->validate_password(account_name, password_attempt);

		if (acc == nullptr) {
			std::cout << RED << "Invalid Password, please try again" << RESET << std::endl;
			attempts++;
		}
		else {
			std::cout << GREEN << "Signed In" << RESET << std::endl;
			return acc;
		}
	} while (attempts < 3);


	std::cout << RED << "Too many failed attempts, returning home" << RESET << std::endl;
	return nullptr;
}

void sign_up(Accounts* accts) {
	std::string account_name = utils::get_line("Account Username");
	trim::trim(account_name);

	std::string password = "";

	do {
		std::string attempt_1 = utils::get_password("Account Password");
		std::string confirm_1 = utils::get_password("Confirm Password");

		if (attempt_1 == confirm_1) {
			password = attempt_1;
		}
		else {
			std::cout << RED << "Passwords do NOT match, try again" << RESET << std::endl;
		}
	} while (password == "");

	accts->add_account(account_name, password);
}