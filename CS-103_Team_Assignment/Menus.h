#pragma once
#include "Common.h"

// no
using namespace std;

namespace menus {
	void welcomeMessage() {
		cout << "*******************************************************" << endl;
		cout << "*****                                             *****" << endl;
		cout << "*****         WELCOME TO THE ORDERING SYTEM       *****" << endl;
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

	void foodMenu() {
		cout << "*\t             FOOD:                            *" << endl;
		cout << "*\t  1. PIE                -  $3.00              *" << endl;
		cout << "*\t  2. HAMBURGER          -  $3.50              *" << endl;
		cout << "*\t  3. SAUSAGE ROLL       -  $3.00              *" << endl;
		cout << "*\t  4. CHICKEN WRAP       -  $5.00              *" << endl;
		cout << "*\t  5. CHOCOLATE MUFFIN   -  $2.50              *" << endl;
		cout << "*\t  6. BROWNIE            -  $2.00              *" << endl;
	}


	void drinkMenu() {
		cout << "*\t         DRINKS $2.00 EACH:                   *" << endl;
		cout << "*\t  1. COKE                                     *" << endl;
		cout << "*\t  2. ORANGE JUICE                             *" << endl;
		cout << "*\t  3. APPLE JUICE                              *" << endl;
		cout << "*\t  4. SPRITE                                   *" << endl;
		cout << "*\t  5. L&P                                      *" << endl;
		cout << "*\t  6. NONE                                     *" << endl;
	}

	void deals() {
		cout << "\nCURRENT DEALS:" << endl;
		cout << "BUY A PIE & DRINK, GET BROWNIE FOR FREE!!!" << endl;
		cout << "BUY A CHICKEN WRAP GET DRINK HALF PRICE!!!" << endl;
	}

	void orderFood() {
		cout << "ORDER PLACEHOLDER" << endl;
	}

	void foodAndDrink() {
		cout << "\n*******************************************************" << endl;
		foodMenu();
		cout << "*******************************************************" << endl;
		drinkMenu();
		cout << "*******************************************************\n" << endl;
	}

	void exitMessage() {
		cout << "THANK YOU FOR USING THE SCHOOL LUNCH ORDERING SYSTEM" << endl;
		cout << "GOODBYE" << endl;
	}
}