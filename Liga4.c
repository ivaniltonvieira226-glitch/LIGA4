#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int id;
    char tipo[100], user[100];
} Ficha;

int main() {
   int tabuleiro[7][6] = {0};
   int tema;
   
   printf("Jogo iniciado!\n");
   printf("Escolha o tema do jogo:\n1 - Individual\n2 - Dois players \n");
   scanf("%d", &tema);



   
    
   return 0;
}