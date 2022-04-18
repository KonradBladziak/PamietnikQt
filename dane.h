#ifndef DANE_H
#define DANE_H
#include <QList>
#include <QDate>
#include <QColorDialog>
class Dane
{

    QString tekst;
    QDateTime all;
    QColor kolor;
    QString font;
    QString picture;
    QString colorname;

public:

    Dane();

    Dane(QString t,QDateTime dt,QString c,QString f,QString p);

    //Settery
     void setFontColor(QString c);
     void setFontStyle(QString f);
     void setText(QString t);
     void setAll(QDateTime dt);
     void setPicture(QString p);
     void setColorName(QString c);

     //Gettery
      QString getText();
      QDateTime getDt();
      QColor getFontColor();
      QString getFontStyle();
      QString getPicture();
      QString getColorName();

      //operatory
      bool operator==(Dane &instacja);
      bool operator!=(Dane &instancja);
      bool operator<(Dane &instacja);


 };

#endif // DANE_H
