class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        // Create an unordered map to count occurrences of elements in target
        unordered_map<int, int> mp;

        // Increment the count of each element in the target array
        for(int &x : target) {
            mp[x]++;
        }

        // Decrement the count of each element in the arr array
        for(int &y : arr) {
            // If an element in arr does not exist in the map, return false
            if(mp.find(y) == mp.end())
                return false;

            // Decrement the count of the element
            mp[y]--;
            // If the count of the element becomes zero, remove it from the map
            if(mp[y] == 0)
                mp.erase(y);
        }

        // If all elements in target are matched and counts are zero, return true
        return true;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)