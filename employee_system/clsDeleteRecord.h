#pragma once
#include "clsStringsAndFiles.h"

class clsDeleteRecord
{
public:
    static void DeleteRecord(){
    vector <clsOperations::stEmp> EMP = clsOperations::GetRecordsFromFile();

    cout << "Enter Your ID : ";
    string ID ; cin >> ID;

    clsOperations::SaveRecordsWithDeleteOnce(EMP, ID);
    }
};
