#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int productOfEvenIndices(const vector<int>& arr) {
    int product = 1;
    for (int i = 0; i < arr.size(); i += 2) {
        product *= arr[i];
    }
    return product;
}

int sumBetweenZeros(const vector<int>& arr) {
    auto first_zero = find(arr.begin(), arr.end(), 0);
    auto last_zero = find(arr.rbegin(), arr.rend(), 0);

    if (first_zero == arr.end() || last_zero == arr.rend()) {
        return 0;
    }

    return accumulate(next(first_zero), prev(last_zero.base()), 0);
}

int main() {
    vector<int> array = { 2, 4, 6, 8, 10, 3, 0, 7, 9, 0, -1, -2, -3 };

    int product = productOfEvenIndices(array);
    cout << "Product of elements with even indices: " << product << endl;

    int sum = sumBetweenZeros(array);
    cout << "Sum of elements between first and last zero elements: " << sum << endl;

    stable_partition(array.begin(), array.end(), [](int x) { return x > 0 || x == 0; });

    cout << "Reorganized array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
