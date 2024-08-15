class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnt5 = 0, cnt10 = 0; // Initialize counters for $5 and $10 bills

        // Iterate through each bill in the vector
        for(int &x : bills) {
            switch(x) {
                case 5:
                    // If the bill is $5, increase the count of $5 bills
                    if(x == 5) cnt5++;
                    break;
                case 10:
                    // If the bill is $10, check if there's a $5 bill for change
                    if(x == 10 && cnt5 > 0) {
                        cnt5--; // Use one $5 bill for change
                        cnt10++; // Increase the count of $10 bills
                        break;
                    } else
                        return false; // Cannot provide change, return false
                case 20:
                    // If the bill is $20, prefer to use one $10 and one $5 bill for change
                    if(cnt10 > 0 && cnt5 > 0) {
                        cnt10--; // Use one $10 bill
                        cnt5--;  // Use one $5 bill
                        break;
                    } 
                    // If no $10 bill is available, use three $5 bills for change
                    else if(cnt5 > 2) {
                        cnt5 -= 3; // Use three $5 bills
                        break;
                    } else 
                        return false; // Cannot provide change, return false
            }
        }
        return true; // Successfully provided change for all customers
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)