/* C++ Standard Template Library - LinkedIn Course */

/* Implemented by Omar Nunez Siri */

#include <iostream>
#include <stack>

using namespace std;

int main() 
{
	const string VISIT = "1";
	const string BACK = "2";
	const string EXIT = "3";

	stack<string> urls;
	string temp;

	while (temp != EXIT) 
	{
		cout << "[1] Visit URL   [2] Back    [3] Exit" << endl;
		cin >> temp;

		if (temp == VISIT)
		{
			cout << "Enter a URL: ";
			cin >> temp;

			urls.push(temp);
		}
		else if (temp == BACK) 
		{
			cout << "Going back..." << endl;
			urls.pop();
		}

		if (temp != EXIT)
		{
			if (urls.size() > 0)
				cout << "Current URL: " << urls.top() << endl;
			else
				cout << "Stack is empty" << endl;
		}	
	}
	return 0;
}