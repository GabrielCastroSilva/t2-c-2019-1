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

Tree* listaArvores;
int tamListaArvores = 0;


void insereListaArvores(Tree arv) {
    listaArvores[tamListaArvores++] = arv;
}

int freqs[256];


int comparator(const void* b1, const void* b2){
    Tree *a = (Tree *) b1;
    Tree *b = (Tree *) b2;
   return b->b - a->b;
}



Tree* createTree(){return NULL;}
int treeIsEmpty(Tree* t){return t == NULL;}

void insertTree(Tree** t, int c, char d){

  if(*t == NULL){
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->left = NULL;
    (*t)->right = NULL;
    (*t)->a = d;
    (*t)->b = c;
  } else {
      return;
  }
}

void showTree(Tree* arv)
{
if (arv == NULL) return;

    showTree(arv->left);
    printf("{%d,%c}", arv->b, arv->a);
    showTree(arv->right);
}

Tree* pesquisar(Tree* arv, int val) {
    if ( arv ==NULL) return NULL;

    if ( arv->b == val)
        return arv;
    else if ( arv->b > val)
            return pesquisar(arv->left, val);
         else
            return pesquisar(arv->right, val);
}

void mostrar(Tree* arv) {
    if (arv == NULL) return;

    printf("(#{%d,%c}", arv->b, arv->a);
    mostrar(arv->left);
    mostrar(arv->right);
    printf(")");

}



void insereArvoreArray(Tree arv, int e, Tree* listadeArvores) {
    listadeArvores[e] = arv;
}

void arrayIntoTree(){
    int e = sizeof(listaArvores);
    Tree* lista = malloc(sizeof(Tree)*256);
    Tree* t = createTree();
    lista = listaArvores;
    while(e != 0){
        if(lista[e].b <= lista[e-1].b){
            Tree* v = createTree();
            int z = lista[e].b + lista[e-1].b;
            insertTree(&v, z, 'Z');
            insertTree(&(*v).left, lista[e-1].b, lista[e-1].a);
            insertTree(&(*v).right, lista[e].b, lista[e].a);
            mostrar(v);
            printf("\n");
            e -= 1;
            insereArvoreArray(*v,e,lista);
        }
        if(lista[e].b > lista[e-1].b){
            Tree* v = createTree();
            int z = lista[e].b + lista[e-1].b;
            insertTree(&v, z, 'Z');
            insertTree(&(*v).left, lista[e].b, lista[e].a);
            insertTree(&(*v).right, lista[e-1].b, lista[e-1].a);
            mostrar(v);
            printf("\n");
            e -= 1;
            insereArvoreArray(*v,e,lista);
        }
    }
}



int main()
{
    /*Leitura de Arquivo*/

    listaArvores = malloc(sizeof(Tree)*256);
    tamListaArvores = 0;

    FILE* arq = fopen("teste.txt", "r");
    if(arq == NULL) {
        printf("Erro! Arquivo nao encontrado!\n");
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
              Tree *arv = malloc(sizeof(Tree));
              arv->a = i;
              arv->b = freqs[i];
              arv->left = NULL;
              arv->right = NULL;
              printf("freq(%c): %d\n", i, freqs[i]);
              insereListaArvores(*arv);
        }
    }

    printf("lista arvores nao ordenado...\n");
    for(int i=0;i<tamListaArvores;i++) {
         printf("(%c:%d) ", listaArvores[i].a, listaArvores[i].b);
    }
    printf("size: %d\n", tamListaArvores);

    qsort(listaArvores, tamListaArvores, sizeof(Tree ), comparator);

    printf("\nOrdenado...\n");
    for(int i=0;i<tamListaArvores;i++) {
         printf("(%c:%d)", listaArvores[i].a, listaArvores[i].b);
    }
    printf("\n");

    arrayIntoTree();

    return 0;
}

