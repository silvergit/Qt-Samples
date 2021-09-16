#include <QCoreApplication>
#include <QDebug>
#include <QFile>
#include <QDir>
#include <QRandomGenerator>
#include <QTextCodec>
// ==========================================================
// ASCII is a 7-bit character set containing 128 characters
QByteArray makeAsciiData()
{
    QByteArray data;
    for (int i = 0; i < 10; i++) {
        data.append(72);
        data.append(101);
        data.append(108);
        data.append(108);
        data.append(111);
        data.append(33);
        data.append(13); // \r
        data.append(10); // \n
    }
    return data;
}

// ==========================================================
// UTF-8 is a variable width chatacter encoding capable of all 1,112,064
// valid code points in Unicode using one to four 8-bit bytes.
QString makeUtf8Data()
{
    QString data;

    data.append("Unicode test\r\n");
    for (int i = 0; i < 10; i++) {
        int number = QRandomGenerator::global()->bounded(1112064);
        data.append(number);
    }
    data.append("\r\n");

    return data;
}

// ==========================================================
// each Base64 digit represent exactly 6 bits of data.
QString makeBase64Data()
{
    QString data;

    for (int i = 0; i < 10; i++) {
        data.append("Hello\r\n");
    }

    return data;
}

// ==========================================================
// HEX
QString makeHexData()
{
    QString data;

    for (int i = 0; i < 10; i++) {
        data.append("Hello\r\n");
    }

    return data;
}

// ==========================================================
// Special Codec
// http://doc.qt.io/qt-5/qtextcodec.html
QString makeQTextCodecData()
{
    QString data;

    for (int i = 0; i < 10; i++) {
        data.append("Hello\r\n");
    }

    return data;
}

// ==========================================================
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //ASCII
    QByteArray ascii_data = makeAsciiData();
    QString path = QDir::currentPath() + QDir::separator() + "ascii_data.txt";
    QFile ascii_file(path);

    if (ascii_file.open(QIODevice::WriteOnly)) {
        ascii_file.write(ascii_data);
        ascii_file.close();
    }

    //UTF-8
    QString utf8_data = makeUtf8Data();
    path = QDir::currentPath() + QDir::separator() + "utf-8_data.txt";
    QFile utf8_file(path);

    if (utf8_file.open(QIODevice::WriteOnly)) {
        QTextStream stream(&utf8_file);
        stream.setCodec("UTF-8");
        stream << utf8_data;
        stream.flush();
        utf8_file.close();
    }

    //BASE64
    QString base64_data = makeBase64Data();
    QByteArray base64_bytes(base64_data.toLatin1());
    QByteArray base64_encoded = base64_bytes.toBase64();
    QByteArray base64_decoded = QByteArray::fromBase64(base64_encoded);

    qInfo() << "Encoded:" << base64_encoded;
    qInfo() << "------------------------";
    qInfo() << "Decoded:" << base64_decoded;

    qInfo() << "------------------------";
    qInfo() << "------------------------";
    qInfo() << "------------------------";

    //HEX
    QString hex_data = makeHexData();
    QByteArray hex_bytes(hex_data.toLatin1());
    QByteArray hex_encoded = hex_bytes.toHex();
    QByteArray hex_decoded = QByteArray::fromHex(hex_encoded);

    qInfo() << "Encoded:" << hex_encoded;
    qInfo() << "------------------------";
    qInfo() << "Decoded:" << hex_decoded;

    qInfo() << "------------------------";
    qInfo() << "------------------------";
    qInfo() << "------------------------";

    //QTextCodec
    //qtextcodec
    QString qtextcodec_data = makeQTextCodecData();
    QTextCodec *codec = QTextCodec::codecForName("UTF-16");
    if (!codec) qFatal("No codec!");

    QByteArray bytes = codec->fromUnicode(qtextcodec_data);
    qInfo() << "Bytes: " << bytes;
    qInfo() << "------------------------";
    QString string = codec->toUnicode(bytes);
    qInfo() << "String: " << string;


    qInfo() << "Done";
    return a.exec();
}
