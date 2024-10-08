// MESSAGE SCALED_PRESSURE3 support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief SCALED_PRESSURE3 message
 *
 * Barometer readings for 3rd barometer
 */
struct SCALED_PRESSURE3 : mavlink::Message {
    static constexpr msgid_t MSG_ID = 143;
    static constexpr size_t LENGTH = 16;
    static constexpr size_t MIN_LENGTH = 14;
    static constexpr uint8_t CRC_EXTRA = 131;
    static constexpr auto NAME = "SCALED_PRESSURE3";


    uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    float press_abs; /*< [hPa] Absolute pressure */
    float press_diff; /*< [hPa] Differential pressure */
    int16_t temperature; /*< [cdegC] Absolute pressure temperature */
    int16_t temperature_press_diff; /*< [cdegC] Differential pressure
                temperature (0, if not available). Report values of 0 (or 1) as 1 cdegC.
             */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  time_boot_ms: " << time_boot_ms << std::endl;
        ss << "  press_abs: " << press_abs << std::endl;
        ss << "  press_diff: " << press_diff << std::endl;
        ss << "  temperature: " << temperature << std::endl;
        ss << "  temperature_press_diff: " << temperature_press_diff << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << press_abs;                     // offset: 4
        map << press_diff;                    // offset: 8
        map << temperature;                   // offset: 12
        map << temperature_press_diff;        // offset: 14
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> press_abs;                     // offset: 4
        map >> press_diff;                    // offset: 8
        map >> temperature;                   // offset: 12
        map >> temperature_press_diff;        // offset: 14
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
