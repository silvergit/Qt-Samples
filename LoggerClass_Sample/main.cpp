#include <QCoreApplication>
#include "test.h"
#include "logger.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "File: " << Logger::fileName;
    Logger::attach();

    qInfo() << "test";

    Logger::logging = false;
    qInfo() << "Don't log this!";

    Logger::logging = true;
    test t;
    t.testing();

    qInfo() << "Finished";

    return a.exec();
}
