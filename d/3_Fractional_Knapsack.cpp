#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    double r1 = (double)a.second / (double)a.first;
    double r2 = (double)b.second / (double)b.first;
    return r1 > r2;
}

double maximumValue(vector<pair<int, int>>& arr, int n, int W) {
    sort(arr.begin(), arr.end(), cmp);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + arr[i].first <= W) {
            curWeight += arr[i].first;
            finalValue += arr[i].second;
        } else {
            int remain = W - curWeight;
            finalValue += arr[i].second * ((double)remain / (double)arr[i].first);
            break;
        }
    }

    return finalValue;
}

int main() {
    int W = 50; // Knapsack capacity
    vector<pair<int, int>> items = {
        {10, 60}, {20, 100}, {30, 120} // Each item as {weight, value}
    };
    
    int n = items.size();
    cout << "Maximum value in Knapsack = " << maximumValue(items, n, W) << endl;

    return 0;
}
