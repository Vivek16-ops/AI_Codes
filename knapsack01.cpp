// 0 1 knapsack practice
#include <iostream>
#include <vector>
using namespace std;

int knsapsack_recurssion(int index, int capacity, vector<int> &weight, vector<int> &values)
{
    // Base Case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            return false;
        }
    }

    int include = 0;
    // Include case
    if (weight[index] <= capacity)
    {
        include = values[index] + knsapsack_recurssion(index - 1, capacity - weight[index], weight, values);
    }

    // Exclude Case
    int exclude = 0 + knsapsack_recurssion(index - 1, capacity, weight, values);

    int ans = max(include, exclude);
    return ans;
}

// Top Down Approach DP(Dynamic Programming)
int topDownApproach(int index, int capacity, vector<int> &weight, vector<int> &values, vector<vector<int>> &dp)
{
    // Base Case
    if (index == 0)
    {
        if (weight[0] <= capacity)
        {
            return values[0];
        }
        else
        {
            return false;
        }
    }

    if (dp[index][capacity] != -1)
    {
        return dp[index][capacity];
    }

    int include = 0;
    // Include case
    if (weight[index] <= capacity)
    {
        include = values[index] + knsapsack_recurssion(index - 1, capacity - weight[index], weight, values);
    }

    // Exclude Case
    int exclude = 0 + knsapsack_recurssion(index - 1, capacity, weight, values);

    dp[index][capacity] = max(include, exclude);
    return dp[index][capacity];
}
int main()
{
    int n;
    cout << "Enter the number of items: " << endl;
    cin >> n;

    int capacity;
    cout << "Enter the capacity of the knapsack: " << endl;
    cin >> capacity;

    vector<int> weight(n);
    vector<int> values(n);
    cout << "Enter the weight and value of the items: " << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        cin >> values[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << "Weight: " << weight[i] << endl;
        cout << "Values: " << values[i] << endl;
    }

    // Normal Recurssive Approach
    // cout << "The Toatal Profit values in the knapsack is: " << knsapsack_recurssion(n - 1, capacity, weight, values);

    // Top - Down Approach
    vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
    cout << "The Toatal Profit values in the knapsack is: " << topDownApproach(n - 1, capacity, weight, values, dp);
    return 0;
}