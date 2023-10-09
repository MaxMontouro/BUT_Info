#include "testbd.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestBD w;
    w.show();
    return a.exec();
}
