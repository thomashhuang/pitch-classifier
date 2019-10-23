#include <vector>

#include "pitch.h"

#ifndef PITCH_SET_H
#define PITCH_SET_H


namespace pitch_classifier {
  class PitchSet {
   public:
    void add_pitch(const Pitch& p);

    const size_t size();

    PitchSet generate_test_set(const int size);

   private:
    std::vector<Pitch> pitches;
  };
  
}

#endif