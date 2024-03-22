#ifndef _ROS_rm_msgs_MovingAverageData_h
#define _ROS_rm_msgs_MovingAverageData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rm_msgs
{

  class MovingAverageData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _real_pos_x_type;
      _real_pos_x_type real_pos_x;
      typedef float _real_pos_y_type;
      _real_pos_y_type real_pos_y;
      typedef float _real_pos_z_type;
      _real_pos_z_type real_pos_z;
      typedef float _real_vel_x_type;
      _real_vel_x_type real_vel_x;
      typedef float _real_vel_y_type;
      _real_vel_y_type real_vel_y;
      typedef float _real_vel_z_type;
      _real_vel_z_type real_vel_z;
      typedef float _filtered_pos_x_type;
      _filtered_pos_x_type filtered_pos_x;
      typedef float _filtered_pos_y_type;
      _filtered_pos_y_type filtered_pos_y;
      typedef float _filtered_pos_z_type;
      _filtered_pos_z_type filtered_pos_z;
      typedef float _filtered_vel_x_type;
      _filtered_vel_x_type filtered_vel_x;
      typedef float _filtered_vel_y_type;
      _filtered_vel_y_type filtered_vel_y;
      typedef float _filtered_vel_z_type;
      _filtered_vel_z_type filtered_vel_z;
      typedef float _filtered_center_x_type;
      _filtered_center_x_type filtered_center_x;
      typedef float _filtered_center_y_type;
      _filtered_center_y_type filtered_center_y;
      typedef float _filtered_center_z_type;
      _filtered_center_z_type filtered_center_z;
      typedef float _real_gyro_vel_type;
      _real_gyro_vel_type real_gyro_vel;
      typedef float _filtered_gyro_vel_type;
      _filtered_gyro_vel_type filtered_gyro_vel;

    MovingAverageData():
      header(),
      real_pos_x(0),
      real_pos_y(0),
      real_pos_z(0),
      real_vel_x(0),
      real_vel_y(0),
      real_vel_z(0),
      filtered_pos_x(0),
      filtered_pos_y(0),
      filtered_pos_z(0),
      filtered_vel_x(0),
      filtered_vel_y(0),
      filtered_vel_z(0),
      filtered_center_x(0),
      filtered_center_y(0),
      filtered_center_z(0),
      real_gyro_vel(0),
      filtered_gyro_vel(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->real_pos_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->real_pos_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->real_pos_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->real_vel_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->real_vel_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->real_vel_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_pos_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_pos_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_pos_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_vel_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_vel_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_vel_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_center_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_center_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_center_z);
      offset += serializeAvrFloat64(outbuffer + offset, this->real_gyro_vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered_gyro_vel);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real_pos_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real_pos_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real_pos_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real_vel_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real_vel_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real_vel_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_pos_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_pos_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_pos_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_vel_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_vel_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_vel_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_center_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_center_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_center_z));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real_gyro_vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered_gyro_vel));
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/MovingAverageData"; };
    virtual const char * getMD5() override { return "12bd9292dde1a0c07797d8236d7c8fa2"; };

  };

}
#endif
