/*  Local para colocar as variaveis :)
    Jogador *jogadores;
    Mao minhaMao;
    Carta cartaInicial;
*/

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LINE 100
#define MAX_ACTION 10
#define MAX_ID_SIZE 10

// Struct para os bots

typedef struct {     // struct feita para representar uma unica carta
    char *valorCarta;
    char *valorNaipe;
}Carta;

typedef struct  {   // struct para guardar as cartas dos jogadores 
    Carta *cartasDoJogador;
    int qtdDeCartas;
}Mao;

typedef struct {   // representa um jogador 
    char id[MAX_ID_SIZE];
    Mao maoDoJogador;
}Jogador;

void debug(char *message) {
    fprintf(stderr, "%s ", message);
}

Carta gerarCarta(char *mensagem){     // transforma uma string com valor e nipe em uma variavel do tipo Carta
    Carta saida;
    int tamanho = strlen(mensagem);

    if (mensagem[0] == '1' && mensagem[1] == '0')
    {
        char valor[3] = "10";
        saida.valorCarta = malloc(sizeof(char) * 3);
        strcpy(saida.valorCarta, valor);
        saida.valorNaipe = malloc(sizeof(char) * tamanho);

        for (int i = 2; i < tamanho; i++){
            saida.valorNaipe[i-2] = mensagem[i];
        }
    }else{
        saida.valorCarta = malloc(sizeof(char)*2);
        saida.valorCarta[0] = mensagem[0];
        saida.valorCarta[1] = '\0';
        saida.valorNaipe = malloc(sizeof(char) * tamanho);

        for (int i = 1; i < tamanho; i++){
            saida.valorNaipe[i-1] = mensagem[i];
        }
    }

    return saida;
}

void acompanhaTotal(Carta totalDeCartas[108], Carta pedaco){
  int i = 0,j=0;
  for(i=0;i < 108; i++){
    if(strcmp(pedaco.valorCarta, totalDeCartas[i].valorCarta) == 0 && strcmp(pedaco.valorNaipe, totalDeCartas[i].valorNaipe) == 0){
      for(j = i; j < 107; j++){
        totalDeCartas[j].valorCarta = totalDeCartas[j+1].valorCarta;
        totalDeCartas[j].valorNaipe = totalDeCartas[j+1].valorNaipe;
      }
      if(j == 107){
        totalDeCartas[j].valorCarta = "";
        totalDeCartas[j].valorNaipe = "";
      }
      break;
    }
  }
}

Mao maoInicial(char *mensagem, Carta totalDeCartas[108]){     // Faz a leitura das cartas iniciais do bot
    Mao saida;
    Carta aux;
    char *pedaco, vetor[10][10];
    int tamanho, cont = 0;

    pedaco = strtok(mensagem, " ");
    while(pedaco != NULL){
        strcpy(vetor[cont],pedaco);
        cont += 1;
        pedaco = strtok(NULL, " ");
    }

    saida.cartasDoJogador = malloc(sizeof(Carta) * (cont-2));

    for (int i = 1; i < cont - 1; i++) {
        tamanho = strlen(vetor[i]);
        aux = gerarCarta(vetor[i]);
        //Retira do cartaTotais o 1º baralho do nosso bot
        acompanhaTotal(totalDeCartas, aux);
        saida.cartasDoJogador[i-1].valorCarta = malloc(sizeof(char) * 3);
        saida.cartasDoJogador[i-1].valorNaipe = malloc(sizeof(char) * 4);
        strcpy(saida.cartasDoJogador[i-1].valorCarta, aux.valorCarta);
        strcpy(saida.cartasDoJogador[i-1].valorNaipe, aux.valorNaipe);
        saida.qtdDeCartas = i;
    }
    free(aux.valorNaipe);
    free(aux.valorCarta);
    return saida;
}


Carta inicializaCarta(char *valorCarta, char *valorNaipe){
  char dados[MAX_LINE];  
  Carta c;

  strcpy(dados, valorCarta);
  strcat(dados, valorNaipe);
  c = gerarCarta(dados);

  return c;
}

void retornaFrase(){
  const char *listaFrases[] = {"Poxa vida!", 
                               "Que nervoso...",
                               "UNO!! Brincadeira...",
                               "Alguem ta querendo umas cartas emprestadas?",
                               "TRUCO! Eh mentira...",
                               "Aff...queria estar vendo a copa"};

  int indice = rand()%6;
  int chance = rand()%100;

  if(chance<=30){
    printf("SAY %s\n", listaFrases[indice]);
  }
}

int verificaNaipe(char *valorNaipe, Mao maoJogador, int *indice){;
  for(int i=0; i<maoJogador.qtdDeCartas; i++){
    if(strcmp(maoJogador.cartasDoJogador[i].valorNaipe, valorNaipe)==0){
      if(indice!=NULL){
        *indice = i;
      }
      return 1;
    }
  }
  return 0;
}
          
int verificaValor(char *valorCarta, Mao maoJogador, int *indice){
  for(int i=0; i<maoJogador.qtdDeCartas; i++){
    if(strcmp(maoJogador.cartasDoJogador[i].valorCarta, valorCarta)==0){
      if(indice!=NULL){
        *indice = i;
      }
      return 1;
    }
  }
  return 0;
}

char *naipeFrequente(Jogador *bot){ //escolhe naipe que aparece com maior frequencia na mao
  char *listaNaipes[] = {"♥","♦","♣","♠"};
  int qtdNaipe[4] = {0};
  int maior, maiorIndice;

  maior = maiorIndice = 0;
   
   for(int i=0; i<4; i++){
      for(int j=0; j<bot->maoDoJogador.qtdDeCartas; j++){
        if(strcmp(listaNaipes[i], bot->maoDoJogador.cartasDoJogador[j].valorNaipe)==0){
          qtdNaipe[i] += 1;
        }
      }
   }

  for(int i=0; i<4; i++){
    if(qtdNaipe[i] > maior){
      maior = qtdNaipe[i];
      maiorIndice = i;
    }
  }

  return listaNaipes[maiorIndice];
}

void retiraCarta(Jogador *bot, int indice){ //função que retira carta da mão quando essa é jogada (atualiza mão)
  Carta *aux;
  int count = 0;
  int qtdCartas = bot->maoDoJogador.qtdDeCartas;
    
  bot->maoDoJogador.cartasDoJogador[indice].valorCarta = NULL;
  bot->maoDoJogador.cartasDoJogador[indice].valorNaipe = NULL;
  aux = malloc(sizeof(Carta)*(qtdCartas-1));

  for(int i=0; i<qtdCartas; i++){
    if(bot->maoDoJogador.cartasDoJogador[i].valorCarta != NULL && bot->maoDoJogador.cartasDoJogador[i].valorNaipe != NULL){
      aux[count++] = bot->maoDoJogador.cartasDoJogador[i];
    }
  }
  bot->maoDoJogador.qtdDeCartas +=-1;
  free(bot->maoDoJogador.cartasDoJogador);
  bot->maoDoJogador.cartasDoJogador = NULL;
  bot->maoDoJogador.cartasDoJogador = aux;
   
} 

void adicionaCarta(Jogador *bot, Carta c){
  int qtdAtual = bot->maoDoJogador.qtdDeCartas;
  bot->maoDoJogador.cartasDoJogador = realloc(bot->maoDoJogador.cartasDoJogador, sizeof(Carta)*(qtdAtual+1));
  bot->maoDoJogador.qtdDeCartas += 1;
  bot->maoDoJogador.cartasDoJogador[qtdAtual] = c;
}

void atualizaEspecial(Carta c, int *especial){
  if(strcmp(c.valorCarta, "C") == 0 || strcmp(c.valorCarta, "V") == 0){
    (*especial) = 1;
  }
}

int selecionaCarta(Carta c, Jogador *bot){ //encontra a carta a ser jogada (AINDA VOU MUDAR VARIAS COISAS)
  int indice = 0; //indice da carta que será jogada
  char naipe[MAX_LINE];
  strcpy(naipe, naipeFrequente(bot));
  naipe[strlen(naipe)] = '\0';

  if(verificaValor("C", bot->maoDoJogador, &indice)){ 
    return indice;
  }else if(strcmp(c.valorNaipe, naipe) == 0 && verificaNaipe(c.valorNaipe, bot->maoDoJogador, &indice)){
    return indice;
  }else if(verificaValor(c.valorCarta, bot->maoDoJogador, &indice)){
    return indice;
  }else if(verificaNaipe(c.valorNaipe, bot->maoDoJogador, &indice)){
    return indice;
  }else if(verificaValor("A", bot->maoDoJogador, &indice)){
    return indice;
  } 
}

int compraCartas(Carta c, char *naipe, int *especial, Jogador *bot){
  if(strcmp(c.valorCarta, "C")==0 && (*especial) == 1){
    (*especial) = 0;
    return 4;
  }else if(strcmp(c.valorCarta, "V")==0 && (*especial) == 1){
    (*especial) = 0;
    return 2;
  }else if(!verificaNaipe(naipe, bot->maoDoJogador, NULL) &&
           !verificaValor(c.valorCarta, bot->maoDoJogador, NULL)){
    return 1;
  }
  return 0;
}

void recebeCartas(int qtdCartas, Jogador *bot){
    char cartas[qtdCartas][MAX_LINE];
    Carta c;

    for(int i=0; i<qtdCartas; i++){
        scanf(" %s\n", cartas[i]);
        c = gerarCarta(cartas[i]);
        adicionaCarta(bot, c);
    }
}

Carta acaoDescarta(Jogador *bot, int indice, char *auxNaipe){
  char naipe[MAX_LINE];
  Carta c = bot->maoDoJogador.cartasDoJogador[indice];
  strcpy(auxNaipe, c.valorNaipe);

  if(strcmp(c.valorCarta, "A") == 0 || strcmp(c.valorCarta, "C") == 0){
      strcpy(naipe, naipeFrequente(bot));
      naipe[strlen(naipe)] = '\0';
      printf("DISCARD %s%s %s\n", c.valorCarta, c.valorNaipe, naipe);
      strcpy(auxNaipe, naipe);
    }else{
      printf("DISCARD %s%s\n", c.valorCarta, c.valorNaipe);
    }
    auxNaipe[strlen(auxNaipe)] = '\0';

    retiraCarta(bot, indice); //retira a carta da mao do jogador
    return c;
}

void inicializaBaralho(Carta totalDeCartas[108]){
  char* naipes[4] = {"♥", "♦", "♣", "♠"}; 
  char* valor[13] = {"A", "2", "3", "4","5","6","7","8","9","10","V","D","R"}; 

  int k = 0,q = 0;
  
  
    for(int i = 0; i < 14; i++){
        if(k < 104){
          for(int j=0; j < 4; j++){
            for(q = 0; q < 2; q++){
              totalDeCartas[k].valorCarta = valor[i];
              totalDeCartas[k].valorNaipe = naipes[j];
              k++;
            }
          }
        }
        if(k > 103 && k < 108){
          for(int j=0; j <= 2; j++){
            for(q = 0; q < 2; q++){
              totalDeCartas[k].valorCarta = "C";
              totalDeCartas[k].valorNaipe = naipes[j];
              k++;
            }
            j++;
          }
        }
      }
}

void desalocaCarta(Carta *c){
    free((*c).valorCarta);
    free((*c).valorNaipe);
}


void acaoCompra(int qtdCartas, Jogador *bot,Carta totalDeCartas[108]){
  char cartas[qtdCartas][MAX_LINE];
  Carta c;

  printf("BUY %d\n", qtdCartas);

  for(int i=0; i<qtdCartas; i++){ //recebe cartas do gerenciador e add na mao
    scanf(" %s\n", cartas[i]);
    c = gerarCarta(cartas[i]);
    //Acompanha total de cartas
    acompanhaTotal(totalDeCartas, c);
    adicionaCarta(bot, c);
  }
}

int main() {

    Carta totalDeCartas[108];//eram 54 cm 1 baralho só
    Carta pilhaSobMesa[115];
    int contador = 0, especial = 0;

    char temp[MAX_LINE];  
    char my_id[MAX_ID_SIZE]; 

    Jogador botT;
    Mao minhaMao;

    char complemento2[MAX_LINE];
    char auxNaipe[MAX_LINE]; //guarda o naipe atual da partida

    setbuf(stdin, NULL);  
    setbuf(stdout, NULL);  
    setbuf(stderr, NULL);
    srand(time(NULL));

   inicializaBaralho(totalDeCartas);
      
    // Ler quais são os jogadores
    scanf("PLAYERS %[^\n]\n", temp);

    // Id do nosso bot
    scanf("YOU %s\n", my_id);
    strcpy(botT.id,my_id);

    // A mão recebida
    scanf("HAND %[^\n]\n", temp);
    minhaMao = maoInicial(temp,totalDeCartas); 
    botT.maoDoJogador = minhaMao;
  
    // carta inicial 
    scanf("TABLE %s\n", temp);
    pilhaSobMesa[contador++] = gerarCarta(temp);
    strcpy(auxNaipe, pilhaSobMesa[contador-1].valorNaipe); //atualiza auxNaipe
    auxNaipe[strlen(auxNaipe)] = '\0';
    atualizaEspecial(pilhaSobMesa[contador-1], &especial);
  
    char id[MAX_ID_SIZE];
    char acao[MAX_ACTION];
    char complemento[MAX_LINE];

    // Fica esperando a vez do seu bot jogar

    while(1) {

    do {

        // ler a jogada do bot anterior a vc 

        scanf(" %s %s", acao, complemento);
      
        //aqui é a adição das cartas na pilhaSobMesa
        if(strcmp(acao, "DISCARD") == 0){
          pilhaSobMesa[contador++] = gerarCarta(complemento);
          strcpy(auxNaipe, pilhaSobMesa[contador-1].valorNaipe);
          //Retira a carta descartada do total de cartas
          acompanhaTotal(totalDeCartas, pilhaSobMesa[contador-1]);

          if(strstr(pilhaSobMesa[contador-1].valorCarta,"A")!= NULL || strstr(pilhaSobMesa[contador-1].valorCarta,"C")!= NULL){
            scanf(" %s", complemento2);
            strcpy(auxNaipe, complemento2);
          }
           atualizaEspecial(pilhaSobMesa[contador-1], &especial);
           auxNaipe[strlen(auxNaipe)] = '\0';
        }

        if(especial == 1 && strcmp(acao, "BUY")==0 && 
          (strcmp(complemento, "2")==0 || strcmp(complemento, "4")==0) ||
           strcmp(acao, "INVALID ACTION") == 0){ //verifica se algum bot respondeu a especial
          especial = 0;
        }

    } while (strcmp(acao, "TURN") || strcmp(complemento, my_id));


    //Vez do bot
    
    int cartasCompradas = 0;
    Carta recebida;
 
    recebida = inicializaCarta(pilhaSobMesa[contador-1].valorCarta, pilhaSobMesa[contador-1].valorNaipe); //inicializa carta recebida

    cartasCompradas = compraCartas(recebida, auxNaipe, &especial, &botT); //verifica se o jogador terá que comprar cartas e retorna a qtd

    strcpy(recebida.valorNaipe, auxNaipe); //atualizaNaipe de carta recebida;

    if(!cartasCompradas){
        int indice = selecionaCarta(recebida, &botT);  //recebe carta que vai jogar

        pilhaSobMesa[contador++] = acaoDescarta(&botT, indice, auxNaipe); //envia açao ao gerenciador, atualiza naipe e mao do jogador
        atualizaEspecial(pilhaSobMesa[contador-1], &especial); //atualiza o status de especial quando bot joga
    }else{
        retornaFrase();
        acaoCompra(cartasCompradas, &botT,totalDeCartas); //compra cartas e atualiza mao do jogador
    }

  }

  for(int i=0; i<contador; i++){
    desalocaCarta(&pilhaSobMesa[i]);
  }

  free(minhaMao.cartasDoJogador);

    return 0;
}