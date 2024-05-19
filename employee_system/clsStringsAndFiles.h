#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class clsOperations
{
public:
    struct stEmp
    {
        string ID, FirstName, LastName,
                Phone, Email, Address;
    };

    static vector<string> Seperate(string Line) {
        vector<string> L_S;
        size_t pos = 0;
        string delimiter = "##";

        while ((pos = Line.find(delimiter)) != string::npos) {
            L_S.push_back(Line.substr(0, pos));
            Line.erase(0, pos + delimiter.length());
        }

        if (!Line.empty()) {
            L_S.push_back(Line);
        }

        return L_S;
    }

    static stEmp ConvertLineToRecord(string Line){
        vector <string> L = Seperate(Line);
        stEmp EMP;

        EMP.ID = L[0];
        EMP.FirstName = L[1];
        EMP.LastName = L[2];
        EMP.Phone = L[3];
        EMP.Email = L[4];
        EMP.Address = L[5];

        return EMP;

    }

    static vector <stEmp> GetRecordsFromFile(){
        fstream File("RECORDS.txt", ios::in);
        vector <stEmp> EMP;


        if (File.is_open()){
            string Line;

            while(getline(File, Line)){
                EMP.push_back(ConvertLineToRecord(Line));
            }
        }

        return EMP;
    }

    static stEmp readNewRecord(){
        vector<stEmp> EMP_DB = GetRecordsFromFile();
        stEmp req;

        cout << " Enter ID : "; cin >> req.ID;

        for (auto& EMP : EMP_DB){
            if (EMP.ID== req.ID){
                cout << " This ID [" + req.ID + "] is Already Exist: ";
                cin >> req.ID;
            }
        }

        cout << " Enter FirstName : "; cin >> req.FirstName;
        cout << " Enter LastName : "; cin >> req.LastName;
        cout << " Enter Phone : "; cin >> req.Phone;
        cout << " Enter Email : "; cin >> req.Email;
        cout << " Enter Address : "; cin >> req.Address;

        return req;
    }


    static string ConvertRecordToLine(stEmp& emp, string Seperate = "##"){
        string Line;

        Line+= emp.ID + Seperate;
        Line+= emp.FirstName + Seperate;
        Line+= emp.LastName + Seperate;
        Line+= emp.Phone + Seperate;
        Line+= emp.Email + Seperate;
        Line+= emp.Address + Seperate;

        return Line;
    }

    static void SaveRecord(string Line){
        fstream File("RECORDS.txt", ios::app);

        if (File.is_open()){
            File << Line << endl;
            File.close();
        }
    }

    static void SaveRecordsOnFile(vector<stEmp>& EMP){
        fstream File("RECORDS.txt", ios::out);

        if (File.is_open()){
            string Line;

            for (auto& record : EMP){
                File << ConvertRecordToLine(record) << endl;
            }
            File.close();
        }
    }

    static void SaveRecordsWithDeleteOnce(vector<stEmp>& EMP, string ID){
        fstream File("RECORDS.txt", ios::out);

        if (File.is_open()){
            for (auto& record : EMP){
                if (record.ID != ID){
                    File << ConvertRecordToLine(record) << endl;
                }
            }
        }

        File.close();
    }

    static stEmp isExist(string ID){
        vector<stEmp> EMP_DB = GetRecordsFromFile();

        for (auto& record : EMP_DB){
            if (record.ID == ID)
                return record;
        }

        return stEmp{};
    }

};
