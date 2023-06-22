#pragma once
#include "Common.h"
#include "Accounts.h"
#include "Menus.h"

#include "Menus.h" 
#include "orderFood.h"
#include "Payments.h"

// i hate this line, don't
using namespace std;
using namespace menus;

int main()
{
	Accounts accs{};
	Account* current_account = nullptr;
	
	bool should_exit = false;
	do {
		clear();
		if (current_account == nullptr) {
			cout << "*                                                     *" << endl;
			cout << "*    Not Signed In                                    *" << endl;
			cout << "*                                                     *" << endl;
		}
		else {
			int total_width_of_name = 33;

			cout << "*                                                     *" << endl;
			cout << "*    Signed In As: ";

			cout << current_account->account_name;

			for (uint8_t i = 0; i < (total_width_of_name - current_account->account_name.size()); i++) 
				cout << " ";
			
			cout << "  *" << endl;
			cout << "*                                                     *" << endl;
		}
		menus::welcomeMessage();
		menus::mainMenu(current_account != nullptr);

		char menuChoice;

		while (true) {
			cout << "*                                                     *" << endl;
			cout << "*    Please select an option:                         *" << endl;
			cout << "*******************************************************";
				
			HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_SCREEN_BUFFER_INFO info;
			GetConsoleScreenBufferInfo(console, &info);

			COORD new_pos = { 35, info.dwCursorPosition.Y - 1 };

			SetConsoleCursorPosition(console, new_pos);


			menuChoice = utils::get_number<char>("", false);

			utils::to_lower(menuChoice);

			bool isValid = false;

			switch (menuChoice)
			{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case 'e':
				isValid = true;
				break;
			default:
				cout << "ERROR..." << endl;
				continue;
			}

			if (isValid) break;
		}

		clear();

		std::vector<Item> cart;

		switch (menuChoice)
		{
		case '1':
			// login
			current_account = login(&accs);
			break;
		case '2':
			// sign up
			sign_up(&accs);
			break;
		case '3':
			// sign out
			current_account = nullptr;
			std::cout << "Signed Out" << std::endl;
			break;
		case '4':
			// menu
		case '5':
			// order
			cout << "\n*******************************************************" << endl;
			menus::foodMenu();
			cout << "*******************************************************" << endl;
			menus::drinkMenu();
			cout << "*******************************************************" << endl;
			menus::deals();
			cout << "*******************************************************" << endl;
			// menu printed regardless
			// so print menu to prevent code duplication
			// if was menu only break here, otherwise 
			// continue through ordering process
			if (menuChoice == '4')
				break;
			cart = orderFood();
			billUser(&cart);
			break;
		case '6':
		case 'e': // E to *E*xit
			menus::exitMessage();
			should_exit = true;
			break;
		}

		if (menuChoice != '6' && menuChoice != 'e') {
			cout << "\nPress any key to continue... " << endl;
			auto _ = _getch(); // to make the lint stfu
			clear();
		}
	} while (!should_exit);
}
