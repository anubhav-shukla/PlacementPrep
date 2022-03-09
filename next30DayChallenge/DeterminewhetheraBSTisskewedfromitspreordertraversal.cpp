#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isSkewedBST(vector<int> &pre){
    int n=pre.size();
    if(n<=2){
        return 1;
    }
    int min_f=min(pre[n-1],pre[n-2]);
    int max_f=max(pre[n-1],pre[n-2]);

    for(int i=n-2;i>=0;i--){
        if(pre[i]<min_f){
            min_f=pre[i];
        }else if(pre[i]>max_f){
            max_f=pre[i];
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> pre = {15,30,25,10,20};
    
    bool isSkewed = isSkewedBST(pre);
    if(isSkewed){
        cout<<"BST is Skewed";
    }
    else{
        cout<<"BST is not skewed";
    }
    return 0;
}