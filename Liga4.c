#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "jogo.h"



int main() {
   int tema;

   srand(time(NULL));
   printf("Bem vindo ao Liga4!\n");
   printf("O jogo consiste em alinhar 4 peças na horizontal, vertical ou diagonal para vencer.\n");
   while(1){
   printf("Escolha o tema do jogo:\n1 - Individual(Player contra o computador)\n2 - Dois players\n3 - Simulado(computador contra computador)\n4 - Sair\n");
   scanf("%d", &tema);

   int tabuleiro[6][7] = {0};

    Ficha jogador1, jogador2;
    jogador1.id = 1;
    jogador2.id = 2;
    jogador1.quantidade_de_fichas = 0;
    jogador2.quantidade_de_fichas = 0;

     // Logica para o tema individual
    if (tema == 1){
        
        printf("Tema Individual selecionado.\n");
        printf("Iniciando o jogo Player vs Computador...\n");
        printf("O jogador 1 será você e o jogador 2 será o computador.\n");
        printf("Digite seu nome: ");
        scanf("%s", jogador1.user);
        strcpy(jogador2.user, "Computador");

        while(1){

            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
            int coluna, inteiro;
            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador1.user);
            
            do{
                inteiro = scanf("%d", &coluna);
                if(Inteiro(inteiro)){
                    printf("Digite um valor inteiro.\n");
                }
                else if(!jogar(tabuleiro, coluna, &jogador1)){
                printf("Coluna inválida ou cheia. Tente novamente.\n");
                }
                else{
                    break;
                }
            } while(1);
            
            jogador1.quantidade_de_fichas++;

            //Logica para verificar vitória do player 1
            if (verificarVitoria(tabuleiro, jogador1.id) == jogador1.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("Parabéns %s! Você venceu!\n\n", jogador1.user);
                printf("Fichas utilizadas: %d\n\n", jogador1.quantidade_de_fichas);
                break;
            }
            //Logica para verificar empate
            if (verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }

            // Logica da jogada do computador
            int colunaComputador;
            do{
            colunaComputador = (rand() % 7) + 1;
            } while(!jogar(tabuleiro, colunaComputador, &jogador2));

            jogador2.quantidade_de_fichas++;

            if (verificarVitoria(tabuleiro, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro,jogador1.id, jogador2.id);
                printf("O %s venceu! Tente novamente.\n", jogador2.user);
                printf("Fichas utilizadas: %d\n\n", jogador2.quantidade_de_fichas);
                break;
            }
        }


        // Lógica para o tema dois players
    } else if (tema == 2){
        printf("Tema Dois players selecionado.\n");

        printf("Iniciando o jogo Player vs Player...\n");
        printf("Digite o nome do jogador 1: ");
        scanf("%s", jogador1.user);
        printf("Digite o nome do jogador 2: ");
        scanf("%s", jogador2.user);

        while(1){
            
            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
            int coluna, inteiro, fichaip;

            //Logica para usar outras fichas do jogador 1
            printf("Escolha qual ficha vai usar:\n");
            printf("1.Comum 2.Portal 3.Explosiva\n");
            scanf("%d", &jogador1.tipo_de_ficha);

            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador1.user);

            do{
            inteiro = scanf("%d", &coluna);
            if(Inteiro(inteiro)){
                printf("Digite um valor Inteiro.\n");
            }
            else if(!jogar(tabuleiro, coluna, &jogador1)){
                printf("\nColuna inválida ou cheia. Tente novamente.\n");
            }

            else { break;}
            } while(1);

            jogador1.quantidade_de_fichas++;

            if (verificarVitoria(tabuleiro, jogador1.id) == jogador1.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("%s, Você venceu!\n\n", jogador1.user);
                printf("Fichas utilizadas: %d\n\n", jogador1.quantidade_de_fichas);
                break;
            }

            if(verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }

            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
            //Logica para usar outras fichas do jogador 2
            printf("Escolha qual ficha vai usar:\n");
            printf("1.Comum 2.Portal 3.Explosiva\n");
            scanf("%d", &jogador2.tipo_de_ficha);

            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador2.user);
            do{
            inteiro = scanf("%d", &coluna);
                if (Inteiro(inteiro)){
                    printf("Digite um valor inteiro.\n");
                }
                else if(!jogar(tabuleiro, coluna, &jogador2)){
                printf("\nColuna inválida ou cheia. Tente novamente.\n");
                }
                else{
                    break;
                }
            } while(1);
            

            jogador2.quantidade_de_fichas++;

             if (verificarVitoria(tabuleiro, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("%s, Você venceu!\n", jogador2.user);
                printf("Fichas utilizadas: %d\n\n", jogador2.quantidade_de_fichas);
                break;
            }

            if (verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }
        }   
    } 
    else if (tema == 3){
        printf("Tema Simulado selecionado.\n");
        printf("Inciando Computador1 vs Computador2...\n");
        strcpy(jogador1.user, "Computador");
        strcpy(jogador2.user, "Komputer");

        while(1){
            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
            int coluna_Computador, coluna;

            do{
            coluna_Computador = (rand() % 7) + 1;
            } while(!jogar(tabuleiro, coluna_Computador, &jogador1));

            jogador1.quantidade_de_fichas++;
            if(verificarVitoria(tabuleiro, jogador1.id) == jogador1.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("%s, Você Venceu!\n\n", jogador1.user);
                printf("Fichas utilizadas: %d\n\n", jogador1.quantidade_de_fichas);
                break;
            }
            
            if(verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("Empate!. O tabuleiro está cheio.\n");
                break;
            }
            
            exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
            do{
            coluna = (rand() % 7) + 1;
            } while(!jogar(tabuleiro, coluna, &jogador2));
            

            jogador2.quantidade_de_fichas++;

            if(verificarVitoria(tabuleiro, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("%s, Você Venceu!\n", jogador2.user);
                printf("Fichas utilizadas: %d\n\n", jogador2.quantidade_de_fichas);
                break;
            }
            
            if(verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro, jogador1.id, jogador2.id);
                printf("Empate!. O tabuleiro está cheio.\n");
                break;
            }

        }
    }  
    else if (tema == 4){
        printf("Encerrando o jogo.\n");
        break;
    }

        }
   return 0;
}