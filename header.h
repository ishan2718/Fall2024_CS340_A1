#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include "error_handlers.h"
using namespace std;

int precedence(string op)
{
    if (op == "^")
    {
        return 3;
    }
    else if (op == "*" || op == "/")
    {
        return 2;
    }
    else if (op == "+" || op == "-")
    {
        return 1;
    }
    return -1;
}

vector<string> string_to_list(string s)
{
    vector<string> result;
    string vector_element = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            vector_element += s[i];
        }
        else
        {
            result.push_back(vector_element);
            vector_element = "";
        }
    }
    result.push_back(vector_element);
    return result;
}

string infix_to_postfix(string exp)
{
    vector<string> exp_list = string_to_list(exp);
    stack<string> st;
    string postfix = "";
    for (int i = 0; i < exp_list.size(); i++)
    {
        try
        {
            int operand = stoi(exp_list[i]);
            postfix += exp_list[i] + " ";
        }
        catch (const invalid_argument &e)
        {
            if (exp_list[i] == "(")
            {
                st.push(exp_list[i]);
            }
            else if (exp_list[i] == ")")
            {
                while (!st.empty() && st.top() != "(")
                {
                    postfix += st.top() + " ";
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && (precedence(st.top()) >= precedence(exp_list[i])))
                {
                    postfix += st.top() + " ";
                    st.pop();
                }
                st.push(exp_list[i]);
            }
        }
    }
    while (!st.empty())
    {
        postfix += st.top() + " ";
        st.pop();
    }
    string result = postfix.substr(0, postfix.length() - 1);
    return result;
}

string infix_to_prefix(string exp)
{
    vector<string> exp_list = string_to_list(exp);
    stack<string> st;
    string prefix = "";
    for (int i = exp_list.size() - 1; i >= 0; i--)
    {
        try
        {
            int operand = stoi(exp_list[i]);
            prefix += exp_list[i] + " ";
        }
        catch (const invalid_argument &e)
        {
            if (exp_list[i] == ")")
            {
                st.push(exp_list[i]);
            }
            else if (exp_list[i] == "(")
            {
                while (!st.empty() && st.top() != ")")
                {
                    prefix += st.top() + " ";
                    st.pop();
                }
                if (!st.empty())
                {
                    st.pop();
                }
            }
            else
            {
                while (!st.empty() && (precedence(st.top()) > precedence(exp_list[i])))
                {
                    prefix += st.top() + " ";
                    st.pop();
                }
                st.push(exp_list[i]);
            }
        }
    }
    while (!st.empty())
    {
        prefix += st.top() + " ";
        st.pop();
    }
    string result = prefix.substr(0, prefix.length() - 1);
    string reverse_result(result.rbegin(), result.rend());
    return reverse_result;
}

string postfix_to_infix(string exp)
{
    vector<string> exp_list = string_to_list(exp);
    stack<string> st;
    string infix = "";
    for (int i = 0; i < exp_list.size(); i++)
    {
        try
        {
            int operand = stoi(exp_list[i]);
            st.push(exp_list[i]);
        }
        catch (const invalid_argument &e)
        {
            string first_operand = st.top();
            st.pop();
            string second_operand = st.top();
            st.pop();
            string temp = first_operand + " " + exp_list[i] + " " + second_operand;
            st.push(temp);
        }
    }
    string result = st.top();
    st.pop();
    string reverse_result(result.rbegin(), result.rend());
    return reverse_result;
}