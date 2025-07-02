#ifndef QIMBROWSERMAINWINDOW_HPP
#define QIMBROWSERMAINWINDOW_HPP

#include <QKeyEvent>
#include <QMainWindow>
#include <QWidget>
#include <qlogging.h>
#include <qnamespace.h>

#include "QimBrowserRootWidget.hpp"

namespace Qim {

class QimBrowserMainWindow : public QMainWindow {
public:
    QimBrowserMainWindow(QWidget *parent = nullptr);
    ~QimBrowserMainWindow();

protected:
    void resizeEvent(QResizeEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;

private:
    QimBrowserRootWidget *m_browserRootWidget;
    Size m_mainWindowSize;
};

} // namespace Qim

#endif // QIMBROWSERMAINWINDOW_HPP
