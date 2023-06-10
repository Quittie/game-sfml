#TEMPLATE = app
#CONFIG += console c++17
#CONFIG -= app_bundle
#CONFIG -= qt

#SOURCES += \
#        ball.cpp \
#        barricadem.cpp \
#        game.cpp \
#        hud.cpp \
#        immoveable.cpp \
#        immoveablecounter.cpp \
#        main.cpp \
#        moveable.cpp \
#        pitch.cpp \
#        player.cpp \
#        ball.cpp \
#        timec.cpp


#INCLUDEPATH += "C:/SFML/SFML-2.5.1/include"
#LIBS += -L"C:/SFML/SFML-2.5.1/lib"

#CONFIG(debug, debug|release){
#    LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-system-d -lsfml-window-d
#} else {
#    LIBS += -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-system -lsfml-window
#}

##HEADERS += \
##    Player.h \
##    TimeC.h \
##    ball.h \
##    barricadem.h \
##    game.h \
##    hud.h \
##    immoveable.h \
##    immoveablecounter.h \
##    moveable.h \
##    pitch.h \
##    pitch.h \
##    ball.h
#    HEADERS += \
#        ball.h \
#        barricadem.h \
#        game.h \
#        immoveable.h \
#        immoveablecounter.h \
#        moveable.h \
#        player.h
#SOURCES +=
#fiutbol.png
#trawka.png
#ball.png
TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ball.cpp \
        barricadem.cpp \
        game.cpp \
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
    game.h \
    immoveable.h \
    immoveablecounter.h \
    moveable.h \
    player.h
SOURCES +=
ball.png
player.png
bramka.png
trawka.png
serce.png


