#include <iostream>
using namespace std;
struct Node{
    int data;
    Node *next = nullptr;
    Node *prev = nullptr;
};
struct ListaEnlazada{
    int size=0;
    Node *head = nullptr;
    Node *tail = nullptr;
};
void pushBack(ListaEnlazada *L,int x) 
{
	if(L->head == nullptr){ // si la lista es vacia
        Node *_new = new Node();
        _new->data = x;
        _new->next = nullptr;
        L->size=1;
        L->head = _new;
        L->tail = _new;
}else {
	Node * aux = L->head;
    Node * aux2 = L->tail;
        while(aux->next!=nullptr){
            aux=aux->next;
   }
   aux->next= new Node();
   
   aux->next->data = x;
   aux2->next->prev = aux;
   L->tail = aux->next;
   

   L->size++;
}

}
void sortedInsert(ListaEnlazada *L,int x){//Complejidad de N^2
    if(L->head == nullptr){ // si la lista es vacia
        Node *_new = new Node();
        _new->data = x;
        _new->next = nullptr;
        L->head = _new;
}else {
    Node * actual = L->head;
    for(int i = 0;i<L->size;i++){
        if(x<=actual->data){
            Node *tmp = new Node();
            tmp->data = x;
            L->head = tmp;
            tmp->next =actual;
            break;
    }
    else if (actual->next!=nullptr){
    if (x>=actual->data&&x<=actual->next->data){
        Node * tmp = new Node();
        tmp->data = x;
        Node * tmp2 = actual->next;
        actual->next = tmp;
        tmp->next = tmp2;
        break;

    }
    }
    
    else {
        Node* temp = new Node();
        temp->data = x;
        actual->next = temp;
    }
    actual = actual->next;

}
 
}
L->size++;

}

void MostrarLista(ListaEnlazada L){
    Node * aux = L.head;
    while(aux!=nullptr){
        cout<<aux->data<<"->";
        aux = aux->next;
    }
    cout<<endl;

}
int Minimun(ListaEnlazada L){
    Node * aux = L.head;
    int menor=L.head->data;
    if(aux->next==nullptr){
        return aux->data;
    }else{
        while(aux->next!=nullptr){
            if(aux->data<=menor){
                menor = aux->data;
            }
            aux = aux->next;
        }
    }
    return menor; 
}
void Insertk(ListaEnlazada *L , int x , int pos){

    Node * actual = L->head;
    int i = 0;
    if(L->head == nullptr){ // si la lista es vacia
        Node *_new = new Node();
        _new->data = x;
        _new->next = nullptr;

        L->head = _new;
    }else if (pos==0){
                Node * aux = new Node();
                aux->data = x;
                L->head = aux;
                aux->next = actual;
                
            }
    else{
        while(actual->next!=nullptr){
            if(pos-1==i){
                Node * aux = new Node();
                Node * aux2 = actual->next;
                aux->data = x;
                actual->next = aux;
                aux->next = aux2;
            }
            ++i;
            actual = actual->next;
        }
        L->size++;


    }
}
bool Ordenado(ListaEnlazada L){
    bool ordenado;
    if(L.head==nullptr){
        cout<<"Lista Vacia"<<endl;
    }
    else if(L.head->next==nullptr){
        cout<<"Sola hay un elemento en la lista"<<endl;
    }
    else {
        while(L.head->next!=nullptr){
            if(L.head->data<L.head->next->data){
                ordenado = true;
            }else{
                ordenado = false;
                break;
            }
            L.head = L.head->next;
        }
    }
    return ordenado;
}
bool IsElement(ListaEnlazada L , int x){
    Node * actual = L.head;
    bool IsElement;
    if(actual==nullptr){
        cout<<"Lista Vacia"<<endl;
    }else{
        while (actual->next!=nullptr){
            if(actual->data==x){
                
                IsElement = true;
                break;
            }else {
                IsElement = false;
        }
        actual = actual->next;
    }
    }
    return IsElement;
}
void ReverseList(ListaEnlazada *L){

    Node * actual = L->head;
    Node * tmp =0;
    Node * aux=0;
    while ( actual!=nullptr){
        tmp = actual->next;
        actual->next= aux;
        aux= actual;
        actual= tmp;
    }
        L->head = aux;
    
}
ListaEnlazada Union(ListaEnlazada L1,ListaEnlazada L2){
    Node* actual = L1.head;
    ListaEnlazada L3;
    
    Node * aux = L3.head;
    Node*temp = actual;
    while(actual!=nullptr){
        pushBack(&L3,actual->data);
        actual = actual->next;
    }
    Node * actual2 = L2.head;

    while(actual2!=nullptr){
        pushBack(&L3,actual2->data);
        actual2 = actual2->next;
    }
    return L3;
}
void InsertTail(ListaEnlazada *L,int x){
    if(L->head == nullptr){ // si la lista es vacia
        Node *_new = new Node();
        _new->data = x;
        _new->next = nullptr;
        L->size=1;
        L->head = _new;
        L->tail = _new;
    }
    else{
        Node *aux = new Node();
        aux->data = x;
        aux->prev = L->tail;
        L->tail = aux; 
        aux->prev->next = L->tail;
        
       L->size++;
    }
}
int main(){
    ListaEnlazada L;
    ListaEnlazada L2;
    ListaEnlazada L4;
    pushBack(&L,12);
    pushBack(&L,13);
    pushBack(&L,-5);
    pushBack(&L,14);
    MostrarLista(L);
    pushBack(&L2,20);
    pushBack(&L2,21);
    pushBack(&L2,2);
    MostrarLista(L);
    cout<< "El menor numero de la lista es "<<Minimun(L)<<endl;
    if(Ordenado(L)==true){
        cout<<"La lista esta ordenada"<<endl;
    }else{
        cout<<"La lista no esta ordenada"<<endl;
    }
    if(IsElement(L,-5)==true){
        cout<<"El elemento se encuentra en la lista"<<endl;
    }else{
        cout<<"El elemento no se encuentra en la lista"<<endl;
    }
    ReverseList(&L);
    MostrarLista(L);
    MostrarLista(L2);
    ListaEnlazada L3 = Union(L,L2);
    cout<< "LA union de la lista 1 y 2 es:"<<endl;
    MostrarLista(L3);
    
    sortedInsert(&L4,5);
    sortedInsert(&L4,1);
    
    sortedInsert(&L4,-20);
    MostrarLista(L4);
    cout<<L2.tail->data<<"->"<<L2.tail->prev->data<<"->"<<L2.tail->prev->prev->data<<endl;
    InsertTail(&L2,5);
    MostrarLista(L2);
    cout<<L2.tail->data<<"->"<<L2.tail->prev->data<<"->"<<L2.tail->prev->prev->data<<endl;
}