//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&a, int n)
    {   
        map<int,int> prefix;
        int largest=0;
        int sum =0;
        for(int i=0;i<n;i++){
            sum+= a[i];
            if(a[i] == 0 and largest == 0)largest = 1;
            if(sum == 0)largest= i+1;
            if(prefix.find(sum) != prefix.end()){
                int len = i-prefix[sum];
                largest = max(largest, len);
            }
            else{
                prefix[sum] = i;
            }
        }
        return largest;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends