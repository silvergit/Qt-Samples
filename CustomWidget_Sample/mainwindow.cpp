#include "mainwindow.h"
#include "myslider.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_MainWidget = new QWidget;
    m_VboxLayout = new QVBoxLayout(this);
    m_Slider = new QSlider;
    MySlider *mySlider = new MySlider(100);

    m_MainWidget->setLayout(m_VboxLayout);
    m_VboxLayout->addWidget(m_Slider);
    m_VboxLayout->addWidget(mySlider);

    m_Slider->setOrientation(Qt::Horizontal);

    mySlider->setValue(m_Slider->value());

    setCentralWidget(m_MainWidget);

    connect(m_Slider, &QSlider::valueChanged, mySlider, &MySlider::valueChanged);
}

MainWindow::~MainWindow()
{
}

