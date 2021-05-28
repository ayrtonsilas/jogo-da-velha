# Tutorial: jogo da velha
##### Autores: 
Ayrton Silas, Danilo Brito, Juliana Nascimento, Liliane Fiúza.

##### Como jogar:
Ao iniciar o jogo, use as teclas do teclado de 1 a 9 para selecionar as posições escolhidas.

##### Formulário de avaliação do desenvolvimento e do jogo:
[Google forms](https://docs.google.com/forms/d/1yqii0mhUsLNflf9Oy4swfCSb3FWstC5kPNRm-SPcjMw/edit?usp=sharing)

##### Conhecimento prévio necessário: 
Estruturas de seleção (if/else), estruturas de repetição (for/while), arrays, matrizes e funções.

##### Objetivo de aprendizagem: 
Ao final deste tutorial, o estudante deve ser capaz de compreender o conceito de matriz de acordo com o que o problema pede.

##### Iniciando
Neste tutorial você vai aprender a desenvolver um clone do jogo da velha, no qual o objetivo é formar sequências de mesmo objeto, em linhas, colunas ou diagonais.

FOTO DO JOGO
![tabuleiro](https://i.ibb.co/X2LGyKF/jogo-da-velha.png)


#####  Definindo a matriz das jogadas e nomes para as imagens
Primeiramente se define a matriz que será usada para armazenar cada jogada. Logo em seguida, criamos um nome para as imagens X e Zero com as variáveis imagemX e imagemO, e definimos a seleção da jogada através da variável imagemAtual.
```cpp
    int main() {
        int jogadas[3][3];
        char imagemX[12] = "imagem_X";
        char imagemO[12] = "imagem_Zero";
        char imagemAtual[12] = imagemX;
    }
```

##### Inicializando validador de posições
Validador de posições que já foram usadas, utilizado para verificar se o usuário pode jogar na posição que foi solicitada.
```cpp
...main
    int verificaPosicaoJogada = 1;
```

##### Definindo um número pra cada jogador
Define um número para cada jogador, informa de qual jogador é a vez e inicializa a matriz que armazena as jogadas com zero.

```cpp
... main
    int jogador1 = 1;
    int jogador2 = 2;
    int jogadorAtual = 1;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            jogadas[i][j] = 0;
        }
    }
```


##### Carregando as imagens
Definimos imagens que utilizaremos no jogo. Para isso vamos usar a função loadImage. A seguir vamos criar as imagens X e Zero com as variáveis imagemX e imagemO e montar o tabuleiro na posição ( 200,50) - 200 pixels horizontal e 50 pixels vertical - utilizando a função drawImage.
```cpp
... main
        loadImage("tabuleiro", "https://i.ibb.co/nwRf4mx/download.png");
        loadImage(imagemX, "https://i.ibb.co/BVf32tS/x.jpg");
        loadImage(imagemO, "https://i.ibb.co/vd4d0tK/zero.jpg");
        drawImage("tabuleiro", 200, 50);
```
Tabuleiro
![tabuleiro](https://i.ibb.co/nwRf4mx/download.png)

Foto do X
![tabuleiro](https://i.ibb.co/BVf32tS/x.jpg)
Foto do Zero
![tabuleiro](https://i.ibb.co/vd4d0tK/zero.jpg)


##### Iniciando as rodadas do jogo
Criamos uma variável playGame para controlar o início e fim do jogo.
Inicialmente leremos um valor do teclado através da função readKey, em seguida verificamos o valor digitado através de isKeyDown e inserimos a jogada na matriz de jogadas. Para simbolizar o jogador 1, inserimos na matriz o número 1 e para simbolizar o jogador 2, inserimos na matriz o número 2. 
Logo após a verificação, validamos através da função validarPosicao() se a posição já está preenchida ou não. Caso esteja, é solicitada uma nova tentativa.
```cpp
...main
bool playGame = true;
while (playGame) {

    readKey();
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
...
```

Aqui chamamos as funções de validação de linhas, colunas e diagonais e armazenamos o retorno delas em uma variável.

```cpp
 ...main
 ...while
        int vencedorLC = validaLinhasColunas(jogadas);
        //implementar função validarDiagonais pelos alunos
        int vencedorDiagonal = validarDiagonais(jogadas);

```

##### Verifica jogador
Verifica se o jogador 1 é o jogador vencedor, se for ele imprime o jogador vencedor e encerra o programa. A mesma verificação ocorre com o jogador 2.
 ```cpp  
 ...main
 ...while
	if (vencedorLC == 1 || vencedorDiagonal == 1) {
	    drawText("Jogador 1 Venceu", 8, 30, 22, "white");
	    playGame = false;
	} else if (vencedorLC == 2 || vencedorDiagonal == 2) {
	    drawText("Jogador 2 Venceu", 8, 30, 22, "white");
	    playGame = false;
	}
```
  

##### Alterna imagens
Esse bloco alterna entre as imagens para mudar a cada rodada. Inicialmente começamos com a imagem X. Também alternamos os jogadores e inicialmente começamos com o jogador 1 validando em ambos se a posição foi preenchida.

```cpp
...main
...while
if (validadorPosicao == 1) {
    if (imagemAtual == imagemO) {
	imagemAtual = imagemX;
	jogadorAtual = jogador1;
    } else {
	imagemAtual = imagemO;
	jogadorAtual = jogador2;
    }
}

```

Aqui encerramos o trecho do while e colocamos o retorno da função main

```cpp
...main
...while
}

    return 0;
```
	
##### Validar um ganhador pelas linhas ou colunas
Com o validaLinhasColunas valida-se a existência de um 
ganhador tanto pelas linhas e/ou pelas colunas. Primeiro verifica se a posição atual da matriz está preenchida. Se caso estiver, compara com as demais posições da mesma linha e se ela for toda igual, retornamos o vencedor. O mesmo se da para as colunas, verifica se a posição atual da matriz está preenchida, se estiver, compara com as demais posições da mesma coluna, se a linha for toda igual retornamos o vencedor.
```cpp
int validaLinhasColunas(int jogadas[3][3]) {
    for (int i = 0; i < 3; i++) {
        if ((jogadas[i][0] > 0) &&
            (jogadas[i][0] == jogadas[i][1]) &&
            (jogadas[i][0] == jogadas[i][2])) {

            return jogadas[i][0];
        }
        if ((jogadas[0][i] > 0) &&
            (jogadas[0][i] == jogadas[1][i]) &&
            (jogadas[0][i] == jogadas[2][i])) {

            return jogadas[0][i];
        }
    }
    return 0;
}
```


##### Verifica posição disponível
Através de validarPosicao é verificado se a posição escolhida pelo usuário está disponível. Caso a posição não puder ser escolhida, ele retorna uma mensagem através do comando drawText e pede para o usuário jogar novamente.

```cpp
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
```

##### Exercício

Para o exercício de implementação, baseado na validação do ganhador pelas linhas ou colunas, solicitamos que seja feita a função validarDiagonais para executar a validação da diagonal principal e da diagonal secundária, verificando se possui o vencedor na rodada e mostrando qual jogador ganhou (1 ou 2).

```cpp
...
int validarDiagonais(int jogadas[3][3]) {
    //aqui você precisa implementar a validação
    //da diagonal principal e secundaria para verificar se tem vencedor
    // retorno esperado:
    //retornar 1 se o vencedor foi o jogador 1
    //retornar 2 se o vencedor foi o jogador 2
    //retornar 0 se ainda não teve vencedor

    //AJUDA (indices abaixo da matriz):
    // 00   	01 	02
    // 10	11	12
    // 20	21	22 

    return 0;
}
```
