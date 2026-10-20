#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

// ===================== Screen (Windows console) =====================

enum class enScreenColor { Green = 1, Red = 2, Yellow = 3 };

void ResetScreen()
{
    system("cls");
    system("color 07");
}

void SetScreenColor(enScreenColor Color)
{
    switch (Color)
    {
    case enScreenColor::Green:
        system("color 2F");
        break;

    case enScreenColor::Red:
        system("color 4F");
        cout << "\a";
        break;

    case enScreenColor::Yellow:
        system("color 6F");
        break;
    }
}
