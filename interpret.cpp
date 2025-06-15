// needs extensive thought and fixing
#include<iostream>
// #include<conio.h>
#include<any>
#include<queue>
#include<math.h>
#include<string.h>
#include<unordered_map>
using namespace std;


class Node
{
    public:
    string id;
    string val;
    Node* func;
    Node* condition;
    Node* expr;

    Node(string val, string id)
    {
        this->id = id;
        this->val = val;
        this->func = NULL;
        this->condition = NULL;
        this->expr = NULL;
    }
};

class parse
{
    private : 
    unordered_map<string, string> keywords = {
        {"is?" , "DECISION"},
        {"zip" , "LOOP"},
    };

    // public : 

};


// int main()
// {
//     Interpret i;
//     queue<pair<string , string>> eval;
//     eval.push(pair("25", "INT"));
//     eval.push(pair("*", "MUL"));
//     eval.push(pair("50", "INT"));
//     eval.push(pair("+", "ADD"));
//     eval.push(pair("60", "INT"));
//     eval.push(pair("+", "ADD"));
//     eval.push(pair("70", "INT"));

//     i.calc(eval);
// }
