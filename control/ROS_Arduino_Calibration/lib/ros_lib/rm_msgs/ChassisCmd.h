#ifndef _ROS_rm_msgs_ChassisCmd_h
#define _ROS_rm_msgs_ChassisCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Accel.h"
#include "ros/time.h"

namespace rm_msgs
{

  class ChassisCmd : public ros::Msg
  {
    public:
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef geometry_msgs::Accel _accel_type;
      _accel_type accel;
      typedef float _power_limit_type;
      _power_limit_type power_limit;
      typedef const char* _follow_source_frame_type;
      _follow_source_frame_type follow_source_frame;
      typedef const char* _command_source_frame_type;
      _command_source_frame_type command_source_frame;
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      enum { RAW =  0 };
      enum { FOLLOW =  1 };
      enum { TWIST =  2 };

    ChassisCmd():
      mode(0),
      accel(),
      power_limit(0),
      follow_source_frame(""),
      command_source_frame(""),
      stamp()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      offset += this->accel.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->power_limit);
      uint32_t length_follow_source_frame = strlen(this->follow_source_frame);
      varToArr(outbuffer + offset, length_follow_source_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->follow_source_frame, length_follow_source_frame);
      offset += length_follow_source_frame;
      uint32_t length_command_source_frame = strlen(this->command_source_frame);
      varToArr(outbuffer + offset, length_command_source_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->command_source_frame, length_command_source_frame);
      offset += length_command_source_frame;
      *(outbuffer + offset + 0) = (this->stamp.sec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.sec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.sec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.sec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.sec);
      *(outbuffer + offset + 0) = (this->stamp.nsec >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->stamp.nsec >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->stamp.nsec >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->stamp.nsec >> (8 * 3)) & 0xFF;
      offset += sizeof(this->stamp.nsec);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      offset += this->accel.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->power_limit));
      uint32_t length_follow_source_frame;
      arrToVar(length_follow_source_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_follow_source_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_follow_source_frame-1]=0;
      this->follow_source_frame = (char *)(inbuffer + offset-1);
      offset += length_follow_source_frame;
      uint32_t length_command_source_frame;
      arrToVar(length_command_source_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_command_source_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_command_source_frame-1]=0;
      this->command_source_frame = (char *)(inbuffer + offset-1);
      offset += length_command_source_frame;
      this->stamp.sec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.sec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.sec);
      this->stamp.nsec =  ((uint32_t) (*(inbuffer + offset)));
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->stamp.nsec |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->stamp.nsec);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/ChassisCmd"; };
    virtual const char * getMD5() override { return "be6a75b7fbbd7f70157e9e49699c128f"; };

  };

}
#endif
