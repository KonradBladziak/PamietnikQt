#include "data.h"

Data::Data(QObject *parent,App *app)
    : QObject(parent),
    mainApp(app)
{
    wczytaj("wspomnienia.txt");
    app->setWarstwaDanych(this);
    app->poka();

}

void Data::wpisz(Dane &instacja)
{

   lista.push_back(instacja);
   for (Dane& temp : lista){
     if(temp==instacja){
       temp=instacja;
     }
   }
   sortuj(lista);

}

void Data::sortuj(QList<Dane> &lista)
{
    std::sort(lista.begin(), lista.end());
    auto v_powtorzone = std::unique(lista.begin(), lista.end());
    lista.erase(v_powtorzone, lista.end());
}

void Data::wczytaj(QString sciezka)
{
       lista.clear();

       wspomnienia.setFileName(sciezka);

       if(wspomnienia.size()!=0){

            if(wspomnienia.open(QIODevice::ReadOnly)){

            QTextStream dane(&wspomnienia);

            Dane instancja;

                while(!dane.atEnd()){

                QString linia = dane.readLine();

                QStringList temp = linia.split(";");

                instancja.setText(temp[0]);
                instancja.setAll(QDateTime::fromString(temp[1]));
                instancja.setFontColor(temp[2]);
                instancja.setFontStyle(temp[3]);
                instancja.setPicture(temp[4]);
                wpisz(instancja);
                }
            }
       }
       wspomnienia.close();
}

void Data::zapisz(QString sciezka)
{
    wspomnienia.setFileName(sciezka);

    if(wspomnienia.open(QIODevice::WriteOnly)){

        QTextStream dane(&wspomnienia);

        for (Dane& elem : lista){

            dane << elem.getText() + ";" + elem.getDt().toString() + ";" + elem.getColorName() + ";" + elem.getFontStyle() + ";" + elem.getPicture()  + '\n';
        }
    }
    wspomnienia.close();
}

void Data::usun()
{
    int pozycja = mainApp->getPozycja();
    if(lista.length()>0 && pozycja-1 < lista.length()){
    lista.removeAt(pozycja-1);
    auto v_powtorzone = std::unique(lista.begin(), lista.end());
    lista.erase(v_powtorzone, lista.end());
    if(pozycja>1){
    pozycja--;
    mainApp->setPozycja(pozycja);
    }
    mainApp->poka();
    }
}

QList<Dane> Data::getWspomnienia()
{
    return lista;
}


