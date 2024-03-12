#ifndef _ROS_cob_frame_tracker_FrameTrackingGoal_h
#define _ROS_cob_frame_tracker_FrameTrackingGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cob_frame_tracker
{

  class FrameTrackingGoal : public ros::Msg
  {
    public:
      typedef const char* _tracking_frame_type;
      _tracking_frame_type tracking_frame;
      typedef float _tracking_duration_type;
      _tracking_duration_type tracking_duration;
      typedef bool _stop_on_goal_type;
      _stop_on_goal_type stop_on_goal;

    FrameTrackingGoal():
      tracking_frame(""),
      tracking_duration(0),
      stop_on_goal(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      uint32_t length_tracking_frame = strlen(this->tracking_frame);
      varToArr(outbuffer + offset, length_tracking_frame);
      offset += 4;
      memcpy(outbuffer + offset, this->tracking_frame, length_tracking_frame);
      offset += length_tracking_frame;
      offset += serializeAvrFloat64(outbuffer + offset, this->tracking_duration);
      union {
        bool real;
        uint8_t base;
      } u_stop_on_goal;
      u_stop_on_goal.real = this->stop_on_goal;
      *(outbuffer + offset + 0) = (u_stop_on_goal.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->stop_on_goal);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t length_tracking_frame;
      arrToVar(length_tracking_frame, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_tracking_frame; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_tracking_frame-1]=0;
      this->tracking_frame = (char *)(inbuffer + offset-1);
      offset += length_tracking_frame;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->tracking_duration));
      union {
        bool real;
        uint8_t base;
      } u_stop_on_goal;
      u_stop_on_goal.base = 0;
      u_stop_on_goal.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->stop_on_goal = u_stop_on_goal.real;
      offset += sizeof(this->stop_on_goal);
     return offset;
    }

    virtual const char * getType() override { return "cob_frame_tracker/FrameTrackingGoal"; };
    virtual const char * getMD5() override { return "1f45d520be90e58935a41f5719d09f2e"; };

  };

}
#endif
