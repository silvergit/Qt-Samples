#ifndef DIRECTORYHELPER_H
#define DIRECTORYHELPER_H

#include <QString>
#include <QDir>
#include <QDebug>

class DirectoryHelper
{
public:
    DirectoryHelper(QString directoryPath = "");

    bool isDirExists();
    QStringList getDrivesList();
    const bool createDirectory(const QString path) const;
    const bool rename(const QString path, const QString newName) const;
    const bool removeRecursively(const QString path) const;
    QStringList getAllFilesInDir();
    QStringList getAllDirsInDir();

    const QString &dirPath() const;
    void setDirPath(const QString &newDirPath);

private:
    QString m_dirPath;
};

#endif // DIRECTORYHELPER_H
