class Solution {
public:
    // Function to reverse the prefix of the string up to the first occurrence of a character 'ch'
    string reversePrefix(string word, char ch) {
        // Reversing the substring from the beginning of the word to the first occurrence of 'ch'
        reverse(begin(word), begin(word) + word.find(ch) + 1);
        return word;
    }
};

// Time complexity: O(n)
//   - Finding the index of 'ch' takes O(n)
//   - Reversing the prefix takes O(n)
//   - Overall, the time complexity is O(n)
// Space complexity: O(1)
//   - The function does not use any extra space proportional to the input size.
//   - Only constant extra space is used.
