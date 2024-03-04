//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    private:
        bool isValid(int grid[N][N], int x,int y, int val){
            int newx = (x/3)*3;
            int newy = (y/3)*3;
            
            for(int i =0;i<N;i++){
                if(grid[x][i] == val)return false;
                if(grid[i][y] == val)return false;
            }
            for(int i =0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(grid[newx+i][newy+j] == val)return false;
                }
            }
            return true;
        }
    public:
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])
    { 
        for(int i = 0;i<N;i++){
            for(int j=0;j<N;j++){
                if(grid[i][j] == 0){
                    for(int x=1;x<=9;x++){
                        if(isValid(grid,i,j,x)){
                            grid[i][j] = x;
                            if(SolveSudoku(grid))return true;
                            else grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        bool is_solved = SolveSudoku(grid);
        if(is_solved){
            // cout<<"True"<<endl;
            for(int i=0;i<N;i++){
                for(int j = 0;j<N;j++){
                    cout<<grid[i][j]<<" ";
                }
                // cout<<endl;
            }
        }
        // else cout<<"False"<<endl;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends