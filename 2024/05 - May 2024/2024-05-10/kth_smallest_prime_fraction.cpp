class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // Max heap to store fractions in descending order of values
        // Pair is used to store the fraction value and its corresponding pair of integers
        priority_queue<pair<double, pair<int, int>>> maxHeap;

        int n = arr.size();

        // Generating all possible fractions from the array
        for(int i = 0; i < n - 1; i++) {
            for(int j = i + 1; j < n; j++) {
                // Calculate the fraction value and store it along with its pair
                maxHeap.push({((double) arr[i] / arr[j]), {arr[i], arr[j]}});

                // If heap size exceeds k, remove the maximum fraction
                if(maxHeap.size() > k) {
                    maxHeap.pop();
                }
            }
        }

        // The top of the max heap now contains the kth smallest fraction
        auto res = maxHeap.top().second;
        return {res.first, res.second};
    }
};
/*
Time Complexity: O(n^2 * logk)20
Space Complexity: O(k)
*/