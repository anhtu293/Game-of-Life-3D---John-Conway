QT += widgets
QT += opengl
LIBS += -lopengl32 -lglu32
QMAKE_CXXFLAGS = -std=c++11
QMAKE_LFLAGS = -std=c++11

HEADERS += \
    Etat.h \
    automate.h \
    mainwindow.h \
    myglwidget.h
SOURCES += \
    Etat.cpp \
    automate.cpp \
    main.cpp \
    mainwindow.cpp \
    myglwidget.cpp
FORMS += \
    mainwindow.ui
