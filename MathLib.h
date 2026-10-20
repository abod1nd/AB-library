#pragma once
#include <cmath>
using namespace std;

// ===================== Numbers & Math =====================

bool IsPrimeNumber(int Number)
{
    if (Number < 2)
        return false;

    int M = Number / 2;

    for (int i = 2; i <= M; i++)
    {
        if (Number % i == 0)
            return false;
    }

    return true;
}

// Used by CopyArray and CountNumbersInArray to pick which numbers to take.
enum class enNumberType { All = 1, Odd = 2, Even = 3, Prime = 4, Positive = 5, Negative = 6 };

bool IsNumberOfType(int Number, enNumberType Type)
{
    switch (Type)
    {
    case enNumberType::Odd:
        return Number % 2 != 0;

    case enNumberType::Even:
        return Number % 2 == 0;

    case enNumberType::Prime:
        return IsPrimeNumber(Number);

    case enNumberType::Positive:
        return Number >= 0; // zero is counted as positive

    case enNumberType::Negative:
        return Number < 0;

    default:
        return true; // All
    }
}

bool IsPerfectNumber(int Number)
{
    if (Number <= 0)
        return false;

    int Sum = 0;

    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum += i;
    }

    return Sum == Number;
}

int ReverseNumber(int Number)
{
    int Remainder = 0;
    int Reversed = 0;

    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Reversed = Reversed * 10 + Remainder;
    }

    return Reversed;
}

bool IsPalindromeNumber(int Number)
{
    return ReverseNumber(Number) == Number;
}

int CountDigitInNumber(int Number, short Digit)
{
    int Count = 0;

    while (Number > 0)
    {
        if (Number % 10 == Digit)
            Count++;

        Number = Number / 10;
    }

    return Count;
}

// ---------- My versions of C++ math functions ----------

float GetAfterTheComma(float Number)
{
    return Number - int(Number);
}

int MyRound(float Number)
{
    float Fraction = GetAfterTheComma(Number);

    if (Number >= 0)
    {
        if (Fraction >= 0.5)
            return int(Number) + 1;
        else
            return int(Number);
    }
    else
    {
        if (Fraction <= -0.5)
            return int(Number) - 1;
        else
            return int(Number);
    }
}

int MyFloor(float Number)
{
    if (Number >= 0 || GetAfterTheComma(Number) == 0)
        return int(Number);
    else
        return int(Number) - 1;
}

int MyCeil(float Number)
{
    if (Number <= 0 || GetAfterTheComma(Number) == 0)
        return int(Number);
    else
        return int(Number) + 1;
}

float MyAbs(float Number)
{
    if (Number < 0)
        return Number * -1;
    else
        return Number;
}

float MySqrt(float Number)
{
    return (float)pow(Number, 0.5);
}
