#include "QimBrowserRootWidget.hpp"
#include <qlogging.h>

namespace Qim {

QimBrowserRootWidget::QimBrowserRootWidget(QWidget *parent) {
    m_mainWindow = parent;
}

void QimBrowserRootWidget::CreateBrowserUI() {
    vtabWidget = new QimBaseWidget();
    vtabWidget->setParent(m_mainWindow);

    browserViewportWidget = new QimBaseWidget();
    browserViewportWidget->setParent(m_mainWindow);
}

void QimBrowserRootWidget::Update() {
    this->CalculateUiLayout();
    vtabWidget->Update();
    browserViewportWidget->Update();
}

void QimBrowserRootWidget::CalculateUiLayout() {
    vtabWidget->SetPosition(0, 0);
    vtabWidget->SetSize(m_mainWindow->width() * m_vtabbarRelativeSize.width,
                        m_mainWindow->height() * m_vtabbarRelativeSize.height);

    browserViewportWidget->SetPosition(vtabWidget->geWidth(), 0);
    browserViewportWidget->SetSize(
        m_mainWindow->width() * m_browserViewportRelativeSize.width,
        m_mainWindow->height() * m_browserViewportRelativeSize.height);
}

} // namespace Qim
