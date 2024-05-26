#include <vector>

using namespace std;

class Solution {
public:
    // Main function to check the record
    int checkRecord(int n) {
        // Transition matrix representing state changes
        vector<vector<int>> M = {{1,1,0,1,0,0},
                                 {1,0,1,1,0,0},
                                 {1,0,0,1,0,0},
                                 {0,0,0,1,1,0},
                                 {0,0,0,1,0,1},
                                 {0,0,0,1,0,0}};
        // Return the result from the matrix exponentiation
        return pow(M, n + 1)[0][3];
    }

private:
    // Function to multiply two matrices A and B
    vector<vector<int>> mult(const vector<vector<int>>& A, const vector<vector<int>>& B) {
        // Resultant matrix C initialized with zeros
        vector<vector<int>> C(6, vector<int>(6));
        // Matrix multiplication logic
        for(int i = 0; i < 6; ++i)
            for(int j = 0; j < 6; ++j)
                for(int k = 0; k < 6; ++k)
                    // Calculate the element C[i][j] with modulo operation
                    C[i][j] = (C[i][j] + (long long)A[i][k] * B[k][j] % 1000000007) % 1000000007;
        return C;
    }

    // Function to compute matrix exponentiation
    vector<vector<int>> pow(vector<vector<int>> A, int n) {
        // Identity matrix B
        vector<vector<int>> B(6, vector<int>(6));
        for(int i = 0; i < 6; ++i) 
            B[i][i] = 1;
        // Binary exponentiation
        while(n > 0) {
            if((n & 1) == 1) 
                B = mult(A, B);
            A = mult(A, A);
            n >>= 1;
        }
        return B;
    }
};

/*
Time Complexity:
- The `checkRecord` function calls `pow` with a matrix of size 6x6 and an exponent of n+1.
- The `mult` function performs matrix multiplication in O(6^3) = O(216) time.
- The `pow` function performs matrix exponentiation using binary exponentiation, which involves O(log n) matrix multiplications.
- Therefore, the overall time complexity is O(216 * log n) = O(log n).

Space Complexity:
- The space complexity is primarily determined by the space needed to store matrices A and B, both of which are 6x6 matrices.
- The space required is O(6^2) = O(36).
- Thus, the overall space complexity is O(1), since the size of the matrices is constant.
*/
