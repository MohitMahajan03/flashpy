//BUILD a custom print method for all files
#include <iostream>
// #include <conio.h>
#include "lex.cpp"
#include "infi.cpp"
#include "exp_syntree.cpp"
#include "interpret.cpp"
#include <vector>
#include <queue>

using namespace std;

vector<pair<string, string>> vec;
float result;

int main()
{
    Lexer lex;
    Convert grammar;
    Syntax_Expr expr_syn_tree;
    Interpret_Expr interpret;

    string text;
    while(1)
    {
        vec.clear();
        cout<<"flashpy > ";
        getline(cin, text);
        if(text == "exit")
            exit(0);
        vec = lex.tokenize(text);
        vec = grammar.postfix(vec);
        expr_syn_tree.syntree(vec);
        
    }
    return 0;
}
