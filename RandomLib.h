#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

// ===================== Random =====================
// Call srand((unsigned)time(NULL)); once at the start of main.

enum class enCharType { SmallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4 };

int RandomNumber(int From, int To)
{
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}

char RandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SmallLetter:
        return char(RandomNumber(97, 122));

    case enCharType::CapitalLetter:
        return char(RandomNumber(65, 90));

    case enCharType::SpecialCharacter:
        return char(RandomNumber(33, 47));

    case enCharType::Digit:
        return char(RandomNumber(48, 57));

    default:
        return char(RandomNumber(97, 122));
    }
}

string GenerateRandomWord(short WordLength, enCharType WordType)
{
    string Word = "";

    for (int i = 1; i <= WordLength; i++)
    {
        Word += RandomCharacter(WordType);
    }

    return Word;
}

string GenerateKey(short NumOfSlots)
{
    string Key = "";

    for (int i = 1; i <= NumOfSlots; i++)
    {
        Key += GenerateRandomWord(4, enCharType::CapitalLetter);

        if (i < NumOfSlots)
            Key += "-";
    }

    return Key;
}
