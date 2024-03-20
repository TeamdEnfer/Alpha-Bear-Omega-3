#ifndef _ROS_jsk_recognition_msgs_VQATaskActionGoal_h
#define _ROS_jsk_recognition_msgs_VQATaskActionGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalID.h"
#include "jsk_recognition_msgs/VQATaskGoal.h"

namespace jsk_recognition_msgs
{

  class VQATaskActionGoal : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalID _goal_id_type;
      _goal_id_type goal_id;
      typedef jsk_recognition_msgs::VQATaskGoal _goal_type;
      _goal_type goal;

    VQATaskActionGoal():
      header(),
      goal_id(),
      goal()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->goal_id.serialize(outbuffer + offset);
      offset += this->goal.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->goal_id.deserialize(inbuffer + offset);
      offset += this->goal.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/VQATaskActionGoal"; };
    virtual const char * getMD5() override { return "e4171f1dde3ad747d7bb43a41ca46d68"; };

  };

}
#endif
