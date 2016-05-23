QT += widgets \
    testlib

CONFIG += c++11

HEADERS += \
    src/exceptions.h \
    src/literal.h \
    src/digital_literal.h \
    src/rational_literal.h \
    src/number_literal.h \
    src/literal_factory.h

SOURCES += \
    src/main.cpp \
    src/digital_literal.cpp \
    src/literal.cpp \
    src/rational_literal.cpp \
    src/number_literal.cpp \
    test/test_number_literal.cpp \
    src/literal_factory.cpp
