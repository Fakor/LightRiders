QT += core gui multimedia widgets

CONFIG += c++17 console
CONFIG -= app_bundle

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
        main.cpp \
    MainWindow.cpp \
    enginegui.cpp \
    squaregui.cpp \
    keyboardagent.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    MainWindow.h \
    enginegui.h \
    squaregui.h \
    keyboardagent.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../static/release/ -lstatic
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../static/debug/ -lstatic
else:unix: LIBS += -L$$OUT_PWD/../static/ -lstatic

INCLUDEPATH += $$PWD/../static
DEPENDPATH += $$PWD/../static

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../static/release/libstatic.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../static/debug/libstatic.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../static/release/static.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../static/debug/static.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../static/libstatic.a
