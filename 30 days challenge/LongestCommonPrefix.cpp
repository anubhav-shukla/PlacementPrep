
string longestCommonPrefix(vector<string> &arr, int n)
{
    string longestPrefix = "";

    for(int idx = 0; idx < arr[0].size(); ++idx)
    {
        char ch = arr[0][idx];
        
        bool matched = true;

        for(int index = 1; index < n; ++index) 
        {   
            if (arr[index].size() < idx or arr[index][idx] != ch)
            {
                matched = false;
                break;
            }
        }

        if (matched)
        {
            longestPrefix += ch;
        }
        else
        {
            break;
        }
    }

    return longestPrefix;
}