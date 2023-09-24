#include<iostream>
using namespace std;
#include<vector>

bool isSafe(int row,int col,vector<vector<int>>& board,int val){
	
	
	int size=board[0].size();
	
	for(int i=0;i<size;i++){
		
		
		//row check
		if(board[row][i]==val){
			return false;
			
		}
		
		//col check
		if(board[i][col]==val){
			return false;
			
		}
		
		//3*3 matrix check
		
		if(board[3*(row/3)+i/3] [3*(col/3)+i%3]==val){
			return false;
		}
		
	}
	
	return true;
	
	
}

bool solve(vector<vector<int>>& board){
	
	
	int n=board[0].size();
	
	//treversing the matrix
	for(int row=0;row<n;row++){
		
		for(int col=0;col<n;col++){
			
			//if cell is empty
			if(board[row][col]==0){
				
				for(int val=1;val<=9;val++){
					
					if(isSafe(row,col,board,val)==1){
						board[row][col]=val;
						
						bool nextemptysolution=solve(board);
						
						if(nextemptysolution==1){
							return true;
						}
						else{
							board[row][col]=0;
						}
						
					}
					
					
				}
				return false;
				
				
			}
			
			
		}
		
	}
	return true;
	
	
}
void solveSudoku(vector<vector<int>>& sudoku){
	solve(sudoku);
}

void print(vector<vector<int>>& board)
{
	int n=board[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}
int main(){
	
vector<vector<int>> board={ { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
							{ 5, 2, 9, 1, 3, 4, 7, 6, 8 },
							{ 4, 8, 7, 6, 2, 9, 5, 3, 1 },
							{ 2, 6, 3, 0, 1, 5, 9, 8, 7 },                            
							{ 9, 7, 4, 8, 6, 0, 1, 2, 5 },
							{ 8, 5, 1, 7, 9, 2, 6, 4, 3 },
							{ 1, 3, 8, 0, 4, 7, 2, 0, 6 },
							{ 6, 9, 2, 3, 5, 1, 8, 7, 4 },
							{ 7, 4, 5, 0, 8, 6, 3, 1, 0 } };

        
	solveSudoku(board);
	print(board);
							

                       


	
}