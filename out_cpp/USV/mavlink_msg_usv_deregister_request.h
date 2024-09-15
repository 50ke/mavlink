#pragma once
// MESSAGE USV_DEREGISTER_REQUEST PACKING

#define MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST 50003


typedef struct __mavlink_usv_deregister_request_t {
 uint32_t time_ms; /*< [ms] system current timestamp.*/
} mavlink_usv_deregister_request_t;

#define MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN 4
#define MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN 4
#define MAVLINK_MSG_ID_50003_LEN 4
#define MAVLINK_MSG_ID_50003_MIN_LEN 4

#define MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC 167
#define MAVLINK_MSG_ID_50003_CRC 167



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_DEREGISTER_REQUEST { \
    50003, \
    "USV_DEREGISTER_REQUEST", \
    1, \
    {  { "time_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_usv_deregister_request_t, time_ms) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_DEREGISTER_REQUEST { \
    "USV_DEREGISTER_REQUEST", \
    1, \
    {  { "time_ms", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_usv_deregister_request_t, time_ms) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_deregister_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_ms [ms] system current timestamp.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_deregister_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint32_t time_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN];
    _mav_put_uint32_t(buf, 0, time_ms);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN);
#else
    mavlink_usv_deregister_request_t packet;
    packet.time_ms = time_ms;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC);
}

/**
 * @brief Pack a usv_deregister_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param time_ms [ms] system current timestamp.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_deregister_request_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint32_t time_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN];
    _mav_put_uint32_t(buf, 0, time_ms);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN);
#else
    mavlink_usv_deregister_request_t packet;
    packet.time_ms = time_ms;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN);
#endif
}

/**
 * @brief Pack a usv_deregister_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param time_ms [ms] system current timestamp.
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_deregister_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint32_t time_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN];
    _mav_put_uint32_t(buf, 0, time_ms);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN);
#else
    mavlink_usv_deregister_request_t packet;
    packet.time_ms = time_ms;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC);
}

/**
 * @brief Encode a usv_deregister_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_deregister_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_deregister_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_deregister_request_t* usv_deregister_request)
{
    return mavlink_msg_usv_deregister_request_pack(system_id, component_id, msg, usv_deregister_request->time_ms);
}

/**
 * @brief Encode a usv_deregister_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_deregister_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_deregister_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_deregister_request_t* usv_deregister_request)
{
    return mavlink_msg_usv_deregister_request_pack_chan(system_id, component_id, chan, msg, usv_deregister_request->time_ms);
}

/**
 * @brief Encode a usv_deregister_request struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param usv_deregister_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_deregister_request_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_usv_deregister_request_t* usv_deregister_request)
{
    return mavlink_msg_usv_deregister_request_pack_status(system_id, component_id, _status, msg,  usv_deregister_request->time_ms);
}

/**
 * @brief Send a usv_deregister_request message
 * @param chan MAVLink channel to send the message
 *
 * @param time_ms [ms] system current timestamp.
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_deregister_request_send(mavlink_channel_t chan, uint32_t time_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN];
    _mav_put_uint32_t(buf, 0, time_ms);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST, buf, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC);
#else
    mavlink_usv_deregister_request_t packet;
    packet.time_ms = time_ms;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC);
#endif
}

/**
 * @brief Send a usv_deregister_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_deregister_request_send_struct(mavlink_channel_t chan, const mavlink_usv_deregister_request_t* usv_deregister_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_deregister_request_send(chan, usv_deregister_request->time_ms);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST, (const char *)usv_deregister_request, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_deregister_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint32_t time_ms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, time_ms);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST, buf, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC);
#else
    mavlink_usv_deregister_request_t *packet = (mavlink_usv_deregister_request_t *)msgbuf;
    packet->time_ms = time_ms;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST, (const char *)packet, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_DEREGISTER_REQUEST UNPACKING


/**
 * @brief Get field time_ms from usv_deregister_request message
 *
 * @return [ms] system current timestamp.
 */
static inline uint32_t mavlink_msg_usv_deregister_request_get_time_ms(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Decode a usv_deregister_request message into a struct
 *
 * @param msg The message to decode
 * @param usv_deregister_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_deregister_request_decode(const mavlink_message_t* msg, mavlink_usv_deregister_request_t* usv_deregister_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_deregister_request->time_ms = mavlink_msg_usv_deregister_request_get_time_ms(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN;
        memset(usv_deregister_request, 0, MAVLINK_MSG_ID_USV_DEREGISTER_REQUEST_LEN);
    memcpy(usv_deregister_request, _MAV_PAYLOAD(msg), len);
#endif
}
