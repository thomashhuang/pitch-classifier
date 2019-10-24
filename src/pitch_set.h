#include <vector>

#include "pitch.h"

#ifndef PITCH_SET_H
#define PITCH_SET_H


namespace pitch_classifier {
  class PitchSet {
   public:
    void add_pitch(const Pitch& p);

    void clear();

    size_t size();

    Pitch& operator[](size_t n);

    /**
     * Instantiates a new PitchSet on the heap which must be deleted after use.
     * Takes size random pitches from the set to create a test set.
     */
    PitchSet* generate_test_set(size_t size);

   private:
    std::vector<Pitch> pitches;
  };
}

#endif
