#include "mainwindow.h"

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QPushButton>
#include <QTableWidget>
#include <QVBoxLayout>
#include <QXmlStreamReader>
#include <student.h>

MainWindow::MainWindow (QWidget* parent) : QMainWindow (parent) {
    students = new QList<Student>{ readXML () };

    widget          = new QWidget;
    mainLayout      = new QVBoxLayout;
    btnLayout       = new QHBoxLayout;
    table           = new QTableWidget (students->length (), 4, this);
    loadBtn         = new QPushButton ("Load xlm");
    loadFromFileBtn = new QPushButton ("Load xlm from file");
    saveToFileBtn   = new QPushButton ("Save xlm to file");

    setCentralWidget (widget);
    widget->setLayout (mainLayout);
    btnLayout->addWidget (loadBtn);
    btnLayout->addWidget (loadFromFileBtn);
    btnLayout->addWidget (saveToFileBtn);
    mainLayout->addWidget (table);
    mainLayout->addLayout (btnLayout);

    table->setHorizontalHeaderLabels (QStringList () << "Name"
                                                     << "Age"
                                                     << "Subject"
                                                     << "Gender");

    connect (loadBtn, &QPushButton::clicked, this, &MainWindow::LoadXMLFromResources);
    connect (loadFromFileBtn, &QPushButton::clicked, this, &MainWindow::loadXMLFile);
    connect (saveToFileBtn, &QPushButton::clicked, this, &MainWindow::saveXMLFile);
}

QList<Student> MainWindow::readXML () {
    QList<Student> students;

    // Load xml file as raw data
    QFile file (":/xml/sample.xml");
    if (!file.open (QIODevice::ReadOnly)) {
        // Error while loading file
        qDebug () << "Error while loading file" << Qt::endl;

    } else {

        // Set data into the QXmlStreamReader before processing
        QXmlStreamReader reader (&file);


        QString name, age, gender, subject;

        while (!reader.atEnd () && !reader.hasError ()) {

            if (reader.readNext () == QXmlStreamReader::StartElement) {
                if (reader.name () == "name") {
                    name = reader.readElementText ();
                } else if (reader.name () == "age") {
                    age = reader.readElementText ();
                } else if (reader.name () == "subject") {
                    subject = reader.readElementText ();
                } else if (reader.name () == "gender") {
                    gender = reader.readElementText ();
                    students.append (Student (name, age, subject, gender));
                }
            }
        }

        file.close ();
    }

    return students;
}

MainWindow::~MainWindow () {
}

void MainWindow::LoadXMLFromResources () {
    for (int i = 0; i < students->length (); i++) {
        QTableWidgetItem* nameItem = new QTableWidgetItem (students->at (i).getName ());
        QTableWidgetItem* ageItem = new QTableWidgetItem (students->at (i).getAge ());
        QTableWidgetItem* subjectItem =
        new QTableWidgetItem (students->at (i).getSubject ());
        QTableWidgetItem* genderItem =
        new QTableWidgetItem (students->at (i).getGender ());

        table->setItem (i, 0, nameItem);
        table->setItem (i, 1, ageItem);
        table->setItem (i, 2, subjectItem);
        table->setItem (i, 3, genderItem);
    }
}

void MainWindow::loadXMLFile () {
    QXmlStreamReader Rxml;

    QString filename = QFileDialog::getOpenFileName (
    this, tr ("Open Xml"), ".", tr ("Xml files (*.xml)"));

    QFile file (filename);
    if (!file.open (QFile::ReadOnly | QFile::Text)) {
        qDebug () << "Error: Cannot read file " << qPrintable (filename) << ": "
                  << qPrintable (file.errorString ()) << Qt::endl;
    }

    Rxml.setDevice (&file);
    Rxml.readNext ();

    while (!Rxml.atEnd ()) {
        if (Rxml.isStartElement ()) {
            if (Rxml.name () == "LAMPS") {
                Rxml.readNext ();
            } else if (Rxml.name () == "LIGHT1") {
                while (!Rxml.atEnd ()) {
                    if (Rxml.isEndElement ()) {
                        Rxml.readNext ();
                        break;
                    } else if (Rxml.isCharacters ()) {
                        Rxml.readNext ();
                    } else if (Rxml.isStartElement ()) {
                        if (Rxml.name () == "State") {
                            qDebug () << Rxml.readElementText ();
                        } else if (Rxml.name () == "Room") {
                            qDebug () << Rxml.readElementText ();
                        } else if (Rxml.name () == "Potencial") {
                            qDebug () << Rxml.readElementText ();
                        }
                        Rxml.readNext ();
                    } else {
                        Rxml.readNext ();
                    }
                }
            }
        } else {
            Rxml.readNext ();
        }


        if (Rxml.hasError ()) {
            qDebug () << "Error: Failed to parse file " << qPrintable (filename)
                      << ": " << qPrintable (Rxml.errorString ()) << Qt::endl;
        } else if (file.error () != QFile::NoError) {
            qDebug () << "Error: Cannot read file " << qPrintable (filename)
                      << ": " << qPrintable (file.errorString ()) << Qt::endl;
        }
    }
    file.close ();
}

void MainWindow::saveXMLFile () {

    QString filename = QFileDialog::getSaveFileName (
    this, tr ("Save Xml"), ".", tr ("Xml files (*.xml)"));


    QFile file (filename);
    file.open (QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter (&file);
    xmlWriter.setAutoFormatting (true);
    xmlWriter.writeStartDocument ();

    xmlWriter.writeStartElement ("LAMPS");

    xmlWriter.writeStartElement ("LIGHT1");
    xmlWriter.writeTextElement ("State", "statevalue");
    xmlWriter.writeTextElement ("Room", "roomvalue");
    xmlWriter.writeTextElement ("Potencial", "potencialvalue");

    xmlWriter.writeEndElement ();

    file.close ();
}
