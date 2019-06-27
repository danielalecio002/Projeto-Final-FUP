#include "colisoes_jogo.h"

//tratando a colisao da bola com o retangulo
void colisao_bola_retangulo(Bola * bola ,Retangulo * retangulo, Retangulo * retangulo2){
    sfVector2f ponto;
    //a variavel ponto recebe um vetor de  duas posições a primeira a
    //posição da bola e a outra a posição da bola menos o raio dela
    ponto = ((sfVector2f){bola->cpos.x,bola->cpos.y});

    if(retangulo->pos.x < ponto.x && retangulo->pos.x + (retangulo->tam.x) > ponto.x ){
        if(retangulo->pos.y  < ponto.y && retangulo->pos.y + (retangulo->tam.y) > ponto.y){
            bola->vel.x *= -1;
            bola->cpos.x = 20;
           //bola->vel.y = 0.01;
            if (retangulo->pos.y  < ponto.y && (retangulo->pos.y +30) > ponto.y){
                bola->vel.y =-0.05;
            }
            if (retangulo->pos.y + 120  < ponto.y && (retangulo->pos.y + retangulo->tam.y) > ponto.y){
                bola->vel.y =0.3;
            }


        }
    }
        bola->cpos.y += bola->vel.y;
    if(retangulo2->pos.x < ponto.x && retangulo2->pos.x + (retangulo2->tam.x) > ponto.x){
        if(retangulo2->pos.y < ponto.y && retangulo2->pos.y + (retangulo2->tam.y )  > ponto.y){
            bola->vel.x *= -1;
            bola->cpos.x = 760;

            if (retangulo2->pos.y  < ponto.y && (retangulo2->pos.y +30) > ponto.y){
                bola->vel.y = 0.05;
            }
            if (retangulo2->pos.y + 120  < ponto.y && (retangulo2->pos.y + retangulo2->tam.y) > ponto.y){
                bola->vel.y =-0.3;
            }


        }
    }

}
//colisao bola paredes
void colisaobola(Bola * bola, jogo * jogo){
    //tratando colisão parte de cima
    if (bola->cpos.y-bola->raio < 0){
        bola->vel.y = - bola->vel.y;
    }
    //tratando colisão parte de baixo
    if (bola->cpos.y > jogo->altura - (2 * bola->raio)){
        bola->vel.y = -bola->vel.y;
    }
}

void colisao_retangulos(Retangulo * retangulo, Retangulo * retangulo2 ,jogo * jogo){
    if (retangulo->pos.y < 0 ){
        retangulo->pos.y = - retangulo->pos.y ;
        retangulo->pos.y = 0;
    }
    if (retangulo->pos.y > jogo->altura - 150){
        retangulo->pos.y = + retangulo->pos.y ;
        retangulo->pos.y = 600 - 150;
    }
    if (retangulo2->pos.y < 0 ){
        retangulo2->pos.y = - retangulo2->pos.y ;
        retangulo2->pos.y = 0;
    }
    if (retangulo2->pos.y > jogo->altura - 150){
        retangulo2->pos.y = + retangulo2->pos.y ;
        retangulo2->pos.y = 600 - 150;
    }
}
