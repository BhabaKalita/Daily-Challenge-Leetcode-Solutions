int subarraysWithKDistinct(vector<int>& A, int K) {
    // Calculate the number of subarrays with at most K distinct elements
    int countWithK = atMostK(A, K);
    // Calculate the number of subarrays with at most (K - 1) distinct elements
    int countWithKMinusOne = atMostK(A, K - 1);
    // Subtract the count of subarrays with at most (K - 1) distinct elements from the count with K distinct elements
    return countWithK - countWithKMinusOne;
}

// Function to calculate the number of subarrays with at most K distinct elements
int atMostK(vector<int>& A, int K) {
    int i = 0; // Start of the window
    int res = 0; // Result count
    unordered_map<int, int> count; // Map to store the count of elements in the current window

    // Iterate through the array
    for (int j = 0; j < A.size(); ++j) {
        // If the element is encountered for the first time in the window, decrement K
        if (!count[A[j]]++) 
            K--;

        // If the count of distinct elements exceeds K, adjust the window by moving the start pointer
        while (K < 0) {
            // Decrement the count of the element going out of the window
            if (!--count[A[i]]) 
                K++;
            // Move the start pointer forward
            i++;
        }

        // Add the count of subarrays ending at the current position to the result
        // The count is equal to the length of the subarray, which is (j - i + 1)
        res += j - i + 1;
    }

    // Return the total count of subarrays with at most K distinct elements
    return res;
}
/*
Time Complexity: O(N)
Space Complexity: O(N)
*/