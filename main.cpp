#include <iostream>
#include <limits>
using namespace std;

/*
                                        INSTRUCTIONS
Write a simple calculator program that repeatedly allows the user to select +,-,*,/ from a menu of
operations on real values and then enter the two operands which then computes the result of applying
the selected operation to those operands. However, the only named variables you may use are pointer
variables; all others must be anonymous variables.

Pay close attention to the following aspects:

error checking
loop function
pointer variables
code efficiency(smart code), readability, documentation.
*/

int main()
{
  //Declare variables
  char *operation; //We will reference a location in memory by using its address, not a variable name (using a pointer variable)
  operation = new(nothrow) char; //Allocate memory for this new pointer
  float *firstnum;
  firstnum = new(nothrow) float;
  float *secondnum;
  secondnum = new(nothrow) float;
  float *answer;
  answer = new(nothrow) float;
  cout << "Welcome to the calculator program!\n";
  while(true){
    cout << "What operation would you like to use? Choose +, -, *, or /" << endl;
    cin >> *operation;
    while(true) {
      if(*operation == '+' || *operation == '-' || *operation == '*' ||*operation == '/') {
        break;
      }
      else {
        cout << "That's not a valid operation! Please choose from +, -, *, or /\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> *operation;
      }
    }
    /*We are assigning the contents of this memory location by referring to its address.
    There is no name associated with this allocated memory space. We are using an anonymous variable*/
    cout << "Enter the first number (Decimals are allowed): " << endl;
    cin >> *firstnum;
    while(!cin){
        cout << "That's not a number! Please enter a number\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> *firstnum;
    }
    cout << "Enter the second number (Decimals are allowed): " << endl;
    cin >> *secondnum;
    while(!cin){
        cout << "That's not a number! Please enter a number\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> *secondnum;
    }
    if(*operation == '-') {
        *answer = *firstnum - *secondnum;
    }
    else if(*operation == '*') {
        *answer = *firstnum * *secondnum;
    }
    else if(*operation == '/') {
        *answer = *firstnum / *secondnum;
    }
    else if(*operation == '+'){
        *answer = *firstnum + *secondnum;
    }
    else {
      cout << "IDK how you managed to break this... but you did ya dingus! >:(";
    }
    cout << *firstnum << *operation << *secondnum << " = " << *answer << endl << endl;
    cout << "Let's do it again! ";
  }
  delete operation;
  delete firstnum;
  delete secondnum;
  delete answer;
  return 0;
}
