#ifndef OKNO_H
#define OKNO_H

#include <QDialog>
#include <QImage>
#include <QColorDialog>
#include <QFileDialog>
#include "dane.h"
#include "app.h"

namespace Ui { class Okno; }

class App;

class Okno : public QDialog
{
    Q_OBJECT

public:
    explicit Okno(QWidget *parent=nullptr,App *app=nullptr);
    ~Okno();

private slots:
    void domyslny();
    void wypelnianie();
    void aktualnyCzas();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Dane instancja;
    Ui::Okno *ui = nullptr;
    App *mainApp = nullptr;
};

#endif // OKNO_H
