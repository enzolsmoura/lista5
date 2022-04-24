/* 
 * Enunciado: 
 * Desenvolva um programa capaz de ler uma string digitada pelo usuário e, 
 * a seguir, implemente a estratégia de criptografia ZENIT - POLAR.
 * A estratégia em questão consiste em substituir os caracteres da string 
 * da seguinte maneira:
 *
 *            Z <-> P 
 *            E <-> O
 *            N <-> L
 *            I <-> A
 *            T <-> R
 *
 * O programa deve desconsiderar a diferença entre letras maíusculas e
 * letras minúsculas.
 *
 * Exemplos:
 *
 *   Digite uma string: polar
 *   zenit
 *
 *   Digite uma string: zenit
 *   polar
 *
 *   Digite uma string: ZeNit
 *   polar
 *   
 *   Digite uma string: seu ou, e ratataci!
 *   sou eu, o tiririca!
 */

#include <stdio.h>
#include <string.h> 
#include <ctype.h> // Aqui existe a função tolower. Busque documentação.

#define MAX 100 // Valor máximo para o tamanho do array. Não modifique.

/* Protótipos */

int zenit_polar (char string[MAX],int ind);

int main (int argc, char *argv[])
{
  char str[MAX];
  int ind;
  printf("Digite uma string: ");
  fgets(str,MAX,stdin);
  for(ind=0;ind<strlen(str);ind++){
    zenit_polar(str,ind);
  }
  printf("%s",str);
  return 0;
}

int zenit_polar (char string[MAX],int ind){
  if(tolower(string[ind])=='z'){
    string[ind]='p';
    return 0;
  }
  if(tolower(string[ind])=='e'){
    string[ind]='o';
    return 0;
  }
  if(tolower(string[ind])=='n'){
    string[ind]='l';
    return 0;
  }
  if(tolower(string[ind])=='i'){
    string[ind]='a';
    return 0;
  }
  if(tolower(string[ind])=='t'){
    string[ind]='r';
    return 0;
  }
  if(tolower(string[ind])=='p'){
    string[ind]='z';
    return 0;
  }
  if(tolower(string[ind])=='o'){
    string[ind]='e';
    return 0;
  }
  if(tolower(string[ind])=='l'){
    string[ind]='n';
    return 0;
  }
  if(tolower(string[ind])=='a'){
    string[ind]='i';
    return 0;
  }
  if(tolower(string[ind])=='r'){
    string[ind]='t';
    return 0;
  }
  return 0;
}