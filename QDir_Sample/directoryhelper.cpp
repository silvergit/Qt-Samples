#include "directoryhelper.h"

DirectoryHelper::DirectoryHelper(QString directoryPath) : m_dirPath(directoryPath) {}

bool DirectoryHelper::isDirExists()
{
    QDir dir(m_dirPath);
    return dir.exists();
}

QStringList DirectoryHelper::getDrivesList()
{
    QStringList list;
    QDir dir;
    foreach (QFileInfo item, dir.drives() ) {
        list << item.absoluteFilePath();
    }
    return list;
}

const bool DirectoryHelper::createDirectory(QString path) const
{
    QDir dir(path);

    if (dir.exists()) {
        qDebug() << path << "Already exists";
        return true;
    }

    if (dir.mkpath(path)) {
        qDebug() << "Directory created";
        return true;
    }

    //else
    qDebug() << "Could not create";
    return false;
}

const bool DirectoryHelper::rename(const QString path, const QString newName) const
{
    QDir dir(path);

    if (!dir.exists()) {
        qDebug() << "Path does not exist";
        return false;
    }

    int pos = path.lastIndexOf(QDir::separator()); //Windows is \ and linux is /
    QString parent = path.mid(0, pos);
    QString newPath = parent + QDir::separator() + newName;

    qInfo() << "Absolute  : " << dir.absolutePath();
    qInfo() << "Parent    : " << parent;
    qInfo() << "New path  : " << newPath;

    return (dir.rename(path, newPath));
}

const bool DirectoryHelper::removeRecursively(const QString path) const
{
    qDebug() << "Removing: " << path;
    QDir dir(path);

    if (!dir.exists()) {
        qDebug() << "Path does not exist";
        return false;
    }

    //Danger!!!
    return dir.removeRecursively();
}

QStringList DirectoryHelper::getAllFilesInDir()
{
    QStringList list;
    QDir dir(m_dirPath);

    foreach (QFileInfo item, dir.entryInfoList() ) {
        if (item.isFile())
            list << item.absoluteFilePath();
    }

    return list;
}

QStringList DirectoryHelper::getAllDirsInDir()
{
    QStringList list;
    QDir dir(m_dirPath);

    foreach (QFileInfo item, dir.entryInfoList() ) {
        if (item.isDir())
            list << item.absoluteFilePath();
    }

    return list;
}

const QString &DirectoryHelper::dirPath() const
{
    return m_dirPath;
}

void DirectoryHelper::setDirPath(const QString &newDirPath)
{
    m_dirPath = newDirPath;
}
