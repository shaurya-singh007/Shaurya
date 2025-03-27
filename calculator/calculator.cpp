#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    // define variables
    string operation;
    double number1, number2;

    // get user input
    cout << "Enter the first number: ";
    cin >> number1;
    cout << "Enter operation( + , - , / , * ): ";
    cin >> operation;
    cout << "Enter the second number: ";
    cin >> number2;

    // if else statement checking the operation

    if (operation == "+")
    {
        cout << number1 + number2;
    }
    else if (operation == "-")
    {
        cout << number1 - number2;
    }
        else if (operation == "/")
        {
            cout << number1 / number2;
        }
            else if (operation == "*")
            {
                cout << number1 * number2;
            }
            else{"not a valid operation";}

            return 0;
 }

