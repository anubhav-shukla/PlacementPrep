
vector<int> maxMinWindow(vector<int> arr, int n) 
{
    vector<int> answer(n);
    
	for (int i = 0; i < n; ++i) 
	{
        answer[i] = INT_MIN;
    }
    for (int i = 0; i < n; ++i) 
	{
        for (int j = i; j < n; ++j) 
		{
            int start = i;

            int end = j;

            int temp = INT_MAX;
            for (int k = start; k <= end; ++k) 
			{
                temp = min(temp, arr[k]);
            }
            
			int length = end - start;

            answer[length] = max(answer[length], temp);
        }
    }

    return answer;
}

