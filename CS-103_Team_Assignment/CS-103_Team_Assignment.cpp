#include "Common.h"

using namespace std;

const string NAMES[11] = {
	// food
	"PIE",
	"HAMBURGER",
	"SAUSAGE ROLL",
	"CHICKEN WRAP",
	"CHOCOLATE MUFFIN",
	"BROWNIE",

	// drinks
	"COKE",
	"ORANGE JUICE",
	"APPLE JUICE",
	"SPRITE",
	"L&P"
};

//function for the welcome message
void welcomeMessage() {
	cout << "*******************************************************" << endl;
	cout << "*****                                             *****" << endl;
	cout << "*****         WELCOME TO THE ORDERING SYTEM       *****"<< endl;
	cout << "*****                                             *****" << endl;
	cout << "*******************************************************\n" << endl;
}

//function for the main menu
void mainMenu() {
	cout << "*******************************************************" << endl;
	cout << "*      [1] LOGIN                                      *" << endl;
	cout << "*      [2] SIGN UP                                    *" << endl;
	cout << "*      [3] MENU                                       *" << endl;
	cout << "*      [4] ORDER                                      *" << endl;
	cout << "*      [5] EXIT                                       *" << endl;
	
}

//function for the food menu
void foodMenu()
{
	cout << "*                                                     *" << endl;
	cout << "*                 FOOD:                               *" << endl;
	cout << "*      1. PIE                -  $3.00                 *" << endl;
	cout << "*      2. HAMBURGER          -  $3.50                 *" << endl;
	cout << "*      3. SAUSAGE ROLL       -  $3.00                 *" << endl;
	cout << "*      4. CHICKEN WRAP       -  $5.00                 *" << endl;
	cout << "*      5. CHOCOLATE MUFFIN   -  $2.50                 *" << endl;
	cout << "*      6. BROWNIE            -  $2.00                 *" << endl;
	cout << "*                                                     *" << endl;
}

//function for the drinks menu
void drinkMenu()
{
	cout << "*                                                     *" << endl;
	cout << "*                  DRINKS:                            *" << endl;
	cout << "*      7. COKE               -  $2.00                 *" << endl;
	cout << "*      8. ORANGE JUICE       -  $2.00                 *" << endl;
	cout << "*      9. APPLE JUICE        -  $2.00                 *" << endl;
	cout << "*      10. SPRITE            -  $2.00                 *" << endl;
	cout << "*      11. L&P               -  $2.00                 *" << endl;
	cout << "*                                                     *" << endl;
}

//function for the deals
void deals()
{
	cout << "*                                                     *" << endl;
	cout << "*        ***CURRENT DEALS***                          *" << endl;
	cout << "*                                                     *" << endl;
	cout << "*    BUY A PIE & DRINK, GET A BROWNIE FOR FREE!!!     *" << endl;
	cout << "*     BUY A CHICKEN WRAP GET A DRINK FOR FREE!!!      *" << endl;
	cout << "*                                                     *" << endl;
}

void orderFood()
{
	int choice = utils::get_number<int>("Please enter the number corresponding to what you want");
	cout << "You have chosen - " << NAMES[--choice] << endl;
}

int main()
{
	int order;

	bool should_exit = false;
	do {
		welcomeMessage();
		mainMenu();

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


			cin >> menuChoice;

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

		switch (menuChoice)
		{
		case '3':
		case '4':
			cout << "\n*******************************************************" << endl;
			foodMenu();
			cout << "*******************************************************" << endl;
			drinkMenu();
			cout << "*******************************************************" << endl;
			deals();
			cout << "*******************************************************" << endl;
			if (menuChoice == '3') 
				break;
			orderFood();
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
