#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int valor;
    char let;
    struct Node* esq;
    struct Node* dir;
};

typedef struct Node NODO;

// prototipos
void inserir(NODO** arv, int val, char c);
void mostrar(NODO* arv);
NODO* pesquisar(NODO* arv, int val);

// código

void inserir(NODO** arv, int val, char c)
{
    if ( *arv == NULL )
    {
        NODO* novo;
        novo = malloc(sizeof(NODO));
        novo->valor = val;   //(*novo).valor = val;
        novo->let = c;
        novo->esq = NULL;
        novo->dir = NULL;

        *arv = novo;
    }
    else
    {
        //if ( val < (**arv)valor)
        if ( val < (*arv)->valor)
            //inserir(&((**arv).esq),val);
            inserir(&((*arv)->esq), val, c);
        else
            inserir(& ((*arv)->dir), val, c);
    }
}

NODO* pesquisar(NODO* arv, int val)
{
    if ( arv ==NULL)
        return NULL;

    if ( arv->valor == val)
        return arv;
    else if ( arv->valor > val)
        return pesquisar(arv->esq, val);
    else
        return pesquisar(arv->dir, val);
}



void mostrar(NODO* arv)
{
    if (arv == NULL)
        return;

    printf("#(%c,%d", arv->let, arv->valor);
    mostrar(arv->esq);
    mostrar(arv->dir);
    printf(")");

}

void bubbleSort(NODO* vet[], int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (vet[j]->valor < vet[i]->valor)
            {
                NODO* aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int freqs[256];
NODO* listaArvores;


/*void insereListaArvores(NODO arv) {
    listaArvores[tamListaArvores++] = arv;
}*/


void padding ( char ch, int n )
{
    int i;

    for ( i = 0; i < n; i++ )
        putchar ( ch );
}


void printree( NODO* root, int level )  //char** table, char* binary, int column
{
    int i;
    // Change to test for leaf
    if(root == NULL)
    {
        // table[column] = &node->letter;
        // table[column+1] = binary;
        // column = column + 2;
        padding ('\t', level);
        puts ("~");
    }
    else
    {
        printree(root->dir, level + 1 );
        // RIGHT
        // strcat(binary, "1");
        // gentable(node->right, table, binary, column);
        padding('\t', level );
        printf("%c:%d\n", root->let, root->valor);
        printree(root->esq, level + 1 );
        // LEFT
        // strcat(binary, "0");
        // gentable(node->left, table, binary, column);
    }
}








int main()
{
    /*Leitura de Arquivo*/

    listaArvores = malloc(sizeof(NODO)*256);


    FILE* arq = fopen("teste.txt", "r");
    if(arq == NULL)
    {
        printf("Erro! Arquivo nao encontrado!\n");
        exit(EXIT_FAILURE);
    }
    // Leitura

    char frase [100];
    char letra;

    char c;
    int freqs[256] = {0};
    int count = 0;


    while ((c = fgetc(arq)) != EOF)
    {

        freqs[c]++;
        if(freqs[c] == 1)
        {
            count++;
        }
    }
    fclose(arq); //Fecha o arquivo



    int tamArvores = 0;
    NODO* listaArvores[] = {NULL};


    for(int i=0; i<256; i++)
    {
        if (freqs[i]>0)
        {
            inserir(&listaArvores[tamArvores], freqs[i], i);
            tamArvores++;
            printf("freq(%c): %d\n", i, freqs[i]);

        }
    }

    char letras[tamArvores];

    printf("lista arvores nao ordenado...\n");
    for(int i=0; i<tamArvores; i++)
    {
        printf("(%c:%d) ", listaArvores[i]->let, listaArvores[i]->valor);
    }
    printf("size: %d\n", tamArvores);

    bubbleSort(listaArvores,tamArvores);

    printf("\nOrdenado...\n");
    for(int i=0; i<tamArvores; i++)
    {
        printf("(%c:%d)", listaArvores[i]->let, listaArvores[i]->valor);
        letras[tamArvores - i] = listaArvores[i]->let;
    }
    printf("\n");




    //arrayIntoTree();

    for(int i = 0  ; i<tamArvores - 1  ; i++)
    {
        NODO* t = NULL;
        inserir(&t, listaArvores[tamArvores - i - 1]->valor + listaArvores[tamArvores - i - 2]->valor, 'Z' );
        t->esq = listaArvores[tamArvores - i - 1];
        t->dir = listaArvores[tamArvores - i - 2];
        listaArvores[tamArvores - i - 2] = t;
        bubbleSort(listaArvores,tamArvores);


    }
    printree(listaArvores[0],0);






    return 0;
}


