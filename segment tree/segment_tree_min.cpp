#include <bits/stdc++.h>
using namespace std;

int a[100005];
int seg[4 * 100005];

void build(int ind, int low, int high) {
    if (low == high) {
        seg[ind] = a[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2*ind + 1, low, mid);
    build(2*ind + 2, mid + 1, high);

    seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
}

int queryMin(int ind, int low, int high, int l, int r) {
    if (r < low || high < l) return INT_MAX;   // no overlap

    if (low >= l && high <= r) return seg[ind]; // complete overlap

    int mid = (low + high) / 2;
    int left = queryMin(2*ind + 1, low, mid, l, r);
    int right = queryMin(2*ind + 2, mid + 1, high, l, r);

    return min(left, right);
}

// point update: a[pos] += val
void pointUpdate(int ind, int low, int high, int pos, int val) {
    if (low == high) {
        seg[ind] += val;
        return;
    }

    int mid = (low + high) / 2;
    if (pos <= mid)
        pointUpdate(2*ind + 1, low, mid, pos, val);
    else
        pointUpdate(2*ind + 2, mid + 1, high, pos, val);

    seg[ind] = min(seg[2*ind + 1], seg[2*ind + 2]);
}
