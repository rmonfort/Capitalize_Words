#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cctype>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream;
using std::getline;
using std::istringstream;

int main(int argc, char *argv[])
{
	string input_file;

	// Check first argument if it exists for input file, otherwise ask user
	if (argc > 1)
	{
		input_file = argv[1];
	}
	else
	{
		cout << "Please enter the path to your input file: " << endl;
		cin >> input_file;
	}

	// Open input file and check if successfully opened
	ifstream ifs(input_file);
	if (!ifs)
	{
		cout << "Failed to open input file." << endl;
		return 1;
	}

	string line;
	while (getline(ifs, line))
	{
		istringstream iss(line);
		string temp;
		// Get each word from line and captalize first letter
		while (getline(iss, temp, ' '))
		{
			if (islower(temp[0]))
			{
				temp[0] = toupper(temp[0]);
			}
			cout << temp << " ";
		}
		cout << endl;
	}

	return 0;
}