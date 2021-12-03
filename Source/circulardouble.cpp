#include "main.h";
#include <cstddef>;
#include <string>

class CircularDouble
{
	Box __box;
public:
	char main(Box _box)
	{
		__box = _box;
		int ch, n;
		while (1)
		{
			ch = menu();
			switch (ch)
			{
			case 1:
				if (start == NULL)
				{
					cout << "\n Number of nodes you want to create: ";
					cin >> n;
					__box.ChangeSystemMessage(cdll_createlist(n));
				}
				else {
					__box.ChangeSystemMessage("List is already created...");
					ch = menu();
				}
				break;
			case 2:
				__box.ChangeSystemMessage(cdll_insert_beg());
				break;
			case 3:
				__box.ChangeSystemMessage(cdll_insert_end());
				break;
			case 4:
				__box.ChangeSystemMessage(cdll_insert_mid());
				break;
			case 5:
				__box.ChangeSystemMessage(cdll_delete_beg());
				
				break;
			case 6:
				__box.ChangeSystemMessage(cdll_delete_last());
				break;
			case 7:
				__box.ChangeSystemMessage(cdll_delete_mid());
				break;
			case 8:
				__box.ChangeSystemMessage(cdll_display_left_right());
				break;
			case 9:
				__box.ChangeSystemMessage(cdll_display_right_left());
				break;
			case 10:
				return ' ';
				break;
			}
		}
	}
private:
	struct cdlinklist
	{
		struct cdlinklist* left;
		int data;
		struct cdlinklist* right;
	};

	typedef struct cdlinklist node;
	node* start = NULL;
	int nodectr;

	node* getnode()
	{
		node* newnode;
		newnode = (node*)malloc(sizeof(node));
		string _data;

		cout << "\n Enter data: ";
		cin >> _data;
		if (__box.isNumber(_data) == false)
		{
			string message;
			message += _data;
			__box.ChangeSystemMessage("Invalid Data to inputed: " + message + " |(note: Interger)...");
			return NULL;
		}
		else {
			newnode->data = stoi(_data);
			newnode->left = NULL;
			newnode->right = NULL;
			return newnode;
		}
	}
	int menu()
	{
		int state = 0, ii;
		string ch = " ";

		while (true)
		{
			switch (state)
			{
			case 0:
				ch = " ";;
				system("cls");
				__box.displayMessage();
				__box.GotoXY(20, 1);
				cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
				__box.GotoXY(20, 2); cout << ChangeColor(FOREGROUND_GREEN) << "|             VINCENT CEREZO              |";
				__box.GotoXY(20, 3); cout << ChangeColor(FOREGROUND_GREEN) << "|       CIRCULAR DOUBLE LINKED LIST       |";
				__box.GotoXY(20, 4); cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
				__box.GotoXY(20, 5); cout << ChangeColor(FOREGROUND_GREEN) << "| 1." << ChangeColor(FOREGROUND_WHITE) << " Create a list                        |";
				__box.GotoXY(20, 6); cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
				__box.GotoXY(20, 7); cout << ChangeColor(FOREGROUND_GREEN) << "| 2." << ChangeColor(FOREGROUND_WHITE) << " Insert a node at beginning           |";
				__box.GotoXY(20, 8); cout << ChangeColor(FOREGROUND_GREEN) << "| 3." << ChangeColor(FOREGROUND_WHITE) << " Insert a node at end                 |";
				__box.GotoXY(20, 9); cout << ChangeColor(FOREGROUND_GREEN) << "| 4." << ChangeColor(FOREGROUND_WHITE) << " Insert a node at mid                 |";
				__box.GotoXY(20, 10); cout << ChangeColor(FOREGROUND_GREEN) << "| 5." << ChangeColor(FOREGROUND_WHITE) << " Delete a node from beginning         |";
				__box.GotoXY(20, 11); cout << ChangeColor(FOREGROUND_GREEN) << "| 6." << ChangeColor(FOREGROUND_WHITE) << " Delete a node from Last              |";
				__box.GotoXY(20, 12); cout << ChangeColor(FOREGROUND_GREEN) << "| 7." << ChangeColor(FOREGROUND_WHITE) << " Delete a node from Middle            |";
				__box.GotoXY(20, 13); cout << ChangeColor(FOREGROUND_GREEN) << "| 8." << ChangeColor(FOREGROUND_WHITE) << " Traverse the list (Left to Right)    |";
				__box.GotoXY(20, 14); cout << ChangeColor(FOREGROUND_GREEN) << "| 9." << ChangeColor(FOREGROUND_WHITE) << " Traverse the list (Right to Left)    |";
				__box.GotoXY(20, 15); cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
				__box.GotoXY(20, 16); cout << ChangeColor(FOREGROUND_RED) << "| 10. Exit                                |";
				__box.GotoXY(20, 17); cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
				__box.GotoXY(20, 18); cout << ChangeColor(FOREGROUND_WHITE) << " Enter your choice: ";
				cin >> ch;
				state = 1;
				break;
			case 1:
				if (__box.isNumber(ch) == false)
				{
					string message;
					message = ch;
					__box.ChangeSystemMessage("Invalid Keyword: " + message);
					ch = " ";
					state = 0;
				}
				else {
					if (stoi(ch) >= 1 && stoi(ch) <= 11)
					{
						return stoi(ch);
					}
					else {
						string message;
						message += ch;
						__box.ChangeSystemMessage("Invalid Keyword: " + message);
						ch = " ";
						state = 0;
					}
				}
				break;
			}

		}
		
	}
	string cdll_createlist(int n)
	{
		int i;
		node* newnode, * temp;
		if (start == NULL)
		{
			nodectr = n;
			for (i = 0; i < n; i++)
			{
				newnode = getnode();
				if (newnode == NULL)
					return "Invalid Input Data";
				if (start == NULL)
				{
					start = newnode;
					newnode->left = start;
					newnode->right = start;
				}
				else
				{
					newnode->left = start->left;
					newnode->right = start;
					start->left->right = newnode;
					start->left = newnode;
				}
			}
		}
		return "List already exist...";

	}
	string cdll_display_left_right()
	{
		node* temp;
		temp = start;
		string message1 = "The contents of List(Left to Right): ";
		string message2;
		string message3;
		if (start == NULL)
			return "List is Empty";
		else
		{
			cout << temp->data;
			message2 = to_string(temp->data);
			temp = temp->right;
			while (temp != start)
			{
				cout << "<->" << temp->data;
				message3 += "<->" + to_string(temp->data);
				/*cout << temp->data;*/
				temp = temp->right;
			}
		}
		return message1 + message2 + message3;
	}
	string cdll_display_right_left()
	{
		node* temp;
		temp = start;

		string message = "The contents of List(Right to Left) : ";
		string message2;
		if (start == NULL)
			return "List is Empty";
		else
		{
			do
			{
				temp = temp->left;
				cout << ChangeColor(FOREGROUND_BLUE)<< "<->" << temp->data;
				message2 = "<->" + to_string(temp->data);
			} while (temp != start);
		}

		return message + message2;
	}

	string cdll_insert_beg()
	{
		node* newnode;
		newnode = getnode();
		if (newnode == NULL)
			return "Invalid Input Data";
		nodectr++;
		if (start == NULL)
		{
			start = newnode;
			newnode->left = start;
			newnode->right = start;
		}
		else
		{
			newnode->left = start->left;
			newnode->right = start;
			start->left->right = newnode;
			start->left = newnode;
			start = newnode;
		}
		string message = "Node Inserted at Beginning withthe data: " + to_string(newnode->data);
		return message;

	}
	string cdll_insert_end()
	{
		node* newnode, * temp;
		newnode = getnode();
		if (newnode == NULL)
			return "Invalid Input Data";
		nodectr++;
		if (start == NULL)
		{
			start = newnode;
			newnode->left = start;
			newnode->right = start;
		}
		else
		{
			newnode->left = start->left;
			newnode->right = start;
			start->left->right = newnode;
			start->left = newnode;
		}
		string message = "Node Inserted at End with the data: " + to_string(newnode->data);

		return message;
	}
	string cdll_insert_mid()
	{
		node* newnode, * temp, * prev;
		int _pos, ctr = 1;
		string pos, message;
		newnode = getnode();
		if(newnode == NULL)
			return "Invalid Input Data";

		cout << "\n Enter the position: ";
		cin >> pos;
		if (__box.isNumber(pos) == false)
		{
			return "Invalid Position " + pos;
		}
		else {
			_pos = stoi(pos);
		}
		if (_pos - nodectr >= 2)
		{
			message = "Not a middle Position: " + to_string(_pos) ;
			return message + " || Out of Range...";
		}
		if (_pos > 1 && _pos <= nodectr)
		{
			temp = start;
			while (ctr < _pos - 1)
			{
				temp = temp->right;
				ctr++;
			}
			newnode->left = temp;
			newnode->right = temp->right;
			temp->right->left = newnode;
			temp->right = newnode;
			nodectr++;
		}
		else {
			message = "Not a middle Position: " + to_string(_pos);
			return message;
		}
		message = "Node Inserted at Middle with the data: " + to_string(newnode->data);
		return message;
	}
	string cdll_delete_beg()
	{
		string message;
		node* temp;
		if (start == NULL)
		{
			message = "No list of nodes...";
			return message;
		}
		else
		{
			nodectr--;
			if (nodectr == 0)
			{
				free(start);
				start = NULL;
			}
			else
			{
				temp = start;
				start = start->right;
				temp->left->right = start;
				start->left = temp->left;
				free(temp);
				message = "Node deleted with the data: " + to_string(temp->data);
				return message;
			}
			
		}
	}
	string cdll_delete_last()
	{
		node* temp;
		string message;
		if (start == NULL)
		{
			message = "Empty List...";
			return message;
		}
		else
		{
			nodectr--;
			if (nodectr == 0)
			{
				free(start);
				start = NULL;
			}
			else
			{
				temp = start;
				while (temp->right != start)
					temp = temp->right;
				temp->left->right = temp->right;
				temp->right->left = temp->left;
				free(temp);
				message = "Node deleted with the data: " + to_string(temp->data);
				return message;
			}
			
		}
	}
	string cdll_delete_mid()
	{
		int ctr = 1, _pos;
		string pos, message;
		node* temp;
		if (start == NULL)
		{
			message = "Empty List...";
			return message;
		}
		else
		{
			cout << "\n Which node to delete: ";
			cin >> pos;
			if (__box.isNumber(pos) == false)
			{
				return "Invalid Position " + pos;
			}
			else _pos = stoi(pos);

			if (_pos > nodectr)
			{
				message = "This node doesn't exist...";
				return message;
			}
			if (_pos > 1 && _pos < nodectr)
			{
				temp = start;
				while (ctr < _pos)
				{
					temp = temp->right;
					ctr++;
				}
				temp->right->left = temp->left;
				temp->left->right = temp->right;
			}
			else
			{
				message = "Invalid position...";
				return message;
			}
			message = "Node deleted with the data: " + to_string(temp->data);
			return message;
		}
	}
};
//VINCENT CEREZO