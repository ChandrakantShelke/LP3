#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Dynamic Programming approach to solve the 0-1 Knapsack problem
int knapSack(int capacity, vector<int>& Weight, vector<int>& Profit, int num) {
    vector<int> dp(capacity + 1, 0);  // Create a vector to knapsack size 

    // Build the dp array from bottom-up
    for (int i = 0; i <= num; i++) {
        for (int j = capacity; j > 0; j--) {
            if (Weight[i] <= j) {
                dp[j] = max(dp[j], dp[j - Weight[i - 1]] + Profit[i - 1]);
            }
        }
    }
    return dp[capacity];  // Return the maximum value for the given weight capacity
}

int main() {
    
	int num;

    // Input the number of items
    cout << "Enter the number of weights or values required: \n";
    cin >> num;

    vector<int> Weight(num);
	vector<int> Profit(num);

    // Input the weights
   // cout << "Enter weights:\n";
    for (int i = 0; i < num; i++) {
        cout << "Enter weight " << (i + 1) << " : ";
        cin >> Weight[i];
    }

    // Input the values
    cout << "Enter Profit:\n";
    for (int i = 0; i < num; i++) {
        cout << "Enter Profit " << (i + 1) << " : ";
        cin >> Profit[i];
    }

    // Input the maximum capacity of the knapsack
    int Capacity;
    cout << "Enter the capacity of the knapsack: ";
    cin >> Capacity;

    // Calculate the maximum value that can be achieved within the capacity
    int maxValue = knapSack(Capacity, Weight, Profit, num);

    cout << "The maximum value that can be obtained is: " << maxValue << endl;

    return 0;
}
