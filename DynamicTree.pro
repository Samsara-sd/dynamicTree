#-------------------------------------------------
#
# Project created by QtCreator 2019-07-13T09:53:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DynamicTree
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
    main.cpp \
    viewmodel/viewmodel.cpp \
    app/app.cpp \
    common/common.cpp \
    common/parameters.cpp \
    common/treeInfo.cpp \
    model/model.cpp \
    view/sinks/MainWindowCommandSink.cpp \
    view/sinks/MainWindowPropertySink.cpp \
    view/view.cpp \
    viewmodel/commands/NodeCommand.cpp \
    viewmodel/sinks/ViewModelSink.cpp \
    viewmodel/commands/insertnodecommand.cpp \
    viewmodel/commands/deletenodecommand.cpp \
    viewmodel/commands/findnodecommand.cpp \
    viewmodel/commands/preordercommand.cpp \
    viewmodel/commands/postordercommand.cpp \
    viewmodel/commands/inordercommand.cpp \
    viewmodel/commands/changestylecommand.cpp


HEADERS += \
    viewmodel/viewmodel.h \
    app/app.h \
    common/common.h \
    common/etlbase.h \
    common/parameters.h \
    common/treeInfo.h \
    model/model.h \
    view/sinks/MainWindowCommandSink.h \
    view/sinks/MainWindowPropertySink.h \
    view/view.h \
    viewmodel/commands/NodeCommand.h \
    viewmodel/sinks/ViewModelSink.h \
    viewmodel/commands/insertnodecommand.h \
    viewmodel/commands/deletenodecommand.h \
    viewmodel/commands/findnodecommand.h \
    viewmodel/commands/preordercommand.h \
    viewmodel/commands/postordercommand.h \
    viewmodel/commands/inordercommand.h \
    viewmodel/commands/changestylecommand.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    view/images/bg.jpg \
    view/images/bg2.jpg \
    view/images/bg3.jpg \
    view/images/bg4.jpeg \
    view/images/1.png \
    view/images/LeftRotate.png \
    view/images/line1.png \
    view/images/line1_.png \
    view/images/line1__.png \
    view/images/line2.png \
    view/images/line2_.png \
    view/images/line2__.png \
    view/images/node.png \
    view/images/nodedelete.png \
    view/images/nodefind.png \
    view/images/nodeflash.png \
    view/images/nodeinsert.png \
    view/images/RightRotate.png \
    view/images/white.png
