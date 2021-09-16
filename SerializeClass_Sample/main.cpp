#include "test.h"
#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QDir>
#include <QFile>

bool saveFile (Test* t, QString path) {
    QFile file (path);
    if (!file.open (QIODevice::WriteOnly))
        return false;

    QDataStream ds (&file);
    ds.setVersion (QDataStream::Qt_5_11);
    ds << *t;

    //    ds << t->map ();
    //    ds << t->name ();

    file.close ();
    return true;
}

bool loadFile (QString path) {
    QFile file (path);
    if (!file.open (QIODevice::ReadOnly))
        return false;

    QDataStream ds (&file);
    Test t;
    ds >> t;

    file.close ();

    qInfo () << "Name" << t.name ();
    foreach (QString key, t.map ().keys ()) {
        qInfo () << key << " : " << t.map ().value (key);
    }

    return true;
}

int main (int argc, char* argv[]) {
    QCoreApplication a (argc, argv);

    QString path = "test.txt";

    Test t;
    t.fill ();
    if (saveFile (&t, path)) {
        loadFile (path);
    }

    return a.exec ();
}
