class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // Step 1: Count the occurrences of each element in arr1 using a map
        map<int, int> m;
        for(auto i : arr1) 
            m[i]++;

        int pos = 0; // Position index for updating arr1

        // Step 2: Place elements from arr2 into arr1 in the order specified by arr2
        for(auto j : arr2) {
            // As long as the count of element j is greater than 0, place j into arr1
            while(m[j]-- > 0) 
                arr1[pos++] = j;
        }

        // Step 3: Place the remaining elements (those not in arr2) into arr1 in sorted order
        for(auto k : m) {
            // As long as the count of element k.first is greater than 0, place k.first into arr1
            while(k.second-- > 0) 
                arr1[pos++] = k.first;
        }

        // Return the sorted array
        return arr1;
    }
};

/*
Time Complexity: O(NlogN)
Space Complexity: O(N)
*/