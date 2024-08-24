class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.length();

        // Handle single-digit numbers separately
        if (len == 1) {
            return to_string(stoi(n) - 1);  // Return the closest palindrome for single-digit numbers
        }

        // Create a vector to store potential candidate palindromes
        vector<long long> candidates;

        // 1. Generate the largest palindrome with one fewer digit
        candidates.push_back(pow(10, len - 1) - 1);  // Example: 999 for 1000

        // 2. Generate the smallest palindrome with one more digit
        candidates.push_back(pow(10, len) + 1);  // Example: 10001 for 9999

        // 3. Generate palindromes by mirroring the first half of the input number
        long long prefix = stoll(n.substr(0, (len + 1) / 2));  // Extract the prefix (first half)

        // Adjust the prefix and create variations
        for (int i = -1; i <= 1; ++i) {
            string p = to_string(prefix + i);  // Adjust the prefix (increment or decrement)
            string candidate = p + string(p.rbegin() + (len % 2), p.rend());  // Create the palindrome by mirroring
            candidates.push_back(stoll(candidate));  // Add the palindrome to the candidates
        }

        // Convert the input number to a long long for comparison
        long long num = stoll(n);

        // Initialize the closest palindrome variable
        long long closest = -1;

        // Iterate through the candidates and find the closest palindrome
        for (long long cand : candidates) {
            if (cand == num) continue;  // Skip the input number itself
            if (closest == -1 ||
                abs(cand - num) < abs(closest - num) ||  // Update the closest palindrome if a closer one is found
                (abs(cand - num) == abs(closest - num) && cand < closest)) {  // If distances are equal, choose the smaller one
                closest = cand;
            }
        }

        return to_string(closest);  // Return the closest palindrome as a string
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)