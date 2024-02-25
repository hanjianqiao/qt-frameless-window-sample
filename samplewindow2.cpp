#include <QVBoxLayout>
#include <QApplication>
#include <QStyle>
#include <QLineEdit>
#include <QComboBox>
#include <QRadioButton>
#include <QProgressBar>
#include "samplewindow2.h"


CustomTitleBar::CustomTitleBar(QWidget *parent)
    : FramelessWindowTitleBar{parent}
{
    m_tabBar = new QTabBar(this);
    m_minimizeButton = new QPushButton("最小化", this);
    m_maximizeButton = new QPushButton("最大化", this);
    m_closeButton = new QPushButton("关闭", this);

    /*
     * BUG：FramelessWindow通过nativeEvent实现鼠标悬浮在最大化按钮触发snap layout的功能
     * 时，发送QEvent::MouseMove事件，但是目标收到的是QEvent::HoverMove事件，无法触发
     * QPushButton的状态变化。暂时通过这个代码处理事件改变QPushButton的状态。QPushButton
     * 也可以是普通的QWidget
    */
    m_maximizeButton->installEventFilter(this);

    QHBoxLayout *rootLayout = new QHBoxLayout(this);
    rootLayout->setContentsMargins(0, 0, 0, 0);
    rootLayout->addWidget(m_tabBar);
    rootLayout->addSpacerItem(new QSpacerItem(1, 1, QSizePolicy::Expanding, QSizePolicy::Preferred));
    rootLayout->addWidget(m_minimizeButton);
    rootLayout->addWidget(m_maximizeButton);
    rootLayout->addWidget(m_closeButton);

    QObject::connect(m_minimizeButton, &QPushButton::clicked, this, [this](){
        window()->showMinimized();
    });
    QObject::connect(m_closeButton, &QPushButton::clicked, this, [this](){
        window()->close();
    });
    QObject::connect(m_tabBar, &QTabBar::currentChanged, this, &CustomTitleBar::currentTabChange);
}

void CustomTitleBar::onWindowStateChanged(Qt::WindowState state){
    switch(state){
    case Qt::WindowState::WindowNoState:
        m_maximizeButton->setText("最大化");
        break;
    case Qt::WindowState::WindowMaximized:
        m_maximizeButton->setText("还原");
        break;
    default:
        break;
    }
}

QWidget *CustomTitleBar::maximizeButton() const{
    return m_maximizeButton;
}

QTabBar *CustomTitleBar::tabBar() const{
    return m_tabBar;
}

void CustomTitleBar::setTitle(const QString &title){
    // 什么都不做
}

void CustomTitleBar::setIcon(const QIcon &icon){
    // 什么都不做
}

SampleWindow2::SampleWindow2()
    : FramelessWindow{}
{
    CustomTitleBar *titleBar = new CustomTitleBar(this);
    QLabel *body = new QLabel(this);
    setTitleBarAndBodyWidget(titleBar, body);

    QObject::connect(titleBar, &CustomTitleBar::currentTabChange, this, [this, body](int index){
        body->setText(QString("当前：%1").arg(QString::number(index)));
    });

    for(int i = 0; i < 10; ++i){
        titleBar->tabBar()->addTab(QString("第%1个").arg(QString::number(i)));
    }
}
