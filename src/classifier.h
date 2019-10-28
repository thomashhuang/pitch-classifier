#ifndef CLASSIFIER_H
#define CLASSIFIER_H

#include <string>
#include <vector>

#include "pitch.h"
#include "pitch_set.h"

namespace pitch_classifier {
  
  class Classifier {
   public:
    virtual void train(PitchSet* training_data) = 0;

    virtual std::vector<std::string> test(PitchSet* test_data) const = 0;

    virtual std::string classify(const Pitch& p) const = 0;
  };
}

#endif
