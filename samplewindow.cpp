#include <QApplication>
#include <QStyle>
#include "samplewindow.h"

using namespace h;

SampleWindow::SampleWindow()
    : FramelessWindow{}
{
    // 自带的titleBar
    FramelessWindowDefaultTitleBar *defaultTitleBar = new FramelessWindowDefaultTitleBar(this);
    // 可以是任意的Widget
    QWidget *bodyWidget = new QLabel("ABC", this);

    setTitleBarAndBodyWidget(defaultTitleBar, bodyWidget);

    // 标题跟图标
    titleBar()->setTitle("这是标题");
    titleBar()->setIcon(QApplication::style()->standardIcon(QStyle::SP_ComputerIcon));
}
