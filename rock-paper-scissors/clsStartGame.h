#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

class clsStartGame
{
private:
	static short ReadRoundNumbers(string st, short f, short t) {

		short n; cout << st; cin >> n;
		while (n > t || n < f) {
			cout << "Select Any Option Between The Range [" << f << " to " << t << "] : ";
			cin >> n;
		}

		return n;
	}

	static void GameHeader() {

		cout << "\t\t\t\t\t\tRock-Paper-Scissors\n";
		cout << "\t\t\t\t\t\t-------------------\n";
		cout << "\t\t\t\t\t___________________________________\n\n";
	}

	static void OperationsGame(short& Pcounter, short& Ccounter) {


		short Computer = rand() % 3 + 1;
		short Person = ReadRoundNumbers("", 1, 3);
		
		if (Person == 1 && Computer == 3 || Person == 2 && Computer == 1 || Person == 3 && Computer == 2) {
			system("color 2");
			cout << "\nYou Win\n";
			Pcounter++;
		}

		else if (Computer == 1 && Person == 3 || Computer == 2 && Person == 1 || Computer == 3 && Person == 2) {
			system("color 4");
			cout << "\nComputer Win\n";
			Ccounter++;
		}
		
		else
		{
			system("color 8");
			cout << "\nNo Winner\n";
		}
	}

	static void FinalGameReult(short& Pcounter, short& Ccounter) {

		string Winner;

		if (Pcounter == Ccounter) 
			Winner = "No Winner";
		else 
			Winner = (Pcounter > Ccounter) ? "User" : "Computer";


		cout << "\n\n\t\t\t\t\t + + + G a m e  O v e r + + + \n";
		cout << "\t\t\t___________________________________________________________\n\n";

		cout << "\t\t\t\t\t User Time To Win : " << Pcounter << "\n";
		cout << "\t\t\t\t\t Computer Time To Win : " << Ccounter << "\n";
		cout << "\t\t\t\t\t Winner is : " << Winner << "\n";

		cout << "\t\t\t___________________________________________________________\n\n";
	}

public:
	

	static void StartGame() {

		short rNumebrs = ReadRoundNumbers("Enter Round Number: ",1,20);
		short Pcounter = 0, Ccounter = 0;

		system("cls");
		GameHeader();

		for (short k = 0; k < rNumebrs; k++) {
			cout << "Round [" << k+1 << "] : \n-------------\n";
			cout << "Choice : ( [1] Rock, [2] Paper, [3] Scissors ) : ";
			OperationsGame(Pcounter, Ccounter);
			cout << "_______________________\n\n";
		}

		FinalGameReult(Pcounter, Ccounter);
	}
};

