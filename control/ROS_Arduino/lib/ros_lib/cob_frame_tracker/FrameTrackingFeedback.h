#ifndef _ROS_cob_frame_tracker_FrameTrackingFeedback_h
#define _ROS_cob_frame_tracker_FrameTrackingFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Twist.h"

namespace cob_frame_tracker
{

  class FrameTrackingFeedback : public ros::Msg
  {
    public:
      typedef geometry_msgs::Twist _twist_type;
      _twist_type twist;
      typedef float _distance_type;
      _distance_type distance;

    FrameTrackingFeedback():
      twist(),
      distance(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->twist.serialize(outbuffer + offset);
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->twist.deserialize(inbuffer + offset);
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
     return offset;
    }

    virtual const char * getType() override { return "cob_frame_tracker/FrameTrackingFeedback"; };
    virtual const char * getMD5() override { return "fe81003ede0829d7392b5d1210ebd6ad"; };

  };

}
#endif
