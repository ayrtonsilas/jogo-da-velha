#include <iostream>

#include <cmath>

#include <inge9>

using namespace std;

int main() {
    //define a matriz para armazenar as jogadas
    int jogadas[3][3];
    //criar nome para a imagem X
    char imagemX[12] = "imagem_X";
    //criar nome para a imagem zero
    char imagemO[12] = "imagem_Zero";
    //define a seleção atual da jogada
    char imagemAtual[12] = imagemX;

    //validador de posições, para ver se usuário pode jogar naquela posição
    int verificaPosicaoJogada = 1;

    //define um numero para cada jogador
    int jogador1 = 1;
    int jogador2 = 2;
    //diz de qual vez é o jogador
    int jogadorAtual = 1;

    //inicializa a matriz que armazena as jogadas com zero
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            jogadas[i][j] = 0;
        }
    }

    //importar imagem do tabuleiro
    loadImage("tabuleiro", "https://i.ibb.co/nwRf4mx/download.png");
    //importa a imagem do X
    loadImage(imagemX, "https://i.ibb.co/BVf32tS/x.jpg");
    //importa a imagem do Z
    loadImage(imagemO, "https://i.ibb.co/vd4d0tK/zero.jpg");

    //escreve o tabuleiro na tela na posição 200 pixels horizontal e 50 pixels vertical
    drawImage("tabuleiro", 200, 50);

    //variavel para controlar se chegou no fim do game
    bool playGame = true;
    //inicia as rodadas do jogo
    while (playGame) {

        //lemos um valor do teclado
        readKey();

        //verificamos o valor digitado
        //inserimos a jogada na matriz de jogadas
        //para simbolizar o jogador 1, inserimos na matriz o numero 1
        //para simbolizar o jogador 2, inserimos na matriz o numero 2
        //dessa forma o retorno das funções de validação
        //ja vão ser o jogador vencedor
        //imprimimos o X ou 0 na tabela de acordo com o numero
        //valida se a posição pode ser escolhida
        if (isKeyDown("1")) {
            verificaPosicaoJogada = validarPosicao(jogadas[2][0]);
            if (verificaPosicaoJogada == 1) {
                jogadas[2][0] = jogadorAtual;
                drawImage(imagemAtual, 210, 210);
            }
        } else if (isKeyDown("2")) {
            verificaPosicaoJogada = validarPosicao(jogadas[2][1]);
            if (verificaPosicaoJogada == 1) {
                jogadas[2][1] = jogadorAtual;
                drawImage(imagemAtual, 290, 210);
            }
        } else if (isKeyDown("3")) {
            verificaPosicaoJogada = validarPosicao(jogadas[2][2]);
            if (verificaPosicaoJogada == 1) {
                jogadas[2][2] = jogadorAtual;
                drawImage(imagemAtual, 360, 210);
            }
        } else if (isKeyDown("4")) {
            verificaPosicaoJogada = validarPosicao(jogadas[1][0]);
            if (verificaPosicaoJogada == 1) {
                jogadas[1][0] = jogadorAtual;
                drawImage(imagemAtual, 210, 140);
            }
        } else if (isKeyDown("5")) {
            verificaPosicaoJogada = validarPosicao(jogadas[1][1]);
            if (verificaPosicaoJogada == 1) {
                jogadas[1][1] = jogadorAtual;
                drawImage(imagemAtual, 290, 140);
            }
        } else if (isKeyDown("6")) {
            verificaPosicaoJogada = validarPosicao(jogadas[1][2]);
            if (verificaPosicaoJogada == 1) {
                jogadas[1][2] = jogadorAtual;
                drawImage(imagemAtual, 360, 140);
            }
        } else if (isKeyDown("7")) {
            verificaPosicaoJogada = validarPosicao(jogadas[0][0]);
            if (verificaPosicaoJogada == 1) {
                jogadas[0][0] = jogadorAtual;
                drawImage(imagemAtual, 210, 65);
            }
        } else if (isKeyDown("8")) {
            verificaPosicaoJogada = validarPosicao(jogadas[0][1]);
            if (verificaPosicaoJogada == 1) {
                jogadas[0][1] = jogadorAtual;
                drawImage(imagemAtual, 290, 65);
            }
        } else if (isKeyDown("9")) {
            verificaPosicaoJogada = validarPosicao(jogadas[0][2]);
            if (verificaPosicaoJogada == 1) {
                jogadas[0][2] = jogadorAtual;
                drawImage(imagemAtual, 360, 65);
            }
        }

        //verifica se existe um jogador vencedor por linhas ou colunas
        int vencedorLC = validaLinhasColunas(jogadas);
        //implementar função validarDiagonais pelos alunos
        int vencedorDiagonal = validarDiagonais(jogadas);

        //verifica se o jogador vencedor é o jogador 1
        //se for ele imprimi o jogador vencedor e encerra o programa
        //a mesma coisa para o jogador 2
        if (vencedorLC == 1 || vencedorDiagonal == 1) {
            drawText("Jogador 1 Venceu", 8, 30, 22, "white");
            playGame = false;
        } else if (vencedorLC == 2 || vencedorDiagonal == 2) {
            drawText("Jogador 2 Venceu", 8, 30, 22, "white");
            playGame = false;
        }
        //alterna entre as imagens para mudar a cada rodada
        //inicialmente começamos com a imagem X
        //tambem alternamos os jogadores
        //inicialmente começamos o o jogador 1
        //valida se a posição foi preenchida
        if (verificaPosicaoJogada == 1) {
            if (imagemAtual == imagemO) {
                imagemAtual = imagemX;
                jogadorAtual = jogador1;
            } else {
                imagemAtual = imagemO;
                jogadorAtual = jogador2;
            }
        }

    }

    return 0;
}

//valida se existe um ganhador pelas linhas ou colunas
int validaLinhasColunas(int jogadas[3][3]) {
    for (int i = 0; i < 3; i++) {
        //verifica se a posição atual da matriz esta preenchida
        //se estiver, compara com as demais posições da mesma linha
        //se a linha for toda igual retornamos o vencedor
        if ((jogadas[i][0] > 0) &&
            (jogadas[i][0] == jogadas[i][1]) &&
            (jogadas[i][0] == jogadas[i][2])) {

            return jogadas[i][0];
        }
        //verifica se a posição atual da matriz esta preenchida
        //se estiver, compara com as demais posições da mesma coluna
        //se a linha for toda igual retornamos o vencedor
        if ((jogadas[0][i] > 0) &&
            (jogadas[0][i] == jogadas[1][i]) &&
            (jogadas[0][i] == jogadas[2][i])) {

            return jogadas[0][i];
        }
    }
    return 0;
}

int validarDiagonais(int jogadas[3][3]) {
    //aqui você precisa implementar a validação
    //da diagonal principal e secundaria para verificar se tem vencedor
    // retorno esperado:
    //retornar 1 se o vencedor foi o jogador 1
    //retornar 2 se o vencedor foi o jogador 2
    //retornar 0 se ainda não teve vencedor

    //AJUDA (indices abaixo da matriz):
    // 00   01 	02
    // 10	11	12
    // 20	21	22 

    return 0;
}

//função faz a verificação se a posição escolhida pelo usuário está disponível e se não puder ser escolhida a posição ele retorna uma mensagem e pede para o usuário jogar de novo
int validarPosicao(int posicao) {
    if (posicao != 0) {
        drawText("Posição já escolhida, aperte uma tecla e jogue novamente", 8, 30, 22, "white");
      	readKey();
      	fillRect(8, 0, 700, 40, "black");
        return 0;
    } else {
        return 1;
    }

}
