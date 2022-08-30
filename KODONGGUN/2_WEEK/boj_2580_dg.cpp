#include <iostream>
#include <vector>
#include <cstring> // memset

using namespace std;

int sudoku[9][9];

void printSudoku()
{
    cout << endl;
    for (int r=0;r<9;r++)
    {
        for (int c=0;c<9;c++)
        {
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}

int checkSudoku(int r, int c, int val)
{
    int sdk[10] = { 0, };
    // 1 row
    for (int cc=0; cc<9; cc++)
    {
        if (sudoku[r][cc] == val) return false;
    }
    // 2 column
    for (int rr=0; rr<9; rr++)
    {
        if (sudoku[rr][c] == val) return false;
    }
    // 3 3*3 square
    for (int rr=0; rr<3; rr++)
    {
        for (int cc=0; cc<3; cc++)
        {
            if (sudoku[(r/3)*3 + rr][(c/3)*3 + cc] == val) return false;
        }
    }

    // skip all return true
    return true;
}

void backtrack(int index)
{
    if (index == 81)
    {
        printSudoku();
        exit(0);                        // program exit
    }
    if (sudoku[index/9][index%9] != 0)  // if number is fixed, go next 
    {
        backtrack(index+1);
        return;
    }
    
    for (int i=1; i<=9;i++)             // if number is zero, find number
    {
        if (!checkSudoku(index/9, index%9, i)) continue; // check conditions
        sudoku[index/9][index%9] = i;
        backtrack(index+1);
        sudoku[index/9][index%9] = 0;
    }
    
}

int main()
{
    for (int i=0;i<81;i++) cin >> sudoku[i/9][i%9];
    backtrack(0);
    return 0;
}