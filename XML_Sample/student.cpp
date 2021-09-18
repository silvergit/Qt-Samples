#include "student.h"

Student::Student()
{

}

Student::Student(QString name, QString age, QString subject, QString gender):
    m_name(name), m_age(age), m_gender(gender), m_subject(subject)
{
}

const QString &Student::getName() const
{
    return m_name;
}

void Student::setName(const QString &newName)
{
    m_name = newName;
}

const QString &Student::getAge() const
{
    return m_age;
}

void Student::setAge(const QString &newAge)
{
    m_age = newAge;
}

const QString &Student::getSubject() const
{
    return m_subject;
}

void Student::setSubject(const QString &newSubject)
{
    m_subject = newSubject;
}

const QString &Student::getGender() const
{
    return m_gender;
}

void Student::setGender(const QString &newGender)
{
    m_gender = newGender;
}

QString Student::toString()
{
    return QString("name: %1, age: %2, subject: %3, gender: %4")
           .arg(this->m_name, this->m_age, this->m_subject, m_subject);
}
