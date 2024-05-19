#pragma once
#include "clsStringsAndFiles.h"

class clsShowAllRecords
{
private:
    static void PrintHeader(){
            cout << left << setw(11) << "ID" << " | "
                 << left << setw(11) << "FirstName" << " | "
                 << left << setw(11) << "LastName" << " | "
                 << left << setw(11) << "Phone" << " | "
                 << left << setw(11) << "Email" << " | "
                 << left << setw(11) << "Address" << "\n";
    }

public:
    static void ShowAllRecords(){
        vector<clsOperations::stEmp> v_emp = clsOperations::GetRecordsFromFile();

        PrintHeader();

        cout << "=============================================================================\n";

        for (auto& record : v_emp){
            cout << left << setw(11) << record.ID << " | "
                 << left << setw(11) << record.FirstName << " | "
                 << left << setw(11) << record.LastName << " | "
                 << left << setw(11) << record.Phone << " | "
                 << left << setw(11) << record.Email << " | "
                 << left << setw(11) << record.Address << "\n";
        }

        cout << "\n=============================================================================\n";
    }
};
