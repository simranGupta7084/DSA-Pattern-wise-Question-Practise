class Solution {
    using Key = tuple<int, int, int>;

    map<Key, int> ids;
    int nextId;

    int getId(TreeNode* root) {
        if (!root) return 0;

        int l = getId(root->left);
        int r = getId(root->right);

        if (l > r) swap(l, r);

        Key key = {root->val, l, r};

        if (ids.count(key))
            return ids[key];

        return ids[key] = nextId++;
    }

public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        ids.clear();
        nextId = 1;

        return getId(root1) == getId(root2);
    }
};