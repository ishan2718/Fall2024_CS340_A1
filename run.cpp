#include <iostream>
#include "header.h"
using namespace std;

int main()
{
    cout << infix_to_prefix("( 4 + 8 ) * ( 6 - 5 ) / ( 3 - 2 ) * ( 2 + 2 )") << endl;
    return 0;
}