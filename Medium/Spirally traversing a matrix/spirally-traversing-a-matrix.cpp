//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int left_column = 0;
        int right_column = c -1;
        int up_row = 0;
        int down_row = r-1;
        vector<int> ans;
        int count = 0,limit = r*c;

        while(count<limit){
            for(int i = left_column ;count<limit && i <= right_column ; i++){
                ans.push_back(matrix[up_row][i]);
                count++;
            }
            up_row++;

            for(int i = up_row ;count<limit && i <= down_row ; i++){
                ans.push_back(matrix[i][right_column]);
                count++;
            }
            right_column--;
            
            for(int i = right_column ;count<limit && i >= left_column ; i--){
                ans.push_back(matrix[down_row][i]);
                count++;
            }
            down_row--;

            for(int i = down_row ;count<limit && i >= up_row ; i--){
                ans.push_back(matrix[i][left_column]);
                count++;
            }
            left_column++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends