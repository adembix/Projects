#pragma once
#include "clsStringsAndFiles.h"

class clsUpdateRecordInfo
{
private:
    static void UpdateInfo(clsOperations::stEmp& EMP){
        cout << " Enter FirstName : ";
        cin >> EMP.FirstName;
        cout << " Enter LastName  : ";
        cin >> EMP.LastName;
        cout << " Enter Phone     : ";
        cin >> EMP.Phone;
        cout << " Enter Email     : ";
        cin >> EMP.Email;
        cout << " Enter Address   : ";
        cin >> EMP.Address;
    }

    static void readIDandFindRecord(){
        cout << " Enter ID : ";
        string ID; cin >> ID;

        vector<clsOperations::stEmp> EMP = clsOperations::GetRecordsFromFile();

        for (auto& record : EMP){
            if (record.ID == ID){
                UpdateInfo(record);
                clsOperations::SaveRecordsOnFile(EMP);
                return;
            }
        }

        cout << "\nThis Record is Not Exist.\n";
    }

public:
    static void UpdateRecordInfo(){
        char check = 'Y';

        do
        {
            readIDandFindRecord();

            cout << "\nDo You Want Update More Records (Y/N) : ";
            cin >> check;

        } while(check == 'Y' || check == 'y');
    }
};
