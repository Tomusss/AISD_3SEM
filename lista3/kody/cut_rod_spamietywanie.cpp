#include <iostream>

using namespace std;

int inf = 2147483647;

float memorized_cut_rod(float P[], float R[],int S[],int n){
    if (R[n-1]>=0){
        return R[n-1];
    }
    float q;
    if (n==0){
        q = 0;
    }else{
        q = -inf;
        for(int i=1;i<=n;i++){
            float aktualny = P[i-1] + memorized_cut_rod(P,R,S,n-i);
            if(aktualny>q){
                S[n-1]=i;
                q = aktualny;
            }
            
        }
    }
    R[n-1] = q;
    return q;
}

void print_solution(int S[],int n){
    while(n>0){
        cout<<S[n-1]<<", ";
        n-=S[n-1];
    }
}

int main(){
    float a[] = {1, 5, 8, 9, 10, 18.22, 18, 20};
    float r[] = {-1,-1,-1,-1,-1,-1,-1,-1};
    int s[8] = {0};
    cout <<endl<< memorized_cut_rod(a,r,s,8)<<endl;
    print_solution(s,8);
    return 0;
}