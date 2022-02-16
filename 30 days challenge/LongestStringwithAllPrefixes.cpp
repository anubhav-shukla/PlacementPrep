#include<map>

string completeString(int n, vector<string> &a) {

    string ans = "";

    map<string,int> mp;

    for (int i = 0; i < n; i++) {
      mp[a[i]] = 1;
    }

    for (int i = 0; i < n; i++) {
      string pre = "";
      bool flag = true;
      for (int j = 0; j < a[i].size(); j++) {
        pre += a[i][j];
        if (mp.count(pre));
        else {
          flag = false;
          break;
        }
      }
      if (flag) {
        if (ans.size() < a[i].size()) {
          ans = a[i];
        }
        else if (ans.size() == a[i].size() && a[i] < ans) {
          ans = a[i];
        }
      }
    }
    if (ans.size() == 0) {
      ans = "None";
    }
    // Return the final result.
    return ans;
}
