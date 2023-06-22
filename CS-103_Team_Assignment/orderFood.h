#pragma once
#include "Common.h"
#include <vector>

using namespace std;

vector<Item> orderFood()
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

	return cart;
}