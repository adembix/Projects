#include "clsStringsAndFiles.h"


class clsDepositScreen
{
public:

	static void ShowDepositScreen()
	{
        double Balance = clsStringsAndFiles::getBalanceFromFile();
        double AddedBalance = 0;

        system("cls");
        cout << setw(15) << left << "" << "\t\t==========================================================\n";
        cout << setw(44) << left << "" << "Show Balance Screen\n";
        cout << setw(15) << left << "" << "\t\t==========================================================\n";

        cout << setw(8) << left << "" << "\t\t__________________________________________________________\n\n";
        cout << setw(40) << left << "" << "Enter Balance Want To Deposit : "; cin >> AddedBalance;

        Balance += AddedBalance;
        clsStringsAndFiles::saveDataOnFile(Balance);

        cout << setw(8) << left << "" << "\t\t__________________________________________________________\n\n";


	}

};

