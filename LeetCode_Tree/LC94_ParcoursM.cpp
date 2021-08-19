# include <iostream>
using namespace std;
# include <vector> 
# include <unordered_set>


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> insert(vector<int> bs, TreeNode* nd){
    if (nd != nullptr){
        bs = insert(bs,nd->left);
        bs.push_back(nd->val);
        bs = insert(bs,nd->right);
    }
    return bs;
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> base;
    if (root != nullptr){
        base = insert(base,root);

    }
    return base;
}


int main(){
    TreeNode tr1 = TreeNode(3);
    tr1.left = new TreeNode(2);
    tr1.right = new TreeNode(6);
    tr1.right->right = new TreeNode(8);
    vector<int> out = inorderTraversal(&tr1);
    for (int x: out){
         cout << x << "  ";
    }
}