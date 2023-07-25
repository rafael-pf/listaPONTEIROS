#include <stdio.h>
#include <string.h>
int main( )
{
    char str[50]; // String
    char str_inv[50]; // String invertida
    char *ptr_str = str;
    char *ptr_inv = str_inv;
    int i=-1;
    scanf(" %s", str);
    
    *(str-1)='\0';

    for(i=0; i<50; i++){
        *(str_inv+i)='\0';
    }
    for(i=0; i<50; i++){
        if(*(str+i)=='\0'){
            ptr_inv = &*(str+i-1);
            i=50;
        }
    }
    
    for(i=0; i<50; i++){
        *(str_inv+i) = *(ptr_inv-i);
        if(*(ptr_inv-i)=='\0'){
            i=50;
        }
    }

    printf(" O inverso da string : %s\n\n",str_inv);
    return 0;
}
