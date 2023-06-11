TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ball.cpp \
        barricadem.cpp \
    counterwithtext.cpp \
        game.cpp \
    goalkeeper.cpp \
        immoveable.cpp \
        immoveablecounter.cpp \
        main.cpp \
        moveable.cpp \
        player.cpp \

INCLUDEPATH += "C:/SFML/SFML-2.5.1/include"
LIBS += -L"C:/SFML/SFML-2.5.1/lib"

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    ball.h \
    barricadem.h \
    counterwithtext.h \
    game.h \
    goalkeeper.h \
    immoveable.h \
    immoveablecounter.h \
    moveable.h \
    player.h
SOURCES +=
ball.png
gate.png
grass.png
clock.png
heart.png
ball2.png
ball3.png
goalkeeper.png
gameover.png
pngwing.png
arial.ttf
ourland.ttf
soccermusic.wav
trumpet.wav


