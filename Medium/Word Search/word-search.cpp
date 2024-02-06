//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        bool helper(vector<vector<char>>& board, string &word,int x,int y,int rows,int cols,int k){
            if(k >= word.size() || (word.size() == 1 && word[k] == board[x][y]))return true;
            if( (x < 0 || x >= rows) || (y<0 || y>=cols) || (board[x][y] == '.') || (word[k] != board[x][y]))return false;
            board[x][y] = '.';
            bool temp = false;
            int x_[4] = {0,0,-1,1};
            int y_[4] = {-1,1,0,0};
            for(int i =0 ;i<4;i++){
                temp = temp || helper(board,word,x+x_[i],y+y_[i],rows,cols,k+1);
            }
            board[x][y] = word[k];
            return temp;
            
        }
public:
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int rows = board.size();
        if(rows == 0)return false;
        int cols = board[0].size();
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(helper(board,word,i,j,rows,cols,0))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends