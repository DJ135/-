#include <iostream>
using namespace std;

int maxSubSum(int a[], int left, int right) {
    int sum = 0;
    if (left == right) {
        sum = a[left] > 0 ? a[left] : 0;
    }
    else {
        int center = (left + right) / 2;
        int leftSum = maxSubSum(a, left, center);
        int rightSum = maxSubSum(a, center + 1, right);

        int s1 = 0;
        int lefts = 0;
        for (int i = center; i >= left; i--) {
            lefts += a[i];
            if (lefts > s1) s1 = lefts;
        }

        int s2 = 0;
        int rights = 0;
        for (int i = center + 1; i < right; i++) {
            rights += a[i];
            if (rights > s2) s2 = rights;
        }
        sum = s1 + s2;
        if (sum < leftSum) sum = leftSum;
        if (sum < rightSum) sum = rightSum;
    }
    return sum;
}

int maxSum(int a[], int n) {
    return maxSubSum(a, 0, n - 1);
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    int a[n];
    cout << "Enter " << n << " elements for the array: ";
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << "The maximum subarray sum for the given array is: " << maxSum(a, n) << endl;
    return 0;
}
