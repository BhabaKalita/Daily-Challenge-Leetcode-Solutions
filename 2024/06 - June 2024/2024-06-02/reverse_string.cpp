class Solution {
public:
    void reverseString(vector<char>& s) {
        // Initialize two pointers: i starts at the beginning, j starts at the end
        int i = 0, j = s.size() - 1;

        // Continue swapping elements until the two pointers meet or cross
        while (i <= j) {
            // Swap the elements at positions i and j
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            // Move the pointers towards the center
            i++;
            j--;
        }
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/