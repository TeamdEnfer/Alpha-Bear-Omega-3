#ifndef _ROS_jsk_recognition_msgs_ClassificationTaskGoal_h
#define _ROS_jsk_recognition_msgs_ClassificationTaskGoal_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "sensor_msgs/Image.h"
#include "sensor_msgs/CompressedImage.h"

namespace jsk_recognition_msgs
{

  class ClassificationTaskGoal : public ros::Msg
  {
    public:
      typedef sensor_msgs::Image _image_type;
      _image_type image;
      typedef sensor_msgs::CompressedImage _compressed_image_type;
      _compressed_image_type compressed_image;
      uint32_t queries_length;
      typedef char* _queries_type;
      _queries_type st_queries;
      _queries_type * queries;

    ClassificationTaskGoal():
      image(),
      compressed_image(),
      queries_length(0), st_queries(), queries(nullptr)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      offset += this->image.serialize(outbuffer + offset);
      offset += this->compressed_image.serialize(outbuffer + offset);
      *(outbuffer + offset + 0) = (this->queries_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->queries_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->queries_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->queries_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->queries_length);
      for( uint32_t i = 0; i < queries_length; i++){
      uint32_t length_queriesi = strlen(this->queries[i]);
      varToArr(outbuffer + offset, length_queriesi);
      offset += 4;
      memcpy(outbuffer + offset, this->queries[i], length_queriesi);
      offset += length_queriesi;
      }
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      offset += this->image.deserialize(inbuffer + offset);
      offset += this->compressed_image.deserialize(inbuffer + offset);
      uint32_t queries_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      queries_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      queries_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      queries_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->queries_length);
      if(queries_lengthT > queries_length)
        this->queries = (char**)realloc(this->queries, queries_lengthT * sizeof(char*));
      queries_length = queries_lengthT;
      for( uint32_t i = 0; i < queries_length; i++){
      uint32_t length_st_queries;
      arrToVar(length_st_queries, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_st_queries; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_st_queries-1]=0;
      this->st_queries = (char *)(inbuffer + offset-1);
      offset += length_st_queries;
        memcpy( &(this->queries[i]), &(this->st_queries), sizeof(char*));
      }
     return offset;
    }

    virtual const char * getType() override { return "jsk_recognition_msgs/ClassificationTaskGoal"; };
    virtual const char * getMD5() override { return "ad8268845f16b9e0cadf4c2ab2c1a7e7"; };

  };

}
#endif
