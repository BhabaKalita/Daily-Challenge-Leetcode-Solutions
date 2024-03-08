#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        // Map to store the frequency of each element in nums
        unordered_map<int, int> freqCounter;

        // Count the frequency of each element in nums
        for (int x : nums) {
            freqCounter[x]++;
        }

        // Find the maximum frequency among all elements
        int maxEle = 0;
        for (auto y : freqCounter) {
            maxEle = max(maxEle, y.second);
        }

        // Count how many elements have the maximum frequency
        int maxFreq = 0;
        for (auto z : freqCounter) {
            if (maxEle == z.second)
                maxFreq++;
        }

        // Calculate the result, which is the product of maximum frequency and the number of elements with that frequency
        int res = maxEle * maxFreq;
        return res;
    }
};
/*
Time Complexity: O(n+m)
Space Complexity: O(m)
*/