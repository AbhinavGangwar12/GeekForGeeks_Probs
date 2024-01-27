//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{   
    void rotate(int arr[],int low,int high){
        if(low>= high)return;
        swap(arr[low],arr[high]);
        rotate(arr,low+1,high-1);
    }
public:
    void leftRotate(int arr[], int n, int d) {
        // code here
        d = d % n;
        if(d<n){
            rotate(arr,0,n-1);
            rotate(arr,0,n-1-d);
            rotate(arr,n-d,n-1);
        }
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cin >> d;
        Solution ob;
        ob.leftRotate(arr, n, d);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}



// } Driver Code Ends