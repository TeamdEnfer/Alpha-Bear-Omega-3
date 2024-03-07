#ifndef _ROS_cras_relative_positional_controller_RelativeMoveActionFeedback_h
#define _ROS_cras_relative_positional_controller_RelativeMoveActionFeedback_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "cras_relative_positional_controller/RelativeMoveFeedback.h"

namespace cras_relative_positional_controller
{

  class RelativeMoveActionFeedback : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef cras_relative_positional_controller::RelativeMoveFeedback _feedback_type;
      _feedback_type feedback;

    RelativeMoveActionFeedback():
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

    virtual const char * getType() override { return "cras_relative_positional_controller/RelativeMoveActionFeedback"; };
    virtual const char * getMD5() override { return "ca4163a8dc9265fb28dabe6c5f261da4"; };

  };

}
#endif
