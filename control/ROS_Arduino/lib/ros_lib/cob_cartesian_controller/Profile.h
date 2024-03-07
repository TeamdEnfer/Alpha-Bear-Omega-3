#ifndef _ROS_cob_cartesian_controller_Profile_h
#define _ROS_cob_cartesian_controller_Profile_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_cartesian_controller
{

  class Profile : public ros::Msg
  {
    public:
      typedef uint8_t _profile_type_type;
      _profile_type_type profile_type;
      typedef float _vel_type;
      _vel_type vel;
      typedef float _accl_type;
      _accl_type accl;
      enum { RAMP = 1 };
      enum { SINOID = 2 };

    Profile():
      profile_type(0),
      vel(0),
      accl(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->profile_type >> (8 * 0)) & 0xFF;
      offset += sizeof(this->profile_type);
      offset += serializeAvrFloat64(outbuffer + offset, this->vel);
      offset += serializeAvrFloat64(outbuffer + offset, this->accl);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->profile_type =  ((uint8_t) (*(inbuffer + offset)));
      offset += sizeof(this->profile_type);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->vel));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->accl));
     return offset;
    }

    virtual const char * getType() override { return "cob_cartesian_controller/Profile"; };
    virtual const char * getMD5() override { return "3631ecf157bdfedf0f8cb3d5f838c11b"; };

  };

}
#endif
