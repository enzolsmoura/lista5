/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma lista de nomes separados por vírgula
 * digitados por um usuário e, a seguir, armazená-los em um array de strings.
 * O array deve ser ordenado alfabéticamente e, a seguir, exibido utilizando o 
 * procedimento exibe_nomes fornecido. A quantidade de nomes digitado deve ser 
 * sempre 5 (definido por MAX_NOMES). O programa deve desconsiderar a diferença 
 * entre letras maiúsculas e minúsculas.
 *
 * Dica: pesquise pela função strtok
 *
 * Exemplo (**CUIDADO COM O ESPAÇO APÓS A VÍRGULA**):
 *
 *   Nomes: Julio,Tiririca,Diego,Alexandre,Nicola
 *   ['alexandre', 'diego', 'julio', 'nicola', 'tiririca']
 *
 *   Nomes: Matheus,Ana Julia,Marco Antonio,Joao,Victoria
 *   ['ana julia', 'joao', 'marco antonio', 'matheus', 'victoria']
 *
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h> 

#define MAX_NOMES 5 // Valor máximo para o tamanho do array. Não modifique.
#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */
void exibe_nomes(char nomes[MAX_NOMES][MAX]);

void bubble_sort(char nomes[MAX_NOMES][MAX], int tam_array);

void lower(char nomes[MAX_NOMES][MAX]);

void troca_elementos(char nomes[MAX_NOMES][MAX], int i, int j);

int main (int argc, char *argv[])
{
  char string[MAX], nomes[MAX_NOMES][MAX], *nome;
  int i = 0;
  printf("Nomes: ");
  fgets(string,MAX,stdin);
  if(string[strlen(string)-1]=='\n'){
    string[strlen(string)-1]='\0';
  }
  nome = strtok(string,",");
  while(nome!=NULL){
    for(int j=0;j<=strlen(nome);j++){
      nomes[i][j] = nome[j]; 
    }
    nome = strtok(NULL,",");
    i++;
  }
  lower(nomes);

  bubble_sort(nomes,sizeof(nomes)/sizeof(nomes[0]));

  exibe_nomes(nomes);
  return 0;
}


void troca_elementos(char nomes[MAX_NOMES][MAX], int i, int j) {
  char aux[MAX];
  strcpy(aux, nomes[i]);
  strcpy(nomes[i], nomes[j]);
  strcpy(nomes[j], aux);

}

void bubble_sort(char nomes[MAX_NOMES][MAX], int tam_array) {
  int n,k;
  for(n=0;n<tam_array;n++){
    for(k=0;k<tam_array-1-n;k++){
      if(strcmp(nomes[k],nomes[k+1])>0){
        troca_elementos(nomes,k,k+1);
      }
    }
  }
 
}

void lower(char nomes[MAX_NOMES][MAX]){
  for(int i=0;i<MAX_NOMES;i++){
    for(int j=0;j<MAX;j++){
      nomes[i][j] = tolower(nomes[i][j]);
    }
  }
}

void exibe_nomes(char nomes[MAX_NOMES][MAX]) {
  printf("[");
  for(int i = 0; i < MAX_NOMES; ++i) {
    printf("'%s'", nomes[i]);
    if( i != MAX_NOMES - 1 ) printf(", ");
  }
  printf("]\n");
}

