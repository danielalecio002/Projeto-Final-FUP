#ifndef COLISOES_JOGO_H
#define COLISOES_JOGO_H
#include "cenario.h"

void colisao_retangulos(Retangulo * retangulo, Retangulo * retangulo2 ,jogo * jogo);
void colisaobola(Bola * bola, jogo * jogo);
void colisao_bola_retangulo(Bola *bola, Retangulo * retangulo,Retangulo * retangulo2);

#endif // COLISOES_JOGO_H
