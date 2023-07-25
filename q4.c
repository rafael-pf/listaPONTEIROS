#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    int tam=0, i=0;
    char string[100];
    char **p;
    char **pAux;

    printf("Digite as palavras: \n");
    while(scanf(" %s", string)!=EOF){
        pAux = p;
        p = (char **) realloc(pAux, (tam+1)* sizeof(char *));
        if(p==NULL){
            printf("Problema de alocacao!\n");
            free(p);
            exit(1);
        }
        p[tam] = (char *) malloc((strlen(string)+1) * sizeof(char));
        strcpy(p[tam++], string);
    }

    printf("Palavras armazenadas: \n");

    for(i=0; i<tam; i++){
        printf("\t-%s\n", p[i]);
    }

    for(i=0; i<tam; i++){
        free(p[i]);
    }
    free(p);
    
    
    return 0;
}
