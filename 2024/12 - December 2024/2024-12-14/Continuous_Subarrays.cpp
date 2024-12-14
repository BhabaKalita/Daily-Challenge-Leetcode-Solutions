class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int rear = 0;
        long long sum = 0;

        multiset<int> st;
        for(int front=0; front<nums.size(); front++) {
            st.insert(nums[front]);

            while(st.size() > 1 && *st.rbegin() - *st.begin() > 2) {
                st.erase(st.find(nums[rear]));
                rear++;
            }

            sum += front - rear + 1;
        }
        return sum;
    }
};
// Time Complexity :  O(nlog⁡k)
// Space Complexity : O(n)
