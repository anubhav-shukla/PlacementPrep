#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
struct Transaction
{
    string name;        // Transaction name
    string record;        // Data object from the database
    int timestamp;      // Timestamp of the current transaction
    char operation;     // Operation type: Read/Write
};
 
void findConflicts(vector<Transaction> t)        // no-ref, no-const
{
    sort(t.begin(), t.end(),
        [](const Transaction &x, const Transaction &y)
        {
            if (x.record != y.record) {
                return x.record < y.record;
            }
 
            return x.timestamp < y.timestamp;
        });
    for (int i = 0; i < t.size(); i++)
    {
        int j = i - 1;
        while (j >= 0 && t[i].record == t[j].record
                && t[i].timestamp <= t[j].timestamp + 5)
        {
            if (t[i].operation == 'W' || t[j].operation == 'W')
            {
                cout << "Transaction " << t[j].name << " & " << t[i].name
                    << " are involved in " << t[j].operation
                    << t[i].operation << " conflict" << endl;
            }
 
            j--;
        }
    }
}
 
int main()
{
    vector<Transaction> t =
    {
        { "T1", "A", 0, 'R' },
        { "T2", "A", 2, 'W' },
        { "T3", "B", 4, 'W' },
        { "T4", "C", 5, 'W' },
        { "T5", "B", 7, 'R' },
        { "T6", "C", 8, 'W' },
        { "T7", "A", 9, 'R' }
    };
 
    findConflicts(t);
 
    return 0;
}
