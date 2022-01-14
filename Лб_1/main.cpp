#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int Rec(char a[20]){
    char a1[20];
    char a2[20];
    int i = 0;
    int j = 0;
    int ki = 0;
    int ko = 0;
    if (strcmp(a, "A") == 0 || strcmp(a, "B") == 0)
       return 1;
    //считаем длину    
    int len = 0;
    while (a[len]!='\0')
        len++;
    if (a[0]=='(' && a[len-1] == ')'&& len>3){
        //удаляем скобки
        for (i = 0; i<len-1; i++){
            a[i] = a[i+1];
        }
        a[len-2] = '\0';
        i=0;
        //рассматриваем случай 1 вида:(A B) или (A (A B))
        if ((a[0]!='(' && a[len-3]!=')') || (a[0]!='(' && a[len-3]==')')){
        	while (a[i]!=' '){
        	a1[i] = a[i];
        	i++;
        	}
        	a1[i] = '\0';
        	i++;
     		while (a[i]!= '\0'){
     	    	a2[j] = a[i];
       	    	j++;
       	    	i++;
        	}
        	a2[j] = '\0';
        return Rec(a1)*Rec(a2);
        }
        //рассмотрим случай 2 вида: ((A B) A)
        if (a[0]=='(' && a[len-3]!=')'){
			for (i=0; i<len-4; i++){
				a1[i]=a[i];
			}
        a1[i] = '\0';
        a2[0] = a[i+1];
        a2[1] = '\0';
        return Rec(a1)*Rec(a2);
		}
        //рассмотрим случай 3 вида: ((A B) (A B))
		if (a[0]=='(' && a[len-3]==')'){
			i = 0;
			while(a[i]!=')'){
				if (a[i]=='(')
					ki++;
            	i++;
			}
			i = 0;
            while (ko!=ki){
				a1[i] = a[i];
				if (a[i]==')')
					ko++;
				i++;
            }
			a1[i] = '\0';
			i++;
			j = 0;
			while (a[i]!='\0'){
				a2[j] = a[i];
				j++;
				i++;
			}
			a2[j] = '\0';
			return Rec(a1)*Rec(a2);
		}
    }
    return 0;
}

int main(){
    cout << "Введите строку" << "\n";
    char a[20];
    int i = 0;
    a[0] = getchar();
    while (a[i]!='\n'){
        i++;
        a[i] = getchar();
    }
    a[i] = '\0';
    int rezult;
    rezult = Rec(a);
    if (rezult==1)  
        cout << "True" << "\n";
    else
        cout << "False" << "\n";
    return 0;
}
