#pragma once
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