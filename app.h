#ifndef APP_H
#define APP_H
#include <QObject>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QList>
#include "dane.h"
#include "qdebug.h"
#include "mainwindow.h"
#include "okno.h"
#include "data.h"

class Data;
class MainWindow;
class Okno;

class App : public QObject
{
    Q_OBJECT
public:
    explicit App(QObject *parent = nullptr);

    void setGlowne(MainWindow *ui = nullptr) {Glowne = ui;};
    void setEdycyjne(Okno *ui = nullptr) {Edycyjne = ui;};
    void setWarstwaDanych(Data *ui = nullptr){Data = ui;};
    void otworzEdycyjne();
    void przesylijInstancje(Dane &instacja);
    void przesylWczytaj(QString sciezka);
    void przesylZapisz(QString sciezka);
    void poka();

    //klawisze
    void usun();
    void zamknij();
    void nastepny();
    void poprzedni();
    void strzalki(QKeyEvent *event);
    void kolkoOdMyszki(QWheelEvent *event);

    //do wyswietlania
    QList<Dane> pobierzWspomnienia();
    void setPozycja(int x);
    int getPozycja();

private:
   MainWindow *Glowne = nullptr;
   Okno *Edycyjne = nullptr;
   Data *Data=nullptr;
   int pozycja = 1;
};

//PROGRAM URUCHAMIAM BEZ SHADOW BUILD

#endif // APP_H
