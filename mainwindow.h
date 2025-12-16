#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>

#include "Battery.h"
#include "BatteryPack.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnAddBattery_clicked();
    void on_btnUse_clicked();
    void on_btnRecharge_clicked();
    void on_radioSeries_toggled(bool checked);

private:
    Ui::MainWindow *ui;

    BatteryPack* pack;
    std::vector<Battery*> batteries;
};

#endif // MAINWINDOW_H
