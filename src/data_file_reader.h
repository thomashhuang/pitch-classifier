#ifndef DATA_FILE_READER_H
#define DATA_FILE_READER_H

#include <string>

#include "pitch_set.h"


namespace pitch_classifier {

  class DataFileReader {

   public:
    PitchSet* generate_pitch_set(const std::string& path);

  };
}



#endif
