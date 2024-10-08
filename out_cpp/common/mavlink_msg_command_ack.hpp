// MESSAGE COMMAND_ACK support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief COMMAND_ACK message
 *
 * Report status of a command. Includes feedback whether the command was executed. The command
                microservice is documented at https://mavlink.io/en/services/command.html
            
 */
struct COMMAND_ACK : mavlink::Message {
    static constexpr msgid_t MSG_ID = 77;
    static constexpr size_t LENGTH = 10;
    static constexpr size_t MIN_LENGTH = 3;
    static constexpr uint8_t CRC_EXTRA = 143;
    static constexpr auto NAME = "COMMAND_ACK";


    uint16_t command; /*<  Command ID (of acknowledged command). */
    uint8_t result; /*<  Result of command. */
    uint8_t progress; /*< [%] The progress percentage when result is
                MAV_RESULT_IN_PROGRESS. Values: [0-100], or UINT8_MAX if the progress is unknown.
             */
    int32_t result_param2; /*<  Additional result information. Can be set with a command-specific
                enum containing command-specific error reasons for why the command might be denied. If used, the
                associated enum must be documented in the corresponding MAV_CMD (this enum should have a 0 value to
                indicate "unused" or "unknown").
             */
    uint8_t target_system; /*<  System ID of the target recipient. This is the ID of the system
                that sent the command for which this COMMAND_ACK is an acknowledgement.
             */
    uint8_t target_component; /*<  Component ID of the target recipient. This is the ID of the
                system that sent the command for which this COMMAND_ACK is an acknowledgement.
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
        ss << "  command: " << command << std::endl;
        ss << "  result: " << +result << std::endl;
        ss << "  progress: " << +progress << std::endl;
        ss << "  result_param2: " << result_param2 << std::endl;
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  target_component: " << +target_component << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << command;                       // offset: 0
        map << result;                        // offset: 2
        map << progress;                      // offset: 3
        map << result_param2;                 // offset: 4
        map << target_system;                 // offset: 8
        map << target_component;              // offset: 9
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> command;                       // offset: 0
        map >> result;                        // offset: 2
        map >> progress;                      // offset: 3
        map >> result_param2;                 // offset: 4
        map >> target_system;                 // offset: 8
        map >> target_component;              // offset: 9
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
