#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// biblioteke potrebne za aplikaciju
#include <QMessageBox>
#include <QStorageInfo>
#include<QSysInfo>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_yorumiAbyssButton_clicked();

    void on_yorumiMistButton_clicked();

    void on_yorumiKrakenButton_clicked();

    void on_yorumiShadeButton_clicked();

    void on_defaultThemeButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
