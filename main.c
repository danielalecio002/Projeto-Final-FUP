#include <stdio.h>
#include<SFML/Graphics.h>
#include<stdlib.h>
#include "cenario.h"
#include <SFML/Audio.h>
#include<stdlib.h>


int main(void)  {
    //inicializando structjogo
    ponto p ={ 0, 0};

    jogo jogo = {800, 600};
    sfRenderWindow * janela;
    //chamando funçao criar janela
    janela = criar_janela(jogo.largura,jogo.altura);

    sfMusic *music = sfMusic_createFromFile("../Projeto_fup/bob.ogg");

    // propriedades do texto
    sfFont * fonte;
    fonte = sfFont_createFromFile("/usr/share/fonts/truetype/ubuntu-font-family/Ubuntu-B.ttf");
    sfText * texto;
    texto = sfText_create();

    // chamando função criar bola,com os parametros raio/posição/velocidade
    Bola bolam = bola_criar(5.0, (sfVector2f) {400,300}, (sfVector2f){0,0}, sfWhite);
    Bola bola = bola_criar(15.0, (sfVector2f) {400,300}, (sfVector2f){0,0}, sfRed);

    // chamando função criar retangulo, os parametros são tamanho/posição
    //Retangulos laterais
    Retangulo retangulo = retangulo_criar((sfVector2f){20,150}, (sfVector2f) {0,225});
    Retangulo retangulo2 = retangulo_criar((sfVector2f){20,150}, (sfVector2f) {780,225});
    //Retangulos de desenhar o cenario
    Retangulo linha = retangulo_criar((sfVector2f){3,600}, (sfVector2f) {399.5,0});
    Retangulo up = retangulo_criar((sfVector2f){800,3}, (sfVector2f) {0,0});
    Retangulo down = retangulo_criar((sfVector2f){800,3}, (sfVector2f) {0,597});

    //Começando o jogo
    while(sfRenderWindow_isOpen(janela)){
        sfColor cor = {65, 105 ,225,0};
        sfEvent Evento;
        while(sfRenderWindow_pollEvent(janela,&Evento)){
            if(Evento.type == sfEvtClosed){
                sfRenderWindow_close(janela);
            }
        }

        //-------------movimentando Retangulo------------------------
        movimento_retangulo(&retangulo, &retangulo2);


        //--------------Movimentando a bola----------------------------
        if (sfKeyboard_isKeyPressed(sfKeySpace)){
            bola.vel.x -= 0.1;
            sfMusic_play(music);
        }
        if (sfKeyboard_isKeyPressed(sfKeyP)){
            sfMusic_pause(music);

        }
        //atualizando a posicao da bola
        bola.cpos.x += bola.vel.x;
        //funcao da colisão bola/retangulos
        colisao_bola_retangulo(&bola, &retangulo, &retangulo2);

        //funçao reiniciar
        reiniciar(&bola,&retangulo,&retangulo2,&jogo , &p, music);

        //-------------Colisão Bola parede em cima---------------------
        colisaobola(&bola,&jogo);

        //--------------Colisão retangulo parede------------------------
        colisao_retangulos(&retangulo, &retangulo2, &jogo);

        //--------------limpando janela---------------------------------
        sfRenderWindow_clear(janela, cor);

        //--------Chamando as Funcoes de Desenhar Objetos do jogo-------
        bola_desenhar(&bolam, janela);
        desenhar_retangulo(&retangulo,janela);
        desenhar_retangulo(&retangulo2,janela);
        desenhar_retangulo(&linha,janela);
        desenhar_retangulo(&up,janela);
        desenhar_retangulo(&down,janela);

        //-----------------texto----------------------------------------
        colocartext(fonte,texto,janela,p.jog1,p.jog2);
        //-----------Desenhando bola principal--------------------------
        bola_desenhar(&bola, janela);
        //--------mostrando janela---------------------------------------
        sfRenderWindow_display(janela);

    }
}
