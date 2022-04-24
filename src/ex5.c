/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma palavra digitada pelo usuário e,
 * a seguir, deve exibir uma string contendo os caracteres da palavra digitada
 * em ordem alfabética. Utilize o algoritmo de ordenação que preferir.
 * O programa deve desconsiderar a diferença entre letras maíusculas e 
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma palavra: ola
 *   alo
 *
 *   Digite uma palavra: alo
 *   alo
 *
 *   Digite uma palavra: RaceCar
 *   aaccerr
 *
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

void quicksort(char string[MAX], int tam_vetor, int comeco, int fim);

int particiona(char string[MAX], int comeco, int fim);

void troca_elementos(char string[MAX], int i, int j);

int main (int argc, char *argv[])
{
  char string[MAX];
  printf("Digite uma palavra: ");
  fgets(string,MAX,stdin);
  quicksort(string,strlen(string),0,strlen(string)-1);
  printf("%s",string);
  return 0;
}

void quicksort(char string[MAX], int tam_string, int comeco, int fim) {
  int j;
  if(comeco<fim){
    
    j = particiona(string,comeco,fim);

    quicksort(string,tam_string,comeco,j-1);
    quicksort(string,tam_string,j+1,fim);
  }
}

int particiona(char string[MAX], int comeco, int fim) {
  int pivo,i,j;
  pivo = (comeco+fim)/2;
  troca_elementos(string,pivo,fim);
  j = comeco;
  for(i=comeco;i<fim;i++){
    if(tolower(string[i])<=tolower(string[fim])){
      troca_elementos(string,i,j);
      j++;
    }
  }
  troca_elementos(string,j,fim);
  return j;
}

void troca_elementos(char string[MAX], int i, int j) {
  int aux;
  aux = tolower(string[i]);
  string[i] = tolower(string[j]);
  string[j] = aux;
}