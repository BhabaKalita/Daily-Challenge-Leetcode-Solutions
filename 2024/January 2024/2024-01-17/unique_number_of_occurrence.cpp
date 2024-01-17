#include <vector>
#include <unordered_map>
#include <unordered_set>

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // Create a map to store the count of occurrences for each element in arr
        unordered_map<int, int> countMap;

        // Create a set to store unique counts of occurrences
        unordered_set<int> uniqueCounts;

        // Iterate through the elements in arr and update the countMap
        for (int x : arr)
            ++countMap[x];

        // Iterate through the key-value pairs in countMap
        for (auto y : countMap)
            // Insert the count (y.second) into the uniqueCounts set
            uniqueCounts.insert(y.second);

        // Check if the number of unique counts is equal to the total number of elements in arr
        return countMap.size() == uniqueCounts.size();
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/