QT -= gui

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
    ViewModelTest.cpp \
    ../common/parameters.cpp \
    ../common/treeInfo.cpp \
    ../model/model.cpp \
    ../viewmodel/commands/changestylecommand.cpp \
    ../viewmodel/commands/deletenodecommand.cpp \
    ../viewmodel/commands/findnodecommand.cpp \
    ../viewmodel/commands/inordercommand.cpp \
    ../viewmodel/commands/insertnodecommand.cpp \
    ../viewmodel/commands/NodeCommand.cpp \
    ../viewmodel/commands/postordercommand.cpp \
    ../viewmodel/commands/preordercommand.cpp \
    ../viewmodel/sinks/ViewModelSink.cpp \
    ../viewmodel/viewmodel.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    ViewModelTest.h \
    ../common/etlbase.h \
    ../common/parameters.h \
    ../common/treeInfo.h \
    ../model/model.h \
    ../viewmodel/commands/changestylecommand.h \
    ../viewmodel/commands/deletenodecommand.h \
    ../viewmodel/commands/findnodecommand.h \
    ../viewmodel/commands/inordercommand.h \
    ../viewmodel/commands/insertnodecommand.h \
    ../viewmodel/commands/NodeCommand.h \
    ../viewmodel/commands/postordercommand.h \
    ../viewmodel/commands/preordercommand.h \
    ../viewmodel/sinks/ViewModelSink.h \
    ../viewmodel/viewmodel.h
