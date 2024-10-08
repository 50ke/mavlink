// MESSAGE STORAGE_INFORMATION support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief STORAGE_INFORMATION message
 *
 * Information about a storage medium. This message is sent in response to a request with
                MAV_CMD_REQUEST_MESSAGE and whenever the status of the storage changes (STORAGE_STATUS). Use
                MAV_CMD_REQUEST_MESSAGE.param2 to indicate the index/id of requested storage: 0 for all, 1 for first, 2
                for second, etc.
            
 */
struct STORAGE_INFORMATION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 261;
    static constexpr size_t LENGTH = 61;
    static constexpr size_t MIN_LENGTH = 27;
    static constexpr uint8_t CRC_EXTRA = 179;
    static constexpr auto NAME = "STORAGE_INFORMATION";


    uint32_t time_boot_ms; /*< [ms] Timestamp (time since system boot). */
    uint8_t storage_id; /*<  Storage ID (1 for first, 2 for second, etc.) */
    uint8_t storage_count; /*<  Number of storage devices */
    uint8_t status; /*<  Status of storage */
    float total_capacity; /*< [MiB] Total capacity. If storage is not ready
                (STORAGE_STATUS_READY) value will be ignored.
             */
    float used_capacity; /*< [MiB] Used capacity. If storage is not ready
                (STORAGE_STATUS_READY) value will be ignored.
             */
    float available_capacity; /*< [MiB] Available storage capacity. If storage is not
                ready (STORAGE_STATUS_READY) value will be ignored.
             */
    float read_speed; /*< [MiB/s] Read speed. */
    float write_speed; /*< [MiB/s] Write speed. */
    uint8_t type; /*<  Type of storage */
    std::array<char, 32> name; /*<  Textual storage name to be used in UI (microSD 1, Internal Memory, etc.)
                This is a NULL terminated string. If it is exactly 32 characters long, add a terminating NULL. If this
                string is empty, the generic type is shown to the user.
             */
    uint8_t storage_usage; /*<  Flags indicating whether this instance
                is preferred storage for photos, videos, etc.
                Note: Implementations should initially set the flags on the system-default storage id used for saving
                media (if possible/supported).
                This setting can then be overridden using MAV_CMD_SET_STORAGE_USAGE.
                If the media usage flags are not set, a GCS may assume storage ID 1 is the default storage for all media
                types.
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
        ss << "  storage_id: " << +storage_id << std::endl;
        ss << "  storage_count: " << +storage_count << std::endl;
        ss << "  status: " << +status << std::endl;
        ss << "  total_capacity: " << total_capacity << std::endl;
        ss << "  used_capacity: " << used_capacity << std::endl;
        ss << "  available_capacity: " << available_capacity << std::endl;
        ss << "  read_speed: " << read_speed << std::endl;
        ss << "  write_speed: " << write_speed << std::endl;
        ss << "  type: " << +type << std::endl;
        ss << "  name: \"" << to_string(name) << "\"" << std::endl;
        ss << "  storage_usage: " << +storage_usage << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << time_boot_ms;                  // offset: 0
        map << total_capacity;                // offset: 4
        map << used_capacity;                 // offset: 8
        map << available_capacity;            // offset: 12
        map << read_speed;                    // offset: 16
        map << write_speed;                   // offset: 20
        map << storage_id;                    // offset: 24
        map << storage_count;                 // offset: 25
        map << status;                        // offset: 26
        map << type;                          // offset: 27
        map << name;                          // offset: 28
        map << storage_usage;                 // offset: 60
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> time_boot_ms;                  // offset: 0
        map >> total_capacity;                // offset: 4
        map >> used_capacity;                 // offset: 8
        map >> available_capacity;            // offset: 12
        map >> read_speed;                    // offset: 16
        map >> write_speed;                   // offset: 20
        map >> storage_id;                    // offset: 24
        map >> storage_count;                 // offset: 25
        map >> status;                        // offset: 26
        map >> type;                          // offset: 27
        map >> name;                          // offset: 28
        map >> storage_usage;                 // offset: 60
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
