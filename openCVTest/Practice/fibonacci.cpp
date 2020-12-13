#include <stdio.h>
#include <iostream>
#include <unordered_map>
long int Fibonacci(int fib);

using namespace std;
unordered_map<int, long int> table;

int main()
{
    
    cout << Fibonacci(3) << "\n";
    cout << Fibonacci(50);
    return -1;
}
long int Fibonacci(int fib)
{
    if(table.find(fib) != table.end())
    {
        return table[fib];
    }
    if(fib <= 2)
    {
        return 1;
    }
    table[fib] = Fibonacci(fib-1) + Fibonacci(fib-2);
    return table[fib];
}