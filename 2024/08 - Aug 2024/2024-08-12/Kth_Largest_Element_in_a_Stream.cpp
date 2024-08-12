// Definition of the KthLargest class
class KthLargest {
public:
    // Priority queue (min-heap) to store the k largest elements
    priority_queue<int, vector<int>, greater<int>> pq;

    // Integer to store the value of k
    int K;

    // Constructor to initialize the class with k and the initial list of numbers
    KthLargest(int k, vector<int>& nums) {
        K = k;  // Set the value of k

        // Iterate through each element in the nums vector
        for(auto &x : nums) {
            pq.push(x);  // Add the element to the priority queue

            // If the size of the priority queue exceeds k, remove the smallest element
            if(pq.size() > K)
                pq.pop();
        }
    }

    // Function to add a new value to the KthLargest object
    int add(int val) {
        pq.push(val);  // Add the new value to the priority queue

        // If the size of the priority queue exceeds k, remove the smallest element
        if(pq.size() > K)
            pq.pop();

        // The top element of the priority queue is the k-th largest element
        return pq.top();
    }
};
//Space Complexity: O(n*logk)
//Space Complexity: O(k)