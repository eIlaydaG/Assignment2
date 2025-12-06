#ifndef BATTERYPACK_H
#define BATTERYPACK_H

#include "Battery.h"
#include <vector>

/**
 * @brief A battery pack composed of Battery cells. Inherits from Battery.
 *
 * The pack exposes combined properties depending on connection type:
 * - SERIES: voltages sum; capacity and charge are the minimum among cells.
 * - PARALLEL: voltage equals any cell's voltage; capacity and charge sum.
 */
class BatteryPack : public Battery {
public:
    /** Connection types for cells in the pack. */
    enum ConnectionType { SERIES, PARALLEL };

    /**
     * @brief Construct a new BatteryPack object
     * @param t Connection type (SERIES or PARALLEL)
     *
     * Note: Battery base is initialized with zeros because the pack's
     * aggregate properties are computed dynamically.
     */
    BatteryPack(ConnectionType t);

    /**
     * @brief Add a battery cell to the pack.
     * @param b Pointer to a Battery (can be a Battery or another BatteryPack)
     */
    void add(Battery* b);

    /** @brief Discharge each child for given hours. */
    void use(double hours) override;

    /** @brief Recharge each child for given hours. */
    void recharge(double hours) override;

    /** @brief Aggregate voltage based on connection type. */
    double getVoltage() const override;

    /** @brief Aggregate capacity based on connection type. */
    double getCapacity() const override;

    /** @brief Aggregate charge based on connection type. */
    double getCharge() const override;

    /** Virtual destructor. */
    virtual ~BatteryPack() {}

private:
    ConnectionType type;
    std::vector<Battery*> cells;
};

#endif // BATTERYPACK_H
