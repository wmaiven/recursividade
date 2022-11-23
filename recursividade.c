#include <malloc.h>
#include <stdio.h>

typedef struct node {
  int valor;
  struct node *prox;
} NODE;

int multiplicacaoPorSoma(int numero, int vezes);
double fatorial(int numero);
void inserirProx(NODE *inicio, int valor);
void imprimeLista(NODE *inicio);

int main(void) {
  int exercicio, aux, N, v;
  double aux2;
  printf("Escolha o exercicio: \n1 - int multiplicacaoPorSoma(int numero, int "
         "vezes)\n2 - double fatorial(int numero)\n3&4 - void inserirProx(NODE *inicio, int valor)\n");
  scanf("%d", &exercicio);

  if (exercicio == 1) {
    printf("Escolhe dois numeros:\n");
    scanf("%d %d", &N, &v);

    aux = multiplicacaoPorSoma(N, v);

    printf("Resultado: %d", aux);
  } else if (exercicio == 2) {
    printf("Qual numero deseja fatorar?\n");
    scanf("%d", &N);

    printf("%.2lf", fatorial(N));
  } else if (exercicio == 3 || exercicio == 4) {
    NODE *inicio = (NODE *)malloc(sizeof(NODE));
    inicio->valor = 1;
    inicio->prox = NULL;

    inserirProx(inicio, 2);
    printf("Primeiro valor: %d\n", inicio->prox->valor);
    inserirProx(inicio, 3);
    printf("Segundo valor: %d\n", inicio->prox->prox->valor);
    printf("Primeiro valor: %d\n", inicio->prox->valor);

    imprimeLista(inicio);
  }else{
    printf(":/");
  }
  return 0;
}

// Att 1
int multiplicacaoPorSoma(int numero, int vezes) {
  if (vezes == 0)
    return vezes;
  else {
    vezes--;
    numero += multiplicacaoPorSoma(numero, vezes);

    return numero;
  }
}

// Att 2
double fatorial(int numero) {
  double resultado = 1;

  if (numero <= 1)
    return (1);
  else {
    while (numero > 1) {
      resultado *= numero;
      numero--;
    }
    return resultado;
  }
}

// Att 3
void inserirProx(NODE *inicio, int valor) {
  if (inicio->prox == NULL) {
    NODE *novo = (NODE *)malloc(sizeof(NODE));
    novo->valor = valor;
    novo->prox = NULL;

    inicio->prox = novo;
    return;
  }

  inserirProx(inicio->prox, valor);
}

//Att 4
void imprimeLista(NODE *inicio) {
  if(inicio != NULL){
    printf("Valor: %d\n", inicio->valor);
    imprimeLista(inicio->prox);
  }
  return;
}