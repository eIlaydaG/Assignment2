#ifndef BATTERYCANVAS_H
#define BATTERYCANVAS_H

#include <QWidget>
#include <vector>
#include "Battery.h"

class BatteryCanvas : public QWidget
{
    Q_OBJECT
public:
    explicit BatteryCanvas(QWidget *parent = nullptr);

    void setBatteries(const std::vector<Battery*> *list);
    void setSeries(bool series);
    int getSelectedIndex() const;

protected:
    void paintEvent(QPaintEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    const std::vector<Battery*> *batteries = nullptr;
    bool isSeries = true;
    int selectedIndex = -1;
};

#endif // BATTERYCANVAS_H
