#include <stdio.h>

int main(){
    int vet[5]={1,2,3,4,5};
    int i=0;
    int *p;
    p = vet;

    printf("a)\n");
    printf("\t%p\n", &vet);
    printf("\t%p\n", *&p);

    printf("b)\n");
    for(i=0; i<5; i++){
        printf("\t%d\n", p[i]);
    }
    
    printf("c)\n");
    for(i=0; i<5; i++){
        printf("\t%d\n", *(p + i));
    }
    
    printf("d)\n");
    printf("i-\n");
    for(i=0; i<5; i++){
        printf("\t%d\n", vet[i]);
    }
    printf("ii-\n");
    for(i=0; i<5; i++){
        printf("\t%d\n", *(vet + i));
    }
    



    return 0;
}
