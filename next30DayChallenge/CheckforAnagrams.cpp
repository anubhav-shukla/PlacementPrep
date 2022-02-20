
#define NO_OF_CHARS 256
#include<bits/stdc++.h>

using namespace std;

class Solution{
    public:
        bool areAnagram(string &str1, string &str2){
    int hash[NO_OF_CHARS] = { 0 };
    int i;

    int n1 = str1.length();
    int n2 = str2.length();
    if (n1 != n2){
       return false;
    }

    for (i = 0; i < n1; i++){
        hash[str1[i]]++;
        hash[str2[i]]--;
    }

    for (i = 0; i < NO_OF_CHARS; i++){
        if (hash[i]){
            return false;
        }
    }
    return true;
}
};
int main(){
    Solution obj;
   string  s = "ababa", p = "ab";
   
    cout<<"Are Anagram "<<obj.areAnagram(p,s) << endl;
     // if 1 than true 
    //  0 than false
    
 }