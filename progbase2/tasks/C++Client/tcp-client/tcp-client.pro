QT += core
QT -= gui

CONFIG += c++11

TARGET = tcp-client
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0





win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../libprogbase-cpp/build/release/ -lprogbase-cpp
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../libprogbase-cpp/build/debug/ -lprogbase-cpp
else:unix: LIBS += -L$$PWD/../../../../libprogbase-cpp/build/ -lprogbase-cpp

INCLUDEPATH += $$PWD/../../../../libprogbase-cpp/include
DEPENDPATH += $$PWD/../../../../libprogbase-cpp/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../libprogbase-cpp/build/release/libprogbase-cpp.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../libprogbase-cpp/build/debug/libprogbase-cpp.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../libprogbase-cpp/build/release/progbase-cpp.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../libprogbase-cpp/build/debug/progbase-cpp.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../libprogbase-cpp/build/libprogbase-cpp.a

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../libprogbase/build/release/ -lprogbase
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../libprogbase/build/debug/ -lprogbase
else:unix: LIBS += -L$$PWD/../../../../libprogbase/build/ -lprogbase

INCLUDEPATH += $$PWD/../../../../libprogbase/include
DEPENDPATH += $$PWD/../../../../libprogbase/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../libprogbase/build/release/libprogbase.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../libprogbase/build/debug/libprogbase.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../../libprogbase/build/release/progbase.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../../libprogbase/build/debug/progbase.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../../libprogbase/build/libprogbase.a
