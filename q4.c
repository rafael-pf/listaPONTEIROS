#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int tam=0, i=0;
    char string[50];
    char **p;
    char *pAux;


    while(scanf(" %s", string)!=EOF){
        p = (char **) malloc((tam+1) * strlen(string) * sizeof(char *));
        *p = string;
        pAux = *p;
        if(p!=NULL){
            p[tam++] = realloc(pAux, (tam+1) * strlen(string) * sizeof(char));
            p[tam++] = string;
            for(i=0; i<tam; i++){
                printf("%s\n", *p[i]);        
            }
        }
    }
    free(p);



    return 0;
}
