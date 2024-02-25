#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    // Data structures to store mappings between prime factors and indices
    unordered_map<int, vector<int>> prime2index; // Maps prime factors to indices
    unordered_map<int, vector<int>> index2prime; // Maps indices to prime factors

    // Depth-first search function to traverse the graph
    void dfs(int ind, vector<int> &visitedIndex, unordered_map<int, bool> &visitedPrime) {
        // If the index is already visited, return
        if (visitedIndex[ind])
            return;

        // Mark the index as visited
        visitedIndex[ind] = true;

        // Iterate over prime factors of the current index
        for (auto &prime : index2prime[ind]) {
            // If the prime factor is already visited, continue to the next one
            if (visitedPrime[prime])
                continue;

            // Mark the prime factor as visited
            visitedPrime[prime] = true;

            // Traverse all indices associated with this prime factor
            for (auto &index1 : prime2index[prime]) {
                // If the index is already visited, continue to the next one
                if (visitedIndex[index1])
                    continue;

                // Recursively visit the index via DFS
                dfs(index1, visitedIndex, visitedPrime);
            }
        }
    }

    // Function to determine if all pairs can be traversed
    bool canTraverseAllPairs(vector<int>& nums) {
        // Populate prime2index and index2prime mappings
        for (int i = 0; i < nums.size(); i++) {
            int temp = nums[i];
            for (int j = 2; j * j <= nums[i]; j++) {
                if (temp % j == 0) {
                    prime2index[j].push_back(i);
                    index2prime[i].push_back(j);
                    while (temp % j == 0)
                        temp /= j;
                }
            }
            if (temp > 1) {
                prime2index[temp].push_back(i);
                index2prime[i].push_back(temp);
            }
        }

        // Initialize visited arrays and maps for DFS
        vector<int> visitedIndex(nums.size(), 0);
        unordered_map<int, bool> visitedPrime;

        // Run DFS starting from index 0
        dfs(0, visitedIndex, visitedPrime);

        // Check if all indices are visited
        for (int i = 0; i < visitedIndex.size(); i++) {
            if (visitedIndex[i] == false)
                return false;
        }
        return true;
    }
};

/*
Time Complexity: O(N * sqrt(N))
Space Complexity: O(N*M)
*/