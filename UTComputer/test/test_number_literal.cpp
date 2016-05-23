//#include <QObject>
//#include <QtTest/QTest>

//#include "../src/number_literal.h"

//class TestNumberLiteral : public QObject {
//    Q_OBJECT

//private slots:
//    void add_data();
//    void add();
//};

//void TestNumberLiteral::add_data()
//{
//    QTest::addColumn<int>("operation");
//    QTest::addColumn<int>("result");

//    IntegerLiteral i = 2;
//    RealLiteral x = 2.5;
//    int j = 3;

//    QTest::newRow("entier + entier") << j << 3;
////    QTest::newRow("réel + réel") << (x + x) << 5;
////    QTest::newRow("entier + réel") << (i + x) << 4.5;
////    QTest::newRow("réel + entier") << (x + i) << 4.5;
//}

//void TestNumberLiteral::add()
//{
//    QFETCH(int, operation);
//    QFETCH(int, result);

//    QCOMPARE(operation, result);
//}

//QTEST_MAIN(TestNumberLiteral)
//#include "test_number_literal.moc"
