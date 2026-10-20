#pragma once
#include <string>
using namespace std;

// ===================== String =====================

char UpperLetter(char Letter)
{
    if (Letter >= 97 && Letter <= 122)
        return char(Letter - 32);
    else
        return Letter;
}

char LowerLetter(char Letter)
{
    if (Letter >= 65 && Letter <= 90)
        return char(Letter + 32);
    else
        return Letter;
}

string UpperFirstLetterOfEachWord(string Line)
{
    bool IsFirstLetter = true;

    for (int i = 0; i < (int)Line.length(); i++)
    {
        if (Line[i] != ' ' && IsFirstLetter)
            Line[i] = UpperLetter(Line[i]);

        IsFirstLetter = (Line[i] == ' ');
    }

    return Line;
}

string LowerFirstLetterOfEachWord(string Line)
{
    bool IsFirstLetter = true;

    for (int i = 0; i < (int)Line.length(); i++)
    {
        if (Line[i] != ' ' && IsFirstLetter)
            Line[i] = LowerLetter(Line[i]);

        IsFirstLetter = (Line[i] == ' ');
    }

    return Line;
}

string UpperAllLine(string Line)
{
    for (int i = 0; i < (int)Line.length(); i++)
        Line[i] = UpperLetter(Line[i]);

    return Line;
}

string LowerAllLine(string Line)
{
    for (int i = 0; i < (int)Line.length(); i++)
        Line[i] = LowerLetter(Line[i]);

    return Line;
}

string EncryptText(string Text, short EncryptionKey)
{
    for (int i = 0; i < (int)Text.length(); i++)
        Text[i] = char(Text[i] + EncryptionKey);

    return Text;
}

string DecryptText(string Text, short EncryptionKey)
{
    return EncryptText(Text, (short)(-EncryptionKey));
}
