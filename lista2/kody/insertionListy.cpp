#include <iostream>
using namespace std;

struct SLel 
{
    SLel * next;
    int data;
};

int main()
{
    SLel *L;     //wskaźnik początku listy
    SLel *e,* p; //wskaźniki elementów listy
    int n=6;
    int values[] = {5, 2, 9, 1, 5, 6}; 

    L = new SLel; //pierwszy strażnik
    L->next = new SLel; //drugi strażnik
    L->next->next =NULL; 
    L->next->data =2147483647;

    //dodawanie do listy
    for (int i=0; i<n; i++) {
        int v = values[i];
        for (p=L; v> p->next->data; p = p->next)//szukanie miejsca   
            ;   
        e = new SLel; //nowy wezel
        e->data = v; 
        e->next = p->next; //wskazywanie na nastepny el
        p->next = e; //p wskazuje na nowy el
    }

    for (p = L->next; p->next; p = p->next)
        cout << p->data << " ";
    cout << endl;

    return 0;
}
