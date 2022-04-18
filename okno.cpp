#include "okno.h"
#include "ui_okno.h"


Okno::Okno(QWidget *parent,App *app)
    : QDialog(parent),
    ui(new Ui::Okno),
    mainApp(app)
{
    app->setEdycyjne(this);
    ui->setupUi(this);
    domyslny();
    wypelnianie();
    aktualnyCzas();
}

Okno::~Okno()
{
    delete ui;
}

void Okno::on_pushButton_2_clicked()
{
    this->close();
}
void Okno::domyslny()
{
    instancja.setPicture("Brak.png");
}

void Okno::wypelnianie()
{
    ui->fontColor->addItems({"Czerwony","Zielony","Niebieski"});
    ui->fontStyle->addItems({"Normalny","Kursywa","Pogrubiony"});
}

void Okno::aktualnyCzas()
{
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
}

void Okno::on_pushButton_3_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"Open Image File","","*.png *.bmp *.jpg");
    instancja.setPicture(filename);
}

void Okno::on_pushButton_clicked()
{
    instancja.setFontColor(ui->fontColor->currentText());
    instancja.setFontStyle(ui->fontStyle->currentText());
    instancja.setText(ui->textEdit->toPlainText());
    instancja.setAll(ui->dateTimeEdit->dateTime());
    mainApp->przesylijInstancje(instancja);
}








