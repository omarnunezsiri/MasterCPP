/* C++ Standard Template Library - LinkedIn Course */

/* Implemented by Omar Nunez Siri */

#define MAX_FLOOR_ROOMS 15
#define MAX_FLOORS 20

#include <iostream>
#include <map>
#include <string>

using namespace std;

bool validateRange(int number, int lowerLimit, int upperLimit)
{
	return number >= lowerLimit && number <= upperLimit;
}

void displayGuests(const map<pair<int, int>, string>& thisMap)
{
	cout << "\nGuests...{" << endl;
	for (auto itr = thisMap.begin(); itr != thisMap.end(); itr++)
		cout << itr->first.first << itr->first.second << "  guest(" << itr->second << ")" << endl;

	cout << "} End" << endl;
}

int main(void)
{
	map<pair<int, int>, string> rooms;
	pair<pair<int, int>, string> guestRoom;
	pair<int, int> roomPair;
	int temp = 0;
	string str;

	cout << "Inserting guests..." << endl;
	while (temp >= 0)
	{
		cout << "\nEnter floor number: ";
		getline(cin, str);
		temp = stoi(str);

		if (temp >= 0)
		{
			if (validateRange(temp, 1, MAX_FLOORS))
			{
				roomPair.first = temp;

				cout << "Enter room number: ";
				getline(cin, str);
				temp = stoi(str);

				if (validateRange(temp, 1, MAX_FLOOR_ROOMS))
				{
					roomPair.second = temp;

					guestRoom.first = roomPair;
					cout << "Enter guest name: ";
					getline(cin, str);
					guestRoom.second = str;

					rooms.insert(guestRoom);
				}
				else
				{
					cout << "Room number must be between " << 1 << " and " << MAX_FLOOR_ROOMS << endl;
				}
			}
			else
			{
				cout << "Floor number must be between " << 1 << " and " << MAX_FLOORS << endl;
			}
			
		}
	}

	displayGuests(rooms);

	temp = 0;
	cout << "\nRemoving guests...\n";

	while (temp >= 0)
	{
		cout << "Enter floor number: ";
		getline(cin, str);
		temp = stoi(str);

		if (temp >= 0)
		{
			roomPair.first = temp;

			cout << "Enter room number: ";
			getline(cin, str);
			temp = stoi(str);

			roomPair.second = temp;
			rooms.erase(roomPair);
		}
	}

	displayGuests(rooms);
	return 0;
}