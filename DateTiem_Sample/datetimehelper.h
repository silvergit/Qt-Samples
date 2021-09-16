#ifndef DATETIMEHELPER_H
#define DATETIMEHELPER_H

#include <QDate>
#include <QTime>
#include <QDebug>

class DateTimeHelper
{
public:

    DateTimeHelper();
    DateTimeHelper(int year, int month, int day);
    DateTimeHelper(QString date);

    QDate getDate();
    QDate getCurrentDate();
    int compare(const QDate date);
    bool isLeapYear();
    QString toString();
    QStringList toStringWithFormats();

    int getYear() const;
    int getMonth() const;
    int getDay() const;
    void setYear(int newYear);
    void setMonth(int newMonth);
    void setDay(int newDay);

private:
    int m_Year;
    int m_Month;
    int m_Day;


};

#endif // DATETIMEHELPER_H
