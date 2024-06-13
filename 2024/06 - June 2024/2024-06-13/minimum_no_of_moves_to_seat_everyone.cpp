class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        // Sort the seats and students arrays to align closest pairs
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());

        int res = 0; // Initialize the result to store the total moves

        // Calculate the total moves required to seat all students
        for (int i = 0; i < students.size(); i++) {
            // Add the absolute difference between the seat and student positions
            res += abs(students[i] - seats[i]);
        }

        return res; // Return the total minimum moves
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/