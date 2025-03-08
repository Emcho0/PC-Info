#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemModel>
#include <QProcess>
#include <QTimer>
#include <QFileIconProvider>
#include <QStorageInfo>
#include <QSysInfo>
#include <QMessageBox>
#include <QFontDatabase>
#include <QColor>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Teme
    void on_yorumiAbyssButton_clicked();
    void on_yorumiMistButton_clicked();
    void on_yorumiKrakenButton_clicked();
    void on_yorumiShadeButton_clicked();
    void on_defaultThemeButton_clicked();

    // Hardverske informacije
    void updateDrives();
    void updateCPU();
    void updateRAM();

    // Sistemske informacije
    void showSysInfo();

private:
    Ui::MainWindow *ui;
    QFileSystemModel *model = nullptr;
    QTimer *driveTimer;
    QTimer *cpuTimer;
    QTimer *ramTimer;

    // Metode za CPU informacije
    QString getCPUName();
    int getCPUCores();

    // Metode za RAM informacije
    QString getTotalRAM();
    QString getAvailableRAM();
    double getRAMUsage();
};
#endif // MAINWINDOW_H
