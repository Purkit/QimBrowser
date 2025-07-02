#include "QimBrowserMainWindow.hpp"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Qim::QimBrowserMainWindow window;
    window.show();

    return app.exec();
}
