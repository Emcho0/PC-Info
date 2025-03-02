#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


// Teme za aplikaciju
// Vise informacija na https://github.com/yorumicolors
void MainWindow::on_yorumiAbyssButton_clicked()
{
    qApp->setStyleSheet(""
                        "*{"
                        " font-size:20px"
                        "}"
                        ""
                        ""
                        "");
    QMessageBox::information(this,"Postavljanje Teme","Tema Yorumi Abyss je uspješno postavljena");
}


void MainWindow::on_yorumiMistButton_clicked()
{
    qApp->setStyleSheet(""
                        "*{"
                        " font-size:20px;"
                        "background-color: #BDBFCB;"
                        "}"
                        ""
                        ""
                        "");
    QMessageBox::information(this,"Postavljanje Teme","Tema Yorumi Mist je uspješno postavljena");
}


void MainWindow::on_yorumiKrakenButton_clicked()
{
    qApp->setStyleSheet(""
                        "*{"
                        " font-size:20px"
                        "}"
                        ""
                        ""
                        "");
    QMessageBox::information(this,"Postavljanje Teme","Tema Yorumi Kraken je uspješno postavljena");
}


void MainWindow::on_yorumiShadeButton_clicked()
{
    qApp->setStyleSheet(""
                        "*{"
                        " font-size:20px"
                        "}"
                        ""
                        ""
                        "");
    QMessageBox::information(this,"Postavljanje Teme","Tema Yorumi Shade je uspješno postavljena");
}



// default tema koja vraca na staro

void MainWindow::on_defaultThemeButton_clicked()
{
    qApp->setStyleSheet("");
    QMessageBox::information(this,"Postavljanje Teme","Tema je uspješno postavljena");
}

