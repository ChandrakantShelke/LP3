//#include<iostream>
//using namespace std;
//
//// Recursive Fibonacci
//int fibonacci(int num) {
//    if(num == 0) {
//        return 0;
//    }
//    if(num == 1) {
//        return 1;
//    }
//    return fibonacci(num - 1) + fibonacci(num - 2);
//}
//
//// Non-recursive Fibonacci
//int fibonacci2(int num) {
//    if(num == 0) return 0;
//    if(num == 1) return 1;
//    
//    int a = 0, b = 1, next;
//    for(int i = 2; i <= num; i++) {
//        next = a + b;
//        a = b;
//        b = next;
//    }
//    return b;
//}
//
//int main() {
//    int n = 0;
//    char choice;
//    
//    while(true) {
//        cout << "Do you want the Fibonacci Series? (y/n): ";
//        cin >> choice;
//        
//        if(choice == 'y' || choice == 'Y') {
//            cout << "Enter the number of terms for the Fibonacci series: ";
//            cin >> n;
//            
//            cout << "Fibonacci Series (recursion): "<<endl;
//            for(int i = 0; i < n; i++) {
//                cout << fibonacci(i) << " ";
//            }
//            cout << endl;
//            
//            cout << "Fibonacci Series (non-recursive): "<<endl;
//            for(int i = 0; i < n; i++) {
//                cout << fibonacci2(i) << " ";
//            }
//            cout << endl;
//            
//        } 
//		else {
//            cout << "Thank you...!!!" << endl;
//            break;
//        }
//    }
//    
//    return 0;
//}

#include<iostream>
using namespace std;

// Recursive Fibonacci
int fibonacci(int num) {
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
    
    return 0;
}

