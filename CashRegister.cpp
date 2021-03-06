#include <iostream>
#include <iomanip>

int main() {
	double TotalCost;
	double CashReceived;
	double Change;
	int Cents;
	int ChangeBills;
	int NumTwenties;
	int ChangeAfterTwenties; //Amount of change remaining after twenties
	int NumTens;
	int ChangeAfterTens;
	int NumFives;
	int ChangeAfterFives;
	int NumOnes;
	int ChangeAfterOnes;
	int NumQuarters;
	int ChangeAfterQ; //This is the amount of change remaining after quarters
	int NumDimes;
	int ChangeAfterD; //Amount of change remaining after dimes
	int NumNickels;
	int ChangeAfterN; //Amount of change remaining after nickels
	int NumPennies;
	bool BillChange = false;
	int ChangeVar;

	std::cout << "What is the total cost?" << std::endl;
	std::cin >> TotalCost;
	std::cout << "How much cash was received?" << std::endl;
	std::cin >> CashReceived;
	Change = CashReceived - TotalCost;
	std::cout << std::setprecision(2) << std::fixed;
	std::cout << "You should give $" <<  Change << " in change." << std::endl;
	
	if (Change > 1) {
		ChangeBills = Change;
		NumTwenties = ChangeBills / 20;
		ChangeAfterTwenties = ChangeBills % 20;
		NumTens = ChangeAfterTwenties / 10;
		ChangeAfterTens = ChangeAfterTwenties % 10;
		NumFives = ChangeAfterTens / 5;
		ChangeAfterFives = ChangeAfterTens % 5;
		NumOnes = ChangeAfterFives;
		ChangeVar = 100 * Change;
		Cents = ChangeVar % 100; 
		BillChange = true;
	}

	if (Change < 1) {
		Cents = static_cast<int>(Change) * 100;
	}
	NumQuarters = Cents / 25;
	ChangeAfterQ = Cents % 25;
	NumDimes = ChangeAfterQ / 10;
	ChangeAfterD = ChangeAfterQ % 10;
	NumNickels = ChangeAfterD / 5;
	ChangeAfterN = ChangeAfterD % 5;
	NumPennies = ChangeAfterN;

	if (BillChange) {
		std::cout << "The change is " << NumTwenties << " twenties, " << NumTens
			 << " tens, " << NumFives << " fives, and " << NumOnes << " ones, "
			 << NumQuarters << " quarters, " << NumDimes << " dimes, "
			 << NumNickels << " nickels, and " << NumPennies << " pennies."
		   	<< std::endl;
	}
	if (!BillChange) {
		std::cout << "This would be best given by giving "
		 << NumQuarters << " quarters, " << NumDimes << " dimes, "
		 << NumNickels << " nickels, and " << NumPennies << " pennies."
		 << std::endl;
		}
}