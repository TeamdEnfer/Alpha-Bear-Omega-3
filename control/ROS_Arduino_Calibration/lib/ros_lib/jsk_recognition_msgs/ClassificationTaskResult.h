#ifndef _ROS_jsk_recognition_msgs_ClassificationTaskResult_h
#define _ROS_jsk_recognition_msgs_ClassificationTaskResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/ClassificationResult.h"

namespace jsk_recognition_msgs
{

  class ClassificationTaskResult : public ros::Msg
  {
    public:
      typedef jsk_recognition_msgs::ClassificationResult _result_type;
      _result_type result;
      typedef bool _done_type;
      _done_type done;

    ClassificationTaskResult():
      result(),
      done(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->result.serialize(outbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_done;
      u_done.real = this->done;
      *(outbuffer + offset + 0) = (u_done.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->done);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->result.deserialize(inbuffer + offset);
      union {
        bool real;
        uint8_t base;
      } u_done;
      u_done.base = 0;
      u_done.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->done = u_done.real;
      offset += sizeof(this->done);
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/ClassificationTaskResult"; };
    virtual const char * getMD5() override { return "0dd1b3e5c6b30e06d55afe495d9d3889"; };

  };

}
#endif
