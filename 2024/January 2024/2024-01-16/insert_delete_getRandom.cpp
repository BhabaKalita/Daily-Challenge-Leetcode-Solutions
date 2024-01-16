// A class that implements a data structure that supports
// insert, remove and getRandom operations in O(1) time
class RandomizedSet {
public:
    // A vector to store the elements
    vector<int> cont;
    // A hash map to store the indices of the elements in the vector
    unordered_map<int, int> mp;

    // Constructor
    RandomizedSet() {

    }

    // Inserts a value to the set if not already present
    // Returns true if the value was inserted, false otherwise
    bool insert(int val) {
        // Check if the value is already in the map
        if(mp.find(val) != mp.end()) return false;
        // Append the value to the vector
        cont.push_back(val);
        // Update the map with the new index
        mp[val] = cont.size()-1;
        return true;
    }

    // Removes a value from the set if present
    // Returns true if the value was removed, false otherwise
    bool remove(int val) {
        // Check if the value is in the map
        if(mp.find(val) == mp.end()) return false;
        // Get the last element in the vector
        int last = cont.back();
        // Swap the last element with the element to be removed
        mp[last] = mp[val];
        cont[mp[val]] = last;
        // Pop the last element from the vector
        cont.pop_back();
        // Erase the value from the map
        mp.erase(val);
        return true;
    }

    // Returns a random element from the set
    int getRandom() {
        // Generate a random index in the range [0, cont.size()-1]
        return cont[rand()%cont.size()];
    }
};

/*
Time Complexity:O(1)
Space Complexity:O(n) 
*/