#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        // Create a frequency map to count occurrences of each number
        unordered_map<int, int> frequencyMap;
        for (int n : nums) {
            frequencyMap[n]++;
        }

        // Sort the nums vector using a custom comparator
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            // If the frequencies are different, sort by frequency in ascending order
            if (frequencyMap[a] != frequencyMap[b]) {
                return frequencyMap[a] < frequencyMap[b];
            }
            // If the frequencies are the same, sort by value in descending order
            return a > b;
        });

        // Return the sorted nums vector
        return nums;
    }
};
/*
Time Complexity: O(nlogn)
Space Complexity: O(n)
*/