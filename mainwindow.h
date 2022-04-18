#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QKeyEvent>
#include <QMouseEvent>
#include <QList>
#include <QVector>
#include <QMainWindow>
#include <QTextEdit>
#include <QImage>
#include "app.h"
#include "okno.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class App;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr,
               App *app=nullptr);
    ~MainWindow();

    void wyswietl(int p);
    void listaWyswietlaczy();

private slots:

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void keyPressEvent(QKeyEvent *event) override;
    void wheelEvent(QWheelEvent *event) override;
    void closeEvent(QCloseEvent *event) override;
    void on_wczytaj_clicked();
    void on_zapisz_clicked();
    void on_usun_clicked();

private:

    QVector<QTextEdit*> wyswietlacze;
    Ui::MainWindow *ui=nullptr;
    App *mainApp=nullptr;
};
#endif // MAINWINDOW_H
