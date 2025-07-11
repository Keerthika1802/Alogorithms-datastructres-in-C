#include <stdio.h>

#define MAX 10

int board[MAX][MAX];
int totalSol = 0;
int N;
int isSafe(int row, int col);
void NQueens(int row)
{
if(row > N)
{
totalSol++;
printf("the solution is :%d\n", totalSol);
for (int i = 1; i <= N; i++)
{
for (int j = 1; j <= N; j++)
{
printf("%d ", board[i][j]);
}
printf("\n");
}
printf("\n");
return;
}

for(int col = 1; col <= N; col++)
{
if(isSafe(row, col))
{
board[row][col] = 1;
NQueens(row + 1);
board[row][col] = 0;
}
}
}

int isSafe(int row, int col)
{
for(int i = 1; i < row; i++)
{
if(board[i][col] == 1)
return 0;
}

for(int i = row - 1, j = col - 1; i >= 1 && j >= 1; i--, j--)
{
if(board[i][j] == 1)
return 0;
}

for(int i = row - 1, j = col + 1; i >= 1 && j <= N; i--, j++)
{
if(board[i][j] == 1)
return 0;
}

return 1;
}

int main()
{
printf("Enter number of Queens: ");
scanf("%d", &N);

for (int i = 1; i <= N; i++)
{
for (int j = 1; j <= N; j++)
{
board[i][j] = 0;
}
}

totalSol = 0;
NQueens(1);
printf("Total solutions found: %d\n", totalSol);

if (totalSol == 0)
{
printf("No solutions exist for %d queens.\n", N);
}
}
