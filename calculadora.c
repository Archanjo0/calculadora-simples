#include <stdio.h>
#include <ctype.h>
#include <string.h>

void limparbuffer(void) {

  char c;

  while ((c = getchar()) != '\n' && c != EOF);
  if (c == EOF) {
    clearerr(stdin);
  }
}

void opcoes(void) {
  printf("(+)soma  (-)subtracao\n(/)divisao  (*)multiplicacao\n");
}

char operacao(void) {
  char escolha;
  printf("escolha uma das opcoes:\n");
  opcoes();
  escolha = getchar();
  limparbuffer();
  if (isalpha(escolha) || isdigit(escolha)) {
    printf("voce digitou um caractere invalido!\n");
    return operacao();
  }else {
    return escolha;
  }
}

void coleta (double *numeros) {
  double num1;
  double num2;
  printf("digite o primeiro elemento: ");
  scanf(" %lf", &num1);
  limparbuffer();
  printf("digite o sugundo elemento: ");
  scanf(" %lf", &num2);
  limparbuffer();
  numeros[0] = num1;
  numeros[1] = num2;
}

void mensagem (void) {
  char aviso[28+1];
  snprintf(aviso, sizeof(aviso), "nao e possivel dividir por 0");
  printf("%s\n", aviso);
}

double execucao(char simbolo, double *numeros) {
  double num1 = numeros[0];
  double num2 = numeros[1];
  switch (simbolo) {
    case '+':
      return num1 + num2;
    case '-':
      return num1 - num2;
    case '/':
      if (num2 == 0){
        mensagem();
       return 0;
      }else {
        return num1 / num2;
      }
    case '*':
      return num1 * num2;
    default:
      printf("operação invalida\n");
      return 0;
  }
}


int main (void) {
  
  printf("\nprograma calculadora simples\n");
  char escolha = operacao();
  double numeros[2];
  coleta(numeros);
  double resultado = execucao(escolha, numeros);
  printf("\no resultado e %.2lf\n", resultado);
  return 0;
}
