#ifndef DATA_H
#define DATA_H
#include <QList>
#include <QMainWindow>
#include <QTextEdit>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include "dane.h"
#include "app.h"

class App;

class Data : public QObject
{
    Q_OBJECT
public:

    explicit Data(QObject *parent = nullptr,App *app=nullptr);
    void wpisz(Dane& instancja);
    void sortuj(QList <Dane>&x);
    void wczytaj(QString sciezka);
    void zapisz(QString sciezka);
    void usun();
    QList<Dane> getWspomnienia();

private:
    QFile wspomnienia;
    QList <Dane>lista;
    App *mainApp=nullptr;

};

#endif // DATA_H
