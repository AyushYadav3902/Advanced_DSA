// WAP in c++ to find the greater element for every element in the array using stack data structure.Th next greater 
#include <bits/stdc++.h>
#include <stack>
using namespace std;

class Stack{
    int arr[10];
    int top;
    int size;
    public:
    Stack(int n){
        size=n;
        top=-1;
    }
    void push(int n){
        ++top;
        arr[top]=n;
    }
    void pop(){
        int temp;
        temp = top;
        top--;
    }
    void find(int target){
        int temp=-1;
        do
        {
            if(top>target)
            temp=top;
            pop();
        }
        while(top!=target);
        cout<<temp;
    }
    
};

int main(){
    Stack st(10); //Use custom Stack class with size
    st.push(10);
    st.push(40);
    st.push(80);
    st.push(20);
    st.push(20);
}