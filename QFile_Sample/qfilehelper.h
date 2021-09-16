#ifndef QFILEHELPER_H
#define QFILEHELPER_H

#include <QFile>
#include <QIODevice>
#include <QDir>
#include <QString>
#include <QByteArray>
#include <QDebug>

class QFileHelper
{
public:
    QFileHelper();
    bool put(QString path, QByteArray data, QIODevice::OpenMode mode);
    bool write(QString path, QByteArray data);
    bool append(QString path, QByteArray data);
    bool read(QString path, QByteArray &bytes);
    bool readLines(QString path, QByteArray &bytes);
};

#endif // QFILEHELPER_H
