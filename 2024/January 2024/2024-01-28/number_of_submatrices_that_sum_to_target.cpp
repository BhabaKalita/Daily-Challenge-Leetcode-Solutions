#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    // Function to calculate the number of subarrays with sum equal to k
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        map<int, int> mp;

        // Traverse the array and keep track of the cumulative sum
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            // If the current sum is equal to k, increment count
            if (sum == k) {
                count++;
            }

            // If there exists a previous sum such that (sum - k), increment count by its frequency
            if (mp.find(sum - k) != mp.end()) {
                count += mp[sum - k];
            }

            // Update the frequency of the current sum
            mp[sum]++;
        }

        return count;
    }

    // Function to calculate the number of submatrices with sum equal to target
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;

        // Iterate over all possible pairs of rows (i, j)
        for (int i = 0; i < matrix.size(); i++) {
            // Initialize an array to store the cumulative sum of each column
            vector<int> sum(matrix[0].size(), 0);

            // Iterate over all possible ending rows (j) for the current starting row (i)
            for (int j = i; j < matrix.size(); j++) {
                // Update the cumulative sum of each column for the current submatrix
                for (int k = 0; k < matrix[0].size(); k++) {
                    sum[k] += matrix[j][k];
                }

                // Use the subarraySum function to count subarrays with sum equal to target
                count += subarraySum(sum, target);
            }
        }

        return count;
    }
};

/*
Time Complexity: O(M^2 * N)
Space Complexity: O(N)
*/