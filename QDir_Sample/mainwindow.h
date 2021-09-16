#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QListWidgetItem>
#include <QMainWindow>
#include <QDebug>

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

private:
    Ui::MainWindow *ui;
    void getAllDrives();

private slots:
    void isExistSlot();
    void fillDirsList(QString path);
    void onDoubleClickList(QListWidgetItem *item);
    void fillFilesList(QString path);
};
#endif // MAINWINDOW_H
