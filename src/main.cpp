#include <QApplication>
#include <QKeyEvent>
#include <QMainWindow>
#include <QWidget>
#include <cstdlib>
#include <print>
#include <qlogging.h>
#include <qnamespace.h>

#include "QimBrowserRootWidget.hpp"

namespace Qim {

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        this->setWindowTitle("QimBrowser");
        m_mainWindowSize.width  = 1200;
        m_mainWindowSize.height = 800;
        this->resize(m_mainWindowSize.width, m_mainWindowSize.height);

        m_browserRootWidget = new QimBrowserRootWidget(this);

        m_browserRootWidget->CreateBrowserUI();
    }

    ~MainWindow() { delete m_browserRootWidget; }

protected:
    void resizeEvent(QResizeEvent *event) override {
        QMainWindow::resizeEvent(event);
        m_mainWindowSize.width  = this->width();
        m_mainWindowSize.height = this->height();
        m_browserRootWidget->Update();
    }

    void keyPressEvent(QKeyEvent *event) override {
        QMainWindow::keyPressEvent(event);
        if (event->key() == Qt::Key_A)
            std::println("A pressed!");
    }

private:
    QimBrowserRootWidget *m_browserRootWidget;
    Size m_mainWindowSize;
};

} // namespace Qim

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Qim::MainWindow window;
    window.show();

    return app.exec();
}
