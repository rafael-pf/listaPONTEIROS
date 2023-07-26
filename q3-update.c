#include <stdio.h>
#include <string.h>
int main(){
    char str[50]; // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i=-1;
    scanf(" %s", str);
    
    *(ptr_str-1)='\0';

    for(i=0; i<50; i++){
        *(ptr_inv+i)='\0';
    }

    i=0;
    do{
        ptr_str=&*(ptr_str+1);
    }while(*(ptr_str+1)!='\0');

    i=0;
    do{
        *(ptr_inv+i)=*(ptr_str-i);
        i++;
    }while(*(ptr_str-i)!='\0');
    

    printf(" O inverso da string : %s\n\n",str_inv);
    return 0;
}
