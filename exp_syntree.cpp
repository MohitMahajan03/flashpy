#include<iostream>
// #include<conio.h>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
#include<math.h>

using namespace std;

class Node
{
    public:
    string id;
    string val;
    Node* left;
    Node* right;

    Node(string val, string id)
    {
        this->id = id;
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node* root = NULL;

class Interpret_Expr
{
    float acc, buff;
    string operation;
    void wipe(queue<pair<string, string>> que)
    {
        while(!que.empty())
            que.pop();
    }
    public:
    bool is_float = false;
    float calc(Node* root)
    {
        if (root == NULL) 
            return 0; 
    
        // leaf node i.e, an integer 
        if (root->left == NULL && root->right == NULL)
        {
            if(root->id == "FLOAT")
            {
                is_float = true;
                return stof(root->val);
            }
            if(root->id == "INT")
                return stoi(root->val);
        } 
    
        // Evaluate left subtree 
        float l_val = calc(root->left); 
    
        // Evaluate right subtree 
        float r_val = calc(root->right); 
    
        // Check which operator to apply 
        if (root->id == "ADD")
            return l_val+r_val; 
    
        else if (root->id == "SUB") 
            return l_val-r_val; 
    
        else if (root->id == "MUL")
            return l_val*r_val; 
    
        else if (root->id == "DIV")
            return l_val/r_val;

        else if (root->id == "POW")
            return pow(l_val ,r_val);

        else
        {
            cout<<root->id<<" Error occured: unidentified operation"<<endl;
            return 0;
        } 
    }
};


class Syntax_Expr : public Interpret_Expr
{

    private:
    vector<pair<string, string>> final_exp;
    Node* op_node = NULL;
    Node* num_node = NULL;
    stack<Node*> nums;
    void inorder(Node* root)
    {
        if(root == NULL)
            return;
        cout<<"(";
        inorder(root->left);
        cout<<root->val;
        final_exp.push_back(pair(root->val, root->id));
        inorder(root->right);
        cout<<")";
    }
    
    void destroy(Node* root)
    {
        if(root == NULL)
            return;
        destroy(root->left);
        destroy(root->right);
        delete(root);
    }

    void wipe(stack<Node*> stacks)
    {
        while(!stacks.empty())
            stacks.pop();
    }

    public:

    Node* syntree(vector<pair<string, string>> exp)
    {
        root = NULL;
        wipe(nums);
        final_exp.clear();
        Node* sub2 = NULL;
        Node* sub1 = NULL;
        for (auto& it : exp)
        {
            if(it.second == "INT" || it.second == "FLOAT")
            {
                num_node = new Node(it.first, it.second);
                nums.push(num_node);
            }
            else
            {
                op_node = new Node(it.first, it.second);
                sub2 = nums.top();
                nums.pop();
                sub1 = nums.top();
                nums.pop();
                op_node->left = sub1;
                op_node->right = sub2;
                nums.push(op_node);
                sub1 = NULL;
                sub2 = NULL;
            }
        }
        root = nums.top();
        nums.pop();
        cout<<"Creating Syntax Tree..."<<endl;
        inorder(root);
        cout<<endl;
        cout<<"Evaluating Expression"<<endl;
        cout<<calc(root)<<endl;
        destroy(root);
        return root;
    }
};

// int main()
// {
//     vector<pair<string, string>> exp = {
//         {"25", "INT"},
//         {"50", "INT"},
//         {"60", "INT"},
//         {"*", "MUL"},
//         {"+", "ADD"},
//         {"70", "INT"},
//         {"+", "ADD"},
//     };
//     Syntax s;
//     s.syntree(exp);
//     cout<<"All fine"<<endl;
//     s.inorder(root);
//     return 0;
// }
