#include "datetimehelper.h"

DateTimeHelper::DateTimeHelper(int year, int month, int day) : m_Year(year), m_Month(month),
    m_Day(day) {}

DateTimeHelper::DateTimeHelper(QString date)
{
    if (date.length() == 10) {
        m_Year  = date.midRef(0, 4).toInt() ;
        m_Month = date.midRef(5, 2).toInt();
        m_Day   = date.midRef(8, 2).toInt();
    }
}

QDate DateTimeHelper::getDate()
{
    QDate date(m_Year, m_Month, m_Day);
    return date;
}

QDate DateTimeHelper::getCurrentDate()
{
    return QDate::currentDate();
}

int DateTimeHelper::compare(const QDate date)
{
    QDate first_date(m_Year, m_Month, m_Day);

    if (first_date == date)
        return 0;
    else if (first_date > date)
        return 1;
    else
        return -1;

    QDate d;
    d.toString();
}

bool DateTimeHelper::isLeapYear()
{
    return QDate::isLeapYear(m_Year);
}

QString DateTimeHelper::toString()
{
    return getDate().toString();
}

QStringList DateTimeHelper::toStringWithFormats()
{
    QDate date(m_Year, m_Month, m_Day);
    QStringList list;

    list << date.toString(Qt::TextDate);
    list << date.toString(Qt::ISODate);
    list << date.toString(Qt::SystemLocaleShortDate);
    list << date.toString(Qt::SystemLocaleLongDate);
    list << date.toString(Qt::DefaultLocaleShortDate);
    list << date.toString(Qt::DefaultLocaleLongDate);
    list << date.toString(Qt::SystemLocaleDate);
    list << date.toString(Qt::LocaleDate);

    return list;
}

int DateTimeHelper::getYear() const
{
    return m_Year;
}

void DateTimeHelper::setYear(int newYear)
{
    m_Year = newYear;
}

int DateTimeHelper::getMonth() const
{
    return m_Month;
}

void DateTimeHelper::setMonth(int newMonth)
{
    m_Month = newMonth;
}

int DateTimeHelper::getDay() const
{
    return m_Day;
}

void DateTimeHelper::setDay(int newDay)
{
    m_Day = newDay;
}
