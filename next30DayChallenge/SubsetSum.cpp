#include <bits/stdc++.h>
using namespace std;

int tab[2000][2000];

int subsetSum(int a[], int n, int sum){
    if(sum ==0)
       return 1;
    if(n<=0)
       return 0;

    if(tab[n-1][sum] != -1)
        return tab[n-1][sum];

    if(a[n-1]>sum)
        return tab[n-1][sum] = subsetSum(a,n-1,sum);
    else{
        return tab[n-1][sum] = subsetSum(a,n - 1, sum) ||
                       subsetSum(a, n - 1, sum - a[n - 1]);
    }              
}

int main(){
    memset(tab, -1, sizeof(tab));
    int n=5;
    int a[] = {1,5,3,7,4};
    int sum =12;

    if(subsetSum(a,n,sum)){
        cout<<'YES' <<endl;
    }else
        cout<<"NO" <<endl;
}