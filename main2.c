/* www.GeeksBR.com */

/* Implementação de árvore binária */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>




typedef struct tree
{
  char a;
  int b;
  struct tree* right;
  struct tree* left;
} Tree;

Tree* listaArvores[256];
int tamListaArvores = 0;




void insereListaArvores(Tree *arv) {
    listaArvores[tamListaArvores++] = arv;


}

int freqs[256];













void main()
{
    /*Leitura de Arquivo*/

    FILE* arq = fopen("teste.txt", "r");
    if(arq == NULL) {
        printf("Erro! Arquivo não encontrado!\n");
        exit(EXIT_FAILURE);
    }
    // Leitura
    char c;

    char frase [100];
    char letra;
    for (int i = 0; i<256; i++) freqs[i]=0;
    while(fgets(frase, 200, arq) != NULL)
        printf("%s\n", frase);
    fclose(arq); //Fecha o arquivo

    for(int x=0; frase[x] != '\0'; x++)
    {
        freqs[frase[x]]++;
    }

    for(int i=0;i<256;i++) {
        if (freqs[i]) {
              printf("<%c: %d>\n", i, freqs[i]);
              Tree *arv = malloc(sizeof(Tree));
              arv->a = i;
              arv->b = freqs[i];
              arv->left = NULL;
              arv->right = NULL;
              insereListaArvores(arv);
        }
    }
    //quicksort(listaArvores, 256);
}
