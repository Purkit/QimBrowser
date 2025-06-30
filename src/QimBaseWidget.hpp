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
        : QWidget(parent), pos_x(x), pos_y(y), m_width(w), m_height(h) {
        QWidget::resize(w, h);
        QWidget::move(pos_x, pos_y);
    }

    QimBaseWidget(Frame &frame, QWidget *parent = nullptr)
        : QWidget(parent), pos_x(frame.absolute_position.x),
          pos_y(frame.absolute_position.y), m_width(frame.absolute_size.width),
          m_height(frame.absolute_size.height) {
        this->Update();
    }

    void SetSize(int width, int heigth) {
        m_width  = width;
        m_height = heigth;
    }

    void SetPosition(int x, int y) {
        pos_x = x;
        pos_y = y;
    }

    void Update() {
        QWidget::resize(m_width, m_height);
        QWidget::move(pos_x, pos_y);
    }

    void Update(Frame &frame) {
        pos_x    = frame.absolute_position.x;
        pos_y    = frame.absolute_position.y;
        m_width  = frame.absolute_size.width;
        m_height = frame.absolute_size.height;

        QWidget::resize(m_width, m_height);
        QWidget::move(pos_x, pos_y);
    }

    int getWidgetWidth() { return QWidget::width(); }

    int getWidgetHeight() { return QWidget::height(); }

protected:
    void paintEvent(QPaintEvent *event) override {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        QRect rect(0, 0, m_width, m_height);

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
    int pos_x, pos_y;
    int m_width, m_height;
};

} // namespace Qim

#endif // QIMBASEWIDGET_HPP
