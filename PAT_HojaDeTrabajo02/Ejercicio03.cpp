#include "Ejercicio03.h"
#include <stack>
#include <cctype>
using namespace std;

int Ejercicio03::calculate(string s)
{
    if (s.empty()) 
    {
        return 0;
    }

    stack<int> operandStack;
    char currentOperator = '+';

    for (size_t i = 0; i < s.length(); i++) 
    {
        if (s[i] == ' ') 
        {
            continue;
        } else if (isdigit(s[i]))
        {
            string numberStr = "";
            while (isdigit(s[i])) 
            {
                numberStr += s[i];
                i++;
            }
            i--;

            int number = stoi(numberStr);

            if (currentOperator == '+') 
            {
                operandStack.push(number);
            } else if (currentOperator == '-')
            {
                operandStack.push(-number);
            } else if (currentOperator == '*')
            {
                int previousOperand = operandStack.top();
                operandStack.pop();
                operandStack.push(previousOperand * number);
            } else if (currentOperator == '/')
            {
                int previousOperand = operandStack.top();
                operandStack.pop();
                operandStack.push(previousOperand / number);
            }
        } else 
        {
            currentOperator = s[i];
        }
    }

    int result = 0;
    while (!operandStack.empty()) 
    {
        result += operandStack.top();
        operandStack.pop();
    }

    return result;
}
