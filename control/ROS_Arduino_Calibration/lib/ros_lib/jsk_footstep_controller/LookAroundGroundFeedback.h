#ifndef _ROS_jsk_footstep_controller_LookAroundGroundFeedback_h
#define _ROS_jsk_footstep_controller_LookAroundGroundFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace jsk_footstep_controller
{

  class LookAroundGroundFeedback : public ros::Msg
  {
    public:

    LookAroundGroundFeedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
     return offset;
    }

    virtual const char * getType() override { return "jsk_footstep_controller/LookAroundGroundFeedback"; };
    virtual const char * getMD5() override { return "d41d8cd98f00b204e9800998ecf8427e"; };

  };

}
#endif
