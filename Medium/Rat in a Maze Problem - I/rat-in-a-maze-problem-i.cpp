//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    bool is_safe(vector<vector<int>> temp,int n,int x,int y,vector<vector<int>> &m){
        if((x>=0 && x < n) && (y>=0 && y < n) && (temp[x][y] == 0) && (m[x][y] == 1))return true;
        else return false;
    }
    void solution(vector<vector<int>>& m,int n,int x,int y,vector<vector<int>> temp,string s,vector<string>& ans){
        if((x == n-1) && (y == n-1)){
            ans.push_back(s);
            return;
        }
        
        temp[x][y] = 1;
        
        // left
        int newx = x;
        int newy = y-1;
        if(is_safe(temp,n,newx,newy,m)){
            s.push_back('L');
            solution(m,n,newx,newy,temp,s,ans);
            s.pop_back();
        }
        // right
        newx = x;
        newy = y+1;
        if(is_safe(temp,n,newx,newy,m)){
            s.push_back('R');
            solution(m,n,newx,newy,temp,s,ans);
            s.pop_back();
        }
        // down
        newx = x+1;
        newy = y;
        if(is_safe(temp,n,newx,newy,m)){
            s.push_back('D');
            solution(m,n,newx,newy,temp,s,ans);
            s.pop_back();
        }
        // up
        newx = x-1;
        newy = y;
        if(is_safe(temp,n,newx,newy,m)){
            s.push_back('U');
            solution(m,n,newx,newy,temp,s,ans);
            s.pop_back();
        }
        
        
        temp[x][y] = 0;
        
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0] == 0)return ans;
        int x = 0;
        int y = 0;
        string out = "";
        vector<vector<int>> temp = m;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                temp[i][j] = 0;
            }
        }
        solution(m,n,x,y,temp,out,ans);
        return ans;
        // Your code goes here
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends