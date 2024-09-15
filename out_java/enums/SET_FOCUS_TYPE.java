/* AUTO-GENERATED FILE.  DO NOT MODIFY.
 *
 * This class was automatically generated by the
 * java mavlink generator tool. It should not be modified by hand.
 */

package com.MAVLink.enums;

/**
 * Focus types for MAV_CMD_SET_CAMERA_FOCUS
 */
public class SET_FOCUS_TYPE {
   public static final int FOCUS_TYPE_STEP = 0; /* Focus one step increment (-1 for focusing in, 1 for focusing out towards infinity). | */
   public static final int FOCUS_TYPE_CONTINUOUS = 1; /* Continuous focus up/down until stopped (-1 for focusing in, 1 for focusing out towards infinity, 0 to stop focusing) | */
   public static final int FOCUS_TYPE_RANGE = 2; /* Focus value as proportion of full camera focus range (a value between 0.0 and 100.0) | */
   public static final int FOCUS_TYPE_METERS = 3; /* Focus value in metres. Note that there is no message to get the valid focus range of the camera, so this can type can only be used for cameras where the range is known (implying that this cannot reliably be used in a GCS for an arbitrary camera). | */
   public static final int FOCUS_TYPE_AUTO = 4; /* Focus automatically. | */
   public static final int FOCUS_TYPE_AUTO_SINGLE = 5; /* Single auto focus. Mainly used for still pictures. Usually abbreviated as AF-S. | */
   public static final int FOCUS_TYPE_AUTO_CONTINUOUS = 6; /* Continuous auto focus. Mainly used for dynamic scenes. Abbreviated as AF-C. | */
   public static final int SET_FOCUS_TYPE_ENUM_END = 7; /*  | */
}