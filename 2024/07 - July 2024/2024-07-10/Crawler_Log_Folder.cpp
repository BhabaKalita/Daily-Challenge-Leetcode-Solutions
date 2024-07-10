class Solution {
public:
    int minOperations(vector<string>& logs) {
        // Initialize a vector to keep track of the folder paths.
        vector<string> paths;

        // Iterate through each log entry in the logs vector.
        for(auto &log: logs) {
            if(log == "../") {
                // If the log entry is "../", move one level up if not already at the root.
                if(!paths.empty()) {
                    paths.pop_back();
                }
            } else if(log != "./") {
                // If the log entry is not "./", it means it's a valid folder name, so add it to the paths vector.
                paths.push_back(log);
            }
            // If the log entry is "./", do nothing as it represents staying in the current directory.
        }

        // The number of operations needed to go back to the main folder is the size of the paths vector.
        return paths.size();
    }
};
// Time Complexity: O(n)
// Space Complexity: O(n)