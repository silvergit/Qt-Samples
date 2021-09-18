#ifndef CONVERTER_H
#define CONVERTER_H

#include <QDebug>
#include <QDir>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>
#include <QObject>
#include <QVariant>
#include <QVariantMap>

#include "test.h"

class Converter : public QObject {
    Q_OBJECT
    public:
    explicit Converter (QObject* parent = nullptr);

    static void writeJson (Test* obj, QString path);
    static Test* readJson (QString path);

    signals:
};

#endif // CONVERTER_H
