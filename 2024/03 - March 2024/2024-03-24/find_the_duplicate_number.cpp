class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() > 1) { // Check if the array size is greater than 1
            int slow = nums[0]; // Initialize slow pointer
            int fast = nums[nums[0]]; // Initialize fast pointer

            // Move slow pointer one step at a time and fast pointer two steps at a time
            // They will meet at some point if there's a cycle
            while (slow != fast) {
                slow = nums[slow]; // Move slow pointer one step
                fast = nums[nums[fast]]; // Move fast pointer two steps
            }

            fast = 0; // Reset fast pointer to the beginning

            // Move both pointers one step at a time until they meet
            // The point where they meet is the start of the cycle which is the duplicate number
            while (fast != slow) {
                fast = nums[fast]; // Move fast pointer one step
                slow = nums[slow]; // Move slow pointer one step
            }
            return slow; // Return the duplicate number
        }
        return -1; // If the array size is not greater than 1, return -1 indicating no duplicate
    }
};

/*
Time Complexity: O(n) where n is the number of elements in the input array.
Space Complexity: O(1) as no extra space is used.
*/