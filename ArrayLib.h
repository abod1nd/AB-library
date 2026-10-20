#pragma once
#include <string>
#include <vector>
#include "InputLib.h"
#include "RandomLib.h"
#include "MathLib.h"
using namespace std;

// ===================== Arrays (1D) =====================

// ---------- Fill ----------

void AddArrayElement(int Arr[100], int& Length, int Number)
{
    Length++;
    Arr[Length - 1] = Number;
}

void FillArrayWithRandomNumbers(int Arr[100], int Length, int From, int To)
{
    for (int i = 0; i < Length; i++)
        Arr[i] = RandomNumber(From, To);
}

void FillArrayWithOrderedNumbers(int Arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
        Arr[i] = i + 1;
}

void FillArrayWithKeys(string Arr[100], int Length, short NumOfSlots)
{
    for (int i = 0; i < Length; i++)
        Arr[i] = GenerateKey(NumOfSlots);
}

void FillArrayFromUser(int Arr[100], int& Length)
{
    Length = 0;

    do
    {
        AddArrayElement(Arr, Length, ReadNumber("Please enter a number:"));
    } while (AskYesNoQ("Do you want to add more numbers? Y/N? "));
}

void FillVectorFromUser(vector<int>& vNumbers)
{
    vNumbers.clear();

    do
    {
        vNumbers.push_back(ReadNumber("Please enter a number:"));
    } while (AskYesNoQ("Do you want to add more numbers? Y/N? "));
}

// ---------- Search & count ----------

int FindNumberPositionInArray(int Arr[100], int Length, int Number)
{
    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] == Number)
            return i;
    }

    return -1;
}

bool IsNumberInArray(int Arr[100], int Length, int Number)
{
    return FindNumberPositionInArray(Arr, Length, Number) != -1;
}

int CountNumberInArray(int Arr[100], int Length, int Number)
{
    int Count = 0;

    for (int i = 0; i < Length; i++)
    {
        if (Arr[i] == Number)
            Count++;
    }

    return Count;
}

// CountNumbersInArray(Arr, Length, enNumberType::Odd)  -> how many odd numbers
int CountNumbersInArray(int Arr[100], int Length, enNumberType Type = enNumberType::All)
{
    int Count = 0;

    for (int i = 0; i < Length; i++)
    {
        if (IsNumberOfType(Arr[i], Type))
            Count++;
    }

    return Count;
}

int MaxNumberInArray(int Arr[100], int Length)
{
    int Max = Arr[0];

    for (int i = 1; i < Length; i++)
    {
        if (Arr[i] > Max)
            Max = Arr[i];
    }

    return Max;
}

int MinNumberInArray(int Arr[100], int Length)
{
    int Min = Arr[0];

    for (int i = 1; i < Length; i++)
    {
        if (Arr[i] < Min)
            Min = Arr[i];
    }

    return Min;
}

// ---------- Copy ----------
// Every Copy function resets DestLength to 0 first.

// CopyArray(Source, SourceLength, Dest, DestLength)                       -> copies everything
// CopyArray(Source, SourceLength, Dest, DestLength, enNumberType::Prime)  -> copies primes only
void CopyArray(int Source[100], int SourceLength, int Dest[100], int& DestLength, enNumberType Type = enNumberType::All)
{
    DestLength = 0;

    for (int i = 0; i < SourceLength; i++)
    {
        if (IsNumberOfType(Source[i], Type))
            AddArrayElement(Dest, DestLength, Source[i]);
    }
}

void CopyArrayInReverse(int Source[100], int SourceLength, int Dest[100], int& DestLength)
{
    DestLength = 0;

    for (int i = SourceLength - 1; i >= 0; i--)
        AddArrayElement(Dest, DestLength, Source[i]);
}

void CopyArrayDistinctNumbers(int Source[100], int SourceLength, int Dest[100], int& DestLength)
{
    DestLength = 0;

    for (int i = 0; i < SourceLength; i++)
    {
        if (!IsNumberInArray(Dest, DestLength, Source[i]))
            AddArrayElement(Dest, DestLength, Source[i]);
    }
}

// ---------- Checks & others ----------

bool IsPalindromeArray(int Arr[100], int Length)
{
    for (int i = 0; i < Length / 2; i++)
    {
        if (Arr[i] != Arr[Length - 1 - i])
            return false;
    }

    return true;
}

bool AreArraysTypical(int Arr1[100], int Arr2[100], int Length)
{
    for (int i = 0; i < Length; i++)
    {
        if (Arr1[i] != Arr2[i])
            return false;
    }

    return true;
}

void SumOfTwoArrays(int Arr1[100], int Arr2[100], int Result[100], int Length)
{
    for (int i = 0; i < Length; i++)
        Result[i] = Arr1[i] + Arr2[i];
}

void Swap(int& A, int& B)
{
    int Temp = A;
    A = B;
    B = Temp;
}

void ShuffleArray(int Arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
        Swap(Arr[i], Arr[RandomNumber(0, Length - 1)]);
}
