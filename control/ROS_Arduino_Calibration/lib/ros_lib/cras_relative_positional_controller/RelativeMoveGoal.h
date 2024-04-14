#ifndef _ROS_cras_relative_positional_controller_RelativeMoveGoal_h
#define _ROS_cras_relative_positional_controller_RelativeMoveGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cras_relative_positional_controller
{

  class RelativeMoveGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _target_x_change_type;
      _target_x_change_type target_x_change;
      typedef float _target_y_change_type;
      _target_y_change_type target_y_change;
      typedef float _target_yaw_change_type;
      _target_yaw_change_type target_yaw_change;
      typedef float _linear_speed_type;
      _linear_speed_type linear_speed;
      typedef float _angular_speed_type;
      _angular_speed_type angular_speed;

    RelativeMoveGoal():
      header(),
      target_x_change(0),
      target_y_change(0),
      target_yaw_change(0),
      linear_speed(0),
      angular_speed(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->target_x_change);
      offset += serializeAvrFloat64(outbuffer + offset, this->target_y_change);
      offset += serializeAvrFloat64(outbuffer + offset, this->target_yaw_change);
      offset += serializeAvrFloat64(outbuffer + offset, this->linear_speed);
      offset += serializeAvrFloat64(outbuffer + offset, this->angular_speed);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->target_x_change));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->target_y_change));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->target_yaw_change));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->linear_speed));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->angular_speed));
     return offset;
    }

    virtual const char * getType() override { return "cras_relative_positional_controller/RelativeMoveGoal"; };
    virtual const char * getMD5() override { return "076cb9f30c482131ca1e2d656eafc266"; };

  };

}
#endif
