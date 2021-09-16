#include <QCoreApplication>
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;

    if (buffer.open(QIODevice::ReadWrite)) {
        qInfo() << "Buffer opened.";
        QByteArray data("Hello world");

        for (int i = 0; i < 5; i++) {
            buffer.write(data);
            buffer.write("\r\n");
        }

        //file and device access you may need to flush the data to the device
        //buffer.flush();

        //move to the first position
        buffer.seek(0);

        qInfo() << buffer.readAll();

        qInfo() << "cloasing the buffer";
        buffer.close();
    } else {
        qInfo() << "Could not open buffer!";
    }

    return a.exec();
}
