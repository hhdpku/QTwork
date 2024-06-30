QT       += core gui \
            quick \
            charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ALL.cpp \
    addddldialog.cpp \
    adddiarydialog.cpp \
    ddldialog.cpp \
    diarydiolog.cpp \
    func.cpp \
    main.cpp \
    mainwindow.cpp \
    modify.cpp \
    modifyddldialog.cpp \
    searching.cpp \
    yuedubaogao.cpp

HEADERS += \
    ALL.h \
    addddldialog.h \
    adddiarydialog.h \
    ddldialog.h \
    diarydiolog.h \
    func.h \
    mainwindow.h \
    modify.h \
    modifyddldialog.h \
    searching.h \
    yuedubaogao.h

FORMS += \
    mainwindow.ui \
    modify.ui \
    searching.ui \
    yuedubaogao.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
