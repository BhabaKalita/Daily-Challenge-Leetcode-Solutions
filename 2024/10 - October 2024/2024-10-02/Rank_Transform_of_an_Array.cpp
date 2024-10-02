vector<int> arrayRankTransform(vector<int>& arr) {
    vector<int> sortedArr = arr;  // Copy the original array
    sort(sortedArr.begin(), sortedArr.end());  // Sort the copy of the array
    
    unordered_map<int, int> rankMap;  // Map to store element to rank mapping
    int rank = 1;  // Initial rank starts from 1

    // Iterate over the sorted array to assign ranks
    for (int num : sortedArr) {
        // Only assign a rank if the element hasn't been assigned one before
        if (rankMap.find(num) == rankMap.end()) {
            rankMap[num] = rank++;
        }
    }

    // Replace each element in the original array with its rank
    for (int i = 0; i < arr.size(); i++) {
        arr[i] = rankMap[arr[i]];
    }

    return arr;
}

/*
  Time Complexity : O(n log n) 
  Space Complexity : O(n)
*/
