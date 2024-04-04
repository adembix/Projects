#pragma once
#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class clsStringsAndFiles
{
public:

	static double getBalanceFromFile()
	{
		fstream File("balance.txt", ios::in);

		if (File.is_open()) {
			string Line;

			while (getline(File, Line)) {

				File.close();
				return stod(Line);
			}
		}
	}

	static void saveDataOnFile(double Balance)
	{
		fstream File("balance.txt", ios::out);

		if (File.is_open()) {
			File << Balance;
		}

		File.close();
	}
};

