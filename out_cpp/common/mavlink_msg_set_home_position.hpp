// MESSAGE SET_HOME_POSITION support class

#pragma once

namespace mavlink {
namespace common {
namespace msg {

/**
 * @brief SET_HOME_POSITION message
 *
 * 
                Sets the home position.
                The home position is the default position that the system will return to and land on.
                The position is set automatically by the system during the takeoff (and may also be set using this
                message).
                The global and local positions encode the position in the respective coordinate frames, while the q
                parameter encodes the orientation of the surface.
                Under normal conditions it describes the heading and terrain slope, which can be used by the aircraft to
                adjust the approach.
                The approach 3D vector describes the point to which the system should fly in normal flight mode and then
                perform a landing sequence along the vector.
                Note: the current home position may be emitted in a HOME_POSITION message on request (using
                MAV_CMD_REQUEST_MESSAGE with param1=242).
            
 */
struct SET_HOME_POSITION : mavlink::Message {
    static constexpr msgid_t MSG_ID = 243;
    static constexpr size_t LENGTH = 61;
    static constexpr size_t MIN_LENGTH = 53;
    static constexpr uint8_t CRC_EXTRA = 85;
    static constexpr auto NAME = "SET_HOME_POSITION";


    uint8_t target_system; /*<  System ID. */
    int32_t latitude; /*< [degE7] Latitude (WGS84) */
    int32_t longitude; /*< [degE7] Longitude (WGS84) */
    int32_t altitude; /*< [mm] Altitude (MSL). Positive for up. */
    float x; /*< [m] Local X position of this position in the local coordinate frame
                (NED)
             */
    float y; /*< [m] Local Y position of this position in the local coordinate frame
                (NED)
             */
    float z; /*< [m] Local Z position of this position in the local coordinate frame (NED:
                positive "down")
             */
    std::array<float, 4> q; /*<  World to surface normal and heading transformation of the takeoff position.
                Used to indicate the heading and slope of the ground
             */
    float approach_x; /*< [m] Local X position of the end of the approach vector.
                Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft
                should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the
                opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
             */
    float approach_y; /*< [m] Local Y position of the end of the approach vector.
                Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft
                should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the
                opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
             */
    float approach_z; /*< [m] Local Z position of the end of the approach vector.
                Multicopters should set this position based on their takeoff path. Grass-landing fixed wing aircraft
                should set it the same way as multicopters. Runway-landing fixed wing aircraft should set it to the
                opposite direction of the takeoff, assuming the takeoff happened from the threshold / touchdown zone.
             */
    uint64_t time_usec; /*< [us] Timestamp (UNIX Epoch time or time since system boot).
                The receiving end can infer timestamp format (since 1.1.1970 or since system boot) by checking for the
                magnitude of the number.
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
        ss << "  target_system: " << +target_system << std::endl;
        ss << "  latitude: " << latitude << std::endl;
        ss << "  longitude: " << longitude << std::endl;
        ss << "  altitude: " << altitude << std::endl;
        ss << "  x: " << x << std::endl;
        ss << "  y: " << y << std::endl;
        ss << "  z: " << z << std::endl;
        ss << "  q: [" << to_string(q) << "]" << std::endl;
        ss << "  approach_x: " << approach_x << std::endl;
        ss << "  approach_y: " << approach_y << std::endl;
        ss << "  approach_z: " << approach_z << std::endl;
        ss << "  time_usec: " << time_usec << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << latitude;                      // offset: 0
        map << longitude;                     // offset: 4
        map << altitude;                      // offset: 8
        map << x;                             // offset: 12
        map << y;                             // offset: 16
        map << z;                             // offset: 20
        map << q;                             // offset: 24
        map << approach_x;                    // offset: 40
        map << approach_y;                    // offset: 44
        map << approach_z;                    // offset: 48
        map << target_system;                 // offset: 52
        map << time_usec;                     // offset: 53
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> latitude;                      // offset: 0
        map >> longitude;                     // offset: 4
        map >> altitude;                      // offset: 8
        map >> x;                             // offset: 12
        map >> y;                             // offset: 16
        map >> z;                             // offset: 20
        map >> q;                             // offset: 24
        map >> approach_x;                    // offset: 40
        map >> approach_y;                    // offset: 44
        map >> approach_z;                    // offset: 48
        map >> target_system;                 // offset: 52
        map >> time_usec;                     // offset: 53
    }
};

} // namespace msg
} // namespace common
} // namespace mavlink
