#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    model = new QFileSystemModel;
    // Azuriranje informacije o diskovima
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDrives);
    timer->start(1000);
    // Azuriranje CPU informacija
    // timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &MainWindow::updateCPU);
    // timer->start(1000);
    // Azuriranje RAM informacija
    // timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, &MainWindow::updateRAM);
    // timer->start(1000);
}

MainWindow::~MainWindow() { delete ui; }

// Teme za aplikaciju
// Vise informacija na https://github.com/yorumicolors
void MainWindow::on_yorumiAbyssButton_clicked() {
    int id = QFontDatabase::addApplicationFont(":/NewFont/Font/GeistMono.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);

    QString yorumiAbyss = R"(
    * {
      font-family: )" + family +
                          R"(;
font-size: 15px;
    }

    QMainWindow {
      background-color: #060914;
    }

    QTabWidget::pane {
      border: 1px solid lightgray;
      border-radius: 5px;
      top: -1px;
      background: #1D202B;
    }

    QTabBar::tab {
      background: #121520;
      border-radius: 5px;
      border: 1px solid lightgray;
      padding: 10px 15px;
    }

    QTabBar::tab:selected {
      background: #343742;
color: #C6DFEC;
      margin-bottom: -1px;
    }

    QLineEdit {
      border-radius: 5px;
      background-color: #74c7ec;
      color: rgb(17, 17, 27);
      padding: 5px 10px;
    }

    QCheckBox {
      color: rgb(205, 214, 244);
    }

    QPushButton {
      border-radius: 5px;
      background-color: #343742;
      color: #C6DFEC;
      padding: 10px 15px;
      border: none;
    }

    QPushButton:hover {
      background-color: #5c526c;
    }

    QPushButton:pressed {
      background-color: #454057;
    }

    QTreeView {
      background-color: rgb(88, 91, 112);
      color: rgb(180, 190, 254);
      border: 5px solid lightgray;
    }

    QListWidget {
      background-color: #1D202B
      color: #BDBFCB;
    }

    QListWidget::item {
      padding: 10px;
      border-width: 2.5px;
    }

    QListWidget::item:selected {
      background-color: #CCCCCC;
    }

    QStatusBar {
      color: rgb(205, 214, 244);
    }
  )";

    qApp->setStyleSheet(yorumiAbyss);
    QMessageBox::information(this, "Postavljanje Teme",
                             "Tema Yorumi Abyss je uspješno postavljena");
}

void MainWindow::on_yorumiMistButton_clicked() {
    int id = QFontDatabase::addApplicationFont(":/NewFont/Font/GeistMono.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QString yorumiMist = R"(
    * {
      font-family: )" + family +
                         R"(;
      font-size: 15px;
      color: #060914;
    }

    QMainWindow {
      background-color: #BDBFCB;
    }

    QTabWidget::pane {
      border: 1px solid #878996;
      border-radius: 5px;
      background: #878996;
    }

    QTabBar::tab {
      background: #1D202B;
      border-radius: 5px;
      border: 1px solid #878996;
      padding: 10px 15px;
      color: #BDBFCB;
    }

    QTabBar::tab:selected {
      background: #BDBFCB;
      color: #060914;
      margin-bottom: -1px;
    }

    QPushButton {
      border-radius: 5px;
      background-color: #343742;
      color: #BDBFCB;
      padding: 10px 15px;
      border: none;
    }

    QPushButton:hover {
      background-color: #A7A9B5;
    }

    QPushButton:pressed {
      background-color: #878996;
    }

    QTreeView {
      background-color: #1C4642;
      color: #BDBFCB;
      border: 2px solid #878996;
    }

    QListWidget {
      background-color: #BDBFCB;
      color: #060914;
    }

    QListWidget::item {
      padding: 10px;
      border-width: 2.5px;
    }

    QListWidget::item:selected {
      background-color: #343742;
      color: #BDBFCB;
    }

    QStatusBar {
      color: #060914;
    }
  )";

    qApp->setStyleSheet(yorumiMist);
    QMessageBox::information(this, "Postavljanje Teme",
                             "Tema Yorumi Mist je uspješno postavljena");
}

void MainWindow::on_yorumiKrakenButton_clicked() {
    int id = QFontDatabase::addApplicationFont(":/NewFont/Font/GeistMono.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QString yorumiKraken = R"(
    * {
      font-family: )" + family +
                           R"(;
font-size: 15px;
    }

    QMainWindow {
      background-color: #0E0D17;
    }

    QTabWidget::pane {
      border: 1px solid #AD8FD6;
      border-radius: 5px;
      top: -1px;
      background: #0E0D17;
    }

    QTabBar::tab {
      background: #121520;
      border-radius: 5px;
      border: 1px solid #A7A9B5;
      padding: 10px 15px;
    }

    QTabBar::tab:selected {
      background: #0E0D17;
      color: #C0BCE6;
      margin-bottom: -1px;
    }

    QPushButton {
      border-radius: 5px;
      background-color: #343742;
      color: #C0BCE6;
      padding: 10px 15px;
      border: none;
    }

    QPushButton:hover {
      background-color: #121520;
    }

    QPushButton:pressed {
      background-color: #A7A9B5;
    }

    QTreeView {
      background-color: #0E121F;
      color: #C0BCE6;
      border: 5px solid #AD8FD6;
    }

    QListWidget {
      background-color: #C0BCE6;
      color: #0E0D17;
    }

    QListWidget::item {
      padding: 10px;
      border-width: 2.5px;
    }

    QListWidget::item:selected {
      background-color: #A7A9B5;
    }

    QStatusBar {
      color: #C0BCE6;
    }
  )";
    qApp->setStyleSheet(yorumiKraken);

    QMessageBox::information(this, "Postavljanje Teme",
                             "Tema Yorumi Kraken je uspješno postavljena");
}

void MainWindow::on_yorumiShadeButton_clicked() {
    int id = QFontDatabase::addApplicationFont(":/NewFont/Font/GeistMono.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QString yorumiShade = R"(
    * {
      font-family: )" + family +
                          R"(;
font-size: 15px;
    }

    QMainWindow {
      background-color: #0F1015;
    }

    QTabWidget::pane {
      border: 1px solid #878996;
      border-radius: 5px;
      top: -1px;
      background: #15171D;
    }

    QTabBar::tab {
      background: #1D202B;
      border-radius: 5px;
      border: 1px solid #878996;
      padding: 10px 15px;
    }

    QTabBar::tab:selected {
      background: #0F1015;
      color: #BDBFCB;
      margin-bottom: -1px;
    }

    QPushButton {
      border-radius: 5px;
      background-color: #343742;
      color: #BDBFCB;
      padding: 10px 15px;
      border: none;
    }

    QPushButton:hover {
      background-color: #121520;
    }

    QPushButton:pressed {
      background-color: #878996;
    }

    QTreeView {
      background-color: #0F1015;
      color: #BDBFCB;
      border: 5px solid #878996;
    }

    QListWidget {
      background-color: #BDBFCB;
      color: #0F1015;
    }

    QListWidget::item {
      padding: 10px;
      border-width: 2.5px;
    }

    QListWidget::item:selected {
      background-color: #878996;
    }

    QStatusBar {
      color: #BDBFCB;
    }
  )";

    qApp->setStyleSheet(yorumiShade);
    QMessageBox::information(this, "Postavljanje Teme",
                             "Tema Yorumi Shade je uspješno postavljena");
}

// default tema koja vraca na staro

void MainWindow::on_defaultThemeButton_clicked() {
    qApp->setStyleSheet("");
    QMessageBox::information(this, "Postavljanje Teme",
                             "Tema je uspješno postavljena");
}

// hardverske informacije
// informacije o disku
void MainWindow::updateDrives() {
    QList<QStorageInfo> diskovi = QStorageInfo::mountedVolumes();
    ui->diskList->clear();

    QFileIconProvider iconProvider;

    for (const QStorageInfo &drive : diskovi) {
        if (!drive.isReady() || drive.isReadOnly()) continue;

        QString driveName = drive.displayName();
        quint64 bytesFree = drive.bytesFree();
        quint64 bytesTotal = drive.bytesTotal();

        QListWidgetItem *item = new QListWidgetItem;

        QString storageText =
            QString::number(bytesFree / 1024 / 1024 / 1024) + " GB free of " +
            QString::number(bytesTotal / 1024 / 1024 / 1024) + " GB";

        item->setIcon(iconProvider.icon(QFileIconProvider::Drive));
        item->setText(driveName + "\n" + storageText);

        item->setData(Qt::UserRole, drive.rootPath());

        ui->diskList->addItem(item);
    }
}

// softverske informacije
// informacije o sistemu
// void MainWindow::showSysInfo(){
//     QList<QSysInfo> info = {QSysInfo::prettyProductName(),
//     QSysInfo::buildCpuArchitecture(),};
// }
