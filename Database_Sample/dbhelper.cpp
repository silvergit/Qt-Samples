#include "authortable.h"
#include "dbhelper.h"
#include <QDebug>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QsqlTableModel>
#include <QSqlError>
///////////////////////////////////////////////////////////////////////////////////////////
DBHelper::DBHelper(const QString &path)
{
    mDb = QSqlDatabase::addDatabase("QSQLITE");
    mDb.setDatabaseName(path);

    if (!mDb.open()) {
        qDebug() << "ERROR: connection with database failed. " << mDb.lastError().text();
    } else {
        qDebug() << "Database: connection ok";
    }
}
///////////////////////////////////////////////////////////////////////////////////////////
QList<QString> DBHelper::fetchFieldFromTable(QString fieldName, QString tableName)
{
    QList<QString> fields;

    QString queryString =  QString("SELECT %1 FROM %2")
                           .arg(fieldName, tableName);

    QSqlQuery query(queryString);

    while (query.next()) {
        QString fetchField = query.value(0).toString();
        fields.append(fetchField);
    }

    return fields;
}
///////////////////////////////////////////////////////////////////////////////////////////
QList<AuthorTable *> DBHelper::fetchAuthors()
{
    QList<AuthorTable *> authors;

    QString stringQuery = QString("SELECT * FROM %1").arg(AuthorTable().TABLE_NAME);

    /***   QSqlQuery ***/
//    QSqlQuery query(stringQuery);
//    int idField = query.record().indexOf(AuthorTable().ID);
//    int forenameField = query.record().indexOf(AuthorTable().FORENAME);
//    int surnameField = query.record().indexOf(AuthorTable().SURNAME);

//    while (query.next()) {
//        QString id = query.value(idField).toString();
//        QString forename = query.value(forenameField).toString();
//        QString surename = query.value(surnameField).toString();

//        AuthorTable *author = new AuthorTable(id.toInt(), forename, surename);

//        authors.append(author);
//    }


    /***    QSqlQueryModel - READ ONLY  ***/
    QSqlQueryModel model;
    model.setQuery(stringQuery);
    for (int i = 0; i < model.rowCount(); ++i) {
        QString id = model.record(i).value(AuthorTable().ID).toString();
        QString forename = model.record(i).value(AuthorTable().FORENAME).toString();
        QString surname = model.record(i).value(AuthorTable().SURNAME).toString();

        AuthorTable *author = new AuthorTable(id.toInt(), forename, surname);
        authors.append(author);
    }

    /***    QSqlTableModel - READ & WRITE    ***/
//    QSqlTableModel model;
//    model.setTable(AuthorTable().TABLE_NAME);
//    model.setFilter("");
//    model.setSort(2, Qt::AscendingOrder);
//    model.select();

//    for (int i = 0; i < model.rowCount(); ++i) {
//        int id = model.record(i).value(AuthorTable().ID).toInt();
//        QString forename = model.record(i).value(AuthorTable().FORENAME).toString();
//        QString surname = model.record(i).value(AuthorTable().SURNAME).toString();

//        AuthorTable *author = new AuthorTable(id, forename, surname);
//        authors.append(author);
//    }

    return authors;
}
///////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////
QSqlTableModel *DBHelper::fetchAuthorsAsModel()
{
    QString stringQuery = QString("SELECT * FROM %1").arg(AuthorTable().TABLE_NAME);

    /***    QSqlTableModel - READ & WRITE    ***/
    QSqlTableModel *model = new QSqlTableModel;
    model->setTable(AuthorTable().TABLE_NAME);
    model->setFilter("");
    model->setSort(2, Qt::AscendingOrder);
    model->select();

    return model;
}
///////////////////////////////////////////////////////////////////////////////////////////
AuthorTable DBHelper::fetchAuthor(int id)
{

    QString stringQuery = QString("SELECT * FROM %1 WHERE id=%2").arg(AuthorTable().TABLE_NAME).arg(id);
    AuthorTable author;

    /***    QSqlQueryModel - READ ONLY  ***/
    QSqlQueryModel model;
    model.setQuery(stringQuery);

    if (model.rowCount() != 0) {
        int id = model.record(0).value(AuthorTable().ID).toInt();
        QString forename = model.record(0).value(AuthorTable().FORENAME).toString();
        QString surname = model.record(0).value(AuthorTable().SURNAME).toString();

        author.setId(id);
        author.setForename(forename);
        author.setSurname(surname);
    } else {
        author.setId(-1);
        author.setForename("");
        author.setSurname("");
    }

    return author;
}
///////////////////////////////////////////////////////////////////////////////////////////
bool DBHelper::insertAuthor(AuthorTable author)
{
    QSqlQuery query("INSERT INTO " + author.TABLE_NAME + " (" + author.FORENAME + ", " + author.SURNAME
                    +
                    ") "
                    "VALUES (\"" + author.getForename() + "\", \"" + author.getSurname() + "\")");

    /***   QSqlQuery ***/
//    if (query.exec()) {
//        return true;
//    } else {
//        return false;
//    }


    /***    QSqlQueryModel - READ ONLY  ***/
    QSqlQueryModel model;
    model.setQuery(query);
    if (model.lastError().isValid())
        qDebug() << model.lastError().text();
    else {
        qDebug() << "Insert is successful";
    }


    /***    QSqlTableModel - READ & WRITE    ***/
//    QSqlTableModel model;
//    model.setTable(AuthorTable().TABLE_NAME);
//    int row = model.rowCount();
//    model.insertRow(row);
//    model.setData(model.index(row, 1), author.getForename());
//    model.setData(model.index(row, 2), author.getSurname());

//    if (model.lastError().isValid())
//        qDebug() << model.lastError().text();
//    else {
//        qDebug() << "Insert is successful";
    //    }
}
///////////////////////////////////////////////////////////////////////////////////////////
bool DBHelper::deleteAuthor(int id)
{
    QString deleteQuery = "DELETE FROM " +
                          AuthorTable().TABLE_NAME +
                          " WHERE " +
                          AuthorTable().ID +
                          "=" +
                          QString::number(id) +
                          ";";
    QSqlQuery query(deleteQuery);

    qDebug () << deleteQuery;

    /***   QSqlQuery ***/
    if (query.exec()) {
        return true;
    } else {
        return false;
    }
}


