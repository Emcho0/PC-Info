#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

// biblioteke potrebne za aplikaciju
#include <QMessageBox>
#include <QStorageInfo>
#include<QSysInfo>
#include <QFileIconProvider>
#include<QTimer>
#include<QFileSystemModel>
#include <QFontDatabase>
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
    // tipke za mijenjanje tema

    void on_yorumiAbyssButton_clicked();

    void on_yorumiMistButton_clicked();

    void on_yorumiKrakenButton_clicked();

    void on_yorumiShadeButton_clicked();

    void on_defaultThemeButton_clicked();


    // funkcije za pracenje hardverskih informacija
    void updateDrives();
    // void updateCPU();
    // void updateRAM();


    // funkcije za pracenje sistemskih informacija informacija
    // void showSysInfo();


private:
    Ui::MainWindow *ui;
     QFileSystemModel *model = nullptr;
    QTimer *timer;
};
#endif // MAINWINDOW_H
