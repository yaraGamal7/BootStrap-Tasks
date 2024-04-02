#include <iostream>

using namespace std;
int fib(int x);

int main() {
    cout << "Fibonacci of 5 is " << fib(5) <<endl;
    return 0;
}


int fib(int x){
    if(x==0||x==1)
        return 1;
    else
        return fib(x-1)+fib(x-2);
}
