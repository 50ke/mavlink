/* AUTO-GENERATED FILE.  DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * java mavlink generator tool. It should not be modified by hand.
 */

// MESSAGE PARAM_VALUE PACKING
package com.MAVLink.common;
import com.MAVLink.MAVLinkPacket;
import com.MAVLink.Messages.MAVLinkMessage;
import com.MAVLink.Messages.MAVLinkPayload;
import com.MAVLink.Messages.Units;
import com.MAVLink.Messages.Description;

/**
 * Emit the value of a onboard parameter. The inclusion of param_count and param_index in the message allows the recipient to keep track of received parameters and allows him to re-request missing parameters after a loss or timeout. The parameter microservice is documented at https://mavlink.io/en/services/parameter.html
 */
public class msg_param_value extends MAVLinkMessage {

    public static final int MAVLINK_MSG_ID_PARAM_VALUE = 22;
    public static final int MAVLINK_MSG_LENGTH = 25;
    private static final long serialVersionUID = MAVLINK_MSG_ID_PARAM_VALUE;

    
    /**
     * Onboard parameter value
     */
    @Description("Onboard parameter value")
    @Units("")
    public float param_value;
    
    /**
     * Total number of onboard parameters
     */
    @Description("Total number of onboard parameters")
    @Units("")
    public int param_count;
    
    /**
     * Index of this onboard parameter
     */
    @Description("Index of this onboard parameter")
    @Units("")
    public int param_index;
    
    /**
     * Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string
     */
    @Description("Onboard parameter id, terminated by NULL if the length is less than 16 human-readable chars and WITHOUT null termination (NULL) byte if the length is exactly 16 chars - applications have to provide 16+1 bytes storage if the ID is stored as string")
    @Units("")
    public byte param_id[] = new byte[16];
    
    /**
     * Onboard parameter type.
     */
    @Description("Onboard parameter type.")
    @Units("")
    public short param_type;
    

    /**
     * Generates the payload for a mavlink message for a message of this type
     * @return
     */
    @Override
    public MAVLinkPacket pack() {
        MAVLinkPacket packet = new MAVLinkPacket(MAVLINK_MSG_LENGTH,isMavlink2);
        packet.sysid = sysid;
        packet.compid = compid;
        packet.msgid = MAVLINK_MSG_ID_PARAM_VALUE;

        packet.payload.putFloat(param_value);
        packet.payload.putUnsignedShort(param_count);
        packet.payload.putUnsignedShort(param_index);
        
        for (int i = 0; i < param_id.length; i++) {
            packet.payload.putByte(param_id[i]);
        }
                    
        packet.payload.putUnsignedByte(param_type);
        
        if (isMavlink2) {
            
        }
        return packet;
    }

    /**
     * Decode a param_value message into this class fields
     *
     * @param payload The message to decode
     */
    @Override
    public void unpack(MAVLinkPayload payload) {
        payload.resetIndex();

        this.param_value = payload.getFloat();
        this.param_count = payload.getUnsignedShort();
        this.param_index = payload.getUnsignedShort();
        
        for (int i = 0; i < this.param_id.length; i++) {
            this.param_id[i] = payload.getByte();
        }
                
        this.param_type = payload.getUnsignedByte();
        
        if (isMavlink2) {
            
        }
    }

    /**
     * Constructor for a new message, just initializes the msgid
     */
    public msg_param_value() {
        this.msgid = MAVLINK_MSG_ID_PARAM_VALUE;
    }

    /**
     * Constructor for a new message, initializes msgid and all payload variables
     */
    public msg_param_value( float param_value, int param_count, int param_index, byte[] param_id, short param_type) {
        this.msgid = MAVLINK_MSG_ID_PARAM_VALUE;

        this.param_value = param_value;
        this.param_count = param_count;
        this.param_index = param_index;
        this.param_id = param_id;
        this.param_type = param_type;
        
    }

    /**
     * Constructor for a new message, initializes everything
     */
    public msg_param_value( float param_value, int param_count, int param_index, byte[] param_id, short param_type, int sysid, int compid, boolean isMavlink2) {
        this.msgid = MAVLINK_MSG_ID_PARAM_VALUE;
        this.sysid = sysid;
        this.compid = compid;
        this.isMavlink2 = isMavlink2;

        this.param_value = param_value;
        this.param_count = param_count;
        this.param_index = param_index;
        this.param_id = param_id;
        this.param_type = param_type;
        
    }

    /**
     * Constructor for a new message, initializes the message with the payload
     * from a mavlink packet
     *
     */
    public msg_param_value(MAVLinkPacket mavLinkPacket) {
        this.msgid = MAVLINK_MSG_ID_PARAM_VALUE;

        this.sysid = mavLinkPacket.sysid;
        this.compid = mavLinkPacket.compid;
        this.isMavlink2 = mavLinkPacket.isMavlink2;
        unpack(mavLinkPacket.payload);
    }

           
    /**
    * Sets the buffer of this message with a string, adds the necessary padding
    */
    public void setParam_Id(String str) {
        int len = Math.min(str.length(), 16);
        for (int i=0; i<len; i++) {
            param_id[i] = (byte) str.charAt(i);
        }

        for (int i=len; i<16; i++) {            // padding for the rest of the buffer
            param_id[i] = 0;
        }
    }

    /**
    * Gets the message, formatted as a string
    */
    public String getParam_Id() {
        StringBuffer buf = new StringBuffer();
        for (int i = 0; i < 16; i++) {
            if (param_id[i] != 0)
                buf.append((char) param_id[i]);
            else
                break;
        }
        return buf.toString();

    }
                           
    /**
     * Returns a string with the MSG name and data
     */
    @Override
    public String toString() {
        return "MAVLINK_MSG_ID_PARAM_VALUE - sysid:"+sysid+" compid:"+compid+" param_value:"+param_value+" param_count:"+param_count+" param_index:"+param_index+" param_id:"+param_id+" param_type:"+param_type+"";
    }

    /**
     * Returns a human-readable string of the name of the message
     */
    @Override
    public String name() {
        return "MAVLINK_MSG_ID_PARAM_VALUE";
    }
}
        