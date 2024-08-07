class Solution {
public:
    // Function to convert a number to words
    string numberToWords(int num) {
        // Mapping numbers to their word representation
        vector<pair<int, string>> mp = {
            {1000000000, "Billion"},
            {1000000, "Million"},
            {1000, "Thousand"},
            {100, "Hundred"},
            {90, "Ninety"},
            {80, "Eighty"},
            {70, "Seventy"},
            {60, "Sixty"},
            {50, "Fifty"},
            {40, "Forty"},
            {30, "Thirty"},
            {20, "Twenty"},
            {19, "Nineteen"},
            {18, "Eighteen"},
            {17, "Seventeen"},
            {16, "Sixteen"},
            {15, "Fifteen"},
            {14, "Fourteen"},
            {13, "Thirteen"},
            {12, "Twelve"},
            {11, "Eleven"},
            {10, "Ten"},
            {9, "Nine"},
            {8, "Eight"},
            {7, "Seven"},
            {6, "Six"},
            {5, "Five"},
            {4, "Four"},
            {3, "Three"},
            {2, "Two"},
            {1, "One"},
        };

        // If the number is zero, return "Zero"
        if(num == 0)
            return "Zero";

        string res = ""; // Result string to store the final word representation

        // Iterate through the mapping from highest to lowest
        for(auto &x : mp) {
            // Temporary strings to store the word parts
            string a = "";
            if(x.first <= num) {
                // If the number is greater than or equal to 100, recursively get the word for the quotient
                if(num >= 100)
                    a = numberToWords(num / x.first) + " ";

                string b = x.second; // The current word part from the mapping
                string c = ""; // For the remainder part

                // If there is a remainder, recursively get the word for the remainder
                if(num % x.first != 0) {
                    c = " " + numberToWords(num % x.first);
                }

                // Concatenate the parts and return as the result
                return res = a + b + c;
            }
        }

        return ""; // This line is never reached
    }
};
// Time Complexity: O(log n)
// Space Complexity: O(log n)