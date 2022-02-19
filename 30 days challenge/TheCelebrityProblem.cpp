
int findCelebrity(int n) {
    vector<int> indegree(n), outdegree(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(knows(i, j)) {
                indegree[j]++;
                outdegree[i]++;
            }
        }
    }

    int celebrity = -1;

    for(int i = 0; i < n; i++) {
        if(indegree[i] == n - 1 && outdegree[i] == 0) {
            celebrity = i;
            break;
        }
    }

    return celebrity;
}