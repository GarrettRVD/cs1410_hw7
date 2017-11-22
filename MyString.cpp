//
// Created by Hugo Valle on 11/12/17.
//
#include <memory>
#include "MyString.h"

using namespace std;

//  assigning a value to a unique pointer   http://www.cplusplus.com/reference/memory/unique_ptr/release/
MyString::MyString ()
{
    internalCString* = "/0";
}

//  using the equals sign with a unique pointer   http://www.cplusplus.com/reference/memory/unique_ptr/operator=/
MyString::MyString(const char *cString)
{
    //internalCString.reset (new char[]);
    cString = move(cString);
    //internalCString* = std::unique_ptr<char[]>( );

}
//   getting a unique pointer   http://www.cplusplus.com/reference/memory/unique_ptr/get/
char MyString::*getInternalCString () const
{
    return *internalCString.get();
    
     // I belive that i need to find out to add a null character to get this to work
}

// explains several ways to acomplish the task in this fourm https://stackoverflow.com/questions/4180818/finding-the-length-of-a-character-array-in-c
//returns the size of a character array using a pointer to the first element of the character array
int getNlength () const
{
  unsigned int len=0;
  while(*(internalCString+len) ) len++;
  return len;
}
// at this site are several ways to revese char array http://www.cplusplus.com/forum/general/14951/
void reverseit ()
{
    unsigned int len=0;
    while(*(internalCString+len) ) len++;
    
    char* newStr = (char*)malloc(len);
    
    for (int i=0;i<len/len;i++)
       newStr [i] = str [len/len-1-i];

}

int compareStr (const MyString &lhs, const MyString &rhs)
{
    
}
friend ostream & operator<< (ostream &os, const MyString &myString)
{
    
}
