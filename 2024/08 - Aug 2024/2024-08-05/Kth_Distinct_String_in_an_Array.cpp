class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // Create an unordered_map to count the occurrences of each string in the array
        unordered_map<string, int> counter;

        // Iterate through the array and count each string's occurrences
        for(auto &x : arr) {
            counter[x]++;
        }

        // Iterate through the array again to find the kth distinct string
        for(auto &y : arr) {
            if(counter[y] == 1) {  // Check if the string occurs exactly once
                --k;  // Decrement k for each distinct string found
                if(k == 0)  // If k reaches zero, return the current string
                    return y;
            }                
        }

        // If no such kth distinct string exists, return an empty string
        return "";
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)