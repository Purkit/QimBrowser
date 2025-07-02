#ifndef QIMBASEWIDGET_HPP
#define QIMBASEWIDGET_HPP

#include <QBrush>
#include <QLinearGradient>
#include <QPainter>
#include <QPen>
#include <QWidget>

#include "QimTypes.hpp"

namespace Qim {
class QimBaseWidget : public QWidget {
public:
    QimBaseWidget(int x, int y, int w, int h, QWidget *parent = nullptr)
        : QWidget(parent) {
        m_absolutePosition = {.x = x, .y = y};
        m_size             = {.width = w, .height = h};

        this->Update();
    }

    QimBaseWidget(QWidget *parent = nullptr) : QWidget(parent) {}

    void SetSize(int w, int h) { m_size = {.width = w, .height = h}; }

    void SetPosition(int x, int y) { m_absolutePosition = {.x = x, .y = y}; }

    void Update() {
        QWidget::resize(m_size.width, m_size.height);
        QWidget::move(m_absolutePosition.x, m_absolutePosition.y);
    }

    int geWidth() { return m_size.width; }
    int getHeight() { return m_size.height; }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        QRect rect(0, 0, m_size.width, m_size.height);

        QLinearGradient gradient(rect.topLeft(), rect.bottomRight());
        gradient.setColorAt(0, QColor(0, 128, 255)); // light blue
        gradient.setColorAt(1, QColor(0, 64, 128));  // darker blue

        painter.setBrush(gradient);
        painter.setPen(Qt::NoPen);
        painter.drawRoundedRect(rect, 20, 20);

        // Add a border around the rectangle
        QPen pen(QColor(255, 255, 255), 5); // White border with 5px thickness
        painter.setPen(pen);
        painter.drawRoundedRect(
            rect, 20, 20); // Draw the same rounded rectangle with border
    }

private:
    Point m_absolutePosition;
    Size m_size;
};

} // namespace Qim

#endif // QIMBASEWIDGET_HPP
