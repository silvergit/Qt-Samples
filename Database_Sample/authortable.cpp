#include "authortable.h"


AuthorTable::AuthorTable()
{

}

AuthorTable::AuthorTable(QString forename, QString surname)
{
    this->forename = forename;
    this->surname = surname;
}

AuthorTable::AuthorTable(int id, QString forename, QString surname)
{
    this->id = id;
    this->forename = forename;
    this->surname = surname;
}

int AuthorTable::getId() const
{
    return id;
}

void AuthorTable::setId(int newId)
{
    id = newId;
}

const QString &AuthorTable::getForename() const
{
    return forename;
}

void AuthorTable::setForename(const QString &newForename)
{
    forename = newForename;
}

const QString &AuthorTable::getSurname() const
{
    return surname;
}

void AuthorTable::setSurname(const QString &newSurname)
{
    surname = newSurname;
}

QString AuthorTable::toString()
{

    QString str;
    str.append("{ID: ");
    str.append(QString::number(this->id));
    str.append(", Forename: ");
    str.append(this->forename);
    str.append(", Surname: ");
    str.append(this->surname);
    str.append("}");
    return str;

}
