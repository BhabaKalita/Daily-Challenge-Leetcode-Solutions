class Solution {
public:
    double mincostToHireWorkers(vector<int> q, vector<int> w, int K) {
    // 'q' represents the quality of each worker
    // 'w' represents the wage of each worker
    // 'K' represents the number of workers to hire
    vector<vector<double>> workers; // Vector to store workers and their cost-to-quality ratio
    for (int i = 0; i < q.size(); ++i)
        workers.push_back({(double)(w[i]) / q[i], (double)q[i]}); // Calculate cost-to-quality ratio and store both ratio and quality
    sort(workers.begin(), workers.end()); // Sort workers based on their cost-to-quality ratio
    double res = DBL_MAX, qsum = 0; // Initialize result and sum of qualities
    priority_queue<int> pq; // Priority queue to store qualities of selected workers
    for (auto worker: workers) { // Iterate through sorted workers
        qsum += worker[1], pq.push(worker[1]); // Add quality to sum and push quality to priority queue
        if (pq.size() > K) qsum -= pq.top(), pq.pop(); // If number of selected workers exceeds K, remove the worker with the highest quality
        cout << qsum << endl;
        if (pq.size() == K) res = min(res, qsum * worker[0]); // If K workers are selected, calculate cost and update result
    }
    return res; // Return the minimum cost to hire K workers
}
};
/*
Time Complexity: O(N log N)
Space Complexity: O(N)
*/