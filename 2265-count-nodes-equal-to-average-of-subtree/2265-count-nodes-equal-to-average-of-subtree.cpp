// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     int result = 0 ;

//     void getSumAndCount(TreeNode* root, int &sum , int &count){
//         if(root == NULL){
//             return ;
//         }

//         sum += root -> val;
//         count += 1 ;

//         getSumAndCount(root -> left, sum, count);
//         getSumAndCount(root -> right, sum, count);
//     }

//     void Solve(TreeNode* root){
        
//         if(root == NULL){
//             return ;
//         }

//         int sum = 0 ;
//         int count = 0;
//         getSumAndCount(root, sum, count);

//         int average = sum / count ;
//         if(average == root -> val){
//             result ++;
//         }

//         Solve(root -> left);
//         Solve(root -> right);
//     }
//     int averageOfSubtree(TreeNode* root) {
//         Solve(root);
//         return result ;
//     }
// };

class Solution {
public:
    int result = 0;

    void solve(TreeNode* node, int& sum, int& count) {
        if (node == NULL) {
            return;   // khali node, kuch add nahi karna
        }
        
        int leftSum = 0, leftCount = 0;
        solve(node->left, leftSum, leftCount);     // pehle left traverse karo
        
        int rightSum = 0, rightCount = 0;
        solve(node->right, rightSum, rightCount);  // fir right traverse karo
        
        // Ab current subtree ka total sum aur count nikalo
        sum = leftSum + rightSum + node->val;
        count = leftCount + rightCount + 1;
        
        // Average nikalo aur check karo
        int average = sum / count;
        if (average == node->val) {
            result++;
        }
    }
    
    int averageOfSubtree(TreeNode* root) {
        int totalSum = 0, totalCount = 0;
        solve(root, totalSum, totalCount);
        return result;
    }
};