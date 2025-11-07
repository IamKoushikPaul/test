#include <iostream>
using namespace std;

int main() {
    int n, capacity;
    cout << "Enter number of items: ";
    cin >> n;
    cout << "Enter capacity: ";
    cin >> capacity;

    int value[n], weight[n];
    for (int i = 0; i < n; i++) {
        cout << "Item " << i + 1 << " value: ";
        cin >> value[i];
        cout << "Item " << i + 1 << " weight: ";
        cin >> weight[i];
    }

    float totalValue = 0.0;

    while (capacity > 0) {
        int bestIndex = -1;
        float bestRatio = 0.0;

        for (int i = 0; i < n; i++) {
            if (weight[i] > 0) {
                float ratio = (float)value[i] / weight[i];
                if (ratio > bestRatio) {
                    bestRatio = ratio;
                    bestIndex = i;
                }
            }
        }

        if (bestIndex == -1) {
            break;
        }

        int takeWeight = (weight[bestIndex] < capacity) ? weight[bestIndex] : capacity;
        totalValue += takeWeight * bestRatio;
        capacity -= takeWeight;
        weight[bestIndex] -= takeWeight;
    }

    cout << "Maximum profit: " << totalValue << endl;

    return 0;
}
