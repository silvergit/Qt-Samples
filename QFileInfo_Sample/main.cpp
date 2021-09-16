#include <QCoreApplication>
#include "fileinfohelper.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    FileInfoHelper helper;

    helper.list(QDir::tempPath());

    return a.exec();
}
