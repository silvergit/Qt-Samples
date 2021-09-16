#include "datetimehelper.h"
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    DateTimeHelper myDate(1992, 11, 5);

    qDebug() << myDate.toString();

    DateTimeHelper myDate2("1993/11/02");
    qDebug() << myDate2.toString();

    qDebug() << "Current date: " << myDate.getCurrentDate().toString();

    qDebug() << "Compare(0 for equal, 1 for grather, -1 for smaller): " << myDate.compare(
                 myDate2.getDate());

    DateTimeHelper myDate3("2012-05-14");
    qDebug() << "Is leap year" << myDate3.getYear() << ": " << myDate3.isLeapYear();

    qDebug() << myDate3.toStringWithFormats();

    return a.exec();
}
