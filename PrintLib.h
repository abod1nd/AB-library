#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// ===================== Print =====================

void PrintArray(int Arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << Arr[i] << " ";

    cout << "\n";
}

void PrintStringArray(string Arr[100], int Length)
{
    for (int i = 0; i < Length; i++)
        cout << "Array[" << i << "] : " << Arr[i] << "\n";
}

void PrintVector(const vector<int>& vNumbers)
{
    for (const int& Number : vNumbers)
        cout << Number << " ";

    cout << "\n";
}
