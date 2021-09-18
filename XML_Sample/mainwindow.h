#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "student.h"
#include <QMainWindow>
#include <qboxlayout.h>
#include <qpushbutton.h>
#include <qtablewidget.h>

class MainWindow : public QMainWindow {
    Q_OBJECT

    public:
    MainWindow (QWidget* parent = nullptr);
    QList<Student> readXML ();
    ~MainWindow ();

    private:
    QList<Student>* students;
    QTableWidget* table;
    QWidget* widget;
    QVBoxLayout* mainLayout;
    QHBoxLayout* btnLayout;
    QPushButton* loadBtn;
    QPushButton* loadFromFileBtn;
    QPushButton* saveToFileBtn;

    private slots:
    void LoadXMLFromResources ();
    void loadXMLFile ();
    void saveXMLFile ();
};

#endif // MAINWINDOW_H
