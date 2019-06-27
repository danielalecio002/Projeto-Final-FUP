#include "restart.h"

//Função de reiniciar a posição dos objetos após cada ponto do jogo
void reiniciar(Bola * bola,Retangulo * retangulo,Retangulo * retangulo2, jogo *jogo , ponto *p ,sfMusic *music){

    if(bola->cpos.x < 0){
        bola->cpos.x =400;
        bola->cpos.y=300;
        sfMusic_pause(music);
        bola->vel.x = 0;
        retangulo->pos.x =0;
        retangulo->pos.y = 225;
        retangulo2->pos.x = 780;
        retangulo2->pos.y =225;
        bola->vel.y =0;
        p->jog2 += 1;


    }
        if(bola->cpos.x > jogo->largura){
        bola->cpos.x =400;
        bola->cpos.y=300;
        sfMusic_pause(music);
        bola->vel.x = 0;
        bola->vel.y =0;
        retangulo->pos.x =0;
        retangulo->pos.y = 225;
        retangulo2->pos.x = 780;
        retangulo2->pos.y =225;
        p->jog1 += 1;



    }

}
