#ifndef QIMBROWSERROOTWIDGET_HPP
#define QIMBROWSERROOTWIDGET_HPP

#include "QimBaseWidget.hpp"
#include "QimTypes.hpp"
#include <QWidget>

namespace Qim {

class QimBrowserRootWidget {
public:
    QimBrowserRootWidget(QWidget *parent);

    void CreateBrowserUI();
    void Update();

private:
    void CalculateUiLayout();

private:
    static constexpr RelativeSize m_vtabbarRelativeSize = {
        .width  = 0.2f,
        .height = 1.0f,
    };

    static constexpr RelativeSize m_browserViewportRelativeSize = {
        .width  = 0.8f,
        .height = 1.0f,
    };

    Frame m_vtabbarFrame;
    Frame m_htabbarFrame;
    Frame m_browserViewportFrame;
    QimBaseWidget *vtabWidget;
    QimBaseWidget *browserViewportWidget;

    QWidget *m_mainWindow;
};

} // namespace Qim

#endif // !QIMBROWSERROOTWIDGET_HPP
