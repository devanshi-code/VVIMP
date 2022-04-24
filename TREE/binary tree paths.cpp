class Solution {
public:
    void rootToLeaf(TreeNode* root,string current,vector<string>&answer)
    {    
        if(root == NULL) return;
        if(root->left==NULL && root->right==NULL)
        {   current+=to_string(root->val);
            answer.push_back(current);
            return;
        }
        string curr=to_string(root->val)+"->";
        if(root->left!=NULL)
            rootToLeaf(root->left,current+curr,answer);
        if(root->right!=NULL)
            rootToLeaf(root->right,current+curr,answer);
        return;
    }    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>answer;
        rootToLeaf(root,"",answer);
        return answer;
    }
};