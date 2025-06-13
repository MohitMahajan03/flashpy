//'''TOKENS'''

/*
Ignore blanck spaces
add words for analysis
componentalize tokenizing for words and digits
*/
#include<iostream>
// #include<conio.h>
#include<string.h>
#include<unordered_map>
#include<vector>

using namespace std;


class Error
{
    public:

    string err(char symbol)
    {
        string error = "Unidentifiable symbol " + symbol;
        return error;
    }
};

class Lexer : public Error
{
    private:
    vector<pair<string, string>> tokens;
    unordered_map<char, string> operators = {
        {'+' , "ADD"},
        {'-' , "SUB"},
        {'*' , "MUL"},
        {'/' , "DIV"},
        {'^' , "POW"},
    };
    bool isFloat = false;

    public:

    void flush_token(string& build)
    {
        if(!build.empty())
        {
            if(isFloat == true)
                tokens.push_back(pair(build, "FLOAT"));
            else
                tokens.push_back(pair(build, "INT"));
            
            build.clear();
        }
    }

    vector<pair<string, string>> tokenize(string text)
    {
        tokens.clear();
        string digits, words;

        for(auto &sym : text)
        {
            if(isdigit(sym))
                digits += sym;
                // cout<<"digits = "<<digits<<" sym = "<<sym<<endl;

            else if(!isalnum(sym))
            {
                flush_token(digits);
                switch(sym)
                {
                    case '+': tokens.push_back(pair("+", operators[sym]));
                        break;
                    case '-': tokens.push_back(pair("-", operators[sym]));
                        break;
                    case '*': tokens.push_back(pair("*", operators[sym]));
                        break;
                    case '/': tokens.push_back(pair("/", operators[sym]));
                        break;
                    case '^': tokens.push_back(pair("^", operators[sym]));
                        break;
                    default: err(sym);
                }
            }
            if(sym == ' ')
                continue;              
            else
                err(sym);
        }
        flush_token(digits);
        cout<<"Generating tokens..."<<endl;
        for(auto &it : tokens)
            cout<<it.first<<" : "<<it.second<<" ";
        cout<<endl;  
        return tokens;
    }
};

// int main()
// {
//     Lexer l;
//     string text = "24+50*60+70";
//     vector<pair<string, string>> res;
//     res = l.tokenize(text);
//     for(auto &it : res)
//         cout<<it.first<<" : "<<it.second<<endl;
//     return 0;
// }
