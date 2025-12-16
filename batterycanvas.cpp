#include "batterycanvas.h"
#include <QPainter>
#include <QLinearGradient>
#include <QMouseEvent>

BatteryCanvas::BatteryCanvas(QWidget *parent)
    : QWidget(parent)
{
    setMinimumHeight(250);
    setAutoFillBackground(true);
}

void BatteryCanvas::setBatteries(const std::vector<Battery*> *list)
{
    batteries = list;
    update();
}

void BatteryCanvas::setSeries(bool series)
{
    isSeries = series;
    update();
}

int BatteryCanvas::getSelectedIndex() const
{
    return selectedIndex;
}

void BatteryCanvas::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.fillRect(rect(), QColor("#FAFAFA"));

    if (!batteries || batteries->empty())
        return;

    int bw = 70, bh = 140, gap = 20;
    int x = 30, y = 30;

    for (int i = 0; i < (int)batteries->size(); ++i)
    {
        Battery* b = (*batteries)[i];
        if (!b) continue;

        double percent = b->getPercent();

        QColor baseColor;
        if (percent > 60)
            baseColor = QColor("#4CAF50");
        else if (percent > 30)
            baseColor = QColor("#FFC107");
        else
            baseColor = QColor("#F44336");

        QRect batteryRect(x, y, bw, bh);

        // Gölge
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(0, 0, 0, 40));
        painter.drawRoundedRect(batteryRect.adjusted(4, 4, 4, 4), 10, 10);

        // Çerçeve
        painter.setPen(QPen(Qt::black, 2));
        painter.setBrush(Qt::NoBrush);
        painter.drawRoundedRect(batteryRect, 10, 10);

        // Doluluk
        int fillHeight = static_cast<int>(bh * percent / 100.0);
        if (fillHeight > 0)
        {
            QRect fillRect(
                x + 4,
                y + bh - fillHeight + 4,
                bw - 8,
                fillHeight - 8
                );

            QLinearGradient grad(fillRect.topLeft(), fillRect.bottomLeft());
            grad.setColorAt(0.0, baseColor.lighter(140));
            grad.setColorAt(1.0, baseColor.darker(140));

            painter.setPen(Qt::NoPen);
            painter.setBrush(grad);
            painter.drawRoundedRect(fillRect, 8, 8);
        }

        // % yazısı
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 11, QFont::Bold));
        painter.drawText(batteryRect, Qt::AlignCenter,
                         QString("%1%").arg((int)percent));

        // Seçili batarya
        if (i == selectedIndex)
        {
            painter.setPen(QPen(QColor("#2196F3"), 3));
            painter.setBrush(Qt::NoBrush);
            painter.drawRoundedRect(
                batteryRect.adjusted(-4, -4, 4, 4), 12, 12
                );
        }

        if (isSeries)
            y += bh + gap;
        else
            x += bw + gap;
    }
}

void BatteryCanvas::mousePressEvent(QMouseEvent *event)
{
    if (!batteries) return;

    int bw = 70, bh = 140, gap = 20;
    int x = 30, y = 30;

    selectedIndex = -1;

    for (int i = 0; i < (int)batteries->size(); ++i)
    {
        QRect rect(x, y, bw, bh);
        if (rect.contains(event->pos()))
        {
            selectedIndex = i;
            break;
        }

        if (isSeries)
            y += bh + gap;
        else
            x += bw + gap;
    }

    update();
}
