#ifndef _ROS_jsk_recognition_msgs_VQATaskResult_h
#define _ROS_jsk_recognition_msgs_VQATaskResult_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "jsk_recognition_msgs/VQAResult.h"

namespace jsk_recognition_msgs
{

  class VQATaskResult : public ros::Msg
  {
    public:
      typedef jsk_recognition_msgs::VQAResult _result_type;
      _result_type result;
      typedef bool _done_type;
      _done_type done;

    VQATaskResult():
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

    virtual const char * getType() override { return "jsk_recognition_msgs/VQATaskResult"; };
    virtual const char * getMD5() override { return "50d986c9be05323bae3ba2f7c0e6ec24"; };

  };

}
#endif
