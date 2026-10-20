#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <climits>
using namespace std;

// ===================== Input =====================

// ReadNumber("...")          -> any int
// ReadNumber("...", 1)       -> 1 or more (positive)
// ReadNumber("...", 1, 10)   -> from 1 to 10
int ReadNumber(string Message, int From = INT_MIN, int To = INT_MAX)
{
    int Number;

    do
    {
        cout << Message << endl;
        cin >> Number;

        while (cin.fail())
        {
            // user didn't input a number
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid Number, Enter a valid one:" << endl;
            cin >> Number;
        }

    } while (Number < From || Number > To);

    return Number;
}

float ReadFloatNumber(string Message)
{
    float Number;

    cout << Message << endl;
    cin >> Number;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid Number, Enter a valid one:" << endl;
        cin >> Number;
    }

    return Number;
}

string ReadString(string Message)
{
    string Line;

    cout << Message << endl;
    getline(cin >> ws, Line);

    return Line;
}

bool AskYesNoQ(string Message)
{
    char Answer = 'N';

    cout << Message;
    cin >> Answer;

    return (Answer == 'Y' || Answer == 'y');
}
