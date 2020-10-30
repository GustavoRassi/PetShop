#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

const float TURTLE = 10.00, PARROT = 100.00, CAT = 20.00, DOG = 150.00;
const float EXTRA_T = 2.00, EXTRA_P = 5.00, EXTRA_C = 6.00, EXTRA_D = 10.00;
const float G_PARROT = 100.00, D_US = 20.00, D_EUROPE = 40.00, D_JAPAN = 60.00;

int main()
{
	int origin;
	float lb, extra_lb, total_lb, final_total;
	char pet, gold, answer;
	bool invalid = false, checkout = false;

	do
	{
		system("cls");
		cout << fixed << showpoint << setprecision(2);
		for (int x = 0; x <= 80; x++)
			cout << "-";
		cout << endl;
		cout << "                                     PETSHOP                                    " << endl;
		for (int x = 0; x <= 80; x++)
			cout << "-";
		cout << endl;
		cout << "      Type of pet       |  Price for 10lb or less | Charge for each extra pound " << endl;
		cout << "\n     t/T = Turtle" << setw(25) << TURTLE << setw(25) << EXTRA_T << endl;
		cout << "     p/P = Parrot" << setw(25) << PARROT << setw(25) << EXTRA_P << endl;
		cout << "     c/C = Cat" << setw(28) << CAT << setw(25) << EXTRA_C << endl;
		cout << "     d/D = Dog" << setw(28) << DOG << setw(25) << EXTRA_D << endl;
		for (int x = 0; x <= 80; x++)
			cout << "-";
		cout << endl;
		cout << "\nEnter the desired pet:" << endl;
		cout << "> ";
		cin >> pet;
		cout << "\nPlease enter the desired weight in pounds:" << endl;
		cout << "> ";
		cin >> lb;
		switch (pet)
		{
			case 't':
			case 'T':
				if (lb <= 0)
					invalid = true;
				else if (lb > 10)
				{
					extra_lb = lb - 10;
					total_lb = extra_lb * EXTRA_T;
					final_total = TURTLE + total_lb;
					checkout = true;
				}
				else
					cout << "\nYour amount to pay will be: $" << TURTLE << endl;
				break;

			case 'p':
			case 'P':
				if (lb <= 0)
					invalid = true;
				else
				{
					cout << "\nYou have the option for the parrot to be gold colored. It will have an additional charge of $" << G_PARROT << "." << endl;
					cout << "[Y/y = Yes - N/n = No]: " << endl;
					cin >> gold;
					if ((gold == 'Y') || (gold == 'y'))
					{
						if (lb > 10)
						{
							extra_lb = lb - 10;
							total_lb = extra_lb * EXTRA_P;
							final_total = PARROT + total_lb + G_PARROT;
						}
						else
							final_total = PARROT + G_PARROT;
						checkout = true;
					}
					else if ((gold == 'N') || (gold == 'n'))
					{
						if (lb > 10)
						{
							extra_lb = lb - 10;
							total_lb = extra_lb * EXTRA_P;
							final_total = PARROT + total_lb;
							checkout = true;
						}
						else
							cout << "\nYour amount to pay will be: $" << PARROT << endl;
					}
					else
						invalid = true;
				}
				break;

			case 'c':
			case 'C':
				if (lb <= 0)
					invalid = true;
				else if (lb > 10)
				{
					extra_lb = lb - 10;
					total_lb = extra_lb * EXTRA_C;
					final_total = CAT + total_lb;
					checkout = true;
				}
				else
					cout << "\nYour amount to pay will be: $" << CAT << endl;
				break;

			case 'd':
			case 'D':
				if (lb <= 0)
					invalid = true;
				else
				{
					cout << "\nDogs will have an additional charge depending on the country that they are from." << endl;
					cout << "\n 1. United States: $20" << endl;
					cout << " 2. Europe: $40" << endl;
					cout << " 3. Japan: $60" << endl;
					cout << endl;
					cout << "-Origin: ";
					cin >> origin;
					if (origin == 1)
					{
						if (lb > 10)
						{
							extra_lb = lb - 10;
							total_lb = extra_lb * EXTRA_D;
							final_total = DOG + total_lb + D_US;
						}
						else
							final_total = DOG + D_US;
						checkout = true;
					}
					else if (origin == 2)
					{
						if (lb > 10)
						{
							extra_lb = lb - 10;
							total_lb = extra_lb * EXTRA_D;
							final_total = DOG + total_lb + D_EUROPE;
						}
						else
							final_total = DOG + D_EUROPE;
						checkout = true;
					}
					if (origin == 3)
					{
						if (lb > 10)
						{
							extra_lb = lb - 10;
							total_lb = extra_lb * EXTRA_D;
							final_total = DOG + total_lb + D_JAPAN;
						}
						else
							final_total = DOG + D_JAPAN;
						checkout = true;
					}
				}
				break;
			default: invalid = true;
		}
		if (invalid == true)
			cout << "***ERROR - Letter or weight is not valid***" << endl;
		if (checkout == true)
			cout << "\nYour amount to pay will be: $" << final_total << endl;

		cout << "\nType 'e' to exit or 'm' to go back to the main menu." << endl;
		cout << "> ";
		cin >> answer;
	} while (answer != 'e');

	system("pause");
	return EXIT_SUCCESS;
}
