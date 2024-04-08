#include <vector>
using namespace std;

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        // Initialize an array to count the number of students preferring each type of sandwich
        int count[] = {0, 0}; // count[0] represents the count of students preferring sandwich type 0, count[1] for sandwich type 1

        int n = students.size(); // Number of students
        int j;

        // Count the number of students preferring each type of sandwich
        for(int &a : students) {
            count[a]++;
        }

        // Iterate through the sandwiches until there are no more students or sandwiches left
        for(j = 0; j < n && count[sandwiches[j]] > 0; ++j) {
            count[sandwiches[j]]--; // Decrement the count of the corresponding sandwich type
        }

        // Return the number of students who couldn't get their preferred sandwiches
        return n - j;
    }
};

/*
Time Complexity: O(n)
Space Complexity: O(1)
*/