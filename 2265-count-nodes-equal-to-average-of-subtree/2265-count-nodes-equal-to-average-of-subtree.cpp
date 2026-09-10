/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int result = 0 ;

    void getSumAndCount(TreeNode* root, int &sum , int &count){
        if(root == NULL){
            return ;
        }

        sum += root -> val;
        count += 1 ;

        getSumAndCount(root -> left, sum, count);
        getSumAndCount(root -> right, sum, count);
    }

    void Solve(TreeNode* root){
        
        if(root == NULL){
            return ;
        }

        int sum = 0 ;
        int count = 0;
        getSumAndCount(root, sum, count);

        int average = sum / count ;
        if(average == root -> val){
            result ++;
        }

        Solve(root -> left);
        Solve(root -> right);
    }
    int averageOfSubtree(TreeNode* root) {
        Solve(root);
        return result ;
    }
};