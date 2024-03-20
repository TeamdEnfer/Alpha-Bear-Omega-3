#ifndef _ROS_jsk_recognition_msgs_VQATaskActionResult_h
#define _ROS_jsk_recognition_msgs_VQATaskActionResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "actionlib_msgs/GoalStatus.h"
#include "jsk_recognition_msgs/VQATaskResult.h"

namespace jsk_recognition_msgs
{

  class VQATaskActionResult : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef actionlib_msgs::GoalStatus _status_type;
      _status_type status;
      typedef jsk_recognition_msgs::VQATaskResult _result_type;
      _result_type result;

    VQATaskActionResult():
      header(),
      status(),
      result()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      offset += this->status.serialize(outbuffer + offset);
      offset += this->result.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      offset += this->status.deserialize(inbuffer + offset);
      offset += this->result.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/VQATaskActionResult"; };
    virtual const char * getMD5() override { return "30a086e0d9e551a4d8fe5f8e213eb027"; };

  };

}
#endif
