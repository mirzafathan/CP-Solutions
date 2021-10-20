// Muhammad Mirza Fathan 2021
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}; 

class Solution {
  public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if(p->val > q->val) return lowestCommonAncestor(root, q, p);
      //TreeNode* temp = root;
      if(root->val < p->val) return lowestCommonAncestor(root->right, p, q);
      else if(root->val > q->val) return lowestCommonAncestor(root->left, p, q);
      else return root;
    }
};

void printPreorder(TreeNode* node)
{
    if (node == NULL)
        return;

    cout << node->val << " ";
 
    printPreorder(node->left);
 
    printPreorder(node->right);
}

//6,2,8,0,4,7,9,null,null,3,5
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  
  vector<int> root;
  while(true) {
    int n; cin >> n;
    if(n==999) break;
    root.push_back(n);
  }

  int p, q; cin >> p >> q;

  TreeNode* node_p;
  TreeNode* node_q;

  TreeNode* t = new TreeNode(root[0]);

  for(int i=1; i<root.size(); i++) {
    if(root[i]==-1) continue;

    TreeNode* newNode = new TreeNode(root[i]);
    TreeNode* temp = t;
    TreeNode* temp_2 = NULL;

    if(root[i]==p) node_p = newNode;
    if(root[i]==q) node_q = newNode;

    while(temp != NULL) {
      temp_2 = temp;
      if(newNode->val < temp->val) {
        temp = temp->left;
      } else {
        temp = temp->right;
      }
    }

    if(newNode->val < temp_2->val) {
      temp_2->left = newNode;
    } else {
      temp_2->right = newNode;
    }

  }

  Solution* ans = new Solution;
  //cout << t->left->left->val << endl;
  cout << ans->lowestCommonAncestor(t, node_p, node_q)->val << endl;

  return 0;
}