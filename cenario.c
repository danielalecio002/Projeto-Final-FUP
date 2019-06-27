#include "cenario.h"
#include<stdio.h>
sfRenderWindow * criar_janela(int largura, int altura){
    sfVideoMode mode = {largura, altura,32};
    sfRenderWindow *  _janela = sfRenderWindow_create(mode, "Pong - Pong", sfResize | sfClose, NULL);
    return _janela;
}
//Funçao criar retangulo
Bola bola_criar(float raio, sfVector2f pos, sfVector2f vel ,sfColor cor){
    Bola b;
    b.raio = raio;
    b.cpos = pos;
    b.vel = vel;
    b.cor = cor;
    return b;
}
//Funçao criar retangulo
Retangulo retangulo_criar(sfVector2f tam ,sfVector2f pos ){
    Retangulo r;
    r.tam = tam;
    r.pos = pos;
    return r;
}
//Função para desenhar bola
void bola_desenhar(Bola * b, sfRenderWindow * janela){
    sfCircleShape * obj = sfCircleShape_create();
    sfCircleShape_setPosition(obj,b->cpos);
    sfCircleShape_setFillColor(obj, b->cor);
    sfCircleShape_setOrigin(obj,(sfVector2f){b->raio,b->raio});
    sfCircleShape_setRadius(obj, b->raio);
    sfRenderWindow_drawCircleShape(janela,obj,NULL);
    sfCircleShape_destroy(obj);
}
//Função para desenhar o retângulo
void desenhar_retangulo(Retangulo * r, sfRenderWindow * janela){

    sfRectangleShape * objr = sfRectangleShape_create();
    sfRectangleShape_setPosition(objr, r->pos);
    sfRectangleShape_setFillColor(objr, sfWhite);
    sfRectangleShape_setSize(objr,(sfVector2f){r->tam.x,r->tam.y});
    sfRenderWindow_drawRectangleShape(janela,objr,NULL);
    sfRectangleShape_destroy(objr);
}

//Função para movimentar o retangulo
void movimento_retangulo(Retangulo * retangulo, Retangulo * retangulo2){
    if(sfKeyboard_isKeyPressed(sfKeyUp)){
        retangulo2->pos.y -=1;
    }
    if(sfKeyboard_isKeyPressed(sfKeyDown)){
        retangulo2->pos.y +=1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyW)){
        retangulo->pos.y -= 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyS)){
        retangulo->pos.y += 1;
    }
}
//Função par exibir o texto na tela
void colocartext ( sfFont * fonte, sfText * texto, sfRenderWindow * janela, int ponto1, int ponto2) {
    char saida[100];

    sprintf(saida,"       %d             %d ", ponto1, ponto2 );
    sfText_setString(texto, saida);
    sfText_setFont(texto, fonte);
    sfText_setPosition(texto,(sfVector2f){10, 0});
    sfText_setCharacterSize(texto, 100);
    sfText_setColor(texto, sfWhite);
    sfRenderWindow_drawText(janela,texto,NULL);
}
