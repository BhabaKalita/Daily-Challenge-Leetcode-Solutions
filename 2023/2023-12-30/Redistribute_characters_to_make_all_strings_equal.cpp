#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool makeEqual(vector<string> &words) {
    // Vector to store the count of each alphabet (26 letters)
    vector<int> count(26, 0);
    // Number of words in the vector
    int wordLen = words.size();

    // Loop through each word in the vector
    for (auto &word : words) {
      // Loop through each character in the word
      for (auto &alpha : word)
        // Increment the count for the current alphabet
        count[alpha - 'a']++;
    }

    // Check if the count of each alphabet is a multiple of the number of words
    for (int i = 0; i < 26; i++) {
      if (count[i] % wordLen != 0)
        // If not, it's not possible to make all strings equal
        return false;
    }

    // If all counts are multiples of the number of words, return true
    return true;
  }
};

// Time Complexity: O(N * M)
//   - N is the total number of characters across all words
//   - M is the average length of the words in the vector

// Space Complexity: O(1) (constant space since the size of count array is fixed
// at 26)
