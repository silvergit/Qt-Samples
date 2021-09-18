#include "commander.h"

Commander::Commander (QObject* parent) : QObject (parent) {
#ifdef Q_OS_WIN
    app  = "cmd";
    endl = "\r\n";
#else
    // not windows OS
    app  = "bash";
    endl = "\n";
#endif

    proc.setProgram (app);
    proc.start ();
    proc.setReadChannelMode (QProcess::MergedChannels);

    connect (&proc, &QProcess::readyRead, this, &Commander::readyRead);
    connect (&proc, &QProcess::readyReadStandardOutput, this, &Commander::readyRead);
    connect (&proc, &QProcess::readyReadStandardError, this, &Commander::readyRead);
}

Commander::~Commander () {
    if (proc.isOpen ())
        proc.close ();
}

void Commander::readyRead () {
    qint64 value = 0;
    do {
        QByteArray line = proc.readAll ();
        qInfo () << line.trimmed ();
        value = line.length ();
    } while (value > 0);
}

void Commander::action (QByteArray data) {
    if (!data.endsWith (endl.toLatin1 ()))
        data.append (endl);
    proc.write (data);
    proc.waitForBytesWritten (1000);
}
