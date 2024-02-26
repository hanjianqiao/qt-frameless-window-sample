#ifndef SAMPLEWINDOW2_H
#define SAMPLEWINDOW2_H

#include <QTabBar>

#include <qt-frameless-window/framelesswindow.h>


class CustomTitleBar : public h::FramelessWindowTitleBar
{
    Q_OBJECT
public:
    CustomTitleBar(QWidget *parent);

    void onWindowStateChanged(Qt::WindowState state) override;
    QWidget *maximizeButton() const override;
    QTabBar *tabBar() const;

signals:
    void currentTabChange(int index);

private:
    QTabBar *m_tabBar;
    QPushButton *m_minimizeButton;
    QPushButton *m_maximizeButton;
    QPushButton *m_closeButton;
};

class SampleWindow2 : public h::FramelessWindow
{
    Q_OBJECT
public:
    explicit SampleWindow2();

signals:
};

#endif // SAMPLEWINDOW2_H
