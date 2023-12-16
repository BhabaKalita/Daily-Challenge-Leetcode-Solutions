#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  /**
   * Check if two strings are anagrams.
   * An anagram is a word or phrase formed by rearranging the letters of
   * another.
   *
   * @param s The first string.
   * @param t The second string.
   * @return True if the strings are anagrams, false otherwise.
   */
  bool isAnagram(string s, string t) {
    // Check if the lengths of the two strings are different
    if (s.size() != t.size())
      return false;

    // Create an array to store the frequency of each character (assuming
    // lowercase English letters)
    int temp[26] = {0};

    // Iterate through each character in both strings
    for (int i = 0; i < s.size(); i++) {
      // Increment count for the character in string s
      temp[s[i] - 'a']++;
      // Decrement count for the character in string t
      temp[t[i] - 'a']--;
    }

    // Check if all counts in the array are zero
    for (auto ele : temp) {
      if (ele)
        return false;
    }

    // If all counts are zero, strings are anagrams
    return true;
  }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/