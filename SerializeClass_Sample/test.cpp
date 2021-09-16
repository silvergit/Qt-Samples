#include "test.h"

Test::Test (QObject* parent) : QObject (parent) {
}

void Test::fill () {
    mName = "test object";
    for (int i = 0; i < 10; i++) {
        QString num   = QString::number (i);
        QString key   = "Key: " + num;
        QString value = "This is item number: " + num;
        mMap.insert (key, value);
    }
}

QString Test::name () {
    return mName;
}

void Test::setName (QString value) {
    mName = value;
}

QMap<QString, QString> Test::map () {
    return mMap;
}
