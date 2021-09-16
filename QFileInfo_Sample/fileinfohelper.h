#ifndef FILEINFOHELPER_H
#define FILEINFOHELPER_H


#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <QDateTime>
#include <QDebug>

class FileInfoHelper
{
public:
    FileInfoHelper();
    void list(const QString path);
};

#endif // FILEINFOHELPER_H
