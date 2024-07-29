class Solution {
public:
    int numTeams(vector<int>& rating) {
        int teams = 0; // Initialize the number of valid teams to 0
        int n = rating.size(); // Get the size of the rating vector

        // Iterate through each element in the rating vector, considering it as the middle element of the team
        for(int j = 1; j < n - 1; j++) {
            int countSmallerLeft = 0; // Count of elements smaller than rating[j] on the left
            int countLargerLeft = 0;  // Count of elements larger than rating[j] on the left
            int countLargerRight = 0; // Count of elements larger than rating[j] on the right
            int countSmallerRight = 0;// Count of elements smaller than rating[j] on the right

            // Iterate over the elements to the left of rating[j]
            for(int i = 0; i < j; i++) {
                if(rating[i] > rating[j]) {
                    countLargerLeft++; // Increment countLargerLeft if rating[i] is greater than rating[j]
                } else if(rating[i] < rating[j]) {
                    countSmallerLeft++; // Increment countSmallerLeft if rating[i] is smaller than rating[j]
                }
            }

            // Iterate over the elements to the right of rating[j]
            for(int k = j + 1; k < n; k++) {
                if(rating[j] < rating[k]) {
                    countLargerRight++; // Increment countLargerRight if rating[k] is greater than rating[j]
                } else if(rating[j] > rating[k]) {
                    countSmallerRight++; // Increment countSmallerRight if rating[k] is smaller than rating[j]
                }
            }

            // Calculate the number of valid teams with rating[j] as the middle element
            teams += (countSmallerLeft * countLargerRight) + (countSmallerRight * countLargerLeft);
        }
        return teams; // Return the total number of valid teams
    }
};
// Time Complexity: O(n^2)
// Space Complexity: O(1)