#include <iostream>

using namespace std;

template<class T>
void Print(T *arr, int n) //вывод массива
{
    cout << "Готовый массив: \n";
    for(int i = 0 ;i < n ;i++)
    {
        cout << arr[i] << ' ';
    }
    cout << "\n";
}

template<class T>
void Qsort_v(T *arr, int begin, int finish, int n)    //соритруем массив по возрастанию
{
    int i=begin+1; //счетчик для элементов
    int ind_1 = begin;  //опорный элемента

     while (i<=finish){
        if (arr[i]<arr[ind_1]){                   //группа 1, если текущий элемент меньше опорного
            if(ind_1+1==i)
                swap(arr[i],arr[ind_1++]);
            else
            {
                swap(arr[ind_1+1],arr[ind_1]);
                swap(arr[i],arr[ind_1]);
                ind_1++;
            }
        }
        i++;
    }

     int j = 0;
     i=ind_1+1; //счетчик для элементов
     while (i<=finish){
        if (arr[i]==arr[ind_1]){                  //группа 2, если текущий элемент равен опорному
            if(ind_1+1==i)
                swap(arr[i],arr[ind_1++]);
            else
            {
                swap(arr[ind_1+1],arr[ind_1]);
                swap(arr[i],arr[ind_1]);
                ind_1++;
            }
            j++;
        }
        i++;
    }

                                             //остальные элементы попадут в 3 группу - больше опорного


     for (int j = 0; j<n;j++){    //вывод промежуточного результата
        cout << arr[j] << ' ';
     }
     cout << "\n";


    if (begin<ind_1-j-1)  //если левее опорного элемента есть что-то
        Qsort_v(arr, begin , ind_1-j-1, n);//для левого массива
    if (ind_1+1<finish) //если правее опорного элемента есть что-то
        Qsort_v(arr, ind_1+1, finish, n);//для правого массива
}

template<class T>
void Qsort_u(T *arr, int begin, int finish, int n)    //соритруем массив по убыванию
{
    int i=begin+1; //счетчик для элементов
    int ind_1 = begin;  //опорный элемента

     while (i<=finish){
        if (arr[i]>arr[ind_1]){                  //группа 1, если текущий элемент больше опорного
            if(ind_1+1==i)
                swap(arr[i],arr[ind_1++]);
            else
            {
                swap(arr[ind_1+1],arr[ind_1]);
                swap(arr[i],arr[ind_1]);
                ind_1++;
            }
        }
        i++;
    }

     int j = 0;
     i=ind_1+1; //счетчик для элементов
     while (i<=finish){
        if (arr[i]==arr[ind_1]){                  //группа 2, если текущий элемент равен опорному
            if(ind_1+1==i)
                swap(arr[i],arr[ind_1++]);
            else
            {
                swap(arr[ind_1+1],arr[ind_1]);
                swap(arr[i],arr[ind_1]);
                ind_1++;
            }
            j++;
        }
        i++;
    }

                                                 //остальные элементы попадут в 3 группу - меньше опорного


     for (int j = 0; j<n;j++){    //вывод промежуточного результата
        cout << arr[j] << ' ';
     }
     cout << "\n";

    if (begin<ind_1-j-1)  //если левее опорного элемента есть что-то
        Qsort_u(arr, begin , ind_1-j-1, n);//для левого массива
    if (ind_1+1<finish) //если правее опорного элемента есть что-то
        Qsort_u(arr, ind_1+1, finish, n);//для правого массива
}

template<class T>
void swap(T& a,T&b) //функция для перестановки двух элементов
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int n ;
    cout<<"Введите количество элементов в массиве:";
    cin >> n;
    int arr[n];
    cout<<"Введите массив:";
    for (int i = 0 ; i<n;i++)
        cin>>arr[i];//ввод массива
    cout<<"Для сортировки по возрастанию выберите 1, а по убыванию - 2\n";
    int chouse;
    cin>>chouse;
    switch (chouse){
        case 1:{
            Qsort_v(arr,0,n-1, n);
            break;
            }
        case 2:{
            Qsort_u(arr,0,n-1, n);
            break;
        }
        default:{
            cout<<"Тип сортировки выбран неверно! Массив отсортирован не будет!\n";
            break;
         }
    }
    Print(arr,n);
}
