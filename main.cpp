#include "mainwindow.h"
#include "app.h"
#include "okno.h"
#include "data.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    App mainProg;
    MainWindow w(nullptr,&mainProg);
    Okno e(nullptr,&mainProg);
    Data d(nullptr,&mainProg);
    w.show();
    return a.exec();
}
