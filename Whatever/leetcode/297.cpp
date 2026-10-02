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
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        queue<TreeNode*> q; string s; s += to_string(root->val); s.push_back(','); q.push(root->left); q.push(root->right);
        while(!q.empty()){
            TreeNode* node = q.front(); q.pop();
            s += (node == NULL) ? "#" : to_string(node->val); s.push_back(',');
            if(node != NULL) { q.push(node->left); q.push(node->right); }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        stringstream ss(data);
        string tok;
        getline(ss, tok, ',');
        TreeNode* root = new TreeNode(stoi(tok));
        queue<TreeNode*> q; q.push(root);
        while(!q.empty()){
            TreeNode* cur = q.front(); q.pop();
            if(getline(ss,tok,',') && tok != "#") {cur->left = new TreeNode(stoi(tok)); q.push(cur->left);}
            if(getline(ss,tok,',') && tok != "#") {cur->right = new TreeNode(stoi(tok)); q.push(cur->right);}
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
int main(){
    
}