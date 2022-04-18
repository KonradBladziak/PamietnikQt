#include "app.h"

App::App(QObject *parent) : QObject(parent)
{

}
//otwieranie okna
void App::otworzEdycyjne()
{
    Edycyjne = new Okno(Glowne,this);
    Edycyjne->exec();
    delete Edycyjne;
}

void App::przesylijInstancje(Dane &instacja)
{
    Data->wpisz(instacja);
    poka();
}

void App::przesylWczytaj(QString sciezka)
{
    Data->wczytaj(sciezka);
    poka();
}

void App::przesylZapisz(QString sciezka)
{
    Data->zapisz(sciezka);
}

void App::poka()
{
    Glowne->wyswietl(pozycja);
}

void App::usun()
{
    Data->usun();
}
//Klawisze
QList<Dane> App::pobierzWspomnienia()
{
    return Data->getWspomnienia();
}

void App::nastepny()
{
    if(pozycja >= 1 && pozycja < pobierzWspomnienia().length()){
    pozycja++;
    Glowne->wyswietl(pozycja);
    }
}

void App::poprzedni()
{
    if(pozycja > 1 && pozycja <= pobierzWspomnienia().length()){
    pozycja--;
    Glowne->wyswietl(pozycja);
    }
}

void App::strzalki(QKeyEvent *event)
{
    int przycisk = event->key();
    switch(przycisk){
    case Qt::Key_Down:
            nastepny();
            break;
    case Qt::Key_Up:
            poprzedni();
            break;
    }
}

void App::kolkoOdMyszki(QWheelEvent *event)
{
    if(event->angleDelta().y() > 0){
        poprzedni();
    }
    else if(event->angleDelta().y() < 0){
        nastepny();
    }
}

void App::setPozycja(int x)
{
    pozycja = x;
}

int App::getPozycja()
{
    return pozycja;
}

