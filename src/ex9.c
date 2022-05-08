/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, ler um intervalo separado por vírgula que deve ser utilizado para
 * gerar uma substring que começa no começo do intervalo digitado e termina no 
 * índice final (intervalo fechado).
 *
 * Exemplos:
 *
 * Digite uma string: Oi, eu sou o Goku!
 * Intervalo: 0, 9
 * Oi, eu sou
 *
 * Digite uma string: 0123456789
 * Intervalo: 3,7
 * 34567
 *
 * Digite uma string: Estruturas de Dados
 * Intervalo: 3, 12
 * ruturas de
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int main (int argc, char *argv[])
{
  char str[MAX],intervalo[MAX];
  int comeco,fim;
  printf("Digite uma string: ");
  fgets(str,MAX,stdin);
  setbuf(stdin,0);
  printf("Intervalo: ");
  fgets(intervalo,MAX,stdin);
  setbuf(stdin,0);
  comeco = atoi(strtok(intervalo,","));
  fim = atoi(strtok(NULL,","));
  for(int i=comeco;i<=fim;i++){
    printf("%c",str[i]);
  }
  return 0;
}
