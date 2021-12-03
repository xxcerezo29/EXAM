#pragma once
#include <iostream>
#include <cstddef>
#include <conio.h>
#include <Windows.h>


using namespace std;

#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

class ChangeColor {
	friend ostream& operator<<(ostream& out, ChangeColor attr)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr.value);
		return out;
	}
public:
	explicit ChangeColor(WORD attributes) : value(attributes) {}
	
	
private:
	WORD value;
	
};
class Pass
{
public:
	string getpass(const char* prompt, bool show_asterisk = true) {
		const char BACKSPACE = 8;
		const char RETURN = 13;

		string password;
		unsigned char ch = 0;

		cout << prompt << endl;

		while ((ch = _getch()) != RETURN)
		{
			if (ch == BACKSPACE)
			{
				if (password.length() != 0)
				{
					if (show_asterisk)
						cout << "\b \b";
					password.resize(password.length() - 1);
				}
			}
			else if (ch == 0 || ch == 224)
			{
				_getch();
				continue;
			}
			else {
				password += ch;
				if (show_asterisk)
					cout << '*';
			}
		}
		cout << endl;
		return password;
	}
};
class Box
{
public:
	void GotoXY(int x, int y)
	{
		COORD coordinate;
		coordinate.X = x;
		coordinate.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
	}
	void CreateBox(int x1, int y1, int x2, int y2) 
	{
		GotoXY(x1, y1); cout << char(201);
		GotoXY(x2, y1); cout << char(187);
		GotoXY(x1, y2); cout << char(200);
		GotoXY(x2, y2); cout << char(188);

		for (int row = y1+1; row < y2; row++)
		{
			GotoXY(x1, row); cout << char(186);
			GotoXY(x2, row); cout << char(186);
		}
		for (int col = x1+1; col < x2; col++)
		{
			GotoXY(col, y1); cout << char(205);
			GotoXY(col, y2); cout << char(205);
		}
	}
	string systemMessage;

	void ChangeSystemMessage(string _message) {
		systemMessage = _message;
	}

	void displayMessage()
	{
		cout << ChangeColor(FOREGROUND_WHITE) << "System Message: " << systemMessage << endl;
	}
	bool isNumber(const string& str) {
		return !str.empty() && find_if(str.begin(), str.end(), [](unsigned char c) {
			return !isdigit(c); }) == str.end();
	}
private:

};








//VINCENT CEREZO

