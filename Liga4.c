#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id, quantidade_de_fichas;
    char user[100];
} Ficha;


//Função para verificar vitória

int verificarVitoria(int tabuleiro[6][7], int id1, int id2){
    // verificar horizontalmente
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id1 && tabuleiro[i][j+1] == id1 
                && tabuleiro[i][j+2] == id1 && tabuleiro[i][j+3] == id1){
                return id1;
            }
            if (tabuleiro[i][j] == id2 && tabuleiro[i][j+1] == id2 
                && tabuleiro[i][j+2] == id2 && tabuleiro[i][j+3] == id2){
                return id2;
            }
        }
        
    }

    // verificar verticalmente
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 7; j++){
            if (tabuleiro[i][j] == id1 && tabuleiro[i+1][j] == id1 
                && tabuleiro[i+2][j] == id1 && tabuleiro[i+3][j] == id1){
                return id1;
            }
            if (tabuleiro[i][j] == id2 && tabuleiro[i+1][j] == id2 
                && tabuleiro[i+2][j] == id2 && tabuleiro[i+3][j] == id2){

                return id2;
            }
        }
    }
    
    // verificar diagonal da direita
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id1 && tabuleiro[i+1][j+1] == id1 && 
                tabuleiro[i+2][j+2] == id1 && tabuleiro[i+3][j+3] == id1){
                return id1;
            }
            if (tabuleiro[i][j] == id2 && tabuleiro[i+1][j+1] == id2 && tabuleiro[i+2][j+2] == id2 
                && tabuleiro[i+3][j+3] == id2){
                return id2;
            }
        }
    }

    // verificar diagonal da esquerda
    for (int i = 3; i < 6; i++){
        for (int j = 0; j < 4; j++){
            if (tabuleiro[i][j] == id1 && tabuleiro[i-1][j+1] == id1 && tabuleiro[i-2][j+2] == id1 && tabuleiro[i-3][j+3] == id1){
                return id1;
            }
            if (tabuleiro[i][j] == id2 && tabuleiro[i-1][j+1] == id2 && tabuleiro[i-2][j+2] == id2 && tabuleiro[i-3][j+3] == id2){
                return id2;
            }
        }
    }

    return 0;
}


//função para verificar empate
int verificarEmpate(int tabuleiro[6][7]){
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 7; j++){
            if (tabuleiro[i][j] == 0){
                return 0; 
            }
        }
    }

    return 1;
}


//Função para jogar

int jogar(int tabuleiro[6][7], int coluna, int id){
    while(1){
        if (coluna < 1 || coluna > 7){
            return 0;
        }
        for (int i = 5; i >= 0; i--){
            if (tabuleiro[i][coluna-1] == 0){
                tabuleiro[i][coluna-1] = id;
                return 1;
            }
        }
        
    }

    return 0;
    
    }


    //função exibir tabuleiro
    void exibirTabuleiro(int tabuleiro[6][7]){
        printf("============LIG4++============\n");
        printf("\n");
        printf("  1   2   3   4   5   6   7  \n");
        printf("\n");
        for(int i = 0; i < 6; i++){
            printf("|");
            for(int j = 0; j < 7;j++){
                printf(" %d |",tabuleiro[i][j]);
            }
            printf("\n");
        } 
        
        printf("-----------------------------\n");
    }


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
    jogador1.quantidade_de_fichas = 21;
    jogador2.quantidade_de_fichas = 21;

     // Logica para o tema individual
    if (tema == 1){
        printf("Tema Individual selecionado.\n");
        printf("Iniciando o jogo Player vs Computador...\n");
        printf("O jogador 1 será você e o jogador 2 será o computador.\n");
        printf("Digite seu nome: ");
        scanf("%s", jogador1.user);
        strcpy(jogador2.user, "Computador");

        while(1){
            exibirTabuleiro(tabuleiro);
            int coluna;
            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador1.user);
            scanf("%d", &coluna);
            if(!jogar(tabuleiro, coluna, jogador1.id)){
                printf("Coluna inválida ou cheia. Tente novamente.\n");
                continue;
            };
            jogador1.quantidade_de_fichas--;

            //Logica para verificar vitória do player 1
            if (verificarVitoria(tabuleiro, jogador1.id, jogador2.id) == jogador1.id){
                exibirTabuleiro(tabuleiro);
                printf("Parabéns %s! Você venceu!\n\n", jogador1.user);
                break;
            }
            //Logica para verificar empate
            if (verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }

            // Logica da jogada do computador
            int coluna_computador = (rand() % 7) + 1;
            if(!jogar(tabuleiro, coluna_computador, jogador2.id)){
                continue;
            }
            jogador2.quantidade_de_fichas--;
            if (verificarVitoria(tabuleiro, jogador1.id, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro);
                printf("O %s venceu! Tente novamente.\n\n", jogador2.user);
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
            exibirTabuleiro(tabuleiro);
            int coluna;
            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador1.user);
            scanf("%d", &coluna);

            if(!jogar(tabuleiro, coluna, jogador1.id)){
                printf("Coluna inválida ou cheia. Tente novamente.\n");
                continue;
            };

            jogador1.quantidade_de_fichas--;

            if (verificarVitoria(tabuleiro, jogador1.id, jogador2.id) == jogador1.id){
                exibirTabuleiro(tabuleiro);
                printf("%s, Você venceu!\n\n", jogador1.user);
                break;
            }

            if(verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro);
                printf("Empate! O tabuleiro está cheio.\n");
                break;
            }

            exibirTabuleiro(tabuleiro);

            printf("%s, escolha uma coluna (1-7) para jogar: ", jogador2.user);
            scanf("%d", &coluna);

            if(!jogar(tabuleiro, coluna, jogador2.id)){
                printf("Coluna inválida ou cheia. Tente novamente.\n");
                continue;
            };

            jogador2.quantidade_de_fichas--;

             if (verificarVitoria(tabuleiro, jogador1.id, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro);
                printf("%s, Você venceu!\n", jogador2.user);
                break;
            }

            if (verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro);
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
            exibirTabuleiro(tabuleiro);
            int coluna_Computador, coluna;

            do{
            coluna_Computador = (rand() % 7) + 1;
            } while(!jogar(tabuleiro, coluna_Computador, jogador1.id));

            jogador1.quantidade_de_fichas--;
            if(verificarVitoria(tabuleiro, jogador1.id, jogador2.id) == jogador1.id){
                exibirTabuleiro(tabuleiro);
                printf("%s, Você Venceu!\n\n", jogador1.user);
                break;
            }
            
            if(verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro);
                printf("Empate!. O tabuleiro está cheio.\n");
                break;
            }
            
            exibirTabuleiro(tabuleiro);
            do{
            coluna = (rand() % 7) + 1;
            } while(!jogar(tabuleiro, coluna, jogador2.id));
            

            jogador2.quantidade_de_fichas--;

            if(verificarVitoria(tabuleiro, jogador1.id, jogador2.id) == jogador2.id){
                exibirTabuleiro(tabuleiro);
                printf("%s, Você Venceu!\n\n", jogador2.user);
                break;
            }
            
            if(verificarEmpate(tabuleiro)){
                exibirTabuleiro(tabuleiro);
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