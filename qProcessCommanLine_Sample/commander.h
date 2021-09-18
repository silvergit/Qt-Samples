#ifndef COMMANDER_H
#define COMMANDER_H

#include <QDebug>
#include <QObject>
#include <QProcess>

class Commander : public QObject {
    Q_OBJECT
    public:
    explicit Commander (QObject* parent = nullptr);
    ~Commander ();

    signals:

    public slots:
    void readyRead ();
    void action (QByteArray data);

    private:
    QProcess proc;
    QString app;
    QString endl;
};

#endif // COMMANDER_H
