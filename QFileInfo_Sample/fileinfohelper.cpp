#include "fileinfohelper.h"

FileInfoHelper::FileInfoHelper()
{

}

void FileInfoHelper::list(const QString path)
{
    qInfo() << "Lisiting: " << path;

    QDir dir(path);
    qInfo() << dir.absolutePath();

    QFileInfoList dirs = dir.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList files = dir.entryInfoList(QDir::Files);

    foreach (QFileInfo fi, dirs) {
        qInfo() << fi.fileName();
    }

    foreach (QFileInfo fi, files) {
        qInfo() << "Name          : " << fi.fileName();
        qInfo() << "...Size       : " << fi.size();
        qInfo() << "...Created    : " << fi.created();
        qInfo() << "...Modified   : " << fi.lastModified();
    }
}
