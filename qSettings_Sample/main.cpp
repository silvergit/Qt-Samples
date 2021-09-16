#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setApplicationName("Tester");
    QCoreApplication::setOrganizationName("Alireza");
    QCoreApplication::setOrganizationDomain("lidora.blog.ir");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    //Save the settings
    //settings.setValue("testKey", 123);

    //Load the settings
    int num = settings.value("testKey").toInt();

    qInfo() << num;

    return a.exec();
}
