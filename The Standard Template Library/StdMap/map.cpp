/* C++ Standard Template Library - LinkedIn Course */

/* Example adapted by Omar Nunez */

#include <iostream>
#include <map>
#include <unordered_map>
#include <string>

using namespace std;

void displayMap(const multimap<int, string>& thisMap)
{
	cout << "Map contents {" << endl;

	for (auto itr = thisMap.begin(); itr != thisMap.end(); itr++)
		cout << "key(" << itr->first << ")  val(" << itr->second << ")" << endl;

	cout << "} End" << endl;
}

int main(void)
{
	multimap<int, string> myMap;
	int temp = 0;
	string tempStr;

	cout << "Inserting elements to the map...\n";
	while (temp >= 0)
	{
		cout << "Enter a key(int): ";
		cin >> temp;

		if (temp >= 0)
		{
			cout << "Enter the value(string): ";
			getline(cin, tempStr);

			myMap.insert(pair<int, string>(temp, tempStr));
		}
	}

	displayMap(myMap);

	temp = 0;
	cout << "Deleting elements from the map...\n";
	while (temp >= 0)
	{
		cout << "Enter a key(int): ";
		cin >> temp;

		if (temp >= 0)
		{
			myMap.erase(temp);
		}
	}

	displayMap(myMap);
	return 0;
}