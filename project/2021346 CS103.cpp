#include <iostream>
#include<sstream>
#include<fstream>
#include<vector>   //also known as dynamic array

using namespace std;

int convert(string str)
{
	if (str == "0")
		return 0;
	else if (str == "1")
		return 1;
	else if (str == "2")
		return 2;
	else if (str == "3")
		return 3;
	else if (str == "4")
		return 4;
	else if (str == "5")
		return 5;
	else if (str == "6")
		return 6;
	else if (str == "7")
		return 7;
	else if (str == "8")
		return 8;
	else if (str == "9")
		return 9;
	else if (str == "10")
		return 10;
	else if (str == "20")
		return 20;
	else if (str == "30")
		return 30;
	else if (str == "35")
		return 35;
	else if (str == "40")
		return 40;
	else
		return 0;
}

string convertTo_str(int num)
{
	if (num == 0)
		return "0";
	else if (num == 1)
		return "1";
	else if (num == 2)
		return "2";
	else if (num == 3)
		return "3";
	else if (num == 4)
		return "4";
	else if (num == 5)
		return "5";
}

int main()
{
	//reading the file
	string word, line;

	vector<vector<string>> all_data;  //initialize
	vector <string> row_data;

	fstream file("data.csv", ios::in);

	while (getline(file, line))
	{
		row_data.clear();

		stringstream str(line);

		while (getline(str, word, ',')) {
			row_data.push_back(word);
		}
		all_data.push_back(row_data);
	}

	int rows = all_data.size();

	char cat, cont = 'n';
	int choice;
	float bill = 0;

	do {
		for (int row = 0; row < rows; row++)
		{
			if (all_data[row][2] == "None")
			{
				cout << all_data[row][0] << " " << all_data[row][1] << endl;
			}
		}

		cout << "Please enter category of items you want to buy from? ";
		cin >> cat;

		if (cat == 'a')
		{
			cout << "_________________" << endl;
			for (int row = 2; row < 7; row++)
			{
				for (int col = 0; col < 3; col++) {
					if (col == 0)
						cout << "|";

					cout << all_data[row][col] << " ";

					if (col == 0)
						cout << "|";
					else if (col == 1)
					{
						if (all_data[row][1].length() == 3)
							cout << "   |";
						else if (all_data[row][1].length() == 5)
							cout << " |";
						else if (all_data[row][1].length() == 6)
							cout << "|";

						cout << "$";
					}
					else if (col == 2)
						if (row == 3)
							cout << "|";
						else
							cout << " |";
				}
				cout << endl;
			}
			cout << "|__|_______|____|" << endl;

			cout << "What do you want to buy: ";
			cin >> choice;


			if (choice >= 6 || choice <= 0)
				cout << "Entry out of range." << endl;
			else {
				if (all_data[choice + 1][3] != "0")
				{
					bill = bill + convert(all_data[choice + 1][2]);
					//stock update
					all_data[choice + 1][3] = convertTo_str((convert(all_data[choice + 1][3])) - 1);
				}
				else
					cout << "Item out of stock." << endl;
			}
		}
		else if (cat == 'b')
		{
			cout << "__________________" << endl;
			for (int row = 8; row < 13; row++)
			{
				for (int col = 0; col < 3; col++) {
					if (col == 0)
						cout << "|";

					cout << all_data[row][col] << ' ';
					
					if (col == 0)
						cout << "|";
					else if (col == 1)
					{
						if (all_data[row][1].length() == 4)
							cout << "    |";
						else if (all_data[row][1].length() == 5)
							cout << "   |";
						else if (all_data[row][1].length() == 6)
							cout << "  |";
						else if (all_data[row][1].length() == 8)
							cout << "|";

						cout << "$";
					}
					else if (col == 2)
						if (row == 10)
							cout << "|";
						else
							cout << " |";
				}
				cout << endl;
			}
			cout << "|__|_________|____|" << endl;

			cout << "What do you want to buy: ";
			cin >> choice;

			if (choice >= 6 || choice <= 0)
				cout << "Choice out of range." << endl;
			else {
				if (all_data[choice + 7][3] != "0")
				{
					bill = bill + convert(all_data[choice + 7][2]);

					all_data[choice + 7][3] = convertTo_str((convert(all_data[choice + 7][3])) - 1);
				}
				else
					cout << "Item out of stock." << endl;
			}
		}
		else if (cat == 'c')
		{
			cout << "__________________" << endl;
			for (int row = 14; row < 19; row++)
			{
				for (int col = 0; col < 3; col++) {
					if (col == 0)
						cout << "|";

					cout << all_data[row][col] << ' ';

					if (col == 0)
						cout << "|";
					else if (col == 1)
					{
						if (all_data[row][1].length() == 4)
							cout << "    |";
						else if (all_data[row][1].length() == 6)
							cout << "  |";
						else if (all_data[row][1].length() == 7)
							cout << " |";

						cout << "$";
					}
					else if (col == 2)
						if (row == 14 || row == 15 || row ==16)
							cout << "|";
						else
							cout << " |";
				}
				cout << endl;
			}
			cout << "|__|_________|____|" << endl;

			cout << "What do you want to buy: ";
			cin >> choice;

			if (choice >= 6 || choice <= 0)
				cout << "Choice out of range.";
			else {
				if (all_data[choice + 13][3] != "0")
				{
					bill = bill + convert(all_data[choice + 13][2]);

					all_data[choice + 13][3] = convertTo_str((convert(all_data[choice + 13][3])) - 1);
				}
				else
					cout << "Item out of stock." << endl;
			}
		}
		else if (cat == 'd')
		{
		cout << "__________________" << endl;
			for (int row = 20; row < 25; row++)
			{
				for (int col = 0; col < 3; col++) {
					if (col == 0)
						cout << "|";

					cout << all_data[row][col] << ' ';

					if (col == 0)
						cout << "|";
					else if (col == 1)
					{
						if (all_data[row][1].length() == 5)
							cout << "    |";
						else if (all_data[row][1].length() == 6)
							cout << "   |";
						else if (all_data[row][1].length() == 7)
							cout << "  |";
						else if (all_data[row][1].length() == 8)
							cout << " |";
						else if (all_data[row][1].length() == 9)
							cout << "|";

						cout << "$";
					}
					else if (col == 2)
						cout << "|";
				}
				cout << endl;
			}
			cout << "|__|__________|___|" << endl;

			cout << "What do you want to buy: ";
			cin >> choice;

			if (choice >= 6 || choice <= 0)
				cout << "Choice out of range." << endl;
			else {
				if (all_data[choice + 19][3] != "0")
				{
					bill = bill + convert(all_data[choice + 19][2]);

					all_data[choice + 19][3] = convertTo_str((convert(all_data[choice + 19][3])) - 1);
				}
				else
					cout << "Item not found." << endl;
			}
		}
		else
		{
			cout << "Invalid entry." << endl;
		}

		bool valid = true;

		do {
			cout << "Do you want to continue?(Y/N) ";
			cin >> cont;

			if ((cont == 'y') || (cont == 'Y') || (cont == 'n') || (cont == 'N')) {
				valid = true;
			}
			else {
				cout << "Invalid Entry" << endl;
				valid = false;
			}
		} while (!valid);

	} while (cont == 'y' || cont == 'Y');

	float tax, shipping;

	tax = bill * 0.05;
	shipping = bill * 0.01;
	bill = bill + tax + shipping;

	cout << "Bill: $" << bill << endl;
	cout << "Tax: $" << tax << endl;
	cout << "Shipping: $" << shipping << endl;

	//Updating the file.
	fstream fout;

	//Creating a new file
	fout.open("newdata.csv", ios::out | ios::app);

	rows = all_data.size();

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fout << all_data[i][j] << ",";
		}
		fout << "\n";
	}

	file.close();
	fout.close();

	//Deleting the old file.
	remove("data.csv");

	//Renaming the new file 
	rename("newdata.csv", "data.csv");
}