#include <QApplication>
#include <QKeyEvent>
#include <QMainWindow>
#include <QWidget>
#include <print>
#include <qlogging.h>
#include <qnamespace.h>

#include "QimBaseWidget.hpp"

namespace Qim {

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        this->setWindowTitle("QimBrowser");
        m_mainWindowSize.width  = 1200;
        m_mainWindowSize.height = 800;
        this->resize(m_mainWindowSize.width, m_mainWindowSize.height);

        CalculateUiLayout();
        CreateUi();
    }

private:
    void CalculateUiLayout() {
        m_vtabbarFrame.absolute_position.x = 0;
        m_vtabbarFrame.absolute_position.y = 0;
        m_vtabbarFrame.absolute_size.width =
            m_mainWindowSize.width * m_vtabbarRelativeSize.width;
        m_vtabbarFrame.absolute_size.height =
            m_mainWindowSize.height * m_vtabbarRelativeSize.height;

        m_browserViewportFrame.absolute_position.x =
            m_vtabbarFrame.absolute_size.width;
        m_browserViewportFrame.absolute_position.y = 0;
        m_browserViewportFrame.absolute_size.width =
            m_mainWindowSize.width * m_browserViewportRelativeSize.width;
        m_browserViewportFrame.absolute_size.height =
            m_mainWindowSize.height * m_browserViewportRelativeSize.height;
    }

    void CreateUi() {
        vtabWidget = new QimBaseWidget(m_vtabbarFrame);
        vtabWidget->setParent(this);

        browserViewportWidget = new QimBaseWidget(m_browserViewportFrame);
        browserViewportWidget->setParent(this);
    }

    void UpdateUi() {
        vtabWidget->Update(m_vtabbarFrame);
        browserViewportWidget->Update(m_browserViewportFrame);
    }

    void ShowVerticalTabbar() {}
    void ShowHoritontalTabbar() {}
    void ShowBrowserViewport() {}

protected:
    void resizeEvent(QResizeEvent *event) override {
        QMainWindow::resizeEvent(event);
        m_mainWindowSize.width  = this->width();
        m_mainWindowSize.height = this->height();
        CalculateUiLayout();
        UpdateUi();
    }

    void keyPressEvent(QKeyEvent *event) override {
        QMainWindow::keyPressEvent(event);
        if (event->key() == Qt::Key_A)
            std::println("A pressed!");
    }

private:
    static constexpr RelativeSize m_vtabbarRelativeSize = {
        .width  = 0.2f,
        .height = 1.0f,
    };

    static constexpr RelativeSize m_browserViewportRelativeSize = {
        .width  = 0.8f,
        .height = 1.0f,
    };
    Size m_mainWindowSize;
    Frame m_vtabbarFrame;
    Frame m_htabbarFrame;
    Frame m_browserViewportFrame;
    QimBaseWidget *vtabWidget;
    QimBaseWidget *browserViewportWidget;
};

} // namespace Qim

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Qim::MainWindow window;
    window.show();

    return app.exec();
}
