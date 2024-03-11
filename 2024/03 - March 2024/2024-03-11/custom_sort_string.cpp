#include <algorithm> // Included for the sort function
#include <string>
using namespace std;

class Solution {
public:
    string customSortString(string O, string S) {
        // Sort string S based on the custom order defined in string O
        sort(S.begin(), S.end(), [&](char a, char b) {
            // Compare the positions of characters 'a' and 'b' in string O
            return O.find(a) < O.find(b);
        });

        // Return the sorted string S
        return S;
    }
};
/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/