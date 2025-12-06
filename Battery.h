#ifndef BATTERY_H
#define BATTERY_H

#include <algorithm>

/**
 * @brief Represents a single battery cell.
 */
class Battery {
public:
    /** Fixed discharge rate in mAh/hour. */
    static constexpr double DISCHARGE_RATE = 100.0;
    /** Fixed recharge rate in mAh/hour. */
    static constexpr double RECHARGE_RATE = 150.0;

    /**
     * @brief Construct a new Battery object
     * @param v Voltage in volts
     * @param c Capacity in mAh
     * @param initialCharge Initial charge in mAh
     */
    Battery(double v, double c, double initialCharge);

    /**
     * @brief Decreases charge based on a fixed discharge rate.
     * @param hours Number of hours of usage.
     */
    virtual void use(double hours);

    /**
     * @brief Increases charge based on a fixed recharge rate.
     * @param hours Number of hours of recharging.
     */
    virtual void recharge(double hours);

    /** @return Voltage in volts. */
    virtual double getVoltage() const;

    /** @return Capacity in mAh. */
    virtual double getCapacity() const;

    /** @return Current charge in mAh. */
    virtual double getCharge() const;

    /**
     * @brief Returns charge as a percentage of capacity (0-100).
     * @return double percent
     */
    virtual double getPercent() const;

    /** Virtual destructor. */
    virtual ~Battery() {}

protected:
    double voltage;
    double capacity;
    double charge;
};

#endif // BATTERY_H
