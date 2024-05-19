#pragma once
#include "clsStringsAndFiles.h"

class clsFindRecord
{
private:
    static void RecordInfo(clsOperations::stEmp& EMP){
        cout << "\n====================\n";
        cout << " ID        : " << EMP.ID << "\n";
        cout << " FirstName : " << EMP.FirstName << "\n";
        cout << " LastName  : " << EMP.LastName << "\n";
        cout << " Phone     : " << EMP.Phone << "\n";
        cout << " Email     : " << EMP.Email << "\n";
        cout << " Address   : " << EMP.Address << "\n";
        cout << "\n====================\n";
    }

public:
    static void FindRecord(){
        cout << "Enter Your ID : ";
        string ID ; cin >> ID;

        auto RESULT = clsOperations::isExist(ID);

        if (RESULT.ID == ID)
            RecordInfo(RESULT);
        else
            cout << "\nRecord is Not Exist\n";

    }
};
