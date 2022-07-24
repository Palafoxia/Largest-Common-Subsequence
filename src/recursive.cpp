#include "recursive.h"

// RECURSIVE SOLUTION
// Returns length of LCS for strings X and Y
int recursiveLCS(string X, string Y, int m, int n) {
    //Terminates here
    if (m == 0 || n == 0) {
        return 0;
    } 
    
    // Check if last character of the (current) strings match
    if (X[m - 1] == Y[n - 1]) {
        return 1 + recursiveLCS(X, Y, m - 1, n - 1);
    } else {
        return max(recursiveLCS(X, Y, m, n - 1), recursiveLCS(X, Y, m - 1, n));
    }
}