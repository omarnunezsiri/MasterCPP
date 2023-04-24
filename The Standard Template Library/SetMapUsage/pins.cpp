/* C++ Standard Template Library - LinkedIn Course */

/* Implemented by Omar Nunez Siri */

#include <iostream>
#include <map>
#include <string>

using namespace std;

void displayMap(const map<pair<int, int>, string>& thisMap)
{
	cout << "Coordinates...{\n";
	for (auto itr = thisMap.begin(); itr != thisMap.end(); itr++)
		cout << "coords(" << itr->first.first << ", " << itr->first.second << ")  val(" << itr->second << ")" << endl;

	cout << "} End" << endl;
}

int main(void)
{
	map<pair<int, int>, string> pins; // pins representing coordinates (latitude, longitude) and a name
	pair<pair<int, int>, string> p;
	pair<int, int> landmark; // pair to hold landmark (coordinates)
	int temp = 0;
	string str;
	
	cout << "Insertion round...\n";
	while (temp >= 0)
	{
		cout << "Enter latitude: ";
		getline(cin, str);
		temp = stoi(str);

		if (temp >= 0)
		{
			/* Enter coordinate values */
			landmark.first = temp;
			cout << "Enter longitude: ";
			getline(cin, str);
			temp = stoi(str);
			landmark.second = temp;

			/* Value for the key pair */
			p.first = landmark;
			cout << "Enter value(string): ";
			getline(cin, str);
			p.second = str;

			pins.insert(p);
		}
	}

	displayMap(pins);
	return 0;
}