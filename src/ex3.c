/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, solicite ao usuário que digite um caractere a ser buscado na
 * string digitada. O programa deve informar ao usuário se o caractere foi
 * encontrado ou não. O programa deve desconsiderar a difereça entre maíusculas
 * e minúsculas. Utilize o algoritmo de busca que achar melhor.
 *
 * Exemplos:
 *
 *   Digite uma string: teste!
 *   Digite a chave: !
 *   Caractere ! encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: M
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: m
 *   Caractere m encontrado na posição 5.
 *
 *   Digite uma string: Ola, Mundo!
 *   Digite a chave: b
 *   Caractere b não foi encontrado.
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int busca_linear(char string[MAX], int tam_string, char chave);

int main (int argc, char *argv[])
{
  char str_1[MAX], chave;
  int a;
  printf("Digite uma string: ");
  fgets(str_1,MAX,stdin);
  setbuf(stdin, 0);
  printf("Digite uma chave: ");
  scanf("%c",&chave);
  a = busca_linear(str_1,strlen(str_1),chave);
  if(a==-1){
    printf("Caractere %c não foi encontrado.",chave);
    return 0;
  }
  printf("Caractere %c encontrado na posição %i",chave,a);
  return 0;
}

int busca_linear(char string[MAX], int tam_string, char chave) {
  int i;
  for(i=0;i<tam_string;i++){
    if(tolower(chave)==tolower(string[i])){
      return i;
    }
  }
  return -1;
}