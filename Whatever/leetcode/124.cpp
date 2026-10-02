#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i = 0; i < (n); ++i)
#define repp(i, c ,n) for(ll i = c; i < (n); ++i)
using P = pair<ll,ll>;
  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    int best = INT_MIN;
    int dfs(TreeNode* node){
        if(!node) return 0;
        int lsum = max(0,dfs(node->left)); int rsum = max(0,dfs(node->right));
        best = max(best, node->val + lsum + rsum);
        return node->val + max(lsum,rsum);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root); return best;
    }
};

 




