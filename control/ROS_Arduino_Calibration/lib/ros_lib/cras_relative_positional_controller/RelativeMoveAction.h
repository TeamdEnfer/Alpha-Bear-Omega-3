#ifndef _ROS_cras_relative_positional_controller_RelativeMoveAction_h
#define _ROS_cras_relative_positional_controller_RelativeMoveAction_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "cras_relative_positional_controller/RelativeMoveActionGoal.h"
#include "cras_relative_positional_controller/RelativeMoveActionResult.h"
#include "cras_relative_positional_controller/RelativeMoveActionFeedback.h"

namespace cras_relative_positional_controller
{

  class RelativeMoveAction : public ros::Msg
  {
    public:
      typedef cras_relative_positional_controller::RelativeMoveActionGoal _action_goal_type;
      _action_goal_type action_goal;
      typedef cras_relative_positional_controller::RelativeMoveActionResult _action_result_type;
      _action_result_type action_result;
      typedef cras_relative_positional_controller::RelativeMoveActionFeedback _action_feedback_type;
      _action_feedback_type action_feedback;

    RelativeMoveAction():
      action_goal(),
      action_result(),
      action_feedback()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->action_goal.serialize(outbuffer + offset);
      offset += this->action_result.serialize(outbuffer + offset);
      offset += this->action_feedback.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->action_goal.deserialize(inbuffer + offset);
      offset += this->action_result.deserialize(inbuffer + offset);
      offset += this->action_feedback.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "cras_relative_positional_controller/RelativeMoveAction"; };
    virtual const char * getMD5() override { return "6ee2ff89b296ae4a90f93ceeb5466279"; };

  };

}
#endif
