/*
Ethan Perry, Program 5 myString
journal:
11/16 - We started thinking about these functions in lab for myString and began to write them. After lab we
        had some early prototypes for assignment and concat at the least.
11/17 - We started looking at the given test files and cleaned up code to turn the lab into a project. Many
        of the methods were improved upon and the test file started to use assert. From there, most of the
        relational and assignment methods were done so operator + and the DYI methods had to be cleaned up.
11/20 - Finished a working copy of op + and created the op * method that replicates and concats strings.
11/22 - Finished the op ^ to capitalize the ptext of a given method. I also did all the documentation needed
        and cleaned up other formatting to get it in working order.

 */

#include "myString.h"
#include <stdlib.h>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;


/*   empty CTOR
PRE: There is no object with the created name and nothing in that space
POST: A new object is created holding a null string (really just the null char)
and has the length variable = 0
 */
myString::myString()  // CTOR (default)
{
  pText = new char[1];
  pText[0] = '\0';
  length=0;
}

/*
PRE: This CTOR is overloaded but nothing will exist in the object before. A string is read in as a param
POST: An object is created with a string (array of char's), a pointer there (*pText), and the length
 */
myString::myString( char newText[] ) { // CTOR (with parameter)
   long newLength = strlen(newText);
   pText = new char[ newLength+1 ];  // add +1 to hold the NULL char '\0'

   strcpy(pText, newText);
   length=strlen(pText);
}

/*   COPY CTOR
PRE: An object already exists and this CTOR births another object mitosis style (clone)
POST: Another object is created with the same string stored as the creators but in a different mem. location
 */
myString::myString(myString& object){

    // this-> should get a clone of object
    this->pText = new char[object.length + 1];

    strcpy(this->pText, object.pText);
    this->length = object.length;
}

/*
The lovely DTOR that unassigns the pointer (unlocks that memory), there by deleting the object
 */
myString::~myString() {// DTOR

    if (pText != 0)
        delete []pText;
}


/*
PRE: Existing object that has a length and string (call is A) can do A.getlength to access private member length
POST: Return length of the string in that object
 */
long myString::getLength() const
{
    return length;
}

/*
PRE: This takes two pre-existing objects and is called by (object1 = object2)
POST: The one on the right (anotherStringObject), gets put into this->object (assigned into)
 */
myString& myString::operator=(const myString& anotherStringObject)
{
    // do we have enough room to hold the new string?
    if (this->length < anotherStringObject.length ) {
        // dang, not enough room, so clean up and make enough room
        delete []this->pText;
        this->pText = new char[ anotherStringObject.length + 1];
    }
    strcpy(this->pText, anotherStringObject.pText);
    this->length = strlen(this->pText);

    return (*this);
}

/*
SUMMARY: This is equivalent to assinginto with string parameter where there already exists a defined string.
PRE: This defined string can be set equal to a class there by assigning that string to copy into the this->object
POST: this->object's pText gets updated to the assigned newText being used in the call.
 */
myString& myString::operator=(const char newText[])
{
    // do we have enough room to hold the new string?
    if (length < strlen(newText) ) {
        // dang, not enough room, so clean up and make enough room
        delete []pText;
        pText = new char[ strlen(newText) + 1];
    }
    strcpy(pText, newText);
    length = strlen(pText);

    return (*this);
}

/*
This function is called by trying to acess an index of a class (called by D[0])
PRE: The input being the desired chracters index (long i)
POST: The function returns the character of this->pText that corresponds to that index in brackets
 */
char myString::operator[](long i) const{
    return(pText[i]);
}

/*
SUMMARY: This function concats the pTexts of two classes and returns them in a deep copy temp
PRE: Two objects are added using that operator (A+B) and are set equal to a pre-existing class (C = A + B)
POST: The deep copy made from the concat is returned by value and is transferred into the assigned class (C)
 */
myString myString::operator+(const myString& object) const{
    myString temp;

    temp.length = this->length + object.length;
    temp.pText = new char[temp.length + 1];

    strcat(strcpy(temp.pText, this->pText),strcpy(temp.pText, object.pText));

    return temp;
}

// ======== RELATIONALS ==============
/* for all relationals the pre is the same
Pre: two existing objects are being related and testing this relationship
Post: The appropriate output true for when the objects relation is valid given the call and false otherwise
 */

bool myString::operator==(const myString& object) const{
    if (this->length == object.length)
        return true;
    else
        return false;
}

bool myString::operator!=(const myString& object) const{
    if (this->length != object.length)
        return true;
    else
        return false;
}

bool myString::operator<(const myString& object) const{
    if(this->length < object.length)
        return true;
    else
        return false;
}

bool myString::operator>(const myString& object) const{
    if(this->length > object.length)
        return true;
    else
        return false;
}

bool myString::operator<=(const myString& object) const{
    if(this->length <= object.length)
        return true;
    else
        return false;
}

bool myString::operator>=(const myString& object) const{
    if(this->length >= object.length)
        return true;
    else
        return false;
}

// ==================== my methods =====================

/*
Summary: this method takes the pText of the object and repeats it i times and concats
Pre: Called by (A*3), the function reads in the long i value (3 would get you the original pText + 2 more concated on)
Post: Similar to op +, this will return a deep copy by value and then call be assigned into a seperate object
 */
myString myString::operator*(const long i) const{
    myString temp;

    temp.length = this->length * i;
    temp.pText = new char[temp.length + 1];
    temp.pText = strcpy(temp.pText, this->pText);
    for(short k = 1; k < i; k++){
        temp.pText = strcat(temp.pText, this->pText);
    }
    return temp;
}

/*
Summary: This method takes the string of the entered objects pText and makes it all capital assigned into the function
         caller, for example (A^B) makes A store capitalized B ptext. (B^B) would make B's ptext all upper.
Pre: There are two existing objects prior and they are called in the form right goes into left
Post: After, the object on the left will have the capitalized pText of the one on the right.
 */
myString& myString::operator^(const myString& object){

    if (this->length < strlen(object.pText) ) {
        delete []this->pText;
        this->pText = new char[strlen(object.pText) + 1];
    }
    strcpy(this->pText, object.pText);
    this->length = object.length;

// convert all chars to upper (took some digging but found char have numerical assosciation)
    for(short i = 0; this->pText[i] != '\0'; i++){
        if(this->pText[i] >= 'a' && this->pText[i] <= 'z'){ // this is saying for lowercase alphabetic chars
            this->pText[i] = this->pText[i] - 32;           // this shifts them to their upper case counterpart
        }
    }
    return (*this);
}

/*
Output stream
Preondition: << operators still used with cout and vector is an assigned vector
Returns: ostream output
*/
ostream& operator<<(/*Inout*/ ostream& output, /*In*/ const myString& someText)
{
    output << someText.pText << endl;

    return output;
}


/*
not sure what to do with all of this but I left it in
 */
/*
myString& myString::firstchar(const myString& object){

 // memory leak?
 char f = new char[2];

 char f = pText[0];

 return f;
}
 */

/*
void myString::appendToMe( const myString& anotherString)
{
    // save a pointer to the old pText so we can delete it later
    char *oldPText = pText;

    // we'll assume do we NOT have enough room to concat the new string
    // new length must be large enough to hold both strings
    long newLength = (length + anotherString.length);
    pText = new char[newLength+1];

    strcpy(pText, oldPText);            // start with original text
    strcat(pText, anotherString.pText); // concat on additional text
    length = strlen(pText);

    delete []oldPText;
}

void myString::appendToMe( const char newText[]) {
    // save a pointer to the old pText so we can delete it later
    char *oldPText = pText;

    // we'll assume do we NOT have enough room to concat the new string
    // new length must be large enough to hold both strings
    long newLength = (length + strlen(newText));
    pText = new char[newLength + 1];

    strcpy(pText, oldPText);    // start with original text
    strcat(pText, newText);     // concat on additional text
    length = strlen(pText);

    delete []oldPText;
}


void myString::PrintMe() const
{
	cout << "Text is: " << pText << endl;
}
 */
