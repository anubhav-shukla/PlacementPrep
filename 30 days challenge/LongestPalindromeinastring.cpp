
bool isPalindrome(string sub) 
{
    int n = sub.length();

    int i = 0, j = n - 1;

    while (i < j) 
    {
        if (sub[i] != sub[j]) 
        {
            return false;
        }
        
        i++;
        j--;
    }

    return true;
}

string longestPalinSubstring(string str)
{
    int n = str.length();

    if (n == 0)
    {
        return "";
    }

    if (n == 1)
    {
        return str;
    }

    int len = 0, start = 0, end = 0;
    bool palFound = false;

    // Create all the substrings.
    for(len = n; len > 0; len--)
    {
        for(int i = 0; i + len - 1 < n; i++)
        {
            string sub = str.substr(i, len);

            if(isPalindrome(sub))
            {
                start = i;
                end = i + len - 1;
                palFound = true;
                break;
            }
        }

        if(palFound)
        {
            break;
        }
    }

    return str.substr(start, len);   
}