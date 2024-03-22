#ifndef _ROS_cob_base_controller_utils_WheelCommands_h
#define _ROS_cob_base_controller_utils_WheelCommands_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"

namespace cob_base_controller_utils
{

  class WheelCommands : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      uint32_t drive_target_velocity_length;
      typedef float _drive_target_velocity_type;
      _drive_target_velocity_type st_drive_target_velocity;
      _drive_target_velocity_type * drive_target_velocity;
      uint32_t steer_target_velocity_length;
      typedef float _steer_target_velocity_type;
      _steer_target_velocity_type st_steer_target_velocity;
      _steer_target_velocity_type * steer_target_velocity;
      uint32_t steer_target_position_length;
      typedef float _steer_target_position_type;
      _steer_target_position_type st_steer_target_position;
      _steer_target_position_type * steer_target_position;
      uint32_t steer_target_error_length;
      typedef float _steer_target_error_type;
      _steer_target_error_type st_steer_target_error;
      _steer_target_error_type * steer_target_error;

    WheelCommands():
      header(),
      drive_target_velocity_length(0), st_drive_target_velocity(), drive_target_velocity(nullptr),
      steer_target_velocity_length(0), st_steer_target_velocity(), steer_target_velocity(nullptr),
      steer_target_position_length(0), st_steer_target_position(), steer_target_position(nullptr),
      steer_target_error_length(0), st_steer_target_error(), steer_target_error(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->drive_target_velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->drive_target_velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->drive_target_velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->drive_target_velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->drive_target_velocity_length);
      for( uint32_t i = 0; i < drive_target_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->drive_target_velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->steer_target_velocity_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steer_target_velocity_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->steer_target_velocity_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->steer_target_velocity_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_target_velocity_length);
      for( uint32_t i = 0; i < steer_target_velocity_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->steer_target_velocity[i]);
      }
      *(outbuffer + offset + 0) = (this->steer_target_position_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steer_target_position_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->steer_target_position_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->steer_target_position_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_target_position_length);
      for( uint32_t i = 0; i < steer_target_position_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->steer_target_position[i]);
      }
      *(outbuffer + offset + 0) = (this->steer_target_error_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->steer_target_error_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->steer_target_error_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->steer_target_error_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->steer_target_error_length);
      for( uint32_t i = 0; i < steer_target_error_length; i++){
      offset += serializeAvrFloat64(outbuffer + offset, this->steer_target_error[i]);
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t drive_target_velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      drive_target_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      drive_target_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      drive_target_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->drive_target_velocity_length);
      if(drive_target_velocity_lengthT > drive_target_velocity_length)
        this->drive_target_velocity = (float*)realloc(this->drive_target_velocity, drive_target_velocity_lengthT * sizeof(float));
      drive_target_velocity_length = drive_target_velocity_lengthT;
      for( uint32_t i = 0; i < drive_target_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_drive_target_velocity));
        memcpy( &(this->drive_target_velocity[i]), &(this->st_drive_target_velocity), sizeof(float));
      }
      uint32_t steer_target_velocity_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      steer_target_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      steer_target_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      steer_target_velocity_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->steer_target_velocity_length);
      if(steer_target_velocity_lengthT > steer_target_velocity_length)
        this->steer_target_velocity = (float*)realloc(this->steer_target_velocity, steer_target_velocity_lengthT * sizeof(float));
      steer_target_velocity_length = steer_target_velocity_lengthT;
      for( uint32_t i = 0; i < steer_target_velocity_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_steer_target_velocity));
        memcpy( &(this->steer_target_velocity[i]), &(this->st_steer_target_velocity), sizeof(float));
      }
      uint32_t steer_target_position_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      steer_target_position_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      steer_target_position_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      steer_target_position_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->steer_target_position_length);
      if(steer_target_position_lengthT > steer_target_position_length)
        this->steer_target_position = (float*)realloc(this->steer_target_position, steer_target_position_lengthT * sizeof(float));
      steer_target_position_length = steer_target_position_lengthT;
      for( uint32_t i = 0; i < steer_target_position_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_steer_target_position));
        memcpy( &(this->steer_target_position[i]), &(this->st_steer_target_position), sizeof(float));
      }
      uint32_t steer_target_error_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      steer_target_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      steer_target_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      steer_target_error_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->steer_target_error_length);
      if(steer_target_error_lengthT > steer_target_error_length)
        this->steer_target_error = (float*)realloc(this->steer_target_error, steer_target_error_lengthT * sizeof(float));
      steer_target_error_length = steer_target_error_lengthT;
      for( uint32_t i = 0; i < steer_target_error_length; i++){
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->st_steer_target_error));
        memcpy( &(this->steer_target_error[i]), &(this->st_steer_target_error), sizeof(float));
      }
     return offset;
    }

    virtual const char * getType() override { return "cob_base_controller_utils/WheelCommands"; };
    virtual const char * getMD5() override { return "77ff79ee11678be45d9ecbc2cb9d23dd"; };

  };

}
#endif
