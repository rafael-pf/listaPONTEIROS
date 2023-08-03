#include <stdio.h>
#include <string.h>
int main(){
    char str[50]; // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i=-1;
    scanf(" %s", str);
    
    //alterar o endereco de memoria anterior a string para \0 (necessario para o ultimo loop)
    *(ptr_str-1)='\0';

    //zerar a str_inv
    for(i=0; i<50; i++){
        *(ptr_inv+i)='\0';
    }

    i=0;

    //procurar ultimo caractere e fazer ptr_str apontar para ele
    do{
        ptr_str=&*(ptr_str+1);
    }while(*(ptr_str+1)!='\0');

    i=0;

    //copiar caracteres de traz pra frente de *ptr_str para *ptr_inv (até achar o \0 que eu declarei no inicio)    
    do{
        *(ptr_inv+i)=*(ptr_str-i);
        i++;
    }while(*(ptr_str-i)!='\0');
    

    printf(" O inverso da string : %s\n\n",str_inv);
    return 0;
}
