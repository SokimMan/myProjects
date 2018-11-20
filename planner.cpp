#include <iostream>
#include <string>
#include <ctime>
#include <fstream>

using namespace std;


void readPlansForToday()
{
	time_t now = time(0);

	tm *ltm = localtime(&now);

	int month = 1 + ltm->tm_mon;
	int year = 1900 + ltm->tm_year;

	string todaysFile = "";

	if (ltm->tm_hour > 4 && 12 > ltm->tm_hour)
	{
		cout << "Good Morning\n";
	}
	else if (ltm->tm_hour > 12 && 18 > ltm->tm_hour)
	{
		cout << "Good Afternoon\n";
	}
	else
	{
		cout << "Good Evening\n";
	}

	todaysFile += to_string(month);
	todaysFile += "-";
	todaysFile += to_string(ltm->tm_mday);
	todaysFile += "-";
	todaysFile += to_string(year);
	todaysFile += ".txt";

	//cout << "The file for the day is " << todaysFile << endl;

	//string todayFile = 1 + ltm->tm_mon + '-' + ltm->tm_mday + '-' + 1970 + ltm->tm_year;

	string line;
	ifstream myfile (todaysFile);
	if (myfile.is_open())
	{
		cout << "You have the following planned for today\n" << endl;

		while ( getline (myfile, line))
		{
			cout << line << endl;
		}
		myfile.close();
	}
	else
	{
		cout << "You have nothing planned for today";
	}

	return;
}

void addToPlanner()
{
	string date;
	cout << "Enter the date for this event(in the form MM-DD-YYYY)\n";
	cin >> date;
	date.append(".txt");

	string event;
	cout << "Enter an event\n";
	cin.ignore();
	getline (cin, event);

	ofstream myfile;
	myfile.open (date, ios::app);

	myfile << event << endl;
	myfile.close();

	return;
}

void listCommands()
{
	cout << "t: print the system time\n";
    cout << "q: quit the program\n";
    cout << "a: add to planner\n";

    return;
}

void time()
{
	time_t now = time(0);

	tm *ltm = localtime(&now);

	if (ltm->tm_hour > 4 && 12 > ltm->tm_hour)
	{
		cout << "Good Morning\n";
	}
	else if (ltm->tm_hour > 12 && 18 > ltm->tm_hour)
	{
		cout << "Good Afternoon\n";
	}
	else
	{
		cout << "Good Evening\n";
	}

	cout << "The date is " << 1 + ltm->tm_mon << "-" << ltm->tm_mday << "-" << 1900 + ltm->tm_year << endl;

	return;
}

void menu()
{
	char input = 'z';

	do
	{
		cout << "Please enter a command(Enter l to list commands): "; 
		cin >> input;
		cout << endl;
		if (input == 't')
		{
			time();
			cout << endl;
		}
		else if (input == 'l')
		{
			listCommands();
			cout << endl;
		}
		else if (input == 'a')
		{
			addToPlanner();
			cout << endl;
		}
		else if (input == 'r')
		{
			readPlansForToday();
			cout << endl;
		}

	}
	while (input != 'q');

	return;
}

int main()
{
	menu();
	return 0;
}