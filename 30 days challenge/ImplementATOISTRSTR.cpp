
int atoiRecursive(string str, int n, int curIdx, int & ans) {
    if (curIdx == n) {
        return ans;
    }

    if (str[curIdx] >= '0'
        and str[curIdx] <= '9') {
        ans = ans * 10 + str[curIdx] - '0';
        return atoiRecursive(str, n, curIdx + 1, ans);
    } 
    else {
        return atoiRecursive(str, n, curIdx + 1, ans);
    }
}

int atoi(string s) {
    bool isNegative = 0;
    int n = s.size();
    if (s[0] == '-') {
        isNegative = 1;
    }

    int ans1 = 0;

    int ans = atoiRecursive(s, n, 0, ans1);

    if (isNegative) {
        return -1 * ans;
    } 
    else {
        return ans;
    }
}