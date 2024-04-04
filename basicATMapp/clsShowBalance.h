#include "clsStringsAndFiles.h"


class clsShowBalance
{

private:


public:

	static void ShowBalance()
	{

        double Balance = clsStringsAndFiles::getBalanceFromFile();

        system("cls");
        cout << setw(15) << left << "" << "\t\t==========================================================\n";
        cout << setw(44) << left << "" << "Show Balance Screen\n";
        cout << setw(15) << left << "" << "\t\t==========================================================\n";

        cout << setw(8) << left << "" << "\t\t__________________________________________________________\n\n";
        cout << setw(43) << left << "" << "  Balance is: [" << Balance << "]\n";
        cout << setw(8) << left << "" << "\t\t__________________________________________________________\n\n";
	}
};

