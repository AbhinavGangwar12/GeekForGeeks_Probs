//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    private:
        int sum(int a[],int n){
            int res = 0;
            for(int i=0;i<n;i++){
                res+=a[i];
            }
            return res;
        }
public:
	vector<int> findSubarray(int a[], int n) {
	    vector<int> ans;
	    int max=0,sum=0;
	    vector<int> temp;
	    for(int i=0;i<n;i++){
	        if(a[i]>=0){
	            temp.push_back(a[i]);
	            sum+= a[i];
	        }
	        if(a[i]<0){
	            if(sum>max){
	                max = sum;
	                ans.clear();
	                ans.assign(temp.begin(),temp.end());
	            }
	            else if(sum == max){
	                if(temp.size() > ans.size()){
	                    ans.clear();
	                    ans.assign(temp.begin(),temp.end());
	                }
	            }
	            temp.clear();
	            sum = 0;
	        }
	    }
	    if(sum>max){
	        if(temp.size() > ans.size()){
	            ans.assign(temp.begin(),temp.end());
	        }
	    }
	    else if(sum == max){
	        if(temp.size() > ans.size()){
	            ans.assign(temp.begin(),temp.end());
	        }
	    }
	    if(ans.size()>0)return ans;
	    else {
	        ans.push_back(-1);
	        return  ans;
	    }
	    
	}




// 	vector<int> findSubarray(int a[], int n) {
	    // code here
	   // vector<int> ans;
	   // vector<int> temp;
	   // long max = INT_MIN;
	   // long temp_sum = 0;
	   // int flag = 0;
	   // for(int i =0;i<n;i++){
	   //     int num = a[i];
	   //     if(num >= 0){
	   //         temp_sum += num;
	   //         temp.push_back(num);
	   //     }
	   //     else{
	   //         if(temp_sum > max || ( (temp_sum == max) && (temp.size() > ans.size()) )){
	   //             max = temp_sum;
	   //             flag = 1;
	   //             ans.clear();
	   //             ans.assign(temp.begin(),temp.end());
	   //             temp_sum = 0;
	   //             temp.clear();
	   //         }
	   //     }
	   // }
	   // if(flag == 0)max = sum(a,n);
	   // if(max == INT_MIN)return {-1};
	   // return ans;
// 	}
};

//{ Driver Code Starts.

void printAns(vector<int> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends