#ifndef _ROS_cob_control_msgs_ObstacleDistance_h
#define _ROS_cob_control_msgs_ObstacleDistance_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/Header.h"
#include "geometry_msgs/Vector3.h"

namespace cob_control_msgs
{

  class ObstacleDistance : public ros::Msg
  {
    public:
      typedef std_msgs::Header _header_type;
      _header_type header;
      typedef const char* _link_of_interest_type;
      _link_of_interest_type link_of_interest;
      typedef const char* _obstacle_id_type;
      _obstacle_id_type obstacle_id;
      typedef float _distance_type;
      _distance_type distance;
      typedef geometry_msgs::Vector3 _frame_vector_type;
      _frame_vector_type frame_vector;
      typedef geometry_msgs::Vector3 _nearest_point_frame_vector_type;
      _nearest_point_frame_vector_type nearest_point_frame_vector;
      typedef geometry_msgs::Vector3 _nearest_point_obstacle_vector_type;
      _nearest_point_obstacle_vector_type nearest_point_obstacle_vector;

    ObstacleDistance():
      header(),
      link_of_interest(""),
      obstacle_id(""),
      distance(0),
      frame_vector(),
      nearest_point_frame_vector(),
      nearest_point_obstacle_vector()
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->header.serialize(outbuffer + offset);
      uint32_t length_link_of_interest = strlen(this->link_of_interest);
      varToArr(outbuffer + offset, length_link_of_interest);
      offset += 4;
      memcpy(outbuffer + offset, this->link_of_interest, length_link_of_interest);
      offset += length_link_of_interest;
      uint32_t length_obstacle_id = strlen(this->obstacle_id);
      varToArr(outbuffer + offset, length_obstacle_id);
      offset += 4;
      memcpy(outbuffer + offset, this->obstacle_id, length_obstacle_id);
      offset += length_obstacle_id;
      offset += serializeAvrFloat64(outbuffer + offset, this->distance);
      offset += this->frame_vector.serialize(outbuffer + offset);
      offset += this->nearest_point_frame_vector.serialize(outbuffer + offset);
      offset += this->nearest_point_obstacle_vector.serialize(outbuffer + offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->header.deserialize(inbuffer + offset);
      uint32_t length_link_of_interest;
      arrToVar(length_link_of_interest, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_link_of_interest; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_link_of_interest-1]=0;
      this->link_of_interest = (char *)(inbuffer + offset-1);
      offset += length_link_of_interest;
      uint32_t length_obstacle_id;
      arrToVar(length_obstacle_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_obstacle_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_obstacle_id-1]=0;
      this->obstacle_id = (char *)(inbuffer + offset-1);
      offset += length_obstacle_id;
      offset += deserializeAvrFloat64(inbuffer + offset, &(this->distance));
      offset += this->frame_vector.deserialize(inbuffer + offset);
      offset += this->nearest_point_frame_vector.deserialize(inbuffer + offset);
      offset += this->nearest_point_obstacle_vector.deserialize(inbuffer + offset);
     return offset;
    }

    virtual const char * getType() override { return "cob_control_msgs/ObstacleDistance"; };
    virtual const char * getMD5() override { return "fbbcad171002ad96c1fc44941d7a1bf1"; };

  };

}
#endif
