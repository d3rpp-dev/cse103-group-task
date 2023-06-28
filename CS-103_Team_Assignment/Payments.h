#pragma once
#include "Common.h"

//function for user payment system
void billUser(std::vector<Item>* cart) {
	
	float totalPrice = 0.0; 
	float payment, totalPayment = 0, change = 0;

	//calculate total price of the cart
	for (uint8_t i = 0; i < cart->size(); i++) {

		Item item = cart->at(i);

		std::cout << item.display() << std::endl;
		totalPrice += item.price;
	}

	//print the total price
	std::cout << std::endl << "Total price                $" << totalPrice << std::endl;

	//print bill for user to pay
	do {
		payment = utils::get_number<float>("your payment");
		totalPayment += payment;
		
		//if user has under payed
		if (totalPayment < totalPrice)
			std::cout << "You still need to pay $" << totalPrice - totalPayment << "\n";
	} while (totalPayment < totalPrice);

	change = (totalPayment - totalPrice);

	//if user has over payed
	if (change != 0.0)
		std::cout << "Your change is $" << change << std::endl;
	//if user has payed exact price
	else
		std::cout << "Exact Payment, No Change" << std::endl;

}