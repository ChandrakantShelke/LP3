#include<iostream>
using namespace std;

int recursiveCalls = 0; // Counter for recursive calls
int iterativeSteps = 0; // Counter for iterative steps


// Recursive Fibonacci
int fibonacci(int num) {
	recursiveCalls++; 
    if(num == 0) {
        return 0;
    }
    if(num == 1) {
        return 1;
    }
    return fibonacci(num - 1) + fibonacci(num - 2);
}

//Iterative Fibonacci
int fibonacci2(int num) {
	
    if(num == 0) return 0;
    if(num == 1) return 1;
    
    int a = 0, b = 1, next;
    for(int i = 2; i <= num; i++) {
    	iterativeSteps++;
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

int main() {
	
    int n = 0;
    
    cout << "Enter the number of terms for the Fibonacci series: ";
    cin >> n;
    
    cout << "Fibonacci Series (recursion): " << endl;
    for(int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    
    cout << "Fibonacci Series (non-recursive): " << endl;
    for(int i = 0; i < n; i++) {
        cout << fibonacci2(i) << " ";
    }
    cout << endl;
    
    cout<<"Recursive Steps : "<<recursiveCalls<<endl; 
    cout<<"Iterative Steps : "<<iterativeSteps<<endl;
    
    return 0;
}

