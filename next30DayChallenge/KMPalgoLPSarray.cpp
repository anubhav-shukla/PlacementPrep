#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:

       bool findPattern(string p, string s)
{
    int m = p.size();
    int n = s.size();
  
    for (int i = 0; i <= n - m; i++)
    {
        int j;

        for (j = 0; j < m; j++)
        {
            if (p[j] == s[i + j])
            {
                continue;
            }
            else
            {
                break;
            }

        }

        if (j == m)
        {
            return true;
        }

    }
    
    return false;
}
};

int main(){
    Solution obj;
   string  s = "ababa", p = "ab";
   
    cout<<"'P' is present in 'S' as a substring "<<obj.findPattern(p,s) << endl;
    // if 1 than true 
    //  0 than false
    
}