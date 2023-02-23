QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfriend.cpp \
    changeprofile.cpp \
    chatbox.cpp \
    chatframe.cpp \
    loginwindow.cpp \
    main.cpp \
    mythread.cpp \
    oqnetwork.cpp \
    oqsocket.cpp \
    registerwindow.cpp \
    settings.cpp \
    user.cpp

HEADERS += \
    addfriend.h \
    changeprofile.h \
    chatbox.h \
    chatframe.h \
    loginwindow.h \
    mainwindow.h \
    mythread.h \
    oqnetwork.h \
    oqsocket.h \
    registerwindow.h \
    settings.h \
    user.h

FORMS += \
    addfriend.ui \
    changeprofile.ui \
    chatbox.ui \
    chatframe.ui \
    loginwindow.ui \
    registerwindow.ui \
    settings.ui \
    user.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resource.qrc \
    Resource.qrc \
    images.qrc