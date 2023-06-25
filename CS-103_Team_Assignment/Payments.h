#pragma once
#include "Common.h"

void billUser(std::vector<Item>* cart) {
	
	float totalPrice = 0.0; 
	float payment, totalPayment = 0, change = 0;


	for (uint8_t i = 0; i < cart->size(); i++) {

		Item item = cart->at(i);

		std::cout << item.display() << std::endl;
		totalPrice += item.price;
	}

	std::cout << std::endl << "Total price                $" << totalPrice << std::endl;

	do {
		payment = utils::get_number<float>("your payment");
		totalPayment += payment;
		
		if (totalPayment < totalPrice)
			std::cout << "You still need to pay $" << totalPrice - totalPayment;
	} while (totalPayment < totalPrice);


	change = (totalPayment - totalPrice);

	if (change != 0.0)
		std::cout << "Your change is $" << change << std::endl;
	else
		std::cout << "Exact Payment, No Change" << std::endl;

}