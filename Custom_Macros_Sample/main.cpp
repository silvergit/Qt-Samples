#include <QCoreApplication>
#include <QDebug>

// Custom macro
#define add(a, b) a + b

int main (int argc, char* argv[]) {
    QCoreApplication a (argc, argv);

    // Easy...but dangerous
    qInfo () << add (1, 2);

    // Lets break it!
    qInfo () << add ("test", 22);
    qInfo () << add (true, true);
    qInfo () << add (false, true);
    qInfo () << add (false, false);
    qInfo () << add ("test", '\n');
    qInfo () << add ("test", '/n');

    return a.exec ();
}
