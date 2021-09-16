#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>

//Out own custom file, will not work with anythin else!

bool makeFile(QString path)
{
    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {
        QByteArray data;
        for (int i = 0; i < 1000; i++) {
            data.append(QString::number(i) + "\r\n");
        }

        file.write(data);
        file.close();
        return true;
    }

    return false;
}

QByteArray getHeader()
{
    QByteArray header;
    header.append("@!~!@");
    return header;
}

bool compressFile(QString originalFile, QString newFile)
{
    QFile oFile(originalFile);
    QFile nFile(newFile);
    QByteArray header = getHeader();

    if (!oFile.open(QIODevice::ReadOnly)) return false;
    if (!nFile.open(QIODevice::WriteOnly)) return false;
    int size = 1024;

    while (!oFile.atEnd()) {
        QByteArray buffer = oFile.read(size);
        QByteArray compressed = qCompress(buffer);
        qInfo() << "Header at:" << nFile.pos();
        nFile.write(header);
        qInfo() << "Size: " << nFile.write(compressed);
    }

    oFile.close();
    nFile.close();
}

bool decompressFile(QString originalFile, QString newFile)
{
    QFile oFile(originalFile);
    QFile nFile(newFile);
    QByteArray header = getHeader();
    int size = 1024;

    if (!oFile.open(QIODevice::ReadOnly)) return false;
    if (!nFile.open(QIODevice::WriteOnly)) return false;

    //Double check that we compresses the file
    QByteArray buffer = oFile.peek(size);
    if (!buffer.startsWith(header)) {
        qCritical() << "We did not create this file!";
        oFile.close();
        nFile.close();
        return false;
    }

    //Find the header positions
    oFile.seek(header.length());
    qInfo() << "Starting at:" << oFile.pos();

    while (!oFile.atEnd()) {
        buffer = oFile.peek(size);
        qint64 index = buffer.indexOf(header);
        qInfo() << "Header found at:" << index;
        if (index > -1) {
            //Have the header!
            qint64 maxbytes = index;
            qInfo() << "Reading: " << maxbytes;
            buffer = oFile.read(maxbytes);
            oFile.read(header.length());
        } else {
            qInfo() << "Read all, no header";
            buffer = oFile.readAll();
        }

        QByteArray decompressed = qUncompress(buffer);
        qInfo() << "Decompressed: " << nFile.write(decompressed);
        nFile.flush();
    }

    oFile.close();
    nFile.close();

    return true;
}

QString getPath(QString fileName)
{
    return QDir::currentPath() + QDir::separator() + fileName;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString originalFile = getPath("original.txt");
    QString compressedFile = getPath("compressed.txt");
    QString decompressedFile = getPath("decompressed.txt");

    if (makeFile(originalFile)) {
        qInfo() << "Original created";

        if (compressFile(originalFile, compressedFile)) {
            qInfo() << "File compressed";
            if (decompressFile(compressedFile, decompressedFile)) {
                qInfo() << "File decompressed!";
            } else {
                qInfo() << "Could not decompress file!";
            }
        } else {
            qInfo() << "File not compressed";
        }
    }
    return a.exec();
}
