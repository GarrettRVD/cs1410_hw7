//
// Created by Andrew Bills on 11/12/17.
//
#include <memory>
#include "MyString.h"
#include <algorithm>

using namespace std;

//  assigning a value to a unique pointer   http://www.cplusplus.com/reference/memory/unique_ptr/release/
MyString::MyString ()
{
    nlength=1;
    internalCString = make_unique<char[]>(nlength);
    internalCString[0] = '\0';
}

//  using the equals sign with a unique pointer   http://www.cplusplus.com/reference/memory/unique_ptr/operator=/
MyString::MyString(const char *cString)
{
    nlength = 1;
    while(*(cString+nlength))
        nlength++;
    internalCString = make_unique<char[]>(nlength+1);
    for(int len = 0; len < (nlength); len ++)
        internalCString[len] = cString[len];
    internalCString[(nlength+1)] = '\0';
}
//   getting a unique pointer   http://www.cplusplus.com/reference/memory/unique_ptr/get/
char *MyString::getInternalCString () const
{
    return internalCString.get();
}
// explains several ways to acomplish the task in this fourm https://stackoverflow.com/questions/4180818/finding-the-length-of-a-character-array-in-c
//returns the size of a character array using a pointer to the first element of the character array
int MyString::getNlength () const
{
    return nlength;
}
// at this site are several ways to revese char array http://www.cplusplus.com/forum/general/14951/
void MyString::reverseit ()
{
    for (int i=0, n = getNlength(); i<n/2; i++)
       swap(internalCString[i], internalCString[n-i-1]);
}

int compareStr (const MyString &lhs, const MyString &rhs)
{

}
ostream & operator<< (ostream &os, const MyString &myString)
{
    os << myString.getInternalCString();
    return os;
}
