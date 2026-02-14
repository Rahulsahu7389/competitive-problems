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

    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
}

// range sum query
int querySum(int ind, int low, int high, int l, int r) {

    // no overlap
    if (r < low || high < l)
        return 0;

    // complete overlap
    if (low >= l && high <= r)
        return seg[ind];

    int mid = (low + high) / 2;

    int left  = querySum(2*ind + 1, low, mid, l, r);
    int right = querySum(2*ind + 2, mid + 1, high, l, r);

    return left + right;
}

// point update : a[pos] += val
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

    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
}
