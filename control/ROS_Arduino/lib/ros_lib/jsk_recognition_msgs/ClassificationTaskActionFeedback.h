#ifndef _ROS_jsk_recognition_msgs_ClassificationTaskActionFeedback_h
#define _ROS_jsk_recognition_msgs_ClassificationTaskActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "jsk_recognition_msgs/ClassificationTaskFeedback.h"

namespace jsk_recognition_msgs
{

  class ClassificationTaskActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef jsk_recognition_msgs::ClassificationTaskFeedback _feedback_type;
      _feedback_type feedback;

    ClassificationTaskActionFeedback():
      header(),
      status(),
      feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/ClassificationTaskActionFeedback"; };
    virtual const char * getMD5() override { return "82e97615735594b25e2cee3da22d3eb7"; };

  };

}
#endif
