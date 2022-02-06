#include<bits/stdc++.h>

using namespace std;

int maxLen(int A[], int n)
{
    // Your code here
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi; 
}
int main(){
    int N = 8, array[] = {6, -2, 2, -8, 1, 7, 4, -10};
    int lon = maxLen(array,N);
    cout<<"Length of the longest subarray with zero Sum is "<<lon;
}