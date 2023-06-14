#include "Common.h"

using namespace std;

void welcomeMessage() {
	cout << "***********************************************" << endl;
	cout << "\t WELCOME TO THE ORDERING SYTEM" << endl;
	cout << "***********************************************" << endl;
}

void mainMenu() {
	cout << "\tPLEASE SELECT AN OPTION:" << endl;
	cout << "\t--   [1] LOGIN    -- " << endl;
	cout << "\t--   [2] SIGN UP  -- " << endl;
	cout << "\t--   [3] MENU     -- " << endl;
	cout << "\t--   [4] ORDER    -- " << endl;
	cout << "\t--   [5] EXIT     -- " << endl;
}

void foodMenu()
{
	cout << "\n 1. PIE              -  $3.00" << endl;
	cout << " 2. HAMBURGER        -  $3.50" << endl;
	cout << " 3. SAUSAGE ROLL     -  $3.00" << endl;
	cout << " 4. CHICKEN WRAP     -  $5.00" << endl;
	cout << " 5. CHOCOLATE MUFFIN -  $2.50" << endl;
	cout << " 6. BROWNIE          -  $2.00" << endl;
	cout << " 7. DRINK            -  $2.00" << endl;
}


void drinkMenu()
{
	cout << "ALL DRINKS $2.00" << endl;
	cout << "1. COKE" << endl;
	cout << "2. ORANGE JUICE" << endl;
	cout << "3. APPLE JUICE" << endl;
	cout << "4. SPRITE" << endl;
	cout << "5. L&P" << endl;
	cout << "6. NONE" << endl;
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

/*double calculateBill(int choice, int quantity) {
	double price;
	switch (choice) {
	case 1:
		price = 3.00;
		break;
	case 2:
		price = 3.50;
		break;
	case 3:
		price = 3.00;
		break;
	case 4:
		price = 5.00;
		break;
	case 5:
		price = 2.50;
		break;
	case 6:
		price = 2.00;
		break;
	case 7:
		price = 2.00;
		break;
	default:
		price = 0.00;
		break;

	}
}
*/

int main()
{
	
	bool should_exit = false;
	do {
		welcomeMessage();
		mainMenu();

		int choice, quantity;
		double totalBill;
		char paymentMethod;
		char menuChoice;

		while (true) {
			cout << "\nPlease select an option: ";
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
			cout << "***********************************************" << endl;
			cout << "FOOD";
			foodMenu();
			cout << "***********************************************" << endl;
			cout << "DRINKS";
			drinkMenu();
			cout << "***********************************************\n" << endl;
			break;
		case '5':
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
