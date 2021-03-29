#include "../tree.h"
#include <iostream>
#include <vector>
#include <stack>

/**
 * LeetCode 29 March 2021 challenge
 * 
 * Given a binary tree and an array with the desired pre-order traversal, returns a list of the flipped nodes 
 * that are required to match said traversal. Returns -1 if impossible.
 */

using namespace std;

vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
    if (root == nullptr || root->val != voyage[0]) return vector<int>{-1};

    vector<int> ans;
    stack<TreeNode*> st;
    st.push(root);
    auto it = voyage.begin();

    while (!st.empty()) {
        TreeNode* node = st.top();
        st.pop();

        if (node->val != *it) return vector<int>{-1};   // Check if current node matches iterator

        // Check node children 
        if (node->left != nullptr && node->right != nullptr) {  // Has both children, check left child
            int left = node->left->val;
            int right = node->right->val;

            if (it+1 != voyage.end()) {
                if (left != *(it+1) && right == *(it+1)) { // Flipped positions
                    TreeNode* temp = node->left;
                    node->left = node->right;
                    node->right = temp;

                    ans.push_back(node->val);   // Add flipped node to result
                }
                else if (left != *(it+1) && right != *(it+1)) {  // No match
                    return vector<int>{-1};
                }

                // Push left node last to be visited first
                st.push(node->right);
                st.push(node->left);
            }
        }
        else if (node->left != nullptr || node->right != nullptr) { // Single child
            TreeNode* child = node->left != nullptr ? node->left : node->right;

            // If there's only one child to a node, we need only check if its value matches the next iterator
            if (it+1 != voyage.end() && child->val == *(it+1)) {
                st.push(child);
            } 
            else return vector<int>{-1};
        }

        // Nothing to do with leaf nodes
        
        it++;   // Move iterator
    }

    return ans;
}

int main() {
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode b(2, &d, &e);
    TreeNode c(3, &f, &g);
    TreeNode a(1, &b, &c);

    vector<int> voyage{1, 3, 7, 6, 2, 4, 5}; 
    vector<int> result = flipMatchVoyage(&a, voyage);

    for (int i : result) cout << i << " ";

    cout << endl;
}


