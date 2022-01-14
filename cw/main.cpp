#include <iostream>
#include <cstring>
#define N 11

using namespace std;

class Elem{
public:
   string key[10];
   int value[10];
   Elem* next;
   Elem* pred;

   void start(){
   for (int i = 0; i < 10; i++){
           key[i] = "NULL";
   }
   }

 };

void print(Elem hash[N]){
    cout << "------------------------------------\n";
    for (int i = 0; i<N; i++){
            cout<<i<<" - ";
            int j =0;
            while (hash[i].key[j]!="NULL"){
            cout<<hash[i].key[j];
            if (hash[i].key[j+1]!="NULL")
                cout<<" -> ";
            j++;
            }
            cout<<"\n";
    }
    cout << "------------------------------------\n";
}

int func(string s){
    int i = 0;
    int res = 0;
    while (s[i]!='\0'){
        res = (int)s[i]+res;
        i++;
    }
    res = res % N;
    return res;
}

void insert(Elem hash[N]){
    cout << "Введите элемент для вставки: ";
    string find_key;
    cin >> find_key;
    int f = func(find_key);
    int j = 0;
    int check = 0;
    while (hash[f].key[j]!="NULL"){
        if (hash[f].key[j]==find_key)
            check = 1;
        j++;
    }
    if (check==0){
        hash[f].key[j] = find_key;
        cout<<"Новая хэш-таблица:\n";
    }
    else {
        cout<<"Такой элемент уже есть в таблице!\n (Таблица будет выведена без измемений)\n";
    }
    print(hash);
}

void deletion(Elem hash[N]){
    cout << "Введите элемент для исключения: ";
    string find_key;
    cin >> find_key;
    int f = func(find_key);
    int j = 0;
    int E = -1;
    while (hash[f].key[j]!="NULL"){
        if (hash[f].key[j]==find_key)
            E=j;
        j++;
    }
    if (E<0)
        cout << "Такого элемента в таблице нет! Удалять нечего!\n (Таблица будет выведена без измемений)\n";
    else {
        if (hash[f].key[E+1]=="NULL")
            hash[f].key[E] = "NULL";
        else{
            while(hash[f].key[E]!="NULL"){
                hash[f].key[E] = hash[f].key[E+1];
                E++;
            }
            cout<<"Новая хэш-таблица:\n";
        }
    }

    print(hash);
}

int main()
{
    Elem hash[N];
    int i = 0;
    for(i = 0; i<N; i++){
        hash[i].start();
    }
    string s;
    i =0;
    cin>>s;
    int j = 0;
    while(s != "!"){
        i = func(s);
        j = 0;
        if (hash[i].key[j]=="NULL"){
            hash[i].key[j] = s;
        }
        else{
            while (hash[i].key[j]!="NULL")
                j++;
            hash[i].key[j] = s;
        }
        cin>>s;

    }
    cout << "\n";

    print(hash);
    insert(hash);
    deletion(hash);
    return 0;
}
