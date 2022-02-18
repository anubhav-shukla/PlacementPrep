vector<int> findSpans(vector<int> &price) {
    int n = price.size();

    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        int j = i;
        while(j >= 0 && price[j] <= price[i]) {
            result[i] += 1;
            j -= 1;
        }
    }

    return result;
}

