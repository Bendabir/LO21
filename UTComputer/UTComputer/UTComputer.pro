QT += widgets \
    testlib

CONFIG += c++11


HEADERS += \
    calculator_exception.h \
    literal.h \
    complex_literal.h \
    expression_literal.h \
    number.h \
    literal_factory.h \
    atom_literal.h

SOURCES += \
    calculator_exception.cpp \
    main.cpp \
    literal.cpp \
    complex_literal.cpp \
    tests/tests.cpp \
    expression_literal.cpp \
    number.cpp \
    literal_factory.cpp \
    atom_literal.cpp
