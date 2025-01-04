class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char> letters;

        for(auto ch:s)
            letters.insert(ch);

        int ans = 0;
        for(char letter:letters) {
            int i=-1;
            int j=0;

            for(int k=0; k<s.size(); k++) {
                if(s[k] == letter) {
                    if(i == -1)
                        i = k;
                    
                    j = k;
                }
            }

            unordered_set<char> res;

            for(int k=i+1; k<j; k++) {
                res.insert(s[k]);
            }

            ans += res.size();
        }
        return ans;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)
