#include "clsDepositScreen.h"
#include "clsShowBalance.h"
#include "clsWithdrawScreen.h"


class clsMainMenueScreen
{
private:
    enum enOptions { eCheckBalance = 1, eDeposit = 2, eWithdraw = 3, eExit = 4 };

    static void GoBackToMainMenue()
    {
        cout << setw(33) << left << "" << "Press Any Key To Go Back To Main Menue\n";
        system("pause>0");

        ShowAtmMainMenue();
    }

    static void ShowAccountBalanceScreen()
    {
        clsShowBalance::ShowBalance();
        //cout << "\nShow Account Balance Screen is Here\n";
    }
    static void ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
        //cout << "\nShow Deposit Screen is Here\n";
    }

    static void ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
        // cout << "\nShow Withdraw Screen is Here\n";
    }

    static short _ReadMainMenueOption()
    {
        cout << setw(37) << left << "" << "  Enter Option Between [1 - 4] : ";
        short n = 0; cin >> n;
        return n;
    }

    static void _MainMenueOption(enOptions eOption)
    {
        switch (eOption)
        {
        case enOptions::eCheckBalance:

            system("cls");
            ShowAccountBalanceScreen();
            GoBackToMainMenue();
            break;

        case enOptions::eDeposit:

            system("cls");
            ShowDepositScreen();
            GoBackToMainMenue();
            break;

        case enOptions::eWithdraw:

            system("cls");
            ShowWithdrawScreen();
            GoBackToMainMenue();
            break;

        case enOptions::eExit:

            break;
        }
    }
public:

    static void ShowAtmMainMenue()
    {
        system("cls");
        cout << setw(15) << left << "" << "\t\t==========================================================\n";
        cout << setw(44) << left << "" << "Main Meneu Screen\n";
        cout << setw(15) << left << "" << "\t\t==========================================================\n";

        cout << setw(8) << left << "" << "\t\t__________________________________________________________\n\n";
        cout << setw(43) << left << "" << "  [1] Check Balance.\n";
        cout << setw(43) << left << "" << "  [2] Deposit.\n";
        cout << setw(43) << left << "" << "  [3] Withdraw.\n";
        cout << setw(43) << left << "" << "  [4] Exit.\n";
        cout << setw(8) << left << "" << "\t\t__________________________________________________________\n\n";


        _MainMenueOption((enOptions)_ReadMainMenueOption());
    }
};

