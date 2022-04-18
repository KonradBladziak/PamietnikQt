#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent,App *app)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      mainApp(app)

{
    setFocusPolicy(Qt::ClickFocus);
    app->setGlowne(this);
    ui->setupUi(this);
    listaWyswietlaczy();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    mainApp->otworzEdycyjne();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    mainApp->przesylZapisz("wspomnienia.txt");
}

void MainWindow::on_wczytaj_clicked()
{
    QString sciezka = QFileDialog::getOpenFileName(this,"Open Image File","","*.txt");
    mainApp->przesylWczytaj(sciezka);
}

void MainWindow::on_zapisz_clicked()
{
    QString sciezka = QFileDialog::getOpenFileName(this,"Open Image File","","*.txt");
    mainApp->przesylZapisz(sciezka);
}

void MainWindow::on_pushButton_2_clicked()
{
   mainApp->nastepny();
}

void MainWindow::on_pushButton_3_clicked()
{
    mainApp->poprzedni();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    mainApp->strzalki(event);
}

void MainWindow::wheelEvent(QWheelEvent *event)
{
    mainApp->kolkoOdMyszki(event);
}

void MainWindow::on_usun_clicked()
{
    mainApp->usun();
}

void MainWindow::listaWyswietlaczy()
{
    wyswietlacze.push_back(ui->textEdit_poprzednie);
    wyswietlacze.push_back(ui->textEdit_aktualne);
    wyswietlacze.push_back(ui->textEdit_starsze);
}

void MainWindow::wyswietl(int p)
{
    int poczatek = p - 1;
    int licznik = 1;

    QList<Dane> lista = mainApp->pobierzWspomnienia();

 for (QTextEdit* elem : wyswietlacze){

     if(poczatek==0){
         elem->setFontWeight(QFont::Normal);
         elem->setFontItalic(false);
         elem->setTextColor("Black");
         elem->setText("Nie ma nowszego");
     }
     if(poczatek>0&&poczatek<lista.length()+1){

         elem->setTextColor(lista[poczatek-1].getFontColor());

         if(lista[poczatek-1].getFontStyle()=="Kursywa"){
         elem->setFontWeight(QFont::Normal);
         elem->setFontItalic(true);
         }

         if(lista[poczatek-1].getFontStyle()=="Pogrubiony"){
         elem->setFontWeight(QFont::Bold);
         elem->setFontItalic(false);
         }

         if(lista[poczatek-1].getFontStyle()=="Normalny"){
         elem->setFontWeight(QFont::Normal);
         elem->setFontItalic(false);
         }

         elem->setText(lista[poczatek-1].getText());
         elem->setFontItalic(false);
         elem->setFontWeight(QFont::Bold);
         elem->append(lista[poczatek-1].getDt().toString("dd-MM-yyyy  hh:mm"));

         if(licznik ==2){
         QImage zdjecie;
         QSize dims = ui->label->size();
         zdjecie = QImage(lista[poczatek-1].getPicture());
         ui->label->setPixmap(QPixmap::fromImage(zdjecie.scaled(dims)));
         }

     }
     if(poczatek>lista.length()){
         elem->setFontWeight(QFont::Normal);
         elem->setFontItalic(false);
         elem->setTextColor("Black");
         elem->setText("Nie ma starszego");
     }

     poczatek++;
     licznik++;
     if(lista.length()==0){
         ui->label->clear();
         ui->textEdit_aktualne->setText("Brak wspomnienia");
     }
}

}





