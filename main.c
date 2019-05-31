/* www.GeeksBR.com */

/* Implementação de árvore binária */

#include <stdio.h>
#include <stdlib.h>




/* Cada nó armazena três informações:
   nesse caso um número (num),
   ponteiro para subárvore à direita (sad)
   e ponteiro para subárvore à esquerda (sae).*/
typedef struct tree
{
  char a;
  int b;
  struct tree* right;
  struct tree* left;
} Tree;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore */
Tree* createTree()
{
  /* Uma árvore é representada pelo endereço do nó raiz,
     essa função cria uma árvore com nenhum elemento,
     ou seja, cria uma árvore vazia, por isso retorna NULL. */
  return NULL;
}



/* Função que verifica se uma árvore é vazia */
int treeIsEmpty(Tree* t)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  return t == NULL;

}

/* Função que mostra a informação da árvore */
void showTree(Tree* t)
{
  /* Essa função imprime os elementos de forma recursiva */

  printf("(#"); /* notação para organizar na hora de mostrar os elementos */
  if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
  {
    /* Mostra os elementos em pré-ordem */
    printf("{%d,%c}", t->b, t->a); /* mostra a raiz */
    showTree(t->left); /* mostra a sae (subárvore à esquerda) */
    showTree(t->right); /* mostra a sad (subárvore à direita) */
  }
  printf(")"); /* notação para organizar na hora de mostrar os elementos */
}

/* Função que insere um dado na árvore */
void insertTree(Tree** t, int c, char d)
{
  /* Essa função insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree)); /* Aloca memória para a estrutura */
    (*t)->left = NULL; /* Subárvore à esquerda é NULL */
    (*t)->right = NULL; /* Subárvore à direita é NULL */
    (*t)->a = d; /* Armazena a informação */
    (*t)->b = c;
  } else {
    if(c < (*t)->b) /* Se o número for menor então vai pra esquerda */
    {
      /* Percorre pela subárvore à esquerda */
      insertTree(&(*t)->left, c, d);
    }
    if(c > (*t)->b) /* Se o número for maior então vai pra direita */
    {
      /* Percorre pela subárvore à direita */
      insertTree(&(*t)->right, c, d);
    }
  }
}

/* Função que verifica se um elemento pertence ou não à árvore */
int isInTree(Tree* t, int num) {

  if(treeIsEmpty(t)) { /* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  }

  /* O operador lógico || interrompe a busca quando o elemento for encontrado */
  return t->b==num || isInTree(t->left, num) || isInTree(t->right, num);
}

int main()
{
   
   /*leitura da string*/
   /*
    char frase [100];
    char letra;
    bool pode;

    for (int i = 0; i<256; i++) freqs[i]=0;
    printf("Digite uma frase:");
    scanf("%s",frase);

    for(int x=0; frase[x] != '\0'; x++)
    {
        freqs[frase[x]]++;
    }

    for(int i=0;i<256;i++) {
        if (freqs[i]) {
              printf("<%c: %d>\n", i, freqs[i]);
        }
    }  
   
   */
  Tree* t = createTree(); /* cria uma árvore */

  insertTree(&t,12,'a'); /* insere o elemento 12 na árvore */
  insertTree(&t,15,'b'); /* insere o elemento 15 na árvore */
  insertTree(&t,10,'c'); /* insere o elemento 10 na árvore */
  insertTree(&t,13,'d'); /* insere o elemento 13 na árvore */

  showTree(t); /* Mostra os elementos da árvore em pré-ordem */

  if(treeIsEmpty(t)) /* Verifica se a árvore está vazia */
  {
    printf("\n\nArvore vazia!!\n");
  } else {
    printf("\n\nArvore NAO vazia!!\n");
  }

  if(isInTree(t, 15)) { /* Verifica se o número 15 pertence a árvore */
    printf("\nO numero 15 pertence a arvore!\n");
  } else {
     printf("\nO numero 15 NAO pertence a arvore!\n");
  }

  if(isInTree(t, 22)) { /* Verifica se o número 22 pertence a árvore */
    printf("\nO numero 22 pertence a arvore!\n\n");
  } else {
     printf("\nO numero 22 NAO pertence a arvore!\n\n");
  }

  free(t); /* Libera a memória alocada pela estrutura árvore */

  return 0;
}
