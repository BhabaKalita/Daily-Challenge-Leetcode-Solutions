class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> ans(n,0); 

        // Initialize variables to track boxes and moves to the left
        int boxToLeft = 0, moveToLeft = 0; 
        // Initialize variables to track boxes and moves to the right
        int boxToRight = 0, moveToRight = 0; 

        // Iterate from left to right
        for(int i=0; i<n; i++) {
            // Add moves to the left calculated so far to the answer
            ans[i] += moveToLeft; 
            // Update the number of boxes to the left
            boxToLeft += boxes[i] - '0'; 
            // Update the total moves to the left 
            moveToLeft += boxToLeft; 

            // Calculate the corresponding index from the right
            int j = n-1-i; 

            // Add moves to the right calculated so far to the answer
            ans[j] += moveToRight; 
            // Update the number of boxes to the right
            boxToRight += boxes[j] - '0'; 
            // Update the total moves to the right
            moveToRight += boxToRight;
        }

        return ans;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)
