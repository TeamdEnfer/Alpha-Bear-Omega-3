#ifndef _ROS_SERVICE_field_enable_sf_tracking_h
#define _ROS_SERVICE_field_enable_sf_tracking_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace webots_ros
{

static const char FIELD_ENABLE_SF_TRACKING[] = "webots_ros/field_enable_sf_tracking";

  class field_enable_sf_trackingRequest : public ros::Msg
  {
    public:
      typedef uint64_t _field_type;
      _field_type field;
      typedef uint64_t _sampling_period_type;
      _sampling_period_type sampling_period;

    field_enable_sf_trackingRequest():
      field(0),
      sampling_period(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->field >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->field >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->field >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->field >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->field >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->field >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->field >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->field >> (8 * 7)) & 0xFF;
      offset += sizeof(this->field);
      *(outbuffer + offset + 0) = (this->sampling_period >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->sampling_period >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->sampling_period >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->sampling_period >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (this->sampling_period >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (this->sampling_period >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (this->sampling_period >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (this->sampling_period >> (8 * 7)) & 0xFF;
      offset += sizeof(this->sampling_period);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      this->field =  ((uint64_t) (*(inbuffer + offset)));
      this->field |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->field |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->field |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->field |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->field |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->field |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->field |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->field);
      this->sampling_period =  ((uint64_t) (*(inbuffer + offset)));
      this->sampling_period |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->sampling_period |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->sampling_period |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      this->sampling_period |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      this->sampling_period |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      this->sampling_period |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      this->sampling_period |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      offset += sizeof(this->sampling_period);
     return offset;
    }

    virtual const char * getType() override { return FIELD_ENABLE_SF_TRACKING; };
    virtual const char * getMD5() override { return "644e14b553e1557adc26794cf580d80c"; };

  };

  class field_enable_sf_trackingResponse : public ros::Msg
  {
    public:
      typedef int8_t _success_type;
      _success_type success;

    field_enable_sf_trackingResponse():
      success(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_success;
      u_success.real = this->success;
      *(outbuffer + offset + 0) = (u_success.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->success);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      union {
        int8_t real;
        uint8_t base;
      } u_success;
      u_success.base = 0;
      u_success.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->success = u_success.real;
      offset += sizeof(this->success);
     return offset;
    }

    virtual const char * getType() override { return FIELD_ENABLE_SF_TRACKING; };
    virtual const char * getMD5() override { return "0b13460cb14006d3852674b4c614f25f"; };

  };

  class field_enable_sf_tracking {
    public:
    typedef field_enable_sf_trackingRequest Request;
    typedef field_enable_sf_trackingResponse Response;
  };

}
#endif
