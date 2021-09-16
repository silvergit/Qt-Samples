#include "directoryhelper.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btnIsExist, &QPushButton::clicked, this, &MainWindow::isExistSlot);
    connect(ui->comboAllDrives, SIGNAL(currentIndexChanged(QString)), this,
            SLOT(fillDirsList(QString)));
    connect(ui->listDirs, &QListWidget::currentTextChanged, this, &MainWindow::fillFilesList);
    connect(ui->listDirs, &QListWidget::itemDoubleClicked, this, &MainWindow::onDoubleClickList);

    getAllDrives();

    DirectoryHelper d("");
    qDebug() << d.createDirectory("C:\\Test");

    qDebug() << d.rename("C:\\Test", "TestNew");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getAllDrives()
{
    DirectoryHelper d("");
    QStringList list = d.getDrivesList();
    ui->comboAllDrives->addItems(list);
}

void MainWindow::fillDirsList(QString path)
{
    ui->groupBox_list->setTitle(path);
    DirectoryHelper d;
    d.setDirPath(path);

    QStringList dirsList = d.getAllDirsInDir();

    ui->listDirs->clear();
    ui->listDirs->addItems(dirsList);
}

void MainWindow::fillFilesList(QString path)
{
    DirectoryHelper d;
    d.setDirPath(path);

    QStringList dirList = d.getAllDirsInDir();
    QStringList fileList = d.getAllFilesInDir();

    ui->listFiles->clear();
    ui->listFiles->addItems(dirList);
    ui->listFiles->addItems(fileList);
}

void MainWindow::onDoubleClickList(QListWidgetItem *item)
{
    fillDirsList(item->text());
    ui->listFiles->clear();
}

void MainWindow::isExistSlot()
{
    QString path = ui->leditIsExist->text();

    if (path.isEmpty()) {
        ui->lblIsExist->setText("Ther is no path");
        return;
    }

    DirectoryHelper d(path);
    bool isExist = d.isDirExists();

    if (isExist) {
        ui->lblIsExist->setText("Exist");
    } else {
        ui->lblIsExist->setText("Not exist");
    }
}

