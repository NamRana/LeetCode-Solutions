class Solution {
    map<int, map<int, multiset<int>>> mp;
    vector< vector<int> > result;
public:
    void vot(TreeNode* root, int row, int col) {
        if(root == NULL)
            return;
        mp[col][row].insert(root->val);
        vot(root->left, row + 1, col - 1);
        vot(root->right, row + 1, col + 1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vot(root, 0, 0);
        
        for(auto &i : mp) {
            vector<int> temp;
            for(auto &j: i.second) {
                temp.insert(temp.end(), j.second.begin(), j.second.end() );
            }
            result.emplace_back(temp);
        }

        return result;
    }
};