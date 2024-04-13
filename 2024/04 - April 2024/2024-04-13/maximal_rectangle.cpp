class Solution {
public:
    int largestRectangle(vector<int>& heights) {

        stack<int> s; // Stack to store indices of heights
        int n = heights.size(); // Size of the input vector
        vector<int> LB(n,0); // Left boundary for each height
        vector<int> RB(n,n); // Right boundary for each height

        // Loop to find the left boundary for each height
        for(int i=0; i<n; i++) {

            // Keep popping elements from the stack while the current height is less than or equal to the height at the top of the stack
            while(!s.empty() && heights[i] <= heights[s.top()]) {
                s.pop();
            }

            // If stack becomes empty, there is no height smaller than the current height to the left
            if(s.empty())
                LB[i] = 0; // Left boundary is 0
            else 
                LB[i] = s.top()+1; // Left boundary is the index at the top of the stack + 1

            s.push(i); // Push the current index onto the stack
        }

        while(!s.empty()) s.pop(); // Clear the stack

        // Loop to find the right boundary for each height
        for(int i=n-1; i>=0; i--) {

            // Keep popping elements from the stack while the current height is less than or equal to the height at the top of the stack
            while(!s.empty() && heights[i] <= heights[s.top()]) {
                s.pop();
            }

            // If stack becomes empty, there is no height smaller than the current height to the right
            if(s.empty())
                RB[i] = n-1; // Right boundary is n-1
            else
                RB[i] = s.top()-1; // Right boundary is the index at the top of the stack - 1

            s.push(i); // Push the current index onto the stack
        }

        // Calculate the area of the largest rectangle
        int area = 0;
        for(int i=0; i<n; i++) {
            int width = RB[i]-LB[i]+1; // Width of the rectangle
            int height = heights[i]; // Height of the rectangle
            area = max(area, width*height); // Update the maximum area
        }
        return area; // Return the maximum area
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size(); // Number of rows in the matrix
        int col = matrix[0].size(); // Number of columns in the matrix
        int maxi = INT_MIN; // Variable to store the maximum area
        vector<int> heights(col,0); // Vector to store the heights of the rectangles

        // Loop through the matrix to calculate heights
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {

                // If the element is '1', increment the height at the corresponding index
                if(matrix[i][j] == '1')
                    heights[j]++;
                else
                    heights[j] = 0; // If the element is '0', reset the height to 0
            }
            // Calculate the maximum area of the rectangle with current heights
            maxi = max(maxi,largestRectangle(heights));
        }
        return maxi; // Return the maximum area
    }
};
/*
Time Complexity: O(row*col*n)
Space Complexity: O(n)
*/