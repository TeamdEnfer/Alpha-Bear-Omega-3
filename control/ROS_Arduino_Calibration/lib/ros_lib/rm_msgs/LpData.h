#ifndef _ROS_rm_msgs_LpData_h
#define _ROS_rm_msgs_LpData_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace rm_msgs
{

  class LpData : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef float _real_type;
      _real_type real;
      typedef float _filtered_type;
      _filtered_type filtered;

    LpData():
      header(),
      real(0),
      filtered(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->real);
      offset += serializeAvrFloat64(outbuffer + offset, this->filtered);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->real));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->filtered));
     return offset;
    }

    virtual const char * getType() override { return "rm_msgs/LpData"; };
    virtual const char * getMD5() override { return "15bf1676ae28702eed3b9b7f8b20c577"; };

  };

}
#endif
