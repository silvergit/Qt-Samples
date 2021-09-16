#ifndef AUTHORTABLE_H
#define AUTHORTABLE_H

#include <QString>

class AuthorTable
{
public:
    AuthorTable();
    AuthorTable(QString forename, QString surname);
    AuthorTable(int id, QString forename, QString surname);

    const QString TABLE_NAME = "author";
    const QString ID = "id";
    const QString FORENAME = "forename";
    const QString SURNAME = "surname";

    int getId() const;
    void setId(int newId);

    const QString &getForename() const;
    void setForename(const QString &newForename);

    const QString &getSurname() const;
    void setSurname(const QString &newSurname);

    QString toString();
private:
    int id;
    QString forename;
    QString surname;
};

#endif // AUTHORTABLE_H
