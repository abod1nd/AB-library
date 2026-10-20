#include "Drift.h"

int main()
{
    srand((unsigned)time(NULL));

    // Input + Arrays
    int Arr[100];
    int Length = ReadNumber("How many numbers? (1 to 100)", 1, 100);

    FillArrayWithRandomNumbers(Arr, Length, 1, 100);
    cout << "\nArray  : ";
    PrintArray(Arr, Length);
    cout << "Max    : " << MaxNumberInArray(Arr, Length) << "\n";
    cout << "Min    : " << MinNumberInArray(Arr, Length) << "\n";
    cout << "Odd    : " << CountNumbersInArray(Arr, Length, enNumberType::Odd) << " number(s)\n";

    int Primes[100], PrimesLength;
    CopyArray(Arr, Length, Primes, PrimesLength, enNumberType::Prime);
    cout << "Primes : ";
    PrintArray(Primes, PrimesLength);

    // String
    string Line = ReadString("\nEnter a line:");
    cout << "Upper first letters : " << UpperFirstLetterOfEachWord(Line) << "\n";
    cout << "Encrypted           : " << EncryptText(Line, 2) << "\n";
    cout << "Decrypted           : " << DecryptText(EncryptText(Line, 2), 2) << "\n";

    // Matrices
    int Matrix[10][10];
    FillMatrixWithOrderedNumbers(Matrix, 3, 3);
    cout << "\nMatrix:\n";
    PrintMatrix(Matrix, 3, 3);
    cout << "Sum of matrix : " << SumOfMatrix(Matrix, 3, 3) << "\n";

    // Math
    cout << "\nIs 7 prime?   " << IsPrimeNumber(7) << "\n";
    cout << "MyRound(2.5) = " << MyRound(2.5f) << "\n";

    return 0;
}
