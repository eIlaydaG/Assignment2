#include "BatteryPack.h"
#include <numeric>
#include <limits>

BatteryPack::BatteryPack(ConnectionType t)
    : Battery(0.0, 0.0, 0.0), type(t) {}

void BatteryPack::add(Battery* b) {
    if (b) cells.push_back(b);
}

void BatteryPack::use(double hours) {
    if (hours < 0) return;
    for (Battery* b : cells) {
        if (b) b->use(hours);
    }
}

void BatteryPack::recharge(double hours) {
    if (hours < 0) return;
    for (Battery* b : cells) {
        if (b) b->recharge(hours);
    }
}

double BatteryPack::getVoltage() const {
    if (cells.empty()) return 0.0;
    if (type == SERIES) {
        double sum = 0.0;
        for (Battery* b : cells) if (b) sum += b->getVoltage();
        return sum;
    } else { // PARALLEL
        // return voltage of any cell (take first non-null)
        for (Battery* b : cells) if (b) return b->getVoltage();
        return 0.0;
    }
}

double BatteryPack::getCapacity() const {
    if (cells.empty()) return 0.0;
    if (type == SERIES) {
        double minCap = std::numeric_limits<double>::infinity();
        for (Battery* b : cells) if (b) minCap = std::min(minCap, b->getCapacity());
        if (minCap == std::numeric_limits<double>::infinity()) return 0.0;
        return minCap;
    } else { // PARALLEL
        double sum = 0.0;
        for (Battery* b : cells) if (b) sum += b->getCapacity();
        return sum;
    }
}

double BatteryPack::getCharge() const {
    if (cells.empty()) return 0.0;
    if (type == SERIES) {
        double minCharge = std::numeric_limits<double>::infinity();
        for (Battery* b : cells) if (b) minCharge = std::min(minCharge, b->getCharge());
        if (minCharge == std::numeric_limits<double>::infinity()) return 0.0;
        return minCharge;
    } else { // PARALLEL
        double sum = 0.0;
        for (Battery* b : cells) if (b) sum += b->getCharge();
        return sum;
    }
}
