int a[100005], seg[4*100005], lazy[4*100005];

void build(int ind, int low, int high){
    if(low == high){
        seg[ind] = a[low];
        return;
    }

    int mid = (low + high) / 2;
    build(2*ind + 1, low, mid);
    build(2*ind + 2, mid + 1, high);

    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
}


// add val to all elements in range [l , r]
void rangeUpdate(int ind, int low, int high, int l, int r, int val){

    // first apply any pending update
    if(lazy[ind] != 0){
        seg[ind] += (high - low + 1) * lazy[ind];

        if(low != high){
            lazy[2*ind + 1] += lazy[ind];
            lazy[2*ind + 2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    // no overlap
    if(r < low || l > high)
        return;

    // complete overlap
    if(low >= l && high <= r){
        seg[ind] += (high - low + 1) * val;

        if(low != high){
            lazy[2*ind + 1] += val;
            lazy[2*ind + 2] += val;
        }
        return;
    }

    // partial overlap
    int mid = (low + high) / 2;

    rangeUpdate(2*ind + 1, low, mid, l, r, val);
    rangeUpdate(2*ind + 2, mid + 1, high, l, r, val);

    seg[ind] = seg[2*ind + 1] + seg[2*ind + 2];
}


int querySumLazy(int ind, int low, int high, int l, int r){

    // resolve pending update
    if(lazy[ind] != 0){
        seg[ind] += (high - low + 1) * lazy[ind];

        if(low != high){
            lazy[2*ind + 1] += lazy[ind];
            lazy[2*ind + 2] += lazy[ind];
        }

        lazy[ind] = 0;
    }

    // no overlap
    if(r < low || l > high)
        return 0;

    // complete overlap
    if(low >= l && high <= r)
        return seg[ind];

    int mid = (low + high) / 2;

    return querySumLazy(2*ind + 1, low, mid, l, r)
         + querySumLazy(2*ind + 2, mid + 1, high, l, r);
}
