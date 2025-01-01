class Solution {
public:
    int maxScore(string s) {
        // Calculate the total number of '1's in the string
        int oneSum = 0, zeroSum = 0, totalSum = 0; 

        for(char c:s) 
            if(c == '1') oneSum +=1; 

        // Iterate through the string, excluding the last character
        for(int i=0; i<s.size()-1; i++) { 

            // If the current character is '0', increment the count of zeros
            if(s[i] == '0')
                zeroSum +=1; 
            // If the current character is '1', decrement the count of ones
            else
                oneSum--; 
            
            // Calculate the current score 
            // (number of zeros in the left part + number of ones in the right part)
            totalSum = max(totalSum, oneSum + zeroSum); 
        }

        return totalSum; 
    }
};
// Time Complexity : O(n)
// Space Complexity : O(1)
