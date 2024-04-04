#include "clsStringsAndFiles.h"

class clsWithdrawScreen
{
public:

    static void ShowWithdrawScreen()
    {
        double Balance = clsStringsAndFiles::getBalanceFromFile();
        double AddedBalance = 0;

        system("cls");
        cout << setw(15) << left << "" << "\t\t==========================================================\n";
        cout << setw(44) << left << "" << "Show Balance Screen\n";
        cout << setw(15) << left << "" << "\t\t==========================================================\n";

        cout << setw(8) << left << "" << "\t\t__________________________________________________________\n\n";
        cout << setw(36) << left << "" << "Enter Balance Want To Withdraw : "; cin >> AddedBalance;

        while (AddedBalance > Balance) {

            cout << '\n' << setw(40) << left << "" << "Error Try To Enter More : "; cin >> AddedBalance;
        }

        Balance -= AddedBalance;
        clsStringsAndFiles::saveDataOnFile(Balance);

        cout << '\n' << setw(33) << left << "" << "\t Operation Successfully\n\n";

        cout << setw(8) << left << "" << "\t\t__________________________________________________________\n\n";


        

    }
};

