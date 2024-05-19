#pragma once
#include "clsStringsAndFiles.h"


class clsAddNewRecord : public clsOperations
{
public:
    static void AddNewRecordScreen(){
         clsOperations::stEmp emp = clsOperations::readNewRecord();
         clsOperations::SaveRecord(clsOperations::ConvertRecordToLine(emp));

         cout << "do you want to add more records?: (y/n)";
         char check; cin >> check;


         if (check == 'y' || check == 'Y'){
            system("cls");
            AddNewRecordScreen();
         }
    }
};
