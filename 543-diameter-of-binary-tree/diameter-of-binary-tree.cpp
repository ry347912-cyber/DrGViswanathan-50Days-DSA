class Solution {
public:
    int diameter = 0;
     
    int solve(TreeNode* root){
       if (root == nullptr)
            return 0;
         
        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);

        diameter = max(diameter, leftHeight + rightHeight);

        return 1 + max(leftHeight, rightHeight);
       } 
       int diameterOfBinaryTree(TreeNode* root){
          solve(root);
          return diameter;
       }
    
};