#ifndef CENARIO_H
#define CENARIO_H
#include<SFML/Graphics.h>
#include <SFML/Audio.h>

typedef struct {
    int largura;
    int altura;

}jogo;

typedef struct{
    float raio;
    sfColor cor;
    sfVector2f cpos;
    sfVector2f vel;
    //float grav;
}Bola;

typedef struct {
    sfVector2f pos;
    sfVector2f tam;
}Retangulo;
typedef struct{
    int jog1;
    int jog2;
}ponto;

sfRenderWindow * criar_janela(int largura, int altura);
Bola bola_criar(float raio, sfVector2f pos, sfVector2f vel ,sfColor cor);
Retangulo retangulo_criar(sfVector2f tam ,sfVector2f pos);
void desenhar_retangulo(Retangulo * r, sfRenderWindow * janela);
void bola_desenhar(Bola * b, sfRenderWindow * janela);
void movimento_retangulo(Retangulo * retangulo, Retangulo * retangulo2);
void colocartext ( sfFont * fonte, sfText * texto, sfRenderWindow * janela, int ponto1, int ponto2);

#endif // CENARIO_H
