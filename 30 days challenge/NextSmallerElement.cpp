#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
       vector<int> nextSmallerElement(vector<int> & arr, int n) 
{
    vector<int> ans(n);

    for (int i = 0; i < n; i++) 
    {
        ans[i] = -1;

        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                ans[i] = arr[j];
                break;
            }
        }

    }
   return ans;
}
};

int main(){
 Solution obj;
    vector<int> v{5,7,1,2,6,0};
    int n= v.size()-1;
    vector<int> res = obj.nextSmallerElement(v,n);
        cout<<" The next smallest elements are "<< endl;
    for(int i=0;i<res.size();i++){
        cout<< res[i] << " ";

    }   
}
