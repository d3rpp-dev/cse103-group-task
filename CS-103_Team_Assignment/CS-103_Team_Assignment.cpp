#pragma once
#include "Common.h"
#include "Menus.h" 
#include "orderFood.h"
#include "Payments.h"

using namespace std;
using namespace menus;


int main()
{
	int order;

	bool should_exit = false;
	do {
		menus::welcomeMessage();
		menus::mainMenu();

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

			bool isValid = false;

			switch (menuChoice)
			{
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
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
		case '3':
		case '4':
			cout << "\n*******************************************************" << endl;
			menus::foodMenu();
			cout << "*******************************************************" << endl;
			menus::drinkMenu();
			cout << "*******************************************************" << endl;
			menus::deals();
			cout << "*******************************************************" << endl;
			if (menuChoice == '3')
				break;
			cart = orderFood();
			billUser(&cart);
			break;

		case '5':
			cout << "********************************************************" << endl;
			cout << "* THANK YOU FOR USING THE SCHOOL LUNCH ORDERING SYSTEM *" << endl;
			cout << "*                       GOODBYE                        *" << endl;
			cout << "********************************************************" << endl;

			should_exit = true;
			break;
		}

		if (menuChoice != '5') {
			cout << "\nPress any key to continue... " << endl;
			_getch();
			clear();
		}
	} while (!should_exit);
}
