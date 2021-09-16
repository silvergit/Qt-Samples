#include "myslider.h"

MySlider::MySlider(QWidget *parent) : QWidget(parent)
{
    m_Value = 0;
    maxWidth = 150;
}

MySlider::MySlider(int value, int width, QWidget *parent)
{
    m_Value = value;
    maxWidth = width;
}


void MySlider::valueChanged(int value)
{
    if (value >= 0 && value <= 100) {
        m_Value = value;
        repaint();
    }

}

void MySlider::setValue(int newValue)
{
    if (m_Value == newValue)
        return;
    m_Value = newValue;
}

void MySlider::setMaxWidth(int newMaxWidth)
{
    maxWidth = newMaxWidth;
}

void MySlider::paintEvent(QPaintEvent *event)
{
    maxWidth = 150;
    QPainter painter(this);
    QRectF rect(0, 0, maxWidth, 20);
    painter.drawRect(rect);

    int width = (maxWidth / 100.0) * m_Value;

    QRectF innerRect(3, 3, width == 0 ? width : width - 4, 14);

    QBrush brush(Qt::blue, Qt::Dense1Pattern);
    painter.setBrush(brush);

    painter.drawRect(innerRect);
}
