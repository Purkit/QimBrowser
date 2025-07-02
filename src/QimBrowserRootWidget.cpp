#include "QimBrowserRootWidget.hpp"
#include <qlogging.h>

namespace Qim {

QimBrowserRootWidget::QimBrowserRootWidget(QWidget *parent) {
    m_mainWindow = parent;
}

void QimBrowserRootWidget::CreateBrowserUI() {
    this->CalculateUiLayout();

    vtabWidget = new QimBaseWidget(m_vtabbarFrame);
    vtabWidget->setParent(m_mainWindow);

    browserViewportWidget = new QimBaseWidget(m_browserViewportFrame);
    browserViewportWidget->setParent(m_mainWindow);
}

void QimBrowserRootWidget::Update() {
    this->CalculateUiLayout();
    vtabWidget->Update(m_vtabbarFrame);
    browserViewportWidget->Update(m_browserViewportFrame);
}

void QimBrowserRootWidget::CalculateUiLayout() {
    m_vtabbarFrame.absolute_position.x = 0;
    m_vtabbarFrame.absolute_position.y = 0;
    m_vtabbarFrame.absolute_size.width =
        m_mainWindow->width() * m_vtabbarRelativeSize.width;
    m_vtabbarFrame.absolute_size.height =
        m_mainWindow->height() * m_vtabbarRelativeSize.height;

    m_browserViewportFrame.absolute_position.x =
        m_vtabbarFrame.absolute_size.width;
    m_browserViewportFrame.absolute_position.y = 0;
    m_browserViewportFrame.absolute_size.width =
        m_mainWindow->width() * m_browserViewportRelativeSize.width;
    m_browserViewportFrame.absolute_size.height =
        m_mainWindow->height() * m_browserViewportRelativeSize.height;
}

} // namespace Qim
