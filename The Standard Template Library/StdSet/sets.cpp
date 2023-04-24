/* C++ Standard Template Library - LinkedIn Course */

/* Example adapted by Omar Nunez */

#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

/* Multisets have the behaviour of a hash table (groups duplicate keys) */
void displaySet(const unordered_multiset<int>& thisSet)
{
	cout << "\nSet contents: { ";
	for (auto itr = thisSet.begin(); itr != thisSet.end(); ++itr) 
	{
		cout << *itr << " ";
	}

	cout << "} End\n" << endl;
}

int main(void)
{
	unordered_multiset<int> theSet;
	int temp = 0;

	cout << "Inserting to the set...\n";

	while (temp >= 0)
	{
		cout << "Enter a number: ";
		cin >> temp;

		if (temp >= 0)
			theSet.insert(temp);
	}

	displaySet(theSet);
	temp = 0;

	cout << "Removing from the set...\n";

	while (temp >= 0)
	{
		cout << "Enter an element: ";
		cin >> temp;

		if (temp >= 0)
			theSet.erase(temp);
	}


	displaySet(theSet);
	return 0;
}