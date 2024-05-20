#include<iostream>
#include<string.h>
using namespace std;

void getTerm3Var(int a, int b, string* terms)
{
    string expressions[2][4] = {"A'B'C'", "A'B'C", "A'BC", "A'BC'", "AB'C'", "AB'C", "ABC", "ABC'"};
    for(int i = 0; i < 8; i++)
    {
        if(*(terms + i) == "")
        {
            *(terms + i) = expressions[a][b];
            break;
        }
    }
}

void outputBit3Var(int size, int* minterms, int flag, int count, int i, int j, string terms)
{
    for(int k = 0; k < size; k++)
    {
        if(*(minterms + k) == *count)
        {
            if(i == 0 && j == 0 && *(minterms + k) != *count)
            {
                break;
            }
            cout << 1;
            flag = 1;
            getTerm3Var(i, j, terms);
        }
    }
    if(flag == 0)
    {
        cout << 0;
    }
    *count += 1;
}

void getTerm4Var(int a, int b, string* terms)
{
    string expressions[4][4] = {"A'B'C'D'", "A'B'C'D", "A'B'CD", "A'B'CD'", "A'BC'D'", "A'BC'D", "A'BCD", "A'BCD'",
                                "ABC'D'", "ABC'D", "ABCD", "ABCD'", "AB'C'D'", "AB'C'D", "AB'CD", "AB'CD'"};
    for(int i = 0; i < 16; i++)
    {
        if(*(terms + i) == "")
        {
            *(terms + i) = expressions[a][b];
            break;
        }
    }
}

void outputBit4Var(int size, int* minterms, int flag, int* count, int i, int j, string* terms)
{
    for(int k = 0; k < size; k++)
    {
        if(*(minterms + k) == *count)
        {
            cout << 1;
            flag = 1;
            getTerm4Var(i, j, terms);
        }
    }
    if(flag == 0)
    {
        cout << 0;
    }
    *count += 1;
}

void getTerm5Var(int a, int b, string* terms)
{
    string expressions[4][8] = {"A'B'C'D'E'", "A'B'C'D'E", "A'B'C'DE", "A'B'C'DE'", "A'B'CD'E'", "A'B'CD'E",
                                "A'B'CDE", "A'B'CDE'", "A'BC'D'E'", "A'BC'D'E", "A'BC'DE", "A'BC'DE'", "A'BCD'E'", "A'BCD'E", "A'BCDE", "A'BCDE'",
                                "ABC'D'E", "ABC'D'E", "ABC'DE", "ABC'DE'", "ABCD'E'", "ABCD'E", "ABCDE", "ABCDE'", "AB'C'D'E'",
                                "AB'C'D'E", "AB'C'DE", "AB'C'DE'", "AB'CD'E'", "AB'CD'E", "AB'CDE", "AB'CDE'"};
    for(int i = 0; i < 8; i++)
    {
        if(*(terms + i) == "")
        {
            *(terms + i) = expressions[a][b];
            break;
        }
    }
}

void outputBit5Var(int size, int* minterms, int flag, int* count, int i, int j, string* terms)
{
    for(int k = 0; k < size; k++)
    {
        if(*(minterms + k) == *count)
        {
            cout << 1;
            flag = 1;
            getTerm5Var(i, j, terms);
        }
    }
    if(flag == 0)
    {
        cout << 0;
    }
    *count += 1;
}

void displayExpression(string* terms, int termCount)
{
    for(int i = 0; i < termCount; i++)
    {
        if(*(terms + i) != "" && i == 0){
            cout << *(terms + i);
        }
        else if(*(terms + i) != "" && i != 0){
            cout << " + " << *(terms + i);
        }
    }
}

void processCell(int* count, int size, int flag, int choice, int i, string* terms, int* minterms)
{
    int loop;
    if(choice == 3)
    {
        loop = 8;
    }
    else
    {
        loop = 4;
    }
    for(int j = 0; j < loop; j++)
    {
        if(j == 2 || j == 6)
        {
            *count += 1;
            if(choice == 1)
            {
                outputBit3Var(size, minterms, flag, count, i, j, terms);
            }
            else if(choice == 2)
            {
                outputBit4Var(size, minterms, flag, count, i, j, terms);
            }
            else if(choice == 3)
            {
                outputBit5Var(size, minterms, flag, count, i, j, terms);
            }
            *count -= 1;
        }
        else if(j == 3 || j == 7)
        {
            *count -= 1;
            if(choice == 1)
            {
                outputBit3Var(size, minterms, flag, count, i, j, terms);
            }
            else if(choice == 2)
            {
                outputBit4Var(size, minterms, flag, count, i, j, terms);
            }
            else if(choice == 3)
            {
                outputBit5Var(size, minterms, flag, count, i, j, terms);
            }
            *count += 1;
        }
        else
        {
            if(choice == 1)
            {
                outputBit3Var(size, minterms, flag, count, i, j, terms);
            }
            else if(choice == 2)
            {
                outputBit4Var(size, minterms, flag, count, i, j, terms);
            }
            else if(choice == 3)
            {
                outputBit5Var(size, minterms, flag, count, i, j, terms);
            }
        }
        cout << "   ";
        if(choice == 3)
        {
            cout << " ";
        }
    }
}

int main()
{
    int choice;
    cout << "Enter 1 for 3 variables K-map, 2 for 4 variables K-map, 3 for 5 variables K-map: ";
    cin >> choice;
    int size;
    cout << "Enter the number of minterms you want to enter: ";
    cin >> size;
    int minterms[size];
    int *mintermPtr;
    mintermPtr = minterms;
    for(int i = 0; i < size; i++)
    {
        cout << "Enter the value of " << i + 1 << " minterm: ";
        cin >> minterms[i];
    }
    int termCount = 32;
    string terms[termCount];
    for(int i = 0; i < termCount; i++)
    {
        terms[i] = "";
    }
    string* termsPtr;
    termsPtr = terms;

    int count = 0, flag;
    if(choice == 1)
    {
        cout << "\n";
        cout << " BC  00  01  11  10\nA\n\n";
        count = 0;
        for(int i = 0; i < 2; i++)
        {
            cout << i << "     ";
            flag = 0;
            processCell(&count, size, flag, choice, i, termsPtr, mintermPtr);
            cout << endl;
        }
    }
    else if(choice == 2)
    {
        cout << "\n";
        cout << "  CD  00  01  11  10\nAB\n\n";
        count = 0;
        for(int i = 0; i < 4; i++)
        {
            flag = 0;
            if(i == 0)
            {
                cout << "00     ";
            }
            else if(i == 1)
            {
                cout << "01     ";
            }
            else if(i == 2)
            {
                cout << "11     ";
            }
            else if(i == 3)
            {
                cout << "10     ";
            }

            if(i == 3)
            {
                count -= 4;
                processCell(&count, size, flag, choice, i, termsPtr, mintermPtr);
                count += 4;
            }
            else if(i == 2)
            {
                count += 4;
                processCell(&count, size, flag, choice, i, termsPtr, mintermPtr);
                count -= 4;
            }
            else
            {
                processCell(&count, size, flag, choice, i, termsPtr, mintermPtr);
            }
            cout << endl;
        }
    }
    else if(choice == 3)
    {
        cout << "\n";
        cout << "  CDE  000  001  011  010  100  101  111  110\nAB\n\n";
        count = 0;
        for(int i = 0; i < 4; i++)
        {
            flag = 0;
            if(i == 0)
            {
                cout << "00      ";
            }
            else if(i == 1)
            {
                cout << "01      ";
            }
            else if(i == 2)
            {
                cout << "11      ";
            }
            else if(i == 3)
            {
                cout << "10      ";
            }

            if(i == 3)
            {
                count -= 4;
                processCell(&count, size, flag, choice, i, termsPtr, mintermPtr);
                count += 4;
            }
            else if(i == 2)
            {
                count += 4;
                processCell(&count, size, flag, choice, i, termsPtr, mintermPtr);
                count -= 4;
            }
            else
            {
                processCell(&count, size, flag, choice, i, termsPtr, mintermPtr);
            }
            cout << endl;
        }
    }
    cout << "\nExpression\n";
    displayExpression(termsPtr, termCount);
    cout << "\n\n";
    return 0;
}
