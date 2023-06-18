#include "Common.h"
#include "Menus.h"

// i hate this line, don't
using namespace std;

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
		menus::welcomeMessage();
		menus::mainMenu();

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
			menus::foodAndDrink();
			break;
		case '5':
			menus::exitMessage();
			should_exit = true;
			break;
		}
		if (menuChoice != '5') {
			cout << "\nPress any key to continue... " << endl;
			auto _ = _getch(); // to make the lint stfu
			clear();
		}
	} while (!should_exit);
}
