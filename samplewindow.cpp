#include <QApplication>
#include <QStyle>
#include "samplewindow.h"

using namespace h;

SampleWindow::SampleWindow()
    : FramelessWindow{}
{
    setTitleBarAndBodyWidget(new FramelessWindowDefaultTitleBar(this), new QLabel("ABC", this));
    titleBar()->setTitle("这是标题");
    titleBar()->setIcon(QApplication::style()->standardIcon(QStyle::SP_ComputerIcon));
}
