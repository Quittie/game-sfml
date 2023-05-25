TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        game.cpp \
        hud.cpp \
        immoveable.cpp \
        main.cpp \
        moveable.cpp

INCLUDEPATH += "C:/SFML/SFML-2.5.1/include"
LIBS += -L"C:/SFML/SFML-2.5.1/lib"

CONFIG(debug, debug|release){
    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
} else {
    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
}

HEADERS += \
    game.h \
    hud.h \
    immoveable.h \
    moveable.h
