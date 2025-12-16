#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    pack = new BatteryPack(BatteryPack::SERIES);

    ui->drawArea->setBatteries(&batteries);
    ui->drawArea->setSeries(true);

    ui->radioSeries->setChecked(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAddBattery_clicked()
{
    Battery* b = new Battery(
        ui->spinVoltage->value(),
        ui->spinCapacity->value(),
        ui->spinInitialCharge->value()
        );

    pack->add(b);
    batteries.push_back(b);

    ui->drawArea->update();
}

void MainWindow::on_btnUse_clicked()
{
    int idx = ui->drawArea->getSelectedIndex();

    if (idx >= 0 && idx < (int)batteries.size())
    {
        batteries[idx]->use(1);          // ✅ tek basış = -1
    }
    else
    {
        for (Battery* b : batteries)
            b->use(1);                   // ✅ tek basış = -1 (hepsi)
    }

    ui->drawArea->update();
}

void MainWindow::on_btnRecharge_clicked()
{
    int idx = ui->drawArea->getSelectedIndex();

    if (idx >= 0 && idx < (int)batteries.size())
    {
        batteries[idx]->recharge(1);     // ✅ tek basış = +1
    }
    else
    {
        for (Battery* b : batteries)
            b->recharge(1);              // ✅ tek basış = +1 (hepsi)
    }

    ui->drawArea->update();
}

void MainWindow::on_radioSeries_toggled(bool checked)
{
    ui->drawArea->setSeries(checked);
}
