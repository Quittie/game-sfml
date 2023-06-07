TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        barricadem.cpp \
        game.cpp \
        hud.cpp \
        immoveable.cpp \
        main.cpp \
        moveable.cpp \
        pitch.cpp \
        player.cpp \
        plyer.cpp


INCLUDEPATH += "C:/SFML/SFML-2.5.1/include"
LIBS += -L"C:/SFML/SFML-2.5.1/lib"

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    Player.h \
    barricadem.h \
    game.h \
    hud.h \
    immoveable.h \
    moveable.h \
    pitch.h \
    pitch.h \
    plyer.h
SOURCES +=
fiutbol.png
trawka.png
ball.png


