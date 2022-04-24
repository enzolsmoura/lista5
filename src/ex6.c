/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler duas palavras digitadas pelo usuário e,
 * a seguir, deve informá-lo se as palavras formam um anagrama. O programa deve
 * desconsiderar a diferença entre letras maíusculas e letras minúsculas.
 *
 * Exemplos:
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robed
 * bored é anagrama de robed
 *
 * Digite uma palavra: bored
 * Digite uma palavra: robbed
 * bored não é anagrama de robbed
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: oii
 * ooi não é anagrama de oii
 *
 * Digite uma palavra: ooi
 * Digite uma palavra: ioo
 * ooi é anagrama de ioo
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int main (int argc, char *argv[])
{
  char str_1[MAX], str_2[MAX];
  int count_1[MAX],count_2[MAX];
  printf("Digite uma palavra: ");
  fgets(str_1,MAX,stdin);
  if(str_1[strlen(str_1)-1]=='\n'){
    str_1[strlen(str_1)-1]='\0';
  }
  setbuf(stdin,0);
  printf("Digite uma palavra: ");
  fgets(str_2,MAX,stdin);
  if(str_2[strlen(str_2)-1]=='\n'){
    str_2[strlen(str_2)-1]='\0';
  }
  if(strlen(str_1)!=strlen(str_2)){
    printf("%s não é anagrama de %s.",str_1,str_2);
    return 0;
  }
  for(int i=0;i<strlen(str_1);i++){
    int counter = 0;
    for(int j=0;j<strlen(str_1);j++){
      if(tolower(str_1[j])==tolower(str_1[i])){
        counter++;
      }
    }
    count_1[i]=counter;
  }
  for(int i=0;i<strlen(str_2);i++){
    int counter = 0;
    for(int j=0;j<strlen(str_2);j++){
      if(tolower(str_2[j])==tolower(str_2[i])){
        counter++;
      }
    }
    count_2[i]=counter;
  }
  for(int i=0;i<strlen(str_1);i++){
    if(count_1[i]!=count_2[i]){
      printf("%s não é anagrama de %s",str_1,str_2);
      return 0;
    }
  }
  printf("%s é anagrama de %s",str_1,str_2);
  return 0;
}
