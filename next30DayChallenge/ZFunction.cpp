#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        int zAlgorithm(string s, string p, int n, int m)
   {

	int count = 0;
	for (int i = 0; i <= n - m; i++)
	{
		int j;

		for (j = 0; j < m; j++)
		{
			if (p[j] != s[i + j])
			{
				break;
			}

		}

		if (j == m)
		{
			count++;
		}

	}

	return count;
}};
int main(){
    Solution obj;
   string  s = "ababa", p = "ab";
   int n=5,m=2;
    cout<<" Number of occurence "<<obj.zAlgorithm(s,p,n,m) << endl;
    
}