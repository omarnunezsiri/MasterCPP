/* C++ Standard Template Library - LinkedIn Course */

/* Implemented by Omar Nunez Siri */

#include <iostream>
#include <stack>

using namespace std;

int main() 
{
	const string VISIT = "1";
	const string BACK = "2";
	const string FORWARD = "3";
	const string EXIT = "4";

	stack<string> urls;
	stack<string> forward_urls;
	string temp;

	while (temp != EXIT) 
	{
		cout << "[1] Visit URL   [2] Back    [3] Forward    [4] Exit" << endl;
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
			if (urls.size() > 0)
			{
				forward_urls.push(urls.top());
				urls.pop();
			}
		}
		else if (temp == FORWARD)
		{
			if (forward_urls.size() > 0)
			{
				urls.push(forward_urls.top());
				forward_urls.pop();
			}
			else {
				cout << "No forward history!" << endl;
			}
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