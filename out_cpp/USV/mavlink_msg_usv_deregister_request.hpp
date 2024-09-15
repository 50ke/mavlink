// MESSAGE USV_DEREGISTER_REQUEST support class

#pragma once

namespace mavlink {
namespace USV {
namespace msg {

/**
 * @brief USV_DEREGISTER_REQUEST message
 *
 * usv/ugc deregister request
 */
struct USV_DEREGISTER_REQUEST : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50003;
    static constexpr size_t LENGTH = 4;
    static constexpr size_t MIN_LENGTH = 4;
    static constexpr uint8_t CRC_EXTRA = 167;
    static constexpr auto NAME = "USV_DEREGISTER_REQUEST";


    uint32_t time_ms; /*< [ms] system current timestamp. */


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
        ss << "  time_ms: " << time_ms << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_ms;                       // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_ms;                       // offset: 0
    }
};

} // namespace msg
} // namespace USV
} // namespace mavlink
