#include <bits/stdc++.h>
using namespace std;

// Function to solve 0-1 Knapsack problem using Dynamic Programming
int knapSack(int W, vector<int>& weights, vector<int>& values, int n) {
    // Create a 2D DP array where dp[i][w] will store the maximum value
    // for the first i items and a maximum weight capacity of w
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // If the item can be included, take the maximum of including or excluding it
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                // If the item cannot be included, exclude it
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The bottom-right cell will contain the maximum value
    return dp[n][W];
}

int main() {
    int W = 50; // Maximum weight of the knapsack
    vector<int> weights = {10, 20, 30}; // Weights of items
    vector<int> values = {60, 100, 120}; // Values of items
    int n = weights.size(); // Number of items

    cout << "Maximum value in Knapsack = " << knapSack(W, weights, values, n) << endl;

    return 0;
}

/*
0/1 Knapsack :
Time Complexity: O(N*W). 
where ‘N’ is the number of weight element and ‘W’ is capacity. As for every weight element we traverse through all weight capacities 1<=w<=W.
Auxiliary Space: O(N*W). 
The use of 2-D array of size ‘N*W’.
*/