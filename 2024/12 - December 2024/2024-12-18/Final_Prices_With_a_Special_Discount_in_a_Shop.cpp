class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        for(int i=0; i<prices.size(); i++) {
            while(st.size() && prices[st.top()] >= prices[i]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i);
        }
        return prices;
    }
};
// Time Complexity : O(n)
// Space Complexity : O(n)
