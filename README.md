# Tutorial: jogo da velha
##### Autores: 
Ayrton, Danilo, Juliana, Liliane

##### Como jogar:
Ao iniciar o jogo, use as teclas do teclado de 1 a 9 para selecionar as posições escolhidas.

##### Formulário de avaliação do desenvolvimento e do jogo:
[Google forms](https://docs.google.com/forms/d/1yqii0mhUsLNflf9Oy4swfCSb3FWstC5kPNRm-SPcjMw/edit?usp=sharing)

##### Link para executar o jogo
[Executar](https://rodrigorgs.github.io/inge9/playground.html)

##### Conhecimento prévio necessário: 
Estruturas de seleção (if/else), estruturas de repetição (for/while), arrays, matrizes.

##### Objetivo de aprendizagem: 
ao final deste tutorial, o estudante deve ser capaz de compreender o conceito de matriz de acordo com o que o problema pede.

##### Iniciando
Neste tutorial você vai aprender a desenvolver um clone do jogo da velha, no qual o objetivo é formar sequências de mesmo objeto, em linhas, colunas ou diagonais.


Definindo a matriz das jogadas e nomes para as imagens
Primeiramente se define a matriz que será usada para armazenar as jogadas com a função Jogadas. Logo em seguida criamos um nome para as imagens X e Zero com as funções imagemX e imagemO e se define a seleção da jogada através da função imagemAtual.
```cpp
    int main() {
        int jogadas[3][3];
        char imagemX[12] = "imagem_X";
        char imagemO[12] = "imagem_Zero";
        char imagemAtual[12] = imagemX;
        return 0
    }
```

Inicializando validador de posições
validador de posições, para ver se usuário pode jogar naquela posição
    int validadorPosicao = 1;

Definindo um numero pra cada jogador
Define um numero para cada jogador, e diz de qual vez é o jogador.

```cpp
... main
    int jogador1 = 1;
    int jogador2 = 2;
    int jogadorAtual = 1;
```

Inicializa a matriz que armazena as jogadas com zero
```cpp
... main
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            jogadas[i][j] = 0;
        }
    }
```


Carregando as imagens
Definimos imagens que vamos usar no jogo. Para isso vamos usar a função loadImage. A seguir vamos criar as imagens X e Zero com as funções imagemX e imagemO e montar o tabuleiro na posição ( 200,50) - 200 pixels horizontal e 50 pixels vertical - usando a função drawImage.
```cpp

    int main() {
        ...
        loadImage("tabuleiro", "https://i.ibb.co/nwRf4mx/download.png");
        loadImage(imagemX, "https://i.ibb.co/BVf32tS/x.jpg");
        loadImage(imagemO, "https://i.ibb.co/vd4d0tK/zero.jpg");
        drawImage("tabuleiro", 200, 50);
        return 0;
    }
    

```
Tabuleiro
![tabuleiro](https://i.ibb.co/nwRf4mx/download.png)

Foto do X
![tabuleiro](https://i.ibb.co/BVf32tS/x.jpg)
Foto do Zero
![tabuleiro](https://i.ibb.co/vd4d0tK/zero.jpg)


Iniciando as rodadas do jogo
Inicialmente se ler um valor do teclado através da função readKey, em seguida verificamos o valor digitado através de isKeyDown, inserimos a jogada na matriz de jogadas.Para simbolizar o jogador 1, inserimos na matriz o numero 1 e para simbolizar o jogador 2, inserimos na matriz o numero 2. Dessa forma o retorno das funções de validação ja vão ser o jogador vencedor e imprimimos o X ou 0 na tabela de acordo com o numero.
```cpp
...main
bool playGame = true;
while (playGame) {

    readKey();
    if (isKeyDown("1")) {
        validadorPosicao = validarPosicao(jogadas[2][0]);
        if (validadorPosicao == 1) {
            jogadas[2][0] = jogadorAtual;
            drawImage(imagemAtual, 210, 210);
        }
    } else if (isKeyDown("2")) {
        validadorPosicao = validarPosicao(jogadas[2][1]);
        if (validadorPosicao == 1) {
            jogadas[2][1] = jogadorAtual;
            drawImage(imagemAtual, 290, 210);
        }
    } else if (isKeyDown("3")) {
        validadorPosicao = validarPosicao(jogadas[2][2]);
        if (validadorPosicao == 1) {
            jogadas[2][2] = jogadorAtual;
            drawImage(imagemAtual, 360, 210);
        }
    } else if (isKeyDown("4")) {
        validadorPosicao = validarPosicao(jogadas[1][0]);
        if (validadorPosicao == 1) {
            jogadas[1][0] = jogadorAtual;
            drawImage(imagemAtual, 210, 140);
        }
    } else if (isKeyDown("5")) {
        validadorPosicao = validarPosicao(jogadas[1][0]);
        if (validadorPosicao == 1) {
            jogadas[1][1] = jogadorAtual;
            drawImage(imagemAtual, 290, 140);
        }
    } else if (isKeyDown("6")) {
        validadorPosicao = validarPosicao(jogadas[1][2]);
        if (validadorPosicao == 1) {
            jogadas[1][2] = jogadorAtual;
            drawImage(imagemAtual, 360, 140);
        }
    } else if (isKeyDown("7")) {
        validadorPosicao = validarPosicao(jogadas[0][0]);
        if (validadorPosicao == 1) {
            jogadas[0][0] = jogadorAtual;
            drawImage(imagemAtual, 210, 65);
        }
    } else if (isKeyDown("8")) {
        validadorPosicao = validarPosicao(jogadas[0][1]);
        if (validadorPosicao == 1) {
            jogadas[0][1] = jogadorAtual;
            drawImage(imagemAtual, 290, 65);
        }
    } else if (isKeyDown("9")) {
        validadorPosicao = validarPosicao(jogadas[0][2]);
        if (validadorPosicao == 1) {
            jogadas[0][2] = jogadorAtual;
            drawImage(imagemAtual, 360, 65);
        }
    }
}
...
```

```cpp
  
        int vencedorLC = validaLinhasColunas(jogadas);
        //implementar função validarDiagonais pelos alunos
        int vencedorDiagonal = validarDiagonais(jogadas);

```

Verifica jogador
verifica se o jogador vencedor é o jogador 1, se for ele imprimi o jogador vencedor e encerra o programa, a mesma coisa para o jogador 2
 ```cpp     
	  if (vencedorLC == 1 || vencedorDiagonal == 1) {
            drawText("Jogador 1 Venceu", 8, 30, 22, "white");
            playGame = false;
        } else if (vencedorLC == 2 || vencedorDiagonal == 2) {
            drawText("Jogador 2 Venceu", 8, 30, 22, "white");
            playGame = false;
        }
	return 0;
	}
```

Alterna imagens
Essa interação alterna entre as imagens para mudar a cada rodada. Inicialmente começamos com a imagem X. Tambem alternamos os jogadores e inicialmente começamos com o jogador 1 validando em ambos se a posição foi preenchida.

```cpp
        if (validadorPosicao == 1) {
            if (imagemAtual == imagemO) {
                imagemAtual = imagemX;
                jogadorAtual = jogador1;
            } else {
                imagemAtual = imagemO;
                jogadorAtual = jogador2;
            }
        }

    return 0;
}

```

	
Validar um ganhador pelas linhas ou colunas
A função validaLinhasColunas valida se existe um ganhador tanto pelas linhas e/ou pelas colunas. Primeiro verifica se a posição atual da matriz esta preenchida. Se estiver, compara com as demais posições da mesma linha se a linha for toda igual retornamos o vencedor. O mesmo se da para as colunas, verifica se a posição atual da matriz esta preenchida, se estiver, compara com as demais posições da mesma coluna, se a linha for toda igual retornamos o vencedor.
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

Verificando qual jogador campeão (1 ou 2)
Através da primeira interação (if) é possivel verificar se o jogador vencedor é o jogador 1,se for, ele imprimi o jogador vencedor e encerra o programa. Verifica o mesmo para o jogador 2.

```cpp
    ...main
    ...while
    int vencedorLC = validaLinhasColunas(jogadas);
    int vencedorDiagonal = validarDiagonais(jogadas);

    if (vencedorLC == 1 || vencedorDiagonal == 1) {
        drawText("Jogador 1 Venceu", 8, 30, 22, "white");
        playGame = false;
    } else if (vencedorLC == 2 || vencedorDiagonal == 2) {
        drawText("Jogador 2 Venceu", 8, 30, 22, "white");
        playGame = false;
    }
 ```       
        
Realizando mudança de imagem entre jogadores
Nessa interação é possível alternar entre as imagens para mudar a cada rodada. Inicialmente começamos com a imagem X. Também alternamos os jogadores, iniciando com o jogador 1.
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


Verifica posição disponível
Através da função validarPosicao, realiza a verificação da posição escolhida pelo usuário, se está disponível. Caso a posição não puder ser escolhida, ele retorna uma mensagem através do comando drawText e pede para o usuário jogar de novo.

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



Para o exercício de implementação, baseado na validação do ganhador pelas linhas ou colunas, solicitamos que seja feita a função validarDiagonais validando diagonal principal e secundaria para verificar se possui o vencedor na rodada, mostrando qual jogador ganhou (1 ou 2).

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
    // 00   01 	02
    // 10	11	12
    // 20	21	22 

    return 0;
}
```
