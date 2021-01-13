#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define UNASSIGNED 0
#define N 9

bool FindUnassignedLocation(int mat[N][N], int &row, int &col);
bool isSafe(int mat[N][N], int row, int col, int num);


bool SolveSudoku(int mat[N][N])
{
    int row, col;
    if (!FindUnassignedLocation(mat, row, col))
       return true;
    for (int num = 1; num <= 9; num++)
    {
        if (isSafe(mat, row, col, num))
        {
            mat[row][col] = num;
            if (SolveSudoku(mat))
                return true;
            mat[row][col] = UNASSIGNED;
        }
    }
    return false;
}


bool FindUnassignedLocation(int mat[N][N], int &row, int &col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (mat[row][col] == UNASSIGNED)
                return true;
    return false;
}


bool UsedInRow(int mat[N][N], int row, int num)
{
    for (int col = 0; col < N; col++)
        if (mat[row][col] == num)
            return true;
    return false;
}


bool UsedInCol(int mat[N][N], int col, int num)
{
    for (int row = 0; row < N; row++)
        if (mat[row][col] == num)
            return true;
    return false;
}


bool UsedInBox(int mat[N][N], int boxStartRow, int boxStartCol, int num)
{
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (mat[row+boxStartRow][col+boxStartCol] == num)
                return true;
    return false;
}


bool isSafe(int mat[N][N], int row, int col, int num)
{
    return !UsedInRow(mat, row, num) && !UsedInCol(mat, col, num) &&
           !UsedInBox(mat, row - row % 3 , col - col % 3, num);
}


void printMat(int mat[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout<<mat[row][col]<<"  ";
        cout<<endl;
    }
}


int main()
{
    int mat[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    if (SolveSudoku(mat) == true)
          printMat(mat);
    else
        cout<<"No solution exists"<<endl;
    return 0;
}
