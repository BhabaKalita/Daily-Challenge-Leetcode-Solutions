class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        // Initialize the smallest and biggest values using the first array
        int smallest = arrays[0][0]; // smallest element from the first array
        int biggest = arrays[0].back(); // largest element from the first array
        int max_d = 0; // to store the maximum distance

        // Iterate over arrays starting from the second array
        for(int i = 1; i < arrays.size(); i++) {
            // Update the maximum distance considering the current array's last element and the smallest element seen so far
            max_d = max(max_d, abs(arrays[i].back() - smallest));

            // Update the maximum distance considering the biggest element seen so far and the current array's first element
            max_d = max(max_d, abs(biggest - arrays[i][0]));

            // Update the smallest element found so far
            smallest = min(smallest, arrays[i][0]);

            // Update the biggest element found so far
            biggest = max(biggest, arrays[i].back());
        }

        // Return the maximum distance found
        return max_d;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)