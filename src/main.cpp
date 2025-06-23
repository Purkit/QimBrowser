#include <QApplication>
#include <QMainWindow>
#include <QWebEngineView>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow window;
    QWebEngineView *view = new QWebEngineView(&window);
    view->load(QUrl("https://www.duckduckgo.com"));

    window.setCentralWidget(view);
    window.resize(1024, 768);
    window.show();

    return app.exec();
}
