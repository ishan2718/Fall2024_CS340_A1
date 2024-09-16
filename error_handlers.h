#ifndef ERRORHANDLERS_H
#define ERRORHANDLERS_H
#pragma once
#include <iostream>
using namespace std;

// To check if the input characters are valid
bool check_char_validity(string exp)
{
    string valid_chars = "1234567890+-*/^() ";
    for (int i = 0; i < exp.length(); i++)
    {
        if (valid_chars.find(exp[i]) == string::npos)
        {
            return 0;
        }
    }
    return 1;
}

// To check if the number of opening and closing brackets
// are equal for an infix input
bool equal_brackets(string exp)
{
    int open_brackets = 0;
    int close_brackets = 0;
    size_t pos = 0;
    while (pos = exp.find("(", pos) != string::npos)
    {
        open_brackets++;
        pos++;
    }
    pos = 0;
    while (pos = exp.find(")", pos) != string::npos)
    {
        close_brackets++;
        pos++;
    }
    return (open_brackets == close_brackets);
}

// master function to run all the error handler
// functions at once
bool check_input_validity(string exp)
{
    return (check_char_validity(exp) && equal_brackets(exp));
}

#endif