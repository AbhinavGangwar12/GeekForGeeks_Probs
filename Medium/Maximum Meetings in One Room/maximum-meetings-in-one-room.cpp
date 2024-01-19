//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    static bool compare(pair< pair <int,int>,int > a,pair<pair <int,int>,int> b){
        return a.first.second < b.first.second;
    }
    
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector < pair < pair <int,int>, int >> a;
        
        for(int i=0;i<N;i++){
            pair< pair <int,int>,int> p = make_pair(make_pair(S[i],F[i]),i+1);
            a.push_back(p);
        }
        
        sort(a.begin(),a.end(),compare);
        
        
        vector <int> final;
        int end = a[0].first.second;
        final.push_back(a[0].second);
        
        for(int i=1;i<N;i++){
            if(a[i].first.first > end){
                final.push_back(a[i].second);
                end = a[i].first.second;
            }
        }
        
        sort(final.begin(),final.end());
        
        return final;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends