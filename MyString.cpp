//
// Created by Andrew Bills on 11/12/17.
//
#include <memory>
#include "MyString.h"
#include <algorithm>

using namespace std;

/*!
 * Default constructor
 */
MyString::MyString ()
{
    nlength=1;
    internalCString = make_unique<char[]>(nlength);
    internalCString[0] = '\0';
}

/*!
 * Constructor with one argument
 * @param cString : const char
 */
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

/*!
 * getInternalCString : getter
 * @return : internalCString
 */
char *MyString::getInternalCString () const
{
    return internalCString.get();
}

/*!
 * getNlength : getter
 * @return : nlength
 */
int MyString::getNlength () const
{
    return nlength;
}

/*!
 * reverseit : revert char array
 */
void MyString::reverseit ()
{
    for (int i=0, n = getNlength(); i<n/2; i++)
       swap(internalCString[i], internalCString[n-i-1]);
}

/*!
 * compareStr : compare two MyString objects
 * @param lhs : const MyString
 * @param rhs : const MyString
 * @return position
 */
int MyString::compareStr (const MyString &lhs, const MyString &rhs)
{

    if(lhs.getNlength() < rhs.getNlength()) return -1;
    else if (lhs.getNlength() > rhs.getNlength()) return 1;
    else if(lhs.internalCString[0] == rhs.internalCString[0]) return 0;
    else return -2;

}

/*!
 * operator << overload
 * @param os : ostream
 * @param myString : const MyString
 * @return os
 */
ostream & operator<< (ostream &os, const MyString &myString)
{
    os << myString.getInternalCString();
    return os;
}
