#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QRandomGenerator>
#include <QVector>
#include <QtAlgorithms>


void randoms (QVector<int>* list, int max) {
    // Attempts to allocate memory for at least size elements.
    list->reserve (max);

    for (int i = 0; i < max; i++) {
        int value = QRandomGenerator::global ()->bounded (1000);
        list->append (value);
    }
}


int main (int argc, char* argv[]) {
    QCoreApplication a (argc, argv);

    QVector<int> list;
    randoms (&list, 10);

    /*  SORT    */
    qInfo () << "Unsorted: " << list;
    qSort (list);

    // STD
    // std::sort(list.begin(),list.end());

    qInfo () << "Sorted: " << list;

    /*  FILL    */
    qFill (list, 0);
    //    list.fill (0);
    qInfo () << list;

    /*  EQUAL    */
    QVector<int> list1, list2;
    randoms (&list1, 10);
    randoms (&list2, 10);

    qInfo () << "Equal: " << qEqual (list1.begin (), list1.end (), list2.begin ());
    qCopy (list1.begin (), list1.end (), list2.begin ());
    qInfo () << "Equal: " << qEqual (list1.begin (), list1.end (), list2.begin ());

    return a.exec ();
}
