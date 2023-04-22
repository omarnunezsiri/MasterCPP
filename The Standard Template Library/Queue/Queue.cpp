/* C++ Standard Template Library - LinkedIn Course */

/* Example adapted by Omar Nunez */

#include <iostream>
#include <queue>

using namespace std;
int main(void)
{
	queue<char> letters;

	char temp = 'a';
	cout << "Inserting at the back..." << endl;

	while (isalnum(temp))
	{
		cout << "Enter any digit/letter: ";
		cin >> temp;

		if (isalnum(temp))
			letters.push(temp);
	}

	cout << "Removing from the front..." << endl;
	while (!letters.empty())
	{
		cout << letters.front() << endl;
		letters.pop();
	}
	return 0;
}