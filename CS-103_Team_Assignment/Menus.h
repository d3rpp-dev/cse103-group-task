#pragma once
#include "Common.h"

// no
using namespace std;

namespace menus {

	//function for the welcome message
	void welcomeMessage() {
		cout << "*******************************************************" << endl;
		cout << "*****                                             *****" << endl;
		cout << "*****         WELCOME TO THE ORDERING SYTEM       *****" << endl;
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
		cout << "*    BUY A CHICKEN WRAP GET A BROWNIE FOR FREE!!!     *" << endl;
		cout << "*                                                     *" << endl;
	}	
}