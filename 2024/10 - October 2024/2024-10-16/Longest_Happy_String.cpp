class Solution {
public:
    // Function to generate the longest diverse string using 'a', 'b', and 'c'
    string longestDiverseString(int a, int b, int c) {
        // Max-heap (priority queue) to store the counts of each character ('a', 'b', 'c') along with their corresponding characters
        priority_queue<pair<int, char>> pq;

        // Push the counts and characters to the priority queue if they are greater than 0
        if(a > 0) pq.push({a, 'a'}); // Push count of 'a'
        if(b > 0) pq.push({b, 'b'}); // Push count of 'b'
        if(c > 0) pq.push({c, 'c'}); // Push count of 'c'}

        string res = ""; // Resultant string to store the longest diverse string

        // Loop until the priority queue becomes empty
        while(!pq.empty()) {

            // Extract the most frequent character (char1) and its count (count1) from the heap
            auto [count1, char1] = pq.top();
            pq.pop();

            // If the last two characters in the result are the same as char1, we must use a different character
            if(res.size() >= 2 && res.back() == char1 && res[res.size()-2] == char1) {
                // If no other character is available, we cannot proceed
                if(pq.empty()) break;

                // Extract the second most frequent character (char2) and its count (count2)
                auto [count2, char2] = pq.top();
                pq.pop();

                // Add char2 to the result string
                res += char2;
                count2--; // Decrement the count of char2

                // If char2 still has occurrences left, push it back to the heap
                if(count2 > 0) pq.push({count2, char2});

                // Push char1 back to the heap, as we haven't used it yet in this iteration
                if(count1 > 0) pq.push({count1, char1});
            } 
            // Otherwise, we can safely add char1 to the result
            else {
                res += char1;
                count1--; // Decrement the count of char1

                // If char1 still has occurrences left, push it back to the heap
                if(count1 > 0) pq.push({count1, char1});
            }

        }
        
        // Return the longest diverse string
        return res;

    }
};
/*
  Time Complexity : O(a+b+c)
  Space Complexity : O(1)
*/
