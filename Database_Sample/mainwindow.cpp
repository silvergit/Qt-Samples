#include "authortable.h"
#include "dbhelper.h"
#include "mainwindow.h"

#include <QDir>
#include <QDebug>
#include <QString>
#include <QList>
#include <QTableView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QDir dir("C:/Users/pazho/Documents/testDb.db");
    qDebug() << dir.absolutePath();

    DBHelper db(dir.absolutePath());

    QList<QString> forenames = db.fetchFieldFromTable(AuthorTable().FORENAME,
                                                      AuthorTable().TABLE_NAME);
    QList<QString> surnames = db.fetchFieldFromTable(AuthorTable().SURNAME,
                                                     AuthorTable().TABLE_NAME);

    qDebug() << forenames;
    qDebug() << surnames;

    AuthorTable a("sdsds", "9999");
    //qDebug() << db.insertAuthor(a);

    QList<AuthorTable *> authors = db.fetchAuthors();

    for (int i = 0; i < authors.size(); i++)
        qDebug() << authors.at(i)->toString();

    int searchId = 10;


    AuthorTable at = db.fetchAuthor(searchId);
    if (at.getId() > 0)
        qDebug() << at.toString();
    else
        qDebug() << "ID: " << searchId << " not find in table";

    if (db.deleteAuthor(6)) {
        qDebug() << "ID:6 deleted";
    } else {
        qDebug() << "ID:6 not exist";
    }

    authors = db.fetchAuthors();
    for (int i = 0; i < authors.size(); i++)
        qDebug() << authors.at(i)->toString();




    QSqlTableModel *model = db.fetchAuthorsAsModel();

//    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
//    model->setHeaderData(1, Qt::Horizontal, QObject::tr("fore name"));
//    model->setHeaderData(2, Qt::Horizontal, QObject::tr("sur name"));
    QTableView *view = new QTableView;
    view->setModel(model);
    view->show();
}

MainWindow::~MainWindow()
{
}

