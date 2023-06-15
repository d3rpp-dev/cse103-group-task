#include "Common.h"

using namespace std;

void welcomeMessage() {
	cout << "*******************************************************" << endl;
	cout << "*****                                             *****" << endl;
	cout << "*****         WELCOME TO THE ORDERING SYTEM       *****"<< endl;
	cout << "*****                                             *****" << endl;
	cout << "*******************************************************\n" << endl;
}

void mainMenu() {
	cout << "\t  [1] LOGIN" << endl;
	cout << "\t  [2] SIGN UP" << endl;
	cout << "\t  [3] MENU " << endl;
	cout << "\t  [4] ORDER " << endl;
	cout << "\t  [5] EXIT " << endl;
}

void foodMenu()
{
	cout << "*\t                                              *" << endl;
	cout << "*\t             FOOD:                            *" << endl;
	cout << "*\t  1. PIE                -  $3.00              *" << endl;
	cout << "*\t  2. HAMBURGER          -  $3.50              *" << endl;
	cout << "*\t  3. SAUSAGE ROLL       -  $3.00              *" << endl;
	cout << "*\t  4. CHICKEN WRAP       -  $5.00              *" << endl;
	cout << "*\t  5. CHOCOLATE MUFFIN   -  $2.50              *" << endl;
	cout << "*\t  6. BROWNIE            -  $2.00              *" << endl;
	cout << "*\t                                              *" << endl;
}


void drinkMenu()
{
	cout << "*\t                                              *" << endl;
	cout << "*\t          DRINKS:                             *" << endl;
	cout << "*\t  1. COKE               -  $2.00              *" << endl;
	cout << "*\t  2. ORANGE JUICE       -  $2.00              *" << endl;
	cout << "*\t  3. APPLE JUICE        -  $2.00              *" << endl;
	cout << "*\t  4. SPRITE             -  $2.00              *" << endl;
	cout << "*\t  5. L&P                -  $2.00              *" << endl;
	cout << "*\t  6. NONE               -  $2.00              *" << endl;
	cout << "*\t                                              *" << endl;
}

void deals()
{
	cout << "\nCURRENT DEALS:" << endl;
	cout << "BUY A PIE & DRINK, GET BROWNIE FOR FREE!!!" << endl;
	cout << "BUY A CHICKEN WRAP GET DRINK HALF PRICE!!!" << endl;
}

void orderFood()
{
	cout << "ORDER PLACEHOLDER" << endl;
}

int main()
{
	int order;

	bool should_exit = false;
	do {
		welcomeMessage();
		mainMenu();

		int choice, quantity;
		double totalBill;
		char paymentMethod;
		char menuChoice;

		while (true) {
			cout << "\n\t  Please select an option: ";
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

		switch (menuChoice)
		{
		case '3':
		case '4':
			cout << "\n*******************************************************" << endl;
			foodMenu();
			cout << "*******************************************************" << endl;
			drinkMenu();
			cout << "*******************************************************\n" << endl;
			if (menuChoice == '3') 
				break;
			cout << "\n Please enter your order: " << endl;
			break;

		case '5':
			cout << "THANK YOU FOR USING THE SCHOOL LUNCH ORDERING SYSTEM" << endl;
			cout << "GOODBYE" << endl;
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
