//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    void reverse(string & s,int i,int j){
        if(i>j)return;
        swap(s[i],s[j]);
        reverse(s,i+1,j-1);
    }
    string reverseWord(string str)
    {
        // Your code goes here
        reverse(str,0,str.length()-1);
        return str;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends