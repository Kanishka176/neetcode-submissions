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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        vector<string> data;
        dfsSe(root, data);
        return join(data, ",");
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals= split(data, ',');
        int i=0;
        return dfsDe(vals,i);
    }

private:
    void dfsSe(TreeNode* node, vector<string>& data){
        if(!node){
            data.push_back("N");
            return;
        }
        data.push_back(to_string(node->val));
        dfsSe(node->left, data);
        dfsSe(node->right, data);
    }

    TreeNode* dfsDe(vector<string>& data, int& i){
        if(data[i]=="N"){
            i++;
            return nullptr;
        }
        TreeNode* node= new TreeNode(stoi(data[i]));
        i++;

        node->left= dfsDe(data, i);
        node->right= dfsDe(data, i);
        return node;
    }

    vector<string> split(const string &s, const char &delim){
        vector<string> el;
        stringstream ss(s);
        string item;
        while(getline(ss, item, delim)){
            el.push_back(item);
        }
        return el;
    }

    string join(const vector<string> &v, const string &delim){
        ostringstream s;
        for(const auto &i : v){
            if(&i!=&v[0])
                s<< delim;
                s<<i;}
            
            return s.str();
        
    }
};