include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

HEADERS += \
        tst_gridboardtest.h \
    tst_enginetest.h

SOURCES += \
        main.cpp

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
