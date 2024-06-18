#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>



using namespace std;

int main()
{
	//Declaring Variables to store userInput
	float initialInvestment;
	float monthlyDeposit;
	float annualInterest;
	float years;
	float months;
	//year end total amount
	float totalAmount;
	//interest and year end interest
	float interestAmount, yearEndInterest;

	//Display what the user will see
	cout << "*************************\n";
	cout << "********Data Input*******\n";
	cout << "Initial Investment Amount: \n";
	cout << "Monthly Deposit: \n";
	cout << "Annual Interest: \n";
	cout << "Number of years: \n";
	//This allows press any key to start to work
	system("PAUSE");

	//Get data from user
	cout << "*************************\n";
	cout << "********Data Input*******\n";
	cout << "Initial Investment Amount: ";
	cin >> initialInvestment;
	cout << "Monthly Deposit: ";
	cin >> monthlyDeposit;
	cout << "Annual Interest: ";
	cin >> annualInterest;
	cout << "Number of years: ";
	cin >> years;
	months = years * 12;

	system("PAUSE");

	//Initialize totalAmount with the initialInvestment this way the amounts can be calculated without monthly deposits
	totalAmount = initialInvestment;
	//Display year data without monthly deposits
	cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";
	for (int i = 0; i < years; i++) {
		//Yearly interest calculation
		interestAmount = (totalAmount) * ((annualInterest / 100));
		//Calculate year end total
		totalAmount = totalAmount + interestAmount;
		//output
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << interestAmount << "\n";

	}

	//Calculations with monthly deposits added on
	totalAmount = initialInvestment;
	//Display
	cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
	cout << "==============================================================\n";
	cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
	cout << "--------------------------------------------------------------\n";
	for (int i = 0; i < years; i++) {
		//Set yearly interest to zero at the start of the year
		yearEndInterest = 0;
		for (int j = 0; j < 12; j++) {
			//Monthly Interest
			interestAmount = (totalAmount + monthlyDeposit) * ((annualInterest / 100) / 12);
			//Month end interest
			yearEndInterest = yearEndInterest + interestAmount;
			//Month end total
			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}
		cout << (i + 1) << "\t\t" << fixed << setprecision(2) << totalAmount << "\t\t\t" << yearEndInterest << "\n";


	}

	return 0;
}
