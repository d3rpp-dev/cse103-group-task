#include "Common.h"

using namespace std;

void welcomeMessage()
{
	cout << "**********************" << endl;
	cout << "**********************" << endl;
	cout << "**** SCHOOL LUNCH ****" << endl;
	cout << "**********************" << endl;
	cout << "**********************\n" << endl;


}

void foodMenu()
{
	cout << "\n 1. PIE              -  $3.00" << endl;
	cout << " 2. HAMBURGER        -  $3.50" << endl;
	cout << " 3. NACHOS           -  $4.50" << endl;
	cout << " 4. ONIGIRI          -  $2.00" << endl;
	cout << " 5. TOFU ROLL        -  $3.25" << endl;
	cout << " 6. SAUSAGE ROLL     -  $3.00" << endl;
	cout << " 7. CHICKEN WRAP     -  $5.00" << endl;
	cout << " 8. CHOCOLATE MUFFIN -  $2.50" << endl;
	cout << " 9. BROWNIE          -  $2.00" << endl;
	cout << "10. DRINKS           -  $2.00" << endl;
}


void drinkMenu()
{
	cout << "1. COKE" << endl;
	cout << "2. ORANGE JUICE" << endl;
	cout << "3. APPLE JUICE" << endl;
	cout << "4. SPRITE" << endl;
	cout << "5. L&P" << endl;
}

void deals()
{
	cout << "\nCURRENT DEALS:" << endl;
	cout << "BUY A PIE & DRINK, GET BROWNIE FOR FREE!!!" << endl;
	cout << "BUY NACHOS GET DRINK HALF PRICE!!!" << endl;
}


int main()
{
	welcomeMessage();

	char menuChoice;

	cout << "1. Food Menu" << endl;
	cout << "2. Order Food" << endl;
	cout << "3. Exit" << endl;


	while (true) {
		cout << "\nPlease select an option: ";
		cin >> menuChoice;

		bool isValid = false;

		switch (menuChoice)
		{
		case '1':
		case '2':
		case '3':
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
	case '1':
		deals();
		foodMenu();
		break;

	case '2':
		break;

	case '3':
		cout << "GOOD BYE" << endl;
		return 0;

	}
}