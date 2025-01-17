#include <iostream>

using namespace std;

int inf = 2147483647;

float maximum(float a, float b){
    if(a>b){
        return a;
    }else{
        return b;
    }
}

float cut_rod(float P[],int n){
    if (n == 0){
        return 0;
    }
    float q = -inf;
    for(int i=1;i<=n;i++){
        q = maximum(q,P[i-1] + cut_rod(P, n-i));
    }
    return q;
}

int main(){
    float a[] = {1, 5, 8, 9, 10, 18.22, 18, 20};

    cout <<endl<< cut_rod(a,8);

}