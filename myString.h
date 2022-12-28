#ifndef MYSTRING
#define MYSTRING

#include <iostream>
using namespace std;


class myString
{
  public:
    myString();                 // CTOR (default)
    myString( char newText[] ); // CTOR (when you know the text already)
    myString(myString& object); // Copy CTOR reading in existing object


    ~myString();                // DTOR

    long getLength() const;     // gets length (accessing private member)

    // Assignment methods that read in an array or object respectively
    myString& operator=(const char newText[]);
    myString& operator=(const myString& anotherStringObject);

    // Overload other relational characters
    char operator[](long i) const;
    myString operator+(const myString& object) const;
    myString operator*(const long i) const;
    myString& operator^(const myString& object);

    // Relational Operators
    bool operator==(const myString& object) const;
    bool operator!=(const myString& object) const;
    bool operator<(const myString& object) const;
    bool operator>(const myString& object) const;
    bool operator<=(const myString& object) const;
    bool operator>=(const myString& object) const;

    //IO operators
    friend ostream& operator<<(/*inout*/ostream& output_stream, /*in*/const myString& someText);
    //void PrintMe() const;

  private:
    char  *pText; // memory for the array of chars will be on the HEAP
    long  length; // number of chars in the text (doesn't include NULL)
    
};

#endif
