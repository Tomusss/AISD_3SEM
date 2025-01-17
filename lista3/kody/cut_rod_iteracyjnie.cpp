#include <iostream>

using namespace std;

int inf = 2147483647;

void ext_bot_up_cut_rod(float P[],float R[],int S[], int n){
    R[0] = 0;
    for(int j = 1;j<=n;j++){
        float q = -inf;
        for (int i = 1;i<=j;i++){
            if(q<P[i-1]+ R[j-i]){
                q = P[i-1] + R[j-i];
                S[j] = i;
            }
        }
        R[j]=q;
    }
}
void print_solution(int S[], float R[],int n){
    while(n>0){
        cout<<S[n]<<", ";
        n-=S[n];
    }
}

int main(){
    int n = 8;
    float a[] = {1, 5, 8, 9, 10, 18.22, 18, 20};
    int s[9] = {0};
    float r[9] = {0};
    ext_bot_up_cut_rod(a,r,s,8);
    
    cout << endl <<r[n] << endl;

    print_solution(s,r,8);
    return 0;
}
