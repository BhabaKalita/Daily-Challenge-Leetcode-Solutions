class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        // Initialize boatCount to keep track of the number of boats needed
        int boatCount = 0;

        // Initialize two pointers, one starting from the beginning and the other from the end
        int left = 0;
        int right = people.size() - 1;

        // Loop until the two pointers meet or pass each other
        while(left <= right){
            // Calculate the sum of weights of people at the current positions of the pointers
            int sum = people[left] + people[right];

            // If the sum is less than or equal to the limit, both people can fit on one boat
            if(sum <= limit){
                boatCount++; // Increment boatCount
                left++;     // Move the left pointer to the right
                right--;    // Move the right pointer to the left
            }
            else{
                // If the sum exceeds the limit, only one person can fit on the boat
                boatCount++; // Increment boatCount
                right--;    // Move the right pointer to the left
            }
        }

        // Return the total number of boats needed
        return boatCount;

    }
};
/*
Time Complexity: O(nlogn)
Space Complexity: O(1)
*/