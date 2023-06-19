#pragma once
#include "Common.h"

// no
using namespace std;

namespace menus {

	struct Item {
		uint8_t id;
		string name;
		float price;

		string display() {
			stringstream ss;
			ss << name << ": $" << std::setprecision(2) << price;
			return ss.str();
		}
	};


	const Item FOOD_PRICE[11] = {
		// food
		{1, "PIE", 3.0},
		{2, "HAMBURGER", 3.50},
		{3, "SAUSAGE ROLL", 3.0},
		{4, "CHICKEN WRAP", 5.0},
		{5, "CHOCOLATE MUFFIN", 2.50},
		{6, "BROWNIE", 2.0},

		// drinks
		{7, "COKE", 2.0},
		{8, "ORANGE JUICE", 2.0},
		{9, "APPLE JUICE", 2.0},
		{10, "SPRITE", 2.0},
		{11, "L&P", 2.0}
	};

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

	void orderFood()
	{
		vector<Item> cart{};
		bool done = false;
		while (!done) {
			int choice = utils::get_number<int>("Please enter the number corresponding to what you want");
			if (choice > 0 && choice < 12) {
				cout << "You have chosen - " << FOOD_PRICE[--choice].name << endl;
			}
			else {
				cout << "Please enter correct number: ";
				continue;
			}

			// --choice appears above, so we needn't do it again
			cart.push_back(FOOD_PRICE[choice]);

			char order_again = utils::get_char("Would you like anything else? [Y/n]");
			utils::to_lower(order_again);

			if (order_again == 'n') {
				done = true;
			}
		}

		bool has_pie = false, has_brownie = false, has_drink = false, has_chicken_wrap = false;
		
		for (uint8_t i = 0; i < cart.size(); i++) {
			uint8_t n = cart[i].id;
			switch (n) {
			case 1: // pie
				has_pie = true;
				break;
			case 4: // chicken wrap
				has_chicken_wrap = true;
				break;
			case 6: // brownie
				has_brownie = true;
				break;
			case 7:
			case 8:
			case 9:
			case 10:
			case 11: // all drinks
				has_drink = true;
				break;
			}
		}

		Item negative_brownie = {
			12, "Deal: Free Brownie", -2.0
		};

		if ((has_pie && has_drink) || has_chicken_wrap) {
			if (!has_brownie) cart.push_back(FOOD_PRICE[5]);
			cart.push_back(negative_brownie);
		}
	}


}