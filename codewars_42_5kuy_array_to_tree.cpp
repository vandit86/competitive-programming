// https://www.codewars.com/kata/57e5a6a67fbcc9ba900021cd/train/cpp

#include <queue>

class Solution
{
  public:
    static TreeNode* arrayToTree(std::vector<int> arr) 
    {
      if (arr.size() == 0)
        return NULL; // TODO: implementation
      
      std::queue <TreeNode*> q_tree;      
      TreeNode* root = new TreeNode (arr[0]); 
      q_tree.push(root);  
      
      for (size_t i = 0; i < arr.size(); i ++){
        
        TreeNode* nxt = q_tree.front();
        q_tree.pop(); 
        
        if (2*i + 1 < arr.size()){
          nxt->m_left = new TreeNode (arr[2*i + 1]); 
          q_tree.push(nxt->m_left);
        }
        
        if (2*i + 2 < arr.size()){
          nxt->m_right = new TreeNode (arr[2*i + 2]); 
          q_tree.push(nxt->m_right);
        }        
      }
      
      return root;      
    }
};
