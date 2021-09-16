#include "qfilehelper.h"

#include <QCoreApplication>
#include <QString>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFileHelper helper;
    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    qInfo() << "Path: " << path;

    QByteArray data("Hello world!\r\n");

    for (int i = 0; i < 5; i++) {
        QString num = QString::number(i);
        num.append(" ");

        QByteArray line(num.toLatin1() + data);
        //helper.write(path, line);
        helper.append(path, line);
    }

    QByteArray bytes;
    bool readResult = helper.read(path, bytes);

    if (readResult) {
        qInfo() << bytes;
    }

    return a.exec();
}
