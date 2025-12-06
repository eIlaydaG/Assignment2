#include "Battery.h"

Battery::Battery(double v, double c, double initialCharge)
    : voltage(v), capacity(c), charge(initialCharge) {
    if (capacity < 0) capacity = 0;
    // Clamp initial charge to [0, capacity]
    if (charge < 0) charge = 0;
    if (charge > capacity) charge = capacity;
}

void Battery::use(double hours) {
    if (hours < 0) return;
    double delta = hours * DISCHARGE_RATE;
    charge -= delta;
    if (charge < 0) charge = 0;
}

void Battery::recharge(double hours) {
    if (hours < 0) return;
    double delta = hours * RECHARGE_RATE;
    charge += delta;
    if (charge > capacity) charge = capacity;
}

double Battery::getVoltage() const {
    return voltage;
}

double Battery::getCapacity() const {
    return capacity;
}

double Battery::getCharge() const {
    return charge;
}

double Battery::getPercent() const {
    if (capacity <= 0) return 0.0;
    return 100.0 * charge / capacity;
}
