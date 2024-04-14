#ifndef _ROS_cob_cartesian_controller_MoveCirc_h
#define _ROS_cob_cartesian_controller_MoveCirc_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace cob_cartesian_controller
{

  class MoveCirc : public ros::Msg
  {
    public:
      typedef geometry_msgs::Pose _pose_center_type;
      _pose_center_type pose_center;
      typedef const char* _frame_id_type;
      _frame_id_type frame_id;
      typedef float _start_angle_type;
      _start_angle_type start_angle;
      typedef float _end_angle_type;
      _end_angle_type end_angle;
      typedef float _radius_type;
      _radius_type radius;

    MoveCirc():
      pose_center(),
      frame_id(""),
      start_angle(0),
      end_angle(0),
      radius(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->pose_center.serialize(outbuffer + offset);
      uint32_t length_frame_id = strlen(this->frame_id);
      varToArr(outbuffer + offset, length_frame_id);
      offset += 4;
      memcpy(outbuffer + offset, this->frame_id, length_frame_id);
      offset += length_frame_id;
      offset += serializeAvrFloat64(outbuffer + offset, this->start_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->end_angle);
      offset += serializeAvrFloat64(outbuffer + offset, this->radius);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->pose_center.deserialize(inbuffer + offset);
      uint32_t length_frame_id;
      arrToVar(length_frame_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_frame_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_frame_id-1]=0;
      this->frame_id = (char *)(inbuffer + offset-1);
      offset += length_frame_id;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->start_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->end_angle));
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->radius));
     return offset;
    }

    virtual const char * getType() override { return "cob_cartesian_controller/MoveCirc"; };
    virtual const char * getMD5() override { return "803efebbec7e0afea7443ebc778555f3"; };

  };

}
#endif
