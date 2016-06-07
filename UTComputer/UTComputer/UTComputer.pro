QT += widgets \
    testlib

CONFIG += c++11

RC_ICONS = icon.ico

HEADERS += \
    calculator_exception.h \
    literal.h \
    complex_literal.h \
    expression_literal.h \
    number.h \
    literal_factory.h \
    atom_literal.h \
    stack.h \
    calculator.h \
    mainwindow.h \
    settings.h \
    edit_atom_dialog.h \
    edit_programm_dialog.h \
    settings_dialog.h \
    memento.h \
    string_literal.h \
    programm_literal.h

SOURCES += \
    calculator_exception.cpp \
    main.cpp \
    literal.cpp \
    complex_literal.cpp \
    tests/tests.cpp \
    expression_literal.cpp \
    number.cpp \
    literal_factory.cpp \
    atom_literal.cpp \
    stack.cpp \
    calculator.cpp \
    mainwindow.cpp \
    settings.cpp \
    edit_atom_dialog.cpp \
    edit_programm_dialog.cpp \
    settings_dialog.cpp \
    string_literal.cpp \
    programm_literal.cpp

FORMS += \
    mainwindow.ui \
    edit_atom_dialog.ui \
    edit_programm_dialog.ui \
    settings_dialog.ui
