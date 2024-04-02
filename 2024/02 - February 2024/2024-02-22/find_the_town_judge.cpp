#include <vector>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // Creating a vector to count the number of trusts for each person
        vector<int> count(n+1, 0);

        // Iterating through the trust vector
        for (auto x : trust) {
            // Decreasing trust count for the trusting person
            count[x[0]]--;
            // Increasing trust count for the trusted person
            count[x[1]]++;
        }

        // Checking for the judge
        for (int i = 1; i <= n; i++) {
            // If a person has been trusted by all except themselves, they are the judge
            if (count[i] == n - 1) return i;
        }

        // If no judge is found
        return -1;
    }
};

/*
Time Complexity: O(E+N)
Space Complexity: O(N)
*/