/* 
 * Enunciado: 
 *  Desenvolva um programa capaz de ler uma string digitada pelo usuário e,
 *  a seguir, exiba essa string invertida.
 *
 *  Exemplo:
 *    Digite uma string: ola
 *    alo
 *
 */

#include <stdio.h>
#include <string.h>

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int main (int argc, char *argv[])
{
    char str_1[MAX], str_inv[MAX];
  printf("Digite uma string: ");
  fgets(str_1,MAX,stdin);
  for(int i = 0; i<strlen(str_1);i++){
    str_inv[strlen(str_1)-i-1]=str_1[i];
  }
  printf("%s",str_inv);
  return 0;
}
