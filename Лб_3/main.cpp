#include <iostream>
#include <cstring>
#define N 11

using namespace std;

class Elem{
public:
   string key[10];
   int value[10];
   Elem* next;

   void start(){
   for (int i = 0; i < 10; i++){
           key[i] = "NULL";
   }
   }

 };

int print(Elem hash[N]){
    for (int i = 0; i<N; i++){
        if (hash[i].key[0]!="NULL"){
            cout<<i<<" - ";
            int j =0;
            while (hash[i].key[j]!="NULL"){
            cout<<hash[i].key[j]<<"  ";
            j++;
            }
            cout<<"\n";
        }
    }
    cout << "\n";
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

void find(Elem hash[N]){
    int find = 1;
    while(find){
    cout << "Введите элемент для поиска?   ";
    string find_key;
    cin >> find_key;
    int f = func(find_key);
    int count = 0;
    int j = 0;
    while (hash[f].key[j]!="NULL"){
        if(hash[f].key[j]==find_key)
            count++;
        j++;
    }
    cout << "\n";
    if(j ==0 )
        cout << "Такого элемента нет!\n";
    else
        cout << "Да, такой элемент есть! В количестве: " << count <<"\n";
    hash[f].key[j] = find_key;
    print(hash);
    cout << "Найти еще элемент? Если да - нажмите 1, если нет - 0\n";
    cin >> find;
    }
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
    find(hash);
    return 0;
}
