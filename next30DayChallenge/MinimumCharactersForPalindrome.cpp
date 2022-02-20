#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool isPalindrome(string str)
{
    int l = str.length();
    int i = 0;
    int j = l - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minCharsforPalindrome(string str)
{
    int count = 0;

    while (str.length() > 0)
    {
        if (isPalindrome(str))
        {
            break;
        }
        else
        {
            count++;
            str.erase(str.begin() + str.length() - 1);
        }
    }
    return count;
}
};
int main(){
    Solution obj;
   string  s = "ababa", p = "ab";
   
    cout<<"Minimum Characters For Palindrome "<<obj.isPalindrome(s) << endl;
     // if 1 than true 
    //  0 than false
    
 }