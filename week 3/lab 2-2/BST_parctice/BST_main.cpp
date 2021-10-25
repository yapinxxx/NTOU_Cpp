#include <iostream>     // cout
#include <algorithm>    // binary_search, std::sort
#include <vector>       // vector
#include <cstdlib>      // system()
using namespace std;

struct MyClass 
{
    bool operator()(int i, int j) { return (i<j);}
} myLessObject;

bool myCompare(int i, int j) 
{ 
    return (i<j); 
}

struct StudentRecord
{
    StudentRecord(int id1, int score1):id(id1), score(score1) {}
    bool operator<(const StudentRecord rhs) const
    {
        return id < rhs.id;
    }
    int id;
    int score;
};

int main() 
{
    int myints[] = {1,2,3,4,5,4,3,2,1};
    vector<int> v(myints, myints+9);  // 1 2 3 4 5 4 3 2 1
   
// using default comparison:
    sort(v.begin(), v.end());
   
    cout << "looking for a 3... ";
    if (binary_search(v.begin(), v.end(), 3))
        cout << "found!\n"; 
    else 
        cout << "not found.\n";

// using myCompare as comp:
    sort(v.begin(), v.end(), myCompare);
   
    cout << "looking for a 6... ";
    if (binary_search(v.begin(), v.end(), 6, myCompare))
        cout << "found!\n"; 
    else 
        cout << "not found.\n";

// using myLessObject as comp:
    sort(v.begin(), v.end(), myLessObject);
   
    cout << "looking for a 5... ";
    if (binary_search(v.begin(), v.end(), 5, myLessObject))
        cout << "found!\n"; 
    else 
        cout << "not found.\n";

    StudentRecord mysr[] = {StudentRecord(15, 91), 
                            StudentRecord(5, 75), 
                            StudentRecord(19, 81), 
                            StudentRecord(3, 90), 
                            StudentRecord(7, 83)};
    vector<StudentRecord> vs(mysr, mysr+5);
    stable_sort(vs.begin(), vs.end());
    cout << "looking for a 19... ";

// use StudentRecord::operator<()
    if (binary_search(vs.begin(), vs.end(), StudentRecord(19,20)))
        cout << "found!\n"; 
    else 
        cout << "not found.\n";

    system("pause");
}