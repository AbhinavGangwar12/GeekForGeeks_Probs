//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        int mini = 0;
        int buy = 0;
        int free = N-1;
        sort(candies,candies+N);
        while(buy<=free){
            mini += candies[buy++];
            free -= K;
        }
        int maxi = 0;
        buy = N-1;
        free = 0;
        while(buy>=free){
            maxi += candies[buy--];
            free += K;
        }
        vector<int> money;
        money.push_back(mini);
        money.push_back(maxi);
        return money;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends