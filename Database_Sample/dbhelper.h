#ifndef DBHELPER_H
#define DBHELPER_H

#include <QList>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QString>
#include "authortable.h"

class DBHelper
{
public:
    DBHelper(const QString &path);
    QList<QString> fetchFieldFromTable(QString fieldName, QString tableName);
    QList<AuthorTable *> fetchAuthors();
    QSqlTableModel *fetchAuthorsAsModel();
    AuthorTable fetchAuthor(int id);
    bool insertAuthor(AuthorTable author);
    bool deleteAuthor(int id);

private:
    QSqlDatabase mDb;
};

#endif // DBHELPER_H
