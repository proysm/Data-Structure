//--------------------------------------------------------------------
//  컴퓨터공학과 2021111954 유수민
//  Laboratory 5                                           test5.cpp
//
//  Test program for the operations in the Stack ADT
//
//--------------------------------------------------------------------

#include <iostream>

#include "stacklnk.cpp"

//--------------------------------------------------------------------


int main()
{
    Stack<double> testStack;     // Test stack
    char testDataItem;        // Stack data item                     
    double  changeDataItem;      // change Data type to int before input testDataItem on Test stack.
    double operand1, operand2, result;
    do
    {
        cout << endl << "Input postix Expression: ";
        cin >> testDataItem;
        // 0~9
        if (testDataItem >= 48 && testDataItem <= 57)
        {
            switch (testDataItem)
            {
            case 48: changeDataItem = 0;  break;
            case 49: changeDataItem = 1;  break;
            case 50: changeDataItem = 2;  break;
            case 51: changeDataItem = 3;  break;
            case 52: changeDataItem = 4;  break;
            case 53: changeDataItem = 5;  break;
            case 54: changeDataItem = 6;  break;
            case 55: changeDataItem = 7;  break;
            case 56: changeDataItem = 8;  break;
            case 57: changeDataItem = 9;  break;
            }
            testStack.push(changeDataItem);
        }
        // +, -, *, /
        else
        {
            switch (testDataItem)
            {
            case '+':
                if (testStack.isEmpty())  cout << "Stack is Empty." << endl;
                else
                {
                    operand1 = testStack.pop();
                    operand2 = testStack.pop();
                    result = operand2 + operand1;
                    cout << "result: " << operand2 << " + " << operand1 << " = " << result << endl;
                    testStack.push(result);
                }
                break;

            case '-':
                if (testStack.isEmpty())  cout << "Stack is Empty." << endl;
                else
                {
                    operand1 = testStack.pop();
                    operand2 = testStack.pop();
                    result = operand2 - operand1;
                    cout << "result: " << operand2 << " - " << operand1 << " = " << result << endl;
                    testStack.push(result);
                }
                break;

            case '*':
                if (testStack.isEmpty())  cout << "Stack is Empty." << endl;
                else
                {
                    operand1 = testStack.pop();
                    operand2 = testStack.pop();
                    result = operand2 * operand1;
                    cout << "result: " << operand2 << " * " << operand1 << " = " << result << endl;
                    testStack.push(result);
                }
                break;

            case '/':
                if (testStack.isEmpty())  cout << "Stack is Empty." << endl;
                else
                {
                    operand1 = testStack.pop();
                    operand2 = testStack.pop();
                    result = operand2 / operand1;
                    cout << "result: " << operand2 << " / " << operand1 << " = " << result << endl;
                    testStack.push(result);
                }
                break;

            case 'Q': case 'q':                   // Quit test program
                break;

            default:                               // Invalid command
                cout << "Inactive or invalid command" << endl;
            }
        }

    } while (testDataItem != 'Q' && testDataItem != 'q');

}