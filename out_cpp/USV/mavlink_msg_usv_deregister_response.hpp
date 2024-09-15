// MESSAGE USV_DEREGISTER_RESPONSE support class

#pragma once

namespace mavlink {
namespace USV {
namespace msg {

/**
 * @brief USV_DEREGISTER_RESPONSE message
 *
 * usv/ugc deregister response
 */
struct USV_DEREGISTER_RESPONSE : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50004;
    static constexpr size_t LENGTH = 1;
    static constexpr size_t MIN_LENGTH = 1;
    static constexpr uint8_t CRC_EXTRA = 7;
    static constexpr auto NAME = "USV_DEREGISTER_RESPONSE";


    uint8_t ack; /*<  1: deregister succeed. 0: deregister failed. */


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
        ss << "  ack: " << +ack << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << ack;                           // offset: 0
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> ack;                           // offset: 0
    }
};

} // namespace msg
} // namespace USV
} // namespace mavlink
