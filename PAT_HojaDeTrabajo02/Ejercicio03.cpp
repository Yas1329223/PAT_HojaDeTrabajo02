#include "Ejercicio03.h"

int Ejercicio03::calculate(string s)
{
    stack<int> operands;
    int num = 0;
    char op = '+';

    for (char c : s)
    {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
        }
        else if (c != ' ')
        {
            if (op == '+') 
            {
                operands.push(num);
            } else if (op == '-') 
            {
                operands.push(-num);
            } else if (op == '*')
            {
                int prev = operands.top();
                operands.pop();
                operands.push(prev * num);
            } else if (op == '/') 
            {
                int prev = operands.top();
                operands.pop();
                operands.push(prev / num);
            }

            op = c;
            num = 0;
        }
    }

    int result = 0;
    while (!operands.empty())
    {
        result += operands.top();
        operands.pop();
    }

    return result;
}
