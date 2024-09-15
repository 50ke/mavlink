#pragma once
// MESSAGE USV_SYSTEM_INFORMATION PACKING

#define MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION 50009


typedef struct __mavlink_usv_system_information_t {
 int32_t lat; /*< [degE7] Latitude (WGS84, EGM96 ellipsoid)*/
 int32_t lon; /*< [degE7] Longitude (WGS84, EGM96 ellipsoid)*/
 char name[128]; /*<  system name*/
 uint8_t connect; /*<  0: not connected. 1: connected.*/
} mavlink_usv_system_information_t;

#define MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN 137
#define MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN 137
#define MAVLINK_MSG_ID_50009_LEN 137
#define MAVLINK_MSG_ID_50009_MIN_LEN 137

#define MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC 59
#define MAVLINK_MSG_ID_50009_CRC 59

#define MAVLINK_MSG_USV_SYSTEM_INFORMATION_FIELD_NAME_LEN 128

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_SYSTEM_INFORMATION { \
    50009, \
    "USV_SYSTEM_INFORMATION", \
    4, \
    {  { "name", NULL, MAVLINK_TYPE_CHAR, 128, 8, offsetof(mavlink_usv_system_information_t, name) }, \
         { "connect", NULL, MAVLINK_TYPE_UINT8_T, 0, 136, offsetof(mavlink_usv_system_information_t, connect) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_usv_system_information_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_usv_system_information_t, lon) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_SYSTEM_INFORMATION { \
    "USV_SYSTEM_INFORMATION", \
    4, \
    {  { "name", NULL, MAVLINK_TYPE_CHAR, 128, 8, offsetof(mavlink_usv_system_information_t, name) }, \
         { "connect", NULL, MAVLINK_TYPE_UINT8_T, 0, 136, offsetof(mavlink_usv_system_information_t, connect) }, \
         { "lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_usv_system_information_t, lat) }, \
         { "lon", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_usv_system_information_t, lon) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_system_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param name  system name
 * @param connect  0: not connected. 1: connected.
 * @param lat [degE7] Latitude (WGS84, EGM96 ellipsoid)
 * @param lon [degE7] Longitude (WGS84, EGM96 ellipsoid)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_system_information_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *name, uint8_t connect, int32_t lat, int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_uint8_t(buf, 136, connect);
    _mav_put_char_array(buf, 8, name, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN);
#else
    mavlink_usv_system_information_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.connect = connect;
    mav_array_memcpy(packet.name, name, sizeof(char)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC);
}

/**
 * @brief Pack a usv_system_information message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param name  system name
 * @param connect  0: not connected. 1: connected.
 * @param lat [degE7] Latitude (WGS84, EGM96 ellipsoid)
 * @param lon [degE7] Longitude (WGS84, EGM96 ellipsoid)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_system_information_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const char *name, uint8_t connect, int32_t lat, int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_uint8_t(buf, 136, connect);
    _mav_put_char_array(buf, 8, name, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN);
#else
    mavlink_usv_system_information_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.connect = connect;
    mav_array_memcpy(packet.name, name, sizeof(char)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN);
#endif
}

/**
 * @brief Pack a usv_system_information message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param name  system name
 * @param connect  0: not connected. 1: connected.
 * @param lat [degE7] Latitude (WGS84, EGM96 ellipsoid)
 * @param lon [degE7] Longitude (WGS84, EGM96 ellipsoid)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_system_information_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *name,uint8_t connect,int32_t lat,int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_uint8_t(buf, 136, connect);
    _mav_put_char_array(buf, 8, name, 128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN);
#else
    mavlink_usv_system_information_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.connect = connect;
    mav_array_memcpy(packet.name, name, sizeof(char)*128);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC);
}

/**
 * @brief Encode a usv_system_information struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_system_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_system_information_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_system_information_t* usv_system_information)
{
    return mavlink_msg_usv_system_information_pack(system_id, component_id, msg, usv_system_information->name, usv_system_information->connect, usv_system_information->lat, usv_system_information->lon);
}

/**
 * @brief Encode a usv_system_information struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_system_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_system_information_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_system_information_t* usv_system_information)
{
    return mavlink_msg_usv_system_information_pack_chan(system_id, component_id, chan, msg, usv_system_information->name, usv_system_information->connect, usv_system_information->lat, usv_system_information->lon);
}

/**
 * @brief Encode a usv_system_information struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param usv_system_information C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_system_information_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_usv_system_information_t* usv_system_information)
{
    return mavlink_msg_usv_system_information_pack_status(system_id, component_id, _status, msg,  usv_system_information->name, usv_system_information->connect, usv_system_information->lat, usv_system_information->lon);
}

/**
 * @brief Send a usv_system_information message
 * @param chan MAVLink channel to send the message
 *
 * @param name  system name
 * @param connect  0: not connected. 1: connected.
 * @param lat [degE7] Latitude (WGS84, EGM96 ellipsoid)
 * @param lon [degE7] Longitude (WGS84, EGM96 ellipsoid)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_system_information_send(mavlink_channel_t chan, const char *name, uint8_t connect, int32_t lat, int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN];
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_uint8_t(buf, 136, connect);
    _mav_put_char_array(buf, 8, name, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION, buf, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC);
#else
    mavlink_usv_system_information_t packet;
    packet.lat = lat;
    packet.lon = lon;
    packet.connect = connect;
    mav_array_memcpy(packet.name, name, sizeof(char)*128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION, (const char *)&packet, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC);
#endif
}

/**
 * @brief Send a usv_system_information message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_system_information_send_struct(mavlink_channel_t chan, const mavlink_usv_system_information_t* usv_system_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_system_information_send(chan, usv_system_information->name, usv_system_information->connect, usv_system_information->lat, usv_system_information->lon);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION, (const char *)usv_system_information, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_system_information_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *name, uint8_t connect, int32_t lat, int32_t lon)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, lat);
    _mav_put_int32_t(buf, 4, lon);
    _mav_put_uint8_t(buf, 136, connect);
    _mav_put_char_array(buf, 8, name, 128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION, buf, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC);
#else
    mavlink_usv_system_information_t *packet = (mavlink_usv_system_information_t *)msgbuf;
    packet->lat = lat;
    packet->lon = lon;
    packet->connect = connect;
    mav_array_memcpy(packet->name, name, sizeof(char)*128);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION, (const char *)packet, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_MIN_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_SYSTEM_INFORMATION UNPACKING


/**
 * @brief Get field name from usv_system_information message
 *
 * @return  system name
 */
static inline uint16_t mavlink_msg_usv_system_information_get_name(const mavlink_message_t* msg, char *name)
{
    return _MAV_RETURN_char_array(msg, name, 128,  8);
}

/**
 * @brief Get field connect from usv_system_information message
 *
 * @return  0: not connected. 1: connected.
 */
static inline uint8_t mavlink_msg_usv_system_information_get_connect(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  136);
}

/**
 * @brief Get field lat from usv_system_information message
 *
 * @return [degE7] Latitude (WGS84, EGM96 ellipsoid)
 */
static inline int32_t mavlink_msg_usv_system_information_get_lat(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field lon from usv_system_information message
 *
 * @return [degE7] Longitude (WGS84, EGM96 ellipsoid)
 */
static inline int32_t mavlink_msg_usv_system_information_get_lon(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Decode a usv_system_information message into a struct
 *
 * @param msg The message to decode
 * @param usv_system_information C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_system_information_decode(const mavlink_message_t* msg, mavlink_usv_system_information_t* usv_system_information)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_system_information->lat = mavlink_msg_usv_system_information_get_lat(msg);
    usv_system_information->lon = mavlink_msg_usv_system_information_get_lon(msg);
    mavlink_msg_usv_system_information_get_name(msg, usv_system_information->name);
    usv_system_information->connect = mavlink_msg_usv_system_information_get_connect(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN? msg->len : MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN;
        memset(usv_system_information, 0, MAVLINK_MSG_ID_USV_SYSTEM_INFORMATION_LEN);
    memcpy(usv_system_information, _MAV_PAYLOAD(msg), len);
#endif
}
