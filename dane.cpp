#include "dane.h"

Dane::Dane()
{
    setText("");
}

Dane::Dane(QString t,QDateTime dt,QString c,QString f,QString p)
{
    setText(t);
    setAll(dt);
    setFontColor(c);
    setFontStyle(f);
    setPicture(p);
}

void Dane::setFontColor(QString c)
{
    colorname = c;

    if(c=="Czerwony"){
       kolor=QColor(255,0,0);
    }
   if(c=="Zielony"){
       kolor=QColor(0,255,0);
   }
   if(c=="Niebieski"){
       kolor=QColor(0,0,255);
   }
}

void Dane::setFontStyle(QString f)
{
    font=f;
}

void Dane::setText(QString t)
{
    tekst=t;
}

//setter czasu i daty
void Dane::setAll(QDateTime dt)
{
    all = dt;
}

void Dane::setPicture(QString p)
{
    picture = p;
}

void Dane::setColorName(QString c)
{
    colorname = c;
}

//gettery
 QString Dane::getText()
{
    return tekst;
}

//getter czasu i daty
QDateTime Dane::getDt()
{
    return all;
}

QColor Dane::getFontColor()
{
    return kolor;
}

QString Dane::getFontStyle()
{
    return font;
}

QString Dane::getPicture()
{
    return picture;
}

QString Dane::getColorName()
{
    return colorname;
}

//operatory
bool Dane::operator==(Dane &instacja){

    return this->getDt()==instacja.getDt();
}

bool Dane::operator!=(Dane &instacja){

    return this->getDt()!=instacja.getDt();
}

bool Dane::operator<(Dane &instacja){

    return this->getDt()>instacja.getDt();
}
