#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Item structure to store profit and weight
class Item {
public:
    int profit, weight;

    Item(int profit, int weight) {
        this->profit = profit;
        this->weight = weight;
    }
};

// Comparator function to sort items by profit/weight ratio
bool comparator(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}

// Function to get the maximum value in the knapsack with given capacity
double getMaxValue(int capacity, vector<Item>& items) {
    // Sort items by descending profit/weight ratio
    sort(items.begin(), items.end(), comparator);

    double totalValue = 0.0;

    // Loop through the sorted items and fill the knapsack
    for (int i=0; i<items.size(); i++) {
    	Item item = items[i]; 
    	
        if (capacity - item.weight >= 0) {
            capacity -= item.weight;
            totalValue += item.profit;
        } 
        
		else {
            double fraction = (double)capacity / item.weight;
            totalValue += item.profit * fraction;
            break;
        }
    }

    return totalValue;
}

int main() {
	
    int n, capacity;
    
    cout << "Enter the number of items: ";
    cin >> n;

    vector<Item> items;
    
    for (int i = 0; i < n; i++) {
        int profit, weight;
        cout << "Enter profit and weight for item " << i + 1 << ": ";
        cin >> profit >> weight;
        items.push_back(Item(profit, weight));
    }

    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    double maxValue = getMaxValue(capacity, items);

    cout << "Maximum value we can obtain = " << maxValue << endl;

    return 0;
}
