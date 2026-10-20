#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// ===================== Files =====================

void LoadDataFromFileToVector(string FileName, vector<string>& vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            vFileContent.push_back(Line);
        }

        MyFile.close();
    }
}

void SaveVectorToFile(string FileName, vector<string>& vFileContent)
{
    fstream MyFile;
    MyFile.open(FileName, ios::out);

    if (MyFile.is_open())
    {
        for (string& Line : vFileContent)
        {
            if (Line != "")
                MyFile << Line << endl;
        }

        MyFile.close();
    }
}

// Replaces the lines that match Record exactly.
void UpdateRecordInFile(string FileName, string Record, string UpdatedRecord)
{
    vector<string> vFileContent;
    LoadDataFromFileToVector(FileName, vFileContent);

    for (string& Line : vFileContent)
    {
        if (Line == Record)
            Line = UpdatedRecord;
    }

    SaveVectorToFile(FileName, vFileContent);
}

// Deletes the lines that match Record exactly
// (an empty line is skipped by SaveVectorToFile).
void DeleteRecordFromFile(string FileName, string Record)
{
    UpdateRecordInFile(FileName, Record, "");
}

void PrintFileContent(string FileName)
{
    fstream MyFile;
    MyFile.open(FileName, ios::in);

    if (MyFile.is_open())
    {
        string Line;

        while (getline(MyFile, Line))
        {
            cout << Line << endl;
        }

        MyFile.close();
    }
}
