#include<iostream>
// #include<conio.h>
#include<string>
#include<stack>
#include<vector>
#include<unordered_map>

using namespace std;

stack<pair<string, string>> stacks;

class Convert
{

    private:

    void wipe(stack<pair<string, string>> stacks)
    {
        while(!stacks.empty())
            stacks.pop();
    }

    int prece(string ch)
    {
        
        for(char op : ch)
        {
            switch(op)
            {

                case '^': return 5;
                case '/': return 4;
                case '*': return 3;
                case '+': return 2;
                case '-': return 1;
            }
        }
        return 0;
    }

    public:

    vector<pair<string, string>> postfix(vector<pair<string, string>> tokens)
    {
        wipe(stacks);
        vector<pair<string, string>> exp;
        exp.clear();
        for(const auto &it : tokens)
        {
            if(it.second == "INT" || it.second == "FLOAT")
                exp.push_back(pair(it.first, it.second));
            else
            {
                int curr_opt = prece(it.first);
                if(stacks.empty())
                    stacks.push(it);
                else
                {
                    while(!stacks.empty() && prece(stacks.top().first) >= curr_opt)
                    {
                        exp.push_back(pair(stacks.top().first, stacks.top().second));
                        stacks.pop();
                    }
                    stacks.push(it);
                }
            }
        }
        while(!stacks.empty())
        {
            exp.push_back(pair(stacks.top().first, stacks.top().second));
            stacks.pop();
        }
        cout<<"After applying grammar" <<endl;
        cout<<"(";
        for(auto &it : exp)
            cout<<it.first<<" : "<<it.second<<" ";

        cout<<")"<<endl;    
        return exp;
    }
};


// int main()
// {
//     Convert c;
//     vector<pair<string, string>> tokens = {
//         {"25" , "INT"},
//         {"+" , "ADD"},
//         {"50" , "INT"},
//         {"*" , "MUL"},
//         {"60" , "INT"},
//         {"+" , "ADD"},
//         {"70" , "INT"}
//     };
//     vector<pair<string, string>>res = c.postfix(tokens);
//     for(auto &it : res)
//         cout<<it.first<<" : "<<it.second<<endl;    
//     return 0;
// }
