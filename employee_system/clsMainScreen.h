#pragma once
#include "clsAddNewRecord.h"
#include "clsShowAllRecords.h"
#include "clsUpdateRecordInfo.h"
#include "clsFindRecord.h"
#include "clsDeleteRecord.h"


class clsMainMenue
{
private:
    struct stEmp
    {
        string ID, FirstName, LastName,
               Phone, Email, Address;
    };

    static short readOption(string text, short f, short t) {
        short n; cout << text; cin >> n;

        while (n < f || n > t) {
            cout << " Out Of Range: ";
            cin >> n;
        }

        return n;
    }

    static void GoBackToMainMenuScreen() {
        cout << "\t Press Any Key To Go Back to Main Menu...";
        system("pause>0");
        MainMenueScreen();
    }

    static void AddNewRecordScreen() {
        clsAddNewRecord::AddNewRecordScreen();
    }

    static void ShowAllRecords() {
        clsShowAllRecords::ShowAllRecords();
    }


    static void FindRecord() {
        clsFindRecord::FindRecord();
    }

    static void UpdatetRecord() {
        clsUpdateRecordInfo::UpdateRecordInfo();
    }

    static void DeleleRecord(){
        clsDeleteRecord::DeleteRecord();
    }


    static void PerformMainMenuScreen(short n) {
        system("cls");

        switch (n)
        {
        case 1:
            AddNewRecordScreen();
            GoBackToMainMenuScreen();

        case 2:
            ShowAllRecords();
            GoBackToMainMenuScreen();

        case 3:
            FindRecord();
            GoBackToMainMenuScreen();

        case 4:
            UpdatetRecord();
            GoBackToMainMenuScreen();

        case 5:
            DeleleRecord();
            GoBackToMainMenuScreen();
        }
    }
public:

    static void MainMenueScreen(){
        system("cls");

        cout << "\n-----------------------------\n";
        cout << "+   Main Menue Screen  +";
        cout << "\n-----------------------------\n";
        cout << "  [1] - Add New Record.\n";
        cout << "  [2] - Show All Records.\n";
        cout << "  [3] - Find Record.\n";
        cout << "  [4] - Update Record Info.\n";
        cout << "  [5] - Delete Record.\n";
        cout << "-----------------------------\n";

        PerformMainMenuScreen(readOption(" Choose Option: ", 1,5));
    }
};
