#include "main.h";
#include "single.cpp";
#include "circulardouble.cpp";

using namespace single;


char menu(Box _box){
	string types;
	int ii = 0;

	while (true)
	{
		switch (ii)
		{
		case 0:
			system("cls");
			_box.displayMessage();
			_box.CreateBox(1, 5, 80, 20);
			_box.GotoXY(20, 8);
			cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
			_box.GotoXY(20, 9);
			cout << ChangeColor(FOREGROUND_GREEN) << "|             VINCENT CEREZO              |";
			_box.GotoXY(20, 10);
			cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
			_box.GotoXY(13, 11);
			cout << ChangeColor(FOREGROUND_WHITE) << "**********************************************************";
			_box.GotoXY(13, 12);
			cout << "*                       *                                *";
			_box.GotoXY(13, 13);
			cout << "* " << ChangeColor(FOREGROUND_GREEN) << "S: Single linked list " << ChangeColor(FOREGROUND_WHITE) << "* " << ChangeColor(FOREGROUND_GREEN) << "D: Circular Double Linked List " << ChangeColor(FOREGROUND_WHITE) << "*";
			_box.GotoXY(13, 14);
			cout << "* " << ChangeColor(FOREGROUND_GREEN)   << "E: EXIT               " << ChangeColor(FOREGROUND_WHITE) << "* " << ChangeColor(FOREGROUND_WHITE) <<"                               *";
			_box.GotoXY(13, 15);
			cout << "*                       *                                *";
			_box.GotoXY(13, 16);
			cout << "**********************************************************";
			_box.GotoXY(13, 17);
			cout << ChangeColor (FOREGROUND_GREEN) << "Enter your Choice: ";
			cin >> types;
			_box.GotoXY(20, 21);
			cout << ChangeColor(FOREGROUND_WHITE);
			ii = 1;
			break;
		case 1:
			if (_box.isNumber(types) == false)
			{
				if (types == "S" || types == "s"  || types == "D"  || types == "d"  || types == "E"  || types == "e") {
					char _types = types[0];
					return _types;
				}
				else {
					string message;
					message += types;
					_box.ChangeSystemMessage("Invalid Keyword: " + message);
					types = " ";
					ii = 0;
				}
			}
			else {
				string message;
				message += types;
				_box.ChangeSystemMessage("Invalid Keyword: " + message);
				types = " ";
				ii = 0;
			}
			break;
		}
	}
	return NULL;
}

int main(){
	char ch = 'P';
	Pass _pass;
	Box _box;
	Single _single;
	CircularDouble _circularDouble;

	const char* correct_password = "Cerezo";
	const char* correct_username = "Vincent";

	

	string username;
	
	string password;


	while (true)
	{
		switch (ch)
		{
		case 'S': case 's':
			ch = _single.SingleMain(_box);
			break;
		case 'D': case 'd':
			ch = _circularDouble.main(_box);
			break;
		case 'E': case 'e':
			exit(0);
			break;
		case 'P':
			cout << "Please enter the Username: "; cin >> username;
			password = _pass.getpass("Please enter the password: ", true);
			ch = ' ';
			break;
		default:
			if (username == correct_username && password == correct_password)
			{
				/*cout << "\nAuthentication success..." << endl;*/
				_box.ChangeSystemMessage("Authentication Success...");
				
				ch = menu(_box);
				
			}
			else {
				//cout << "Authentication error..." << endl;
				system("cls");
				_box.ChangeSystemMessage("Authentication Error...");
				_box.displayMessage();
				ch = 'P';
			}
			
			break;
		}
	}
}






















//VINCENT CEREZO