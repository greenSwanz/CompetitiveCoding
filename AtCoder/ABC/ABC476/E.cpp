#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;

using namespace std;

template <typename T> class SegmentTree {
private:
    vector<T> tree;
    vector<T> treeMax;
    vector<int> idxMin, idxMax;
    vector<T> arr;
    int n;

    int left(int node) { return 2 * node + 1; }
    int right(int node) { return 2 * node + 2; }
    int mid(int l, int r) { return l + (r - l) / 2; }

        void build(int node, int start, int end)
    {
        if (start == end) {
            tree[node] = arr[start];
            treeMax[node] = arr[start];
            idxMin[node] = idxMax[node] = start;
            return;
        }
        int m = mid(start, end);
        build(left(node), start, m);
        build(right(node), m + 1, end);
        tree[node] = min(tree[left(node)], tree[right(node)]);
        idxMin[node] = tree[left(node)] <= tree[right(node)]
                     ? idxMin[left(node)] : idxMin[right(node)];
        treeMax[node] = max(treeMax[left(node)], treeMax[right(node)]);
        idxMax[node] = treeMax[left(node)] >= treeMax[right(node)]
                     ? idxMax[left(node)] : idxMax[right(node)];
    }

        void update(int node, int start, int end, int idx, T val)
    {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
            treeMax[node] = val;
            idxMin[node] = idxMax[node] = start;
            return;
        }
        int m = mid(start, end);
        if (idx <= m)
            update(left(node), start, m, idx, val);
        else
            update(right(node), m + 1, end, idx, val);
        tree[node] = min(tree[left(node)], tree[right(node)]);
        idxMin[node] = tree[left(node)] <= tree[right(node)]
                     ? idxMin[left(node)] : idxMin[right(node)];
        treeMax[node] = max(treeMax[left(node)], treeMax[right(node)]);
        idxMax[node] = treeMax[left(node)] >= treeMax[right(node)]
                     ? idxMax[left(node)] : idxMax[right(node)];
    }

    pair<pair<int,int>,pair<T,T>> query(pair<int,int> node, int start, int end, int l, int r)
    {
    if (r < start || end < l)
        return {{-1,-1},{numeric_limits<T>::max(),numeric_limits<T>::lowest()}};
    if (l <= start && end <= r)
        return {{idxMin[node.first],idxMax[node.second]}, {tree[node.first],treeMax[node.second]}};
    int m = mid(start, end);
    pair<pair<int,int>,pair<T,T>> a = query({left(node.first),left(node.second)}, start, m, l, r);
    pair<pair<int,int>,pair<T,T>> b = query({right(node.first),right(node.second)}, m + 1, end, l, r);
    bool amin = a.second.first  <= b.second.first;
    bool amax = a.second.second >= b.second.second;
    return {{amin ? a.first.first : b.first.first, amax ? a.first.second : b.first.second},
            {amin ? a.second.first : b.second.first, amax ? a.second.second : b.second.second}};
    }

public:
    SegmentTree(const vector<T>& a)
        : arr(a)
        , n(a.size())
    {
        tree.resize(4 * n);
        treeMax.resize(4 * n);
        idxMin.resize(4 * n);
        idxMax.resize(4 * n);
        build(0, 0, n - 1);
    }

    void update(int idx, T val)
    {
        update(0, 0, n - 1, idx, val);
    }

    pair<pair<int,int>,pair<T,T>> query(int l, int r)
    {
        return query({0,0}, 0, n - 1, l, r);
    }
};

int main()
{
    ll N,M; cin >> N >> M;
    vector<ll> Pe(N); rep(i,N){cin >> Pe[i];}
    SegmentTree<ll> st(Pe);
    rep(_,M){
        int left,right; cin >> left >> right; --left; --right;
        pair<pair<int,int>,pair<ll,ll>> pa = st.query(left,right);
        Pe[pa.first.first] = pa.second.second;
        Pe[pa.first.second] = pa.second.first;
        st.update(pa.first.first, pa.second.second);
        st.update(pa.first.second, pa.second.first);
    }
    rep(i,N) cout << Pe[i] << " ";
    cout << endl;
    return 0;
}