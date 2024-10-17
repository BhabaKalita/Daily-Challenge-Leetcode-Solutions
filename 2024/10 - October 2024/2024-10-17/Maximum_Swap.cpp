class Solution {
public:
    int maximumSwap(int num) {
        // 1. Convert the integer to a string for easier manipulation
        string numStr = to_string(num);
        int n = numStr.size();

        // 2. Create an array 'last' to store the last index of each digit
        vector<int> last(10, -1); // Initialize all elements to -1

        // 3. Iterate through the string and update the 'last' array
        for (int i = 0; i < n; i++) {
            last[numStr[i] - '0'] = i; // Store the index of the current digit
        }

        // 4. Iterate through the string again to find the maximum possible swap
        for (int j = 0; j < n; j++) {
            // 5. Iterate from 9 to the current digit (numStr[j] - '0')
            for (int d = 9; d > numStr[j] - '0'; d--) {
                // 6. If the last index of digit 'd' is greater than the current index 'j',
                //    it means we can swap the current digit with 'd' to get a larger number
                if (last[d] > j) {
                    // 7. Swap the digits at indices 'j' and 'last[d]'
                    swap(numStr[j], numStr[last[d]]);

                    // 8. Convert the modified string back to an integer and return it
                    return stoi(numStr);
                }
            }
        }

        // 9. If no suitable swap was found, return the original number
        return num;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
