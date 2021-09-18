#ifndef STUDENT_H
#define STUDENT_H

#include <QString>



class Student
{
public:
    Student();
    Student(QString name, QString age, QString subject, QString gender);

    const QString &getName() const;
    void setName(const QString &newName);

    const QString &getAge() const;
    void setAge(const QString &newAge);

    const QString &getSubject() const;
    void setSubject(const QString &newSubject);

    const QString &getGender() const;
    void setGender(const QString &newGender);

    QString toString();

private:
    QString m_name;
    QString m_age;
    QString m_subject;
    QString m_gender;
};

#endif // STUDENT_H
