#ifndef _ROS_cras_relative_positional_controller_RelativeMoveFeedback_h
#define _ROS_cras_relative_positional_controller_RelativeMoveFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cras_relative_positional_controller
{

  class RelativeMoveFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _remaining_x_type;
      _remaining_x_type remaining_x;
      typedef float _remaining_y_type;
      _remaining_y_type remaining_y;
      typedef float _remaining_yaw_type;
      _remaining_yaw_type remaining_yaw;

    RelativeMoveFeedback():
      header(),
      remaining_x(0),
      remaining_y(0),
      remaining_yaw(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->remaining_x);
      offset += serializeAvrFloat64(outbuffer + offset, this->remaining_y);
      offset += serializeAvrFloat64(outbuffer + offset, this->remaining_yaw);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->remaining_x));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->remaining_y));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->remaining_yaw));
     return offset;
    }

    virtual const char * getType() override { return "cras_relative_positional_controller/RelativeMoveFeedback"; };
    virtual const char * getMD5() override { return "72433b4cfcff0a735c49c79ee46c8808"; };

  };

}
#endif
