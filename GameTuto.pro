QT       += core gui \
            multimedia







greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    brick.cpp \
    bullet.cpp \
    button.cpp \
    endscreen.cpp \
    enemy.cpp \
    enemybullet.cpp \
    game.cpp \
    health.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    player.cpp \
    score.cpp

HEADERS += \
    brick.h \
    bullet.h \
    button.h \
    endscreen.h \
    enemy.h \
    enemybullet.h \
    game.h \
    health.h \
    mainmenu.h \
    mainwindow.h \
    player.h \
    score.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
