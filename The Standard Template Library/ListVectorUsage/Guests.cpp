/* C++ Standard Template Library - LinkedIn Course */

/* Implemented by Omar Nunez Siri */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>

using namespace std;

//#define USE_VECTOR
#define USE_LIST

class Guest 
{
    string name;
    string gender;
    int age;
public:
    Guest() {}
    ~Guest() {}

    void setGender(string in)
    {
        char i = in.c_str()[0];
        if (i == 'b' || i == 'B' || i == 'm' || i == 'M')
            gender = "Boy";
        else
            gender = "Girl";
    }

    string getGender()
    {
        return gender;
    }

    void setName(string name)
    {
        this->name = name;
    }

    string getName()
    {
        return name;
    }

    void setAge(int age)
    {
        this->age = age;
    }

    int getAge()
    {
        return age;
    }

    friend ostream& operator<<(ostream&, const Guest&);
};

ostream& operator<<(ostream& os, const Guest& g)
{
    os << "Name: " << g.name << endl;
    os << "Gender: " << g.gender << endl;
    os << "Age: " << g.age << endl;
    return os;
}

#ifdef USE_VECTOR
typedef vector<Guest> myContainer;
#elif defined USE_LIST
typedef list<Guest> myContainer;
#endif

void readFile(myContainer* guests)
{
    string line;

    ifstream ifs("my_guests.txt");
    if (ifs.is_open())
    {
        Guest temp;
        while (getline(ifs, line))
        {
            temp.setName(line);
            getline(ifs, line);
            temp.setGender(line);
            getline(ifs, line);
            temp.setAge(stoi(line));

            guests->push_back(temp);
        }

        ifs.close();
    }
    else
        cerr << "Unable to open file." << endl;
}

void printGuest(myContainer* guests, int index)
{
    cout << "\n--- Print By Index Start ---" << endl;

    int count = 0;
    auto itr = guests->begin();
    
    while (itr != guests->end() && count <= index) {
        if (count == index)
            cout << *itr << endl;

        ++itr;
        ++count;
    }

    cout << "--- Print By Index End ---\n" << endl;
}

bool removeGuest(myContainer* guests, int index) 
{
    int count = 0;
    auto itr = guests->begin();
    while (count != index && itr != guests->end())
    {
        count++;
        itr++;
    }

    if (count == index)
    {
        guests->erase(itr);
        return true;
    }

    return false;
}

float calculateAverage(myContainer* guests)
{
    float average = 1.0f;

    for (auto itr = guests->begin(); itr != guests->end(); ++itr)
    {
		average += itr->getAge();
	}

    return average / guests->size();
}

void printGuests(myContainer* guests)
{
    cout << "--- Container Content Start ---" << endl;

    for (auto itr = guests->begin(); itr != guests->end(); ++itr)
    {
        cout << *itr << endl;
    }

    cout << "--- Container Content End ---" << endl;
}

int main()
{
    myContainer* myGuests = new myContainer;

    readFile(myGuests);
    printGuests(myGuests);

    printGuest(myGuests, 2);

    if (!removeGuest(myGuests, 2))
        cout << "Guest wasn't found to be deleted!" << endl;

    printGuests(myGuests);

    cout << "Average age: " << calculateAverage(myGuests) << endl;
    return 0;
}