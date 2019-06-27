TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.c \
    cenario.c \
    colisoes_jogo.c \
    restart.c
LIBS+= -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

HEADERS += \
    cenario.h \
    colisoes_jogo.h \
    restart.h
