#ifndef TEST_H
#define TEST_H

#include <QDataStream>
#include <QDebug>
#include <QMap>
#include <QObject>

class Test : public QObject {
    Q_OBJECT
    public:
    explicit Test (QObject* parent = nullptr);

    void fill ();
    QString name ();
    void setName (QString value);
    QMap<QString, QString> map ();

    friend QDataStream& operator<< (QDataStream& stream, Test& t) {
        qInfo () << "Operload >>";
        stream << t.mName;
        stream << t.mMap;
        return stream;
    }

    friend QDataStream& operator>> (QDataStream& stream, Test& t) {
        qInfo () << "Operload >>";
        stream >> t.mName;
        stream >> t.mMap;
        return stream;
    }

    signals:

    public:
    QString mName;
    QMap<QString, QString> mMap;
    void setMap (const QMap<QString, QString>& newMap);
};

#endif // TEST_H
