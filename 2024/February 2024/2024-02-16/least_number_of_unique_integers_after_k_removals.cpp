#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        // Create a frequency map to count occurrences of each number
        unordered_map<int, int> freq;

        // Populate the frequency map
        for(auto x:arr) {
            freq[x]++;
        }

        // Create a min heap (priority queue) to store frequencies
        priority_queue<int, vector<int>, greater<int>> pq;

        // Push all frequencies into the priority queue
        for(auto y:freq) {
            pq.push(y.second);
        }

        // Greedily remove the frequencies starting from the smallest
        while(k > 0) {
            k -= pq.top(); // Remove the smallest frequency
            if(k >= 0) {
                pq.pop(); // If we can still remove more elements, pop the top element
            }
        }

        // The size of the priority queue now represents the number of unique integers left
        return pq.size();
    }
};

/*
Time Complexity: O(m + n log n)
Space Complexity: O(m + n)
*/