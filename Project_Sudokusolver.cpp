#include <iostream>
using namespace std;
// EE20BTECH11024 - Kunwar Harshvardhan Singh

void printsudoku(int arr[9][9])
{ 
    cout << endl;
   for (int r = 0; r < 9; r++){
      for (int c = 0; c < 9; c++){
         if(c == 3 || c == 6)
            cout << "| ";
         cout << arr[r][c] <<" ";
      }
      if(r == 2 || r == 5){
         cout << endl;
         for(int i = 0; i<7; i++)
            cout << "---";
      }
      cout << endl;
   }
   cout << endl;
}

bool valid(int arr[9][9], int n, int row, int col)
{
	if (!(arr[row][col] == 0)) return false;
	bool status = true;
	int gridx = (col / 3) * 3;
	int gridy = (row / 3) * 3;
	for (int i = 0; i < 9; i++) {
        if (arr[i][col] == n) 
        { status = false; break; }
		else if (arr[row][i] == n) 
        { status = false; break; }
		else if (arr[gridy + i / 3][gridx + i % 3] == n) 
        { status = false; break; }
	}
	return status;
}

bool findemptyslot(int arr[9][9], int &row, int &col){
   for (row = 0; row < 9; row++)
      for (col = 0; col < 9; col++)
         if (arr[row][col] == 0)
            return true;
   return false;
}

bool solvesudoku(int arr[9][9]){
   int row, col;
   if (!findemptyslot(arr, row, col))
      return true;
   for (int n = 1; n <= 9; n++){
      if (valid(arr, n, row, col)){
         arr[row][col] = n;
         if (solvesudoku(arr))
            return true;
         arr[row][col] = 0;
      }
   }
   return false;
}


int main()
{
	int sudoku[9][9] = {
		{0,0,0,0,0,0,0,0,5},
		{0,0,7,0,0,3,0,0,0},
		{2,0,0,9,0,0,4,1,0},
		{1,0,0,4,0,0,2,6,0},
		{0,0,0,0,0,0,8,0,0},
		{0,4,0,0,9,0,0,0,0},
		{0,0,0,6,0,0,0,0,8},
		{5,0,0,0,0,0,0,0,9},
		{0,0,2,0,7,0,6,5,0}
	};
	
	if (solvesudoku(sudoku)) cout << "successfully solved board!" << std::endl;
	printsudoku(sudoku);

	return 0;
}