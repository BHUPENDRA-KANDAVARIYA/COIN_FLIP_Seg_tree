#include <bits/stdc++.h>
using namespace std;
#define ll long long;
class Seg
{
private:
    vector<int> seg;
    vector<int> lazy;

public:
    Seg(int n)
    {
        seg.resize(4 * n + 1);
        seg.resize(4 * n + 1);
    }

    void build(int idx, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[idx] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    // Now flop the coin.
    void update(int idx, int l, int h, int low, int high)
    {
        if (lazy[idx] != 0)
        {
            if (lazy[idx] % 2 != 0)
                seg[idx] = (h - l + 1) - seg[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (low > h || high < l)
            return;
        if (low >= l && high <= h)
        {
            seg[idx];
            if (low != high)
            {
                seg[idx] = (h - l + 1) - seg[idx];
                lazy[2 * idx + 1]++;
                lazy[2 * idx + 2]++;
            }
            return;
        }
        int mid = (low + high) / 2;
        update(2 * idx + 1, l, h, low, mid);
        update(2 * idx + 2, l, h, mid + 1, high);
        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }
    int query(int idx, int low, int high, int l, int h)
    {
        if (low > h || high < l)
            return 0;
        if (lazy[idx] != 0)
        {
            if (lazy[idx] % 2 != 0)
                seg[idx] = (high - low + 1) - seg[idx];
            if (low != high)
            {
                lazy[2 * idx + 1] += lazy[idx];
                lazy[2 * idx + 2] += lazy[idx];
            }
            lazy[idx] = 0;
        }
        if (low >= l && high <= h)
            return seg[idx];
        int mid = (low + high) / 2;
        return query(2 * idx + 1, low, mid, l, h) + query(2 * idx + 2, mid + 1, high, l, h);
    }
};
int main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}