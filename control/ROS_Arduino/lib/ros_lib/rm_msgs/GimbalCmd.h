#ifndef _ROS_rm_msgs_GimbalCmd_h
#define _ROS_rm_msgs_GimbalCmd_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "ros/time.h"
#include "geometry_msgs/PointStamped.h"

namespace rm_msgs
{

  class GimbalCmd : public ros::Msg
  {
    public:
      typedef ros::Time _stamp_type;
      _stamp_type stamp;
      typedef uint8_t _mode_type;
      _mode_type mode;
      typedef float _rate_yaw_type;
      _rate_yaw_type rate_yaw;
      typedef float _rate_pitch_type;
      _rate_pitch_type rate_pitch;
      typedef float _bullet_speed_type;
      _bullet_speed_type bullet_speed;
      typedef geometry_msgs::PointStamped _target_pos_type;
      _target_pos_type target_pos;
      enum { RATE =  0 };
      enum { TRACK =  1 };
      enum { DIRECT =  2 };

    GimbalCmd():
      stamp(),
      mode(0),
      rate_yaw(0),
      rate_pitch(0),
      bullet_speed(0),
      target_pos()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
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
      *(outbuffer + offset + 0) = (this->mode >> (8 * 0)) & 0xFF;
      offset += sizeof(this->mode);
      offset += serializeAvrFloat64(outbuffer + offset, this->rate_yaw);
      offset += serializeAvrFloat64(outbuffer + offset, this->rate_pitch);
      offset += serializeAvrFloat64(outbuffer + offset, this->bullet_speed);
      offset += this->target_pos.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
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
      this->mode =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->mode);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rate_yaw));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->rate_pitch));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->bullet_speed));
      offset += this->target_pos.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/GimbalCmd"; };
    virtual const char * getMD5() override { return "8bed4be5d11eafc7b7a7b054096b4208"; };

  };

}
#endif
