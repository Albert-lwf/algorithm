#include <iostream>
#include <vector>
#include "editor/cn/[26]删除排序数组中的重复项.cpp"

using namespace std;

template<class TV>
void print(vector<TV> v) {
    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}

template<class T>
void print(T v){
    cout << v << endl;
}

void print(){
    cout << "Hello, World!" << endl;
}

int main() {
    print(result());
    return 0;
}