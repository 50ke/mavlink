/** @file
 *	@brief MAVLink comm testsuite protocol generated from USV.xml
 *	@see http://mavlink.org
 */

#pragma once

#include <gtest/gtest.h>
#include "USV.hpp"

#ifdef TEST_INTEROP
using namespace mavlink;
#undef MAVLINK_HELPER
#include "mavlink.h"
#endif


TEST(USV, USV_REGISTER_REQUEST)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_REGISTER_REQUEST packet_in{};
    packet_in.msg_src = 5;
    packet_in.link_type = 72;
    packet_in.channel_type = 139;

    mavlink::USV::msg::USV_REGISTER_REQUEST packet1{};
    mavlink::USV::msg::USV_REGISTER_REQUEST packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.msg_src, packet2.msg_src);
    EXPECT_EQ(packet1.link_type, packet2.link_type);
    EXPECT_EQ(packet1.channel_type, packet2.channel_type);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_REGISTER_REQUEST)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_register_request_t packet_c {
         5, 72, 139
    };

    mavlink::USV::msg::USV_REGISTER_REQUEST packet_in{};
    packet_in.msg_src = 5;
    packet_in.link_type = 72;
    packet_in.channel_type = 139;

    mavlink::USV::msg::USV_REGISTER_REQUEST packet2{};

    mavlink_msg_usv_register_request_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.msg_src, packet2.msg_src);
    EXPECT_EQ(packet_in.link_type, packet2.link_type);
    EXPECT_EQ(packet_in.channel_type, packet2.channel_type);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(USV, USV_REGISTER_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_REGISTER_RESPONSE packet_in{};
    packet_in.target_system = 5;

    mavlink::USV::msg::USV_REGISTER_RESPONSE packet1{};
    mavlink::USV::msg::USV_REGISTER_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_REGISTER_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_register_response_t packet_c {
         5
    };

    mavlink::USV::msg::USV_REGISTER_RESPONSE packet_in{};
    packet_in.target_system = 5;

    mavlink::USV::msg::USV_REGISTER_RESPONSE packet2{};

    mavlink_msg_usv_register_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(USV, USV_DEREGISTER_REQUEST)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_DEREGISTER_REQUEST packet_in{};
    packet_in.time_ms = 963497464;

    mavlink::USV::msg::USV_DEREGISTER_REQUEST packet1{};
    mavlink::USV::msg::USV_DEREGISTER_REQUEST packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.time_ms, packet2.time_ms);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_DEREGISTER_REQUEST)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_deregister_request_t packet_c {
         963497464
    };

    mavlink::USV::msg::USV_DEREGISTER_REQUEST packet_in{};
    packet_in.time_ms = 963497464;

    mavlink::USV::msg::USV_DEREGISTER_REQUEST packet2{};

    mavlink_msg_usv_deregister_request_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.time_ms, packet2.time_ms);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(USV, USV_DEREGISTER_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_DEREGISTER_RESPONSE packet_in{};
    packet_in.ack = 5;

    mavlink::USV::msg::USV_DEREGISTER_RESPONSE packet1{};
    mavlink::USV::msg::USV_DEREGISTER_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.ack, packet2.ack);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_DEREGISTER_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_deregister_response_t packet_c {
         5
    };

    mavlink::USV::msg::USV_DEREGISTER_RESPONSE packet_in{};
    packet_in.ack = 5;

    mavlink::USV::msg::USV_DEREGISTER_RESPONSE packet2{};

    mavlink_msg_usv_deregister_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.ack, packet2.ack);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(USV, USV_CONNECT_REQUEST)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_CONNECT_REQUEST packet_in{};
    packet_in.target_system = 5;

    mavlink::USV::msg::USV_CONNECT_REQUEST packet1{};
    mavlink::USV::msg::USV_CONNECT_REQUEST packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_CONNECT_REQUEST)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_connect_request_t packet_c {
         5
    };

    mavlink::USV::msg::USV_CONNECT_REQUEST packet_in{};
    packet_in.target_system = 5;

    mavlink::USV::msg::USV_CONNECT_REQUEST packet2{};

    mavlink_msg_usv_connect_request_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(USV, USV_CONNECT_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_CONNECT_RESPONSE packet_in{};
    packet_in.target_system = 5;
    packet_in.ack = 72;

    mavlink::USV::msg::USV_CONNECT_RESPONSE packet1{};
    mavlink::USV::msg::USV_CONNECT_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.ack, packet2.ack);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_CONNECT_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_connect_response_t packet_c {
         5, 72
    };

    mavlink::USV::msg::USV_CONNECT_RESPONSE packet_in{};
    packet_in.target_system = 5;
    packet_in.ack = 72;

    mavlink::USV::msg::USV_CONNECT_RESPONSE packet2{};

    mavlink_msg_usv_connect_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.ack, packet2.ack);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(USV, USV_DISCONNECT_REQUEST)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_DISCONNECT_REQUEST packet_in{};
    packet_in.target_system = 5;

    mavlink::USV::msg::USV_DISCONNECT_REQUEST packet1{};
    mavlink::USV::msg::USV_DISCONNECT_REQUEST packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_DISCONNECT_REQUEST)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_disconnect_request_t packet_c {
         5
    };

    mavlink::USV::msg::USV_DISCONNECT_REQUEST packet_in{};
    packet_in.target_system = 5;

    mavlink::USV::msg::USV_DISCONNECT_REQUEST packet2{};

    mavlink_msg_usv_disconnect_request_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(USV, USV_DISCONNECT_RESPONSE)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_DISCONNECT_RESPONSE packet_in{};
    packet_in.target_system = 5;
    packet_in.ack = 72;

    mavlink::USV::msg::USV_DISCONNECT_RESPONSE packet1{};
    mavlink::USV::msg::USV_DISCONNECT_RESPONSE packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.target_system, packet2.target_system);
    EXPECT_EQ(packet1.ack, packet2.ack);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_DISCONNECT_RESPONSE)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_disconnect_response_t packet_c {
         5, 72
    };

    mavlink::USV::msg::USV_DISCONNECT_RESPONSE packet_in{};
    packet_in.target_system = 5;
    packet_in.ack = 72;

    mavlink::USV::msg::USV_DISCONNECT_RESPONSE packet2{};

    mavlink_msg_usv_disconnect_response_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.target_system, packet2.target_system);
    EXPECT_EQ(packet_in.ack, packet2.ack);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif

TEST(USV, USV_SYSTEM_INFORMATION)
{
    mavlink::mavlink_message_t msg;
    mavlink::MsgMap map1(msg);
    mavlink::MsgMap map2(msg);

    mavlink::USV::msg::USV_SYSTEM_INFORMATION packet_in{};
    packet_in.name = to_char_array("IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDE");
    packet_in.connected = 157;
    packet_in.lat = 17.0;
    packet_in.lon = 45.0;

    mavlink::USV::msg::USV_SYSTEM_INFORMATION packet1{};
    mavlink::USV::msg::USV_SYSTEM_INFORMATION packet2{};

    packet1 = packet_in;

    //std::cout << packet1.to_yaml() << std::endl;

    packet1.serialize(map1);

    mavlink::mavlink_finalize_message(&msg, 1, 1, packet1.MIN_LENGTH, packet1.LENGTH, packet1.CRC_EXTRA);

    packet2.deserialize(map2);

    EXPECT_EQ(packet1.name, packet2.name);
    EXPECT_EQ(packet1.connected, packet2.connected);
    EXPECT_EQ(packet1.lat, packet2.lat);
    EXPECT_EQ(packet1.lon, packet2.lon);
}

#ifdef TEST_INTEROP
TEST(USV_interop, USV_SYSTEM_INFORMATION)
{
    mavlink_message_t msg;

    // to get nice print
    memset(&msg, 0, sizeof(msg));

    mavlink_usv_system_information_t packet_c {
         17.0, 45.0, "IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDE", 157
    };

    mavlink::USV::msg::USV_SYSTEM_INFORMATION packet_in{};
    packet_in.name = to_char_array("IJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDE");
    packet_in.connected = 157;
    packet_in.lat = 17.0;
    packet_in.lon = 45.0;

    mavlink::USV::msg::USV_SYSTEM_INFORMATION packet2{};

    mavlink_msg_usv_system_information_encode(1, 1, &msg, &packet_c);

    // simulate message-handling callback
    [&packet2](const mavlink_message_t *cmsg) {
        MsgMap map2(cmsg);

        packet2.deserialize(map2);
    } (&msg);

    EXPECT_EQ(packet_in.name, packet2.name);
    EXPECT_EQ(packet_in.connected, packet2.connected);
    EXPECT_EQ(packet_in.lat, packet2.lat);
    EXPECT_EQ(packet_in.lon, packet2.lon);

#ifdef PRINT_MSG
    PRINT_MSG(msg);
#endif
}
#endif
