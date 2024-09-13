class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(); // Get the size of the array
        vector<int> pre(n); // Create a prefix XOR array to store the cumulative XORs

        // Initialize the first element of the prefix XOR array
        pre[0] = arr[0];

        // Calculate the prefix XOR for each element in the array
        for (int i = 1; i < n; i++) {
            pre[i] = pre[i - 1] ^ arr[i]; // XOR the current element with the previous prefix XOR
        }

        // Create a vector to store the results of the queries
        vector<int> res(queries.size());

        // Process each query
        for (int k = 0; k < res.size(); k++) {
            int i = queries[k][0]; // Get the start index of the query
            int j = queries[k][1]; // Get the end index of the query

            // If the start index is 0, the result is simply the prefix XOR at the end index
            if (i == 0) {
                res[k] = pre[j];
            } else {
                // Otherwise, calculate the XOR of the prefix XORs at the end and start indices
                res[k] = pre[j] ^ pre[i - 1];
            }
        }

        return res; // Return the vector of results
    }
};
/*
  Time Complexity : O(n)
  Space Complexity : O(n)
*/
