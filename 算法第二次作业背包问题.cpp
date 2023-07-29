#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int itemCount;
    cin >> itemCount;
    int maxWeight;
    cin >> maxWeight;

    vector<int> weights(itemCount + 1, 0);
    vector<int> values(itemCount + 1, 0);
    vector<vector<int>> dp(itemCount + 1, vector<int>(maxWeight + 1));
    vector<vector<bool>> selected(itemCount + 1, vector<bool>(maxWeight + 1, false));

    for (int i = 1; i <= itemCount; i++)
        cin >> weights[i];

    for (int i = 1; i <= itemCount; i++)
        cin >> values[i];

    int maxTotalValue = 0;

    for (int i = 1; i <= itemCount; i++) {
        for (int j = 0; j <= maxWeight; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j >= weights[i]) {
                if (dp[i][j] < dp[i - 1][j - weights[i]] + values[i]) {
                    selected[i][j] = true;
                }
                dp[i][j] = max(dp[i][j], dp[i - 1][j - weights[i]] + values[i]);
            }
            maxTotalValue = max(maxTotalValue, dp[i][j]);
        }
    }

    vector<int> selectedItems;
    int itemIndex = itemCount, weightLeft = maxWeight;

    while (itemIndex > 0 && weightLeft > 0) {
        if (selected[itemIndex][weightLeft]) {
            selectedItems.push_back(itemIndex);
            weightLeft -= weights[itemIndex];
        }
        itemIndex--;
    }

    reverse(selectedItems.begin(), selectedItems.end());

    cout << maxTotalValue << endl;

    for (int i = 0; i < selectedItems.size(); i++) {
        cout << selectedItems[i] << " ";
    }

    cout << endl;

    return 0;
}
