#include "QimBrowserMainWindow.hpp"

namespace Qim {

QimBrowserMainWindow::QimBrowserMainWindow(QWidget *parent)
    : QMainWindow(parent) {
    this->setWindowTitle("QimBrowser");
    m_mainWindowSize.width  = 1200;
    m_mainWindowSize.height = 800;
    this->resize(m_mainWindowSize.width, m_mainWindowSize.height);

    m_browserRootWidget = new QimBrowserRootWidget(this);

    m_browserRootWidget->CreateBrowserUI();
}

QimBrowserMainWindow::~QimBrowserMainWindow() { delete m_browserRootWidget; }

void QimBrowserMainWindow::resizeEvent(QResizeEvent *event) {
    QMainWindow::resizeEvent(event);
    m_mainWindowSize.width  = this->width();
    m_mainWindowSize.height = this->height();
    m_browserRootWidget->Update();
}

void QimBrowserMainWindow::keyPressEvent(QKeyEvent *event) {
    QMainWindow::keyPressEvent(event);
    if (event->key() == Qt::Key_A) {
        // std::println("A pressed!");
    }
}

} // namespace Qim
