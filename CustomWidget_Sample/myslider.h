#ifndef MYSLIDER_H
#define MYSLIDER_H

#include <QPaintEvent>
#include <QWidget>
#include <QPainter>

class MySlider : public QWidget
{
    Q_OBJECT
public:
    explicit MySlider(QWidget *parent = nullptr);
    explicit MySlider(int value, int width = 150, QWidget *parent = nullptr);

    int getMaxWidth() const;
    void setMaxWidth(int newMaxWidth);

    void setValue(int newValue);

public slots:
    void valueChanged(int value);

private:
    int m_Value;
    int maxWidth;

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // MYSLIDER_H
