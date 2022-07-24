// CS141 Project: Dynamic Programming - Longest Common Subsequence

#include "dynamic.h"
#include "recursive.h"

#include <iostream>
#include <vector>

int main() {
    // EXAMPLES
    vector<string> X;
    X.push_back("abc");
    X.push_back("abcdefg");
    X.push_back("acadb");
    X.push_back("BACDB");

    vector<string> Y;
    Y.push_back("xbc");
    Y.push_back("abxdfg");
    Y.push_back("cbda");
    Y.push_back("BDCB");

    cout << X.size() << endl;

    for(int i = 0; i < X.size(); i++) {
        int m = X[i].length();
        int n = Y[i].length();

        cout << "Find the LCS for strings \"" << X[i] << "\" (X) and \"" << Y[i] << "\" (Y)" << endl;
        cout << "RECURSIVE SOLUTION" << endl;
        cout << "Length of LCS: " << recursiveLCS(X[i], Y[i], m, n) << endl;
        cout << "DYNAMIC PROGRAMMING SOLUTION" << endl;
        cout << dynamicLCS(X[i], Y[i], m, n) << endl << endl;
    }
    cin.ignore();
}