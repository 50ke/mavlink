#pragma once
// MESSAGE USV_REGISTER_REQUEST PACKING

#define MAVLINK_MSG_ID_USV_REGISTER_REQUEST 50001


typedef struct __mavlink_usv_register_request_t {
 uint8_t msg_src; /*<  msg source*/
 uint8_t link_type; /*<  msg source*/
 uint8_t channel_type; /*<  msg source*/
} mavlink_usv_register_request_t;

#define MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN 3
#define MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN 3
#define MAVLINK_MSG_ID_50001_LEN 3
#define MAVLINK_MSG_ID_50001_MIN_LEN 3

#define MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC 91
#define MAVLINK_MSG_ID_50001_CRC 91



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_USV_REGISTER_REQUEST { \
    50001, \
    "USV_REGISTER_REQUEST", \
    3, \
    {  { "msg_src", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_usv_register_request_t, msg_src) }, \
         { "link_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_usv_register_request_t, link_type) }, \
         { "channel_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_usv_register_request_t, channel_type) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_USV_REGISTER_REQUEST { \
    "USV_REGISTER_REQUEST", \
    3, \
    {  { "msg_src", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_usv_register_request_t, msg_src) }, \
         { "link_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_usv_register_request_t, link_type) }, \
         { "channel_type", NULL, MAVLINK_TYPE_UINT8_T, 0, 2, offsetof(mavlink_usv_register_request_t, channel_type) }, \
         } \
}
#endif

/**
 * @brief Pack a usv_register_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param msg_src  msg source
 * @param link_type  msg source
 * @param channel_type  msg source
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_register_request_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t msg_src, uint8_t link_type, uint8_t channel_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, msg_src);
    _mav_put_uint8_t(buf, 1, link_type);
    _mav_put_uint8_t(buf, 2, channel_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN);
#else
    mavlink_usv_register_request_t packet;
    packet.msg_src = msg_src;
    packet.link_type = link_type;
    packet.channel_type = channel_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_REGISTER_REQUEST;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC);
}

/**
 * @brief Pack a usv_register_request message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param msg_src  msg source
 * @param link_type  msg source
 * @param channel_type  msg source
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_register_request_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t msg_src, uint8_t link_type, uint8_t channel_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, msg_src);
    _mav_put_uint8_t(buf, 1, link_type);
    _mav_put_uint8_t(buf, 2, channel_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN);
#else
    mavlink_usv_register_request_t packet;
    packet.msg_src = msg_src;
    packet.link_type = link_type;
    packet.channel_type = channel_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_REGISTER_REQUEST;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN);
#endif
}

/**
 * @brief Pack a usv_register_request message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param msg_src  msg source
 * @param link_type  msg source
 * @param channel_type  msg source
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_usv_register_request_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t msg_src,uint8_t link_type,uint8_t channel_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, msg_src);
    _mav_put_uint8_t(buf, 1, link_type);
    _mav_put_uint8_t(buf, 2, channel_type);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN);
#else
    mavlink_usv_register_request_t packet;
    packet.msg_src = msg_src;
    packet.link_type = link_type;
    packet.channel_type = channel_type;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_USV_REGISTER_REQUEST;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC);
}

/**
 * @brief Encode a usv_register_request struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param usv_register_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_register_request_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_usv_register_request_t* usv_register_request)
{
    return mavlink_msg_usv_register_request_pack(system_id, component_id, msg, usv_register_request->msg_src, usv_register_request->link_type, usv_register_request->channel_type);
}

/**
 * @brief Encode a usv_register_request struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param usv_register_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_register_request_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_usv_register_request_t* usv_register_request)
{
    return mavlink_msg_usv_register_request_pack_chan(system_id, component_id, chan, msg, usv_register_request->msg_src, usv_register_request->link_type, usv_register_request->channel_type);
}

/**
 * @brief Encode a usv_register_request struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param usv_register_request C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_usv_register_request_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_usv_register_request_t* usv_register_request)
{
    return mavlink_msg_usv_register_request_pack_status(system_id, component_id, _status, msg,  usv_register_request->msg_src, usv_register_request->link_type, usv_register_request->channel_type);
}

/**
 * @brief Send a usv_register_request message
 * @param chan MAVLink channel to send the message
 *
 * @param msg_src  msg source
 * @param link_type  msg source
 * @param channel_type  msg source
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_usv_register_request_send(mavlink_channel_t chan, uint8_t msg_src, uint8_t link_type, uint8_t channel_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN];
    _mav_put_uint8_t(buf, 0, msg_src);
    _mav_put_uint8_t(buf, 1, link_type);
    _mav_put_uint8_t(buf, 2, channel_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_REGISTER_REQUEST, buf, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC);
#else
    mavlink_usv_register_request_t packet;
    packet.msg_src = msg_src;
    packet.link_type = link_type;
    packet.channel_type = channel_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_REGISTER_REQUEST, (const char *)&packet, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC);
#endif
}

/**
 * @brief Send a usv_register_request message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_usv_register_request_send_struct(mavlink_channel_t chan, const mavlink_usv_register_request_t* usv_register_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_usv_register_request_send(chan, usv_register_request->msg_src, usv_register_request->link_type, usv_register_request->channel_type);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_REGISTER_REQUEST, (const char *)usv_register_request, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC);
#endif
}

#if MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_usv_register_request_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t msg_src, uint8_t link_type, uint8_t channel_type)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, msg_src);
    _mav_put_uint8_t(buf, 1, link_type);
    _mav_put_uint8_t(buf, 2, channel_type);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_REGISTER_REQUEST, buf, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC);
#else
    mavlink_usv_register_request_t *packet = (mavlink_usv_register_request_t *)msgbuf;
    packet->msg_src = msg_src;
    packet->link_type = link_type;
    packet->channel_type = channel_type;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_USV_REGISTER_REQUEST, (const char *)packet, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_MIN_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_CRC);
#endif
}
#endif

#endif

// MESSAGE USV_REGISTER_REQUEST UNPACKING


/**
 * @brief Get field msg_src from usv_register_request message
 *
 * @return  msg source
 */
static inline uint8_t mavlink_msg_usv_register_request_get_msg_src(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field link_type from usv_register_request message
 *
 * @return  msg source
 */
static inline uint8_t mavlink_msg_usv_register_request_get_link_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field channel_type from usv_register_request message
 *
 * @return  msg source
 */
static inline uint8_t mavlink_msg_usv_register_request_get_channel_type(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  2);
}

/**
 * @brief Decode a usv_register_request message into a struct
 *
 * @param msg The message to decode
 * @param usv_register_request C-struct to decode the message contents into
 */
static inline void mavlink_msg_usv_register_request_decode(const mavlink_message_t* msg, mavlink_usv_register_request_t* usv_register_request)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    usv_register_request->msg_src = mavlink_msg_usv_register_request_get_msg_src(msg);
    usv_register_request->link_type = mavlink_msg_usv_register_request_get_link_type(msg);
    usv_register_request->channel_type = mavlink_msg_usv_register_request_get_channel_type(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN? msg->len : MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN;
        memset(usv_register_request, 0, MAVLINK_MSG_ID_USV_REGISTER_REQUEST_LEN);
    memcpy(usv_register_request, _MAV_PAYLOAD(msg), len);
#endif
}
