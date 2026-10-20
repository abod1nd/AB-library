#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include "RandomLib.h"
using namespace std;

// ===================== Matrices (2D) =====================
// Declare matrices in main as int Matrix[10][10] and work with any size up to 10x10.

// ---------- Fill & print ----------

void FillMatrixWithRandomNumbers(int Matrix[10][10], short Rows, short Cols, int From, int To)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = RandomNumber(From, To);
        }
    }
}

void FillMatrixWithOrderedNumbers(int Matrix[10][10], short Rows, short Cols)
{
    int Counter = 1;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Matrix[i][j] = Counter;
            Counter++;
        }
    }
}

void PrintMatrix(int Matrix[10][10], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            cout << setw(4) << Matrix[i][j] << " ";
        }
        cout << "\n";
    }
}

// ---------- Sums ----------

int SumOfMatrix(int Matrix[10][10], short Rows, short Cols)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Sum += Matrix[i][j];
        }
    }

    return Sum;
}

int SumOfMatrixRow(int Matrix[10][10], short Cols, short RowNumber)
{
    int Sum = 0;

    for (short j = 0; j < Cols; j++)
        Sum += Matrix[RowNumber][j];

    return Sum;
}

int SumOfMatrixCol(int Matrix[10][10], short Rows, short ColNumber)
{
    int Sum = 0;

    for (short i = 0; i < Rows; i++)
        Sum += Matrix[i][ColNumber];

    return Sum;
}

void SumOfMatrixRowsInArray(int Matrix[10][10], short Rows, short Cols, int Result[10])
{
    for (short i = 0; i < Rows; i++)
        Result[i] = SumOfMatrixRow(Matrix, Cols, i);
}

void SumOfMatrixColsInArray(int Matrix[10][10], short Rows, short Cols, int Result[10])
{
    for (short j = 0; j < Cols; j++)
        Result[j] = SumOfMatrixCol(Matrix, Rows, j);
}

// ---------- Operations ----------

// Result becomes Cols x Rows.
void TransposeMatrix(int Matrix[10][10], int Result[10][10], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Result[j][i] = Matrix[i][j];
        }
    }
}

void MultiplyTwoMatrices(int Matrix1[10][10], int Matrix2[10][10], int Result[10][10], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            Result[i][j] = Matrix1[i][j] * Matrix2[i][j];
        }
    }
}

void GetMiddleRowOfMatrix(int Matrix[10][10], short Rows, short Cols, int MiddleRow[10])
{
    int Middle = Rows / 2;

    for (short j = 0; j < Cols; j++)
        MiddleRow[j] = Matrix[Middle][j];
}

void GetMiddleColOfMatrix(int Matrix[10][10], short Rows, short Cols, int MiddleCol[10])
{
    int Middle = Cols / 2;

    for (short i = 0; i < Rows; i++)
        MiddleCol[i] = Matrix[i][Middle];
}

// ---------- Search & count ----------

int CountNumberInMatrix(int Matrix[10][10], short Rows, short Cols, int Number)
{
    int Count = 0;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
                Count++;
        }
    }

    return Count;
}

bool IsNumberInMatrix(int Matrix[10][10], short Rows, short Cols, int Number)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] == Number)
                return true;
        }
    }

    return false;
}

vector<int> GetIntersectedNumbersInMatrices(int Matrix1[10][10], int Matrix2[10][10], short Rows, short Cols)
{
    vector<int> vIntersectedNumbers;

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            int CurrentNumber = Matrix2[i][j];

            if (IsNumberInMatrix(Matrix1, Rows, Cols, CurrentNumber))
                vIntersectedNumbers.push_back(CurrentNumber);
        }
    }

    return vIntersectedNumbers;
}

int MaxNumberInMatrix(int Matrix[10][10], short Rows, short Cols)
{
    int Max = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] > Max)
                Max = Matrix[i][j];
        }
    }

    return Max;
}

int MinNumberInMatrix(int Matrix[10][10], short Rows, short Cols)
{
    int Min = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix[i][j] < Min)
                Min = Matrix[i][j];
        }
    }

    return Min;
}

// ---------- Checks ----------

bool AreMatricesEqual(int Matrix1[10][10], int Matrix2[10][10], short Rows, short Cols)
{
    return SumOfMatrix(Matrix1, Rows, Cols) == SumOfMatrix(Matrix2, Rows, Cols);
}

bool AreMatricesTypical(int Matrix1[10][10], int Matrix2[10][10], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (Matrix1[i][j] != Matrix2[i][j])
                return false;
        }
    }

    return true;
}

bool IsScalarMatrix(int Matrix[10][10], short Rows, short Cols)
{
    int FirstDiagonalElement = Matrix[0][0];

    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols; j++)
        {
            if (i == j && Matrix[i][j] != FirstDiagonalElement)
                return false;
            else if (i != j && Matrix[i][j] != 0)
                return false;
        }
    }

    return true;
}

bool IsIdentityMatrix(int Matrix[10][10], short Rows, short Cols)
{
    return Matrix[0][0] == 1 && IsScalarMatrix(Matrix, Rows, Cols);
}

bool IsSparseMatrix(int Matrix[10][10], short Rows, short Cols)
{
    int MatrixSize = Rows * Cols;
    return CountNumberInMatrix(Matrix, Rows, Cols, 0) >= (MatrixSize / 2);
}

bool IsPalindromeMatrix(int Matrix[10][10], short Rows, short Cols)
{
    for (short i = 0; i < Rows; i++)
    {
        for (short j = 0; j < Cols / 2; j++)
        {
            if (Matrix[i][j] != Matrix[i][Cols - 1 - j])
                return false;
        }
    }

    return true;
}
