/* C++ Standard Template Library - LinkedIn Course */

/* Example adapted by Omar Nunez */

#include <iostream>
#include <deque>

using namespace std;

void displayDeque(deque<int>& numbers)
{
	cout << "Deque content: {  ";

	auto itr = numbers.begin();
	for(; itr != numbers.end(); ++itr)
		cout << *itr << " ";

	cout << " }\n\n";
}

int main(void)
{
	deque<int> numbers;

	int temp = 0;

	cout << "Inserting at the back..." << endl;
	while (temp >= 0) 
	{
		cout << "Enter a number: ";
		cin >> temp;

		if (temp >= 0)
			numbers.push_back(temp);
	}


	displayDeque(numbers);

	temp = 0;
	cout << "Inserting at the front..." << endl;
	while (temp >= 0)
	{
		cout << "Enter a number: ";
		cin >> temp;
		if (temp >= 0)
			numbers.push_front(temp);
	}


	displayDeque(numbers);
	
	return 0;
}