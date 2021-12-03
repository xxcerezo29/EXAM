#include "main.h";
#include <cstddef>;
#include <string>;

namespace single {
	class Single
	{
		Box __box;
	public:
		char SingleMain(Box _box)
		{

			__box = _box;

			int _ch, n,type;
			char ans = ' ';
			while (1)
			{
				_ch = menu();
				switch (_ch)
				{
				case 1:
					if (start == NULL)
					{
						std::cout << "Number of nodes you want to create: " << endl;
						std::cin >> n;
						__box.ChangeSystemMessage(createlist(n));
					}
					else {
						__box.ChangeSystemMessage("List is already created...");
						_ch = menu();
					}
					break;
				case 2:
					_box.ChangeSystemMessage(insert_at_beg());
					break;
				case 3:
					_box.ChangeSystemMessage(insert_at_end());
					break;
				case 4:
					_box.ChangeSystemMessage(insert_at_mid());
					break;
				case 5:
					_box.ChangeSystemMessage(delete_at_beg());
					break;
				case 6:
					_box.ChangeSystemMessage(delete_at_last());
					break;
				case 7:
					_box.ChangeSystemMessage(delete_at_mid());
					break;
				case 8:
					_box.ChangeSystemMessage(traverse());
					break;
				case 9:
					std::cout << "\n The contents of List (Right to Left): \n";
					rev_traverse(start);
					std::cout << " X ";
					break;
				case 10:
					//std::cout << ChangeColor(FOREGROUND_BLUE)<< "\n No of nodes : " << countnode(start);
					if(start != NULL)
					{
						string message = "Number of nodes in the list: " + to_string(countnode(start));
						_box.ChangeSystemMessage(message);
					}
					else
					{
						//_box.systemMessage = "List of nodes doesn't exist...";
						_box.ChangeSystemMessage("List of nodes doesn't exist...");

					}
					
					break;
				case 11:
					system("cls");
					return ' ';
					break;
				}
			}
		}
	private:
		struct  slinklist
		{
			int data;
			struct slinklist* next;
		};

		typedef struct slinklist node;

		node* start = NULL;

		string statusText;

		int menu()
		{
			int state = 0, ii;
			string ch = " ";

			while (true)
			{
				switch (state)
				{
				case 0:
					ch = " ";
					system("cls");
					__box.displayMessage();
					__box.GotoXY(20, 1);
					cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
					__box.GotoXY(20, 2); cout << ChangeColor(FOREGROUND_GREEN) << "|             VINCENT CEREZO              |";
					__box.GotoXY(20, 3); cout << ChangeColor(FOREGROUND_GREEN) << "|           SINGLE LINKED LIST            |";
					__box.GotoXY(20, 4); cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
					__box.GotoXY(20, 5); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 1." << ChangeColor(FOREGROUND_WHITE) << " Create a list                        |";
					__box.GotoXY(20, 6); cout << "|-----------------------------------------|";
					__box.GotoXY(20, 7); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 2." << ChangeColor(FOREGROUND_WHITE) << " Insert a node at beginning           |";
					__box.GotoXY(20, 8); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 3." << ChangeColor(FOREGROUND_WHITE) << " Insert a node at end                 |";
					__box.GotoXY(20, 9); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 4." << ChangeColor(FOREGROUND_WHITE) << " Insert a node at mid                 |";
					__box.GotoXY(20, 10); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 5." << ChangeColor(FOREGROUND_WHITE) << " Delete a node from beginning         |";
					__box.GotoXY(20, 11); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 6." << ChangeColor(FOREGROUND_WHITE) << " Delete a node from Last              |";
					__box.GotoXY(20, 12); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 7." << ChangeColor(FOREGROUND_WHITE) << " Delete a node from Middle            |";
					__box.GotoXY(20, 13); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 8." << ChangeColor(FOREGROUND_WHITE) << " Traverse the list (Left to Right)    |";
					__box.GotoXY(20, 14); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 9." << ChangeColor(FOREGROUND_WHITE) << " Traverse the list (Right to Left)    |";
					__box.GotoXY(20, 15); cout << "|" << ChangeColor(FOREGROUND_GREEN) << " 10." << ChangeColor(FOREGROUND_WHITE) << " Count nodes                         |";
					__box.GotoXY(20, 16); cout << "|-----------------------------------------|";
					__box.GotoXY(20, 17); cout << "|" << ChangeColor(FOREGROUND_RED) << " 11. Exit                                |";
					__box.GotoXY(20, 18); cout << ChangeColor(FOREGROUND_WHITE) << "|-----------------------------------------|";
					__box.GotoXY(20, 19); cout << ChangeColor(FOREGROUND_WHITE) << " Enter you choice: ";
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

		node* getnode()
		{
			node* newnode;
			newnode = (node*)malloc(sizeof(node));
			string _data;

			std::cout << "\n Enter data: ";
			std::cin >> _data;
			if (__box.isNumber(_data) == false)
			{
				string message;
				message += _data;
				__box.ChangeSystemMessage("Invalid Data inputed: " + message + " |(note: Interger)...");
				return NULL;
			}
			else {
				newnode->data = stoi(_data);
				newnode->next = NULL;
				return newnode;
			}
		}

		int countnode(node* ptr)
		{
			int count = 0;
			while (ptr != NULL)
			{
				count++;
				ptr = ptr->next;
			}
			return(count);
		}

		string createlist(int n)
		{
			int i;
			node* newnode, * temp;
			for (i = 0; i < n; i++)
			{
				newnode = getnode();
				if (newnode == NULL)
					return "Invalid Input Data";
				if (start == NULL)
				{
					start = newnode;
				}
				else
				{
					temp = start;
					while (temp->next != NULL)
						temp = temp->next;
					temp->next = newnode;
				}
			}
			return "List Created...";
		}
		string traverse()
		{
			node* temp;
			temp = start;
			std::cout << "\n The contents of List (Left to Right): \n";
			string message1 = "The contents of List (Left to Right): ";
			string message2;
			string message3;
			if (start == NULL)
			{
				std::cout<< ChangeColor(FOREGROUND_RED) << "\n List is Empty";
				return "List is Empty...";
			}
			else
			{
				cout << ChangeColor(FOREGROUND_BLUE) << " " << temp->data;
				message2 = to_string(temp->data);
				temp = temp->next;
				while (temp != NULL)
				{
					std::cout << "->" << temp->data;
					message3 += "->" + to_string(temp->data);
					temp = temp->next;
				}
			}
			return message1 + message2 + message3;
		}
		string rev_traverse(node* start)
		{
			string message;
			if (start == NULL)
			{
				return "Empty List...";
			}
			else
			{
				
				rev_traverse(start->next);
				std::cout << ChangeColor(FOREGROUND_BLUE) << "<-" << start->data;
				message = "<-" + to_string(start->data);
			}
			return message;
		}
		string insert_at_beg()
		{
			node* newnode;
			newnode = getnode();
			if(newnode == NULL)
				return "Invalid Input Data";
			if (start == NULL)
			{
				start = newnode;
			}
			else
			{
				newnode->next = start;
				start = newnode;
			}
			string message = "Node Inserted at Beginning with the data: " + to_string(newnode->data);
			return message;
		}
		string insert_at_end()
		{
			node* newnode, * temp;
			newnode = getnode();
			if (newnode == NULL)
				return "Invalid Input Data";
			if (start == NULL)
			{
				start = newnode;
			}
			else
			{
				temp = start;
				while (temp->next != NULL)
					temp = temp->next;
				temp->next = newnode;
			}
			cout << ChangeColor(FOREGROUND_BLUE) << "\n Node Inserted at End";
			string message = "Node Inserted at End with the data: " + to_string(newnode->data);

			return message;
		}
		string insert_at_mid()
		{
			node* newnode, * temp, * prev;
			string pos, message;
			int _pos,nodectr, ctr = 1;
			newnode = getnode();
			if (newnode == NULL)
				return "Invalid Input Data";
			std::cout << "\n Enter the position: ";
			std::cin >> pos;
			if (__box.isNumber(pos) == false)
			{
				return "Invalid Position " + pos;

			}else {
				_pos = stoi(pos);
			}
			nodectr = countnode(start);
			
			if (_pos > 1 && _pos < nodectr)
			{
				temp = prev = start;
				while (ctr < _pos)
				{
					prev = temp;
					temp = temp->next;
					ctr++;
				}
				prev->next = newnode;
				newnode->next = temp;
			}
			else {
				std::cout << ChangeColor(FOREGROUND_RED) << "position " << _pos << " is not a middle position";
				message = "Not a middle Position: " + to_string(_pos);
				return message;
				system("pause");
			}
				//
			cout << ChangeColor(FOREGROUND_BLUE) << "\n Node Inserted at Middle ";
			message = "Node Inserted at Middle with the data: " + to_string(newnode->data);
			return message;
		}
		string delete_at_beg()
		{
			string message;
			node* temp;
			if (start == NULL)
			{
				//std::cout<< ChangeColor(FOREGROUND_RED) << "\n No nodes are exist..";
				message = "No list of nodes...";
				return message;
			}
			else
			{
				temp = start;
				start = temp->next;
				free(temp);
				std::cout << ChangeColor(FOREGROUND_RED) << "\n Node deleted ";
				
			}
			message = "Node deleted with the data: " + to_string(temp->data);
			return message;
		}
		string delete_at_last()
		{
			node* temp, * prev;
			string message;
			if (start == NULL)
			{
				message = "Empty List...";
				return message;
			}
			else
			{
				temp = start;
				prev = start;
				while (temp->next != NULL)
				{
					prev = temp;
					temp = temp->next;
				}
				prev->next = NULL;
				free(temp);
				std::cout << ChangeColor(FOREGROUND_RED) << "\n Node deleted ";
				message = "Node deleted with the data: " + to_string(temp->data);
				return message;
			}
		}
		string delete_at_mid()
		{
			int ctr = 1, _pos, nodectr;
			string message, pos;
			node* temp, * prev;
			if (start == NULL)
			{
				std::cout << ChangeColor(FOREGROUND_RED) << "\n Empty List..";
				message = "Empty List...";
				return message;
			}
			else
			{
				std::cout << "\n Enter position of node to delete: ";
				std::cin >> pos;
				if (__box.isNumber(pos) == false)
				{
					return "Invalid Position " + pos;
				}
				else {
					_pos = stoi(pos);
				}
				nodectr = countnode(start);
				if (_pos > nodectr)
				{
					message = "This node doesn't exist...";
					return message;
				}
				if (_pos > 1 && _pos < nodectr)
				{
					temp = prev = start;
					while (ctr < _pos)
					{
						prev = temp;
						temp = temp->next;
						ctr++;
					}
					prev->next = temp->next;
					free(temp);
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
}
//VINCENT CEREZO