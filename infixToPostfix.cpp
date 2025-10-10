#include <bits/stdc++.h>
using namespace std;

int precedence(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

vector<string> infixToPostfix(string s, unordered_map<char,int>& vars){
    stack<char> st; vector<string> out;
    for(char c: s){
        if(isalpha(c)) out.push_back(to_string(vars[c]));
        else if(isdigit(c)) out.push_back(string(1,c));
        else if(c=='(') st.push(c);
        else if(c==')'){
            while(!st.empty() && st.top()!='('){
                out.push_back(string(1,st.top())); st.pop();
            }
            st.pop();
        }
        else {
            while(!st.empty() && precedence(st.top())>=precedence(c)){
                out.push_back(string(1,st.top())); st.pop();
            }
            st.push(c);
        }
    }
    while(!st.empty()){
        out.push_back(string(1,st.top())); st.pop();
    }
    return out;
}

int evalPostfix(vector<string>& exp){
    stack<int> st;
    for(auto &t: exp){
        if(isdigit(t[0])) st.push(stoi(t));
        else if(t.size()>1 || isdigit(t[0])) st.push(stoi(t));
        else {
            int b=st.top(); st.pop();
            int a=st.top(); st.pop();
            if(t=="+") st.push(a+b);
            else if(t=="-") st.push(a-b);
            else if(t=="*") st.push(a*b);
            else if(t=="/") st.push(a/b);
        }
    }
    return st.top();
}

int main(){
    unordered_map<char,int> vars={{'x',5},{'y',3}};
    string expr="(x+2)*y";
    auto postfix=infixToPostfix(expr,vars);
    cout<<evalPostfix(postfix)<<endl;
}
