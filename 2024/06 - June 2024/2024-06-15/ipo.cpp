class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        // Create a vector of pairs to store projects as (capital, profit)
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }

        // Sort the projects based on the required capital in ascending order
        sort(projects.begin(), projects.end());

        int i = 0; // Initialize index for iterating over sorted projects
        priority_queue<int> maximizeCapital; // Max-heap to store profits of feasible projects

        // Repeat the process for k projects or until no more projects can be selected
        while (k--) {            
            // Push all feasible projects (whose capital is less than or equal to available capital) into the heap
            while (i < n && projects[i].first <= w) {
                maximizeCapital.push(projects[i].second);
                i++;
            }

            // If no projects are feasible, break out of the loop
            if (maximizeCapital.empty())
                break;

            // Select the project with the maximum profit and add it to the current capital
            w += maximizeCapital.top();
            maximizeCapital.pop();
        }

        // Return the final maximized capital after k projects
        return w;
    }
};

/*
Time Complexity: O(n log n)
Space Complexity: O(n)
*/