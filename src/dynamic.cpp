#include "dynamic.h"

#include <iostream>
#include <vector>

// DYNAMIC PROGRAMMING SOLUTION
// Returns length of LCS for strings X and Y and prints LCS
int dynamicLCS(string X, string Y, int m, int n) {
    // BUILDING THE LENGTH MATRIX    
    int i, j, k, l; // Loop variables

    // Initialize the L (length) matrix
    // Same as int L[m + 1][n + 1], but dynamically sized
    int** L = new int* [m + 1];
    for (k = 0; k < m + 1; k++) {
        L[k] = new int[n + 1];
    }

    // Build the matrix L[m + 1][n + 1] in bottom up fashion starting from row and col 0
    // L[i][j] contains length of LCS of X[0.... i - 1] and Y[0.... j - 1]
    for (i = 0; i <= m; i++) { // For all rows
        for (j = 0; j <= n; j++) { // For all columns
            if (i == 0 || j == 0) { // Top row and left column initialized to 0
                L[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) { // Last characters of the (current) strings match
                L[i][j] = L[i - 1][j - 1] + 1; // Add 1 to the length from the element to the top-left of the matrix
            } else { // The last characters do not match
                L[i][j] = max(L[i][j - 1], L[i - 1][j]); // Take the max length from either the element to the top or left (top if equal)
            }
        }
    }

    // BUILDING THE LONGEST COMMON SUBSEQUENCE
    // Initialize an empty char vector to print the LCS
    vector<char> LCS{};

    // Store chars into the LCS vector starting from the bottom-right corner of L (length) matrix
    i = m, j = n; // Loop variables

    while (i > 0 && j > 0) {
        // Current character matches
        if (X[i - 1] == Y[j - 1]) {
            LCS.insert(LCS.begin(), X[i - 1]); // Put current character into beginning of LCS vector
            i--; j--; // Move diagonally top-left
        }
        // If current characters are not the same, go in direction of larger value (up or left)
        else if (L[i - 1][j] > L[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Print LCS of X and Y and length
    cout << "LCS of X and Y: \"";
    for (l = 0; l < LCS.size(); l++) {
        cout << LCS[l];
    }

    cout << "\"" << endl;

    // L[m][n] (last element of L matrix) is the length of the LCS of the entire strings, X and Y
    cout << "Length of LCS: ";
    return L[m][n];
}