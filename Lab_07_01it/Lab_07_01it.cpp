#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Generate(int** b, const int rowcount, const int colcount, const int low, const int high)
{
   for (int i = 0; i < rowcount; i++)
       for (int j = 0; j < colcount; j++)
           b[i][j] = low + rand() % (high - low + 1);
}

void print(int** b, const int rowcount, const int colcount)
{
    for (int i = 0; i < rowcount; i++)
    {
        for (int j = 0; j < colcount; j++)
        {
            cout << b[i][j] << "\t";
        }
        cout << "\n";
    }
    cout << "\n";
}

void Change(int** b, const int firstrow, const int secondrow, const int colcount)
{
    int tmp;
    for (int j = 0; j < colcount; j++)
    {
        tmp = b[firstrow][j];
        b[firstrow][j] = b[secondrow][j];
        b[secondrow][j] = tmp;
    }
}

void Sort(int** b, const int rowcount, const int colcount)
{
    for (int i0 = 0; i0 < rowcount - 1; i0++)
        for (int i1 = 0; i1 < rowcount - i0 - 1; i1++)
            if ((b[i1][0] > b[i1 + 1][0])
                ||
                (b[i1][0] == b[i1 + 1][0] &&
                 b[i1][1] < b[i1 + 1][1])
                ||
                (b[i1][0] == b[i1 + 1][0] &&
                 b[i1][1] == b[i1 + 1][1] &&
                 b[i1][3] > b[i1 + 1][3]))
                Change(b, i1, i1 + 1, colcount);
}

void Calc(int** b, const int rowcount, const int colcount, int& S, int& k)
{
    S = 0;
    k = 0;
    for (int i = 0; i < rowcount; i++)
        for (int j = 0; j < colcount; j++)
            if (b[i][j] % 2 == 0 || !(b[i][j] % 8 == 0))
            {  
                S += b[i][j];
                b[i][j] = 0;
                k++;
            }
}

int main()
{
    srand((unsigned)time(NULL));
    const int low = 8;
    const int high = 73;
    const int rowcount = 7;
    const int colcount = 6;
    int S = 0;
    int k = 0;

    int **b = new int*[rowcount];
    for (int i = 0; i < rowcount; i++)
        b[i] = new int[colcount];

    Generate(b, rowcount, colcount, low, high);
    print(b, rowcount, colcount);
    Sort(b, rowcount, colcount);
    print(b, rowcount, colcount);

   
    Calc(b, rowcount, colcount, S, k);
    cout << "S = " << S << endl;
    cout << "k = " << k << endl;
    print(b, rowcount, colcount);

    for (int i = 0; i < rowcount; i++)
        delete[] b[i];
    delete[] b;
    system("pause");
    return 0;
}