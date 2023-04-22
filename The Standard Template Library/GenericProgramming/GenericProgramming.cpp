/* C++ Standard Template Library - LinkedIn Course */

/* Example provided by Eduardo Corpeño */

#include <iostream>

using namespace std;

#define BITS_IN_BYTE 8
template <typename T>

int size_in_bits(const T& a) {
	return (sizeof(a) * BITS_IN_BYTE);
}

int main(void)
{
	cout << size_in_bits(91) << endl;
	cout << size_in_bits('a') << endl;
	cout << size_in_bits(3.123f) << endl;
	cout << size_in_bits(3.123) << endl;
	return 0;
}