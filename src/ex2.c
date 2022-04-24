/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, informe-o se o valor digitado se trata de um palíndromo ou não.
 * O programa deve descosiderar diferença entre maíusculas e minúsculas.
 *
 * Exemplos:
 *
 *  Digite uma string: racecar
 *  É palíndromo
 *
 *  Digite uma string: oi
 *  Não é palíndromo
 *
 *  Digite uma string: RaceCar
 *  É palíndromo
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

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

  for(int i=0;i<strlen(str_1)-1;i++){
    if(tolower(str_inv[i+1])!=tolower(str_1[i])){
      printf("Não é palíndromo");
      return 0;
    }
  }
  printf("É palíndromo");
  return 0;
}
