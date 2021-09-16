#include "qfilehelper.h"

QFileHelper::QFileHelper()
{

}

bool QFileHelper::put(QString path, QByteArray data, QIODevice::OpenMode mode)
{
    QFile file(path);

    if (!file.open(mode)) {
        qWarning() << file.errorString();
        return false;
    }

    qint64 bytes = file.write(data);

    if (!bytes) {
        qWarning() << file.errorString();
    } else {
        qInfo() << "Wrote " << bytes << " to the file";
    }

    file.flush(); //Not really need
    file.close();

    return true;
}

bool QFileHelper::write(QString path, QByteArray data)
{
    qInfo() << "Write to file";

    if (put(path, data, QIODevice::WriteOnly)) {
        qInfo() << "Data written to file";
    } else {
        qWarning() << "Failed to write to file";
    }
}

bool QFileHelper::append(QString path, QByteArray data)
{
    qInfo() << "Append to file";

    if (put(path, data, QIODevice::Append)) {
        qInfo() << "Data written to file";
    } else {
        qWarning() << "Failed to write to file";
    }
}

bool QFileHelper::read(QString path, QByteArray &bytes)
{
    QFile file(path);
    if (!file.exists()) {
        qWarning() << "File not found";
        return false;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << file.errorString();
        return false;
    }

    bytes = file.readAll(); //Best small files!

    file.close();
    return true;
}

bool QFileHelper::readLines(QString path, QByteArray &bytes)
{
    QFile file(path);
    if (!file.exists()) {
        qWarning() << "File not found";
        return false;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << file.errorString();
        return false;
    }

    while (!file.op) {

    }

    file.close();
    return true;
}


