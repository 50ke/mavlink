// MESSAGE USV_REGISTER_REQUEST support class

#pragma once

namespace mavlink {
namespace USV {
namespace msg {

/**
 * @brief USV_REGISTER_REQUEST message
 *
 * usv/ugc register request
 */
struct USV_REGISTER_REQUEST : mavlink::Message {
    static constexpr msgid_t MSG_ID = 50001;
    static constexpr size_t LENGTH = 3;
    static constexpr size_t MIN_LENGTH = 3;
    static constexpr uint8_t CRC_EXTRA = 91;
    static constexpr auto NAME = "USV_REGISTER_REQUEST";


    uint8_t msg_src; /*<  msg source */
    uint8_t link_type; /*<  msg source */
    uint8_t channel_type; /*<  msg source */


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
        ss << "  msg_src: " << +msg_src << std::endl;
        ss << "  link_type: " << +link_type << std::endl;
        ss << "  channel_type: " << +channel_type << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << msg_src;                       // offset: 0
        map << link_type;                     // offset: 1
        map << channel_type;                  // offset: 2
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> msg_src;                       // offset: 0
        map >> link_type;                     // offset: 1
        map >> channel_type;                  // offset: 2
    }
};

} // namespace msg
} // namespace USV
} // namespace mavlink
