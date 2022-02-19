
vector<int> stringMatch(string &str, string &pat) 
{

    vector<int> result;

    for (int i = 0; i <= str.length() - pat.length(); i++) 
    {
    
        bool flag = 1;

        for (int j = 0; j < pat.size(); j++) 
        {
            if (str[i + j] != pat[j]) 
            {
                flag = 0;
            }
        }

        if (flag == 1) 
        {
            result.push_back(i);
        }
    }

    return result;
}