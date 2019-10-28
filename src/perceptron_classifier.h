#ifndef PERCEPTRON_CLASSIFIER_H
#define PERCEPTRON_CLASSIFIER_H

#include <string>
#include <unordered_map>
#include <vector>

#include "classifier.h"
#include "pitch.h"
#include "pitch_set.h"

namespace pitch_classifier {
  class PerceptronClassifier : public Classifier {
   public:
    virtual void train(PitchSet* training_data);

    virtual std::vector<std::string> test(PitchSet* test_data) const;

    virtual std::string classify(const Pitch& p) const;

   private:
    std::vector<std::string> repertoire;

    std::vector<std::vector<double> > weights;

    size_t classify_index(const Pitch& p) const;

    int pitch_index(std::string label) const;

  };
}

#endif
