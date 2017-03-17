#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

/*

Implementar um analisador síntatico descendente recursivo para a gramática abaixo:

E -> +EE
E -> *EE
E -> b
E -> a

*/

char token;
void match(char tokenEsperado);

void erro();
void E();

void match(char tokenEsperado) { //consome o próprio token. Se aceito, chama o próximo 
    if (token == tokenEsperado){
        token = getchar();
    } else {
        erro();
    }
}


    


void erro() {
  printf("%s", "Erro de Sintaxe!\n");
  exit(1);
}

void E() {
   
    switch (token) {
        case '+': //match +EE em seguida
            match('+');
            match(token);
            match(token);
            break;
        case '*': //match EE em seguida
            match('*');
            match(token);
            match(token);
            break;
        case 'a':
            match('a');
            break;
        case 'b':
            match('b');
            break;
        default: 
            erro();
            break;
        
        
    }
    
    
    
    
  
}

int main(int argc, char const *argv[]) {
    printf("Insira uma cadeia: ");
    token = getchar();
    E();
  return 0;
}
