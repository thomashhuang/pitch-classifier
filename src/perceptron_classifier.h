#ifndef PERCEPTRON_CLASSIFIER_H
#define PERCEPTRON_CLASSIFIER_H

#include <map>
#include <string>
#include <vector>

#include "classifier.h"
#include "pitch.h"
#include "pitch_set.h"

namespace pitch_classifier {
  class PerceptronClassifier : public Classifier {
   public:
    PerceptronClassifier();

    PerceptronClassifier(double learning_rate);

    void train(PitchSet* training_data);

    std::vector<std::string> test(PitchSet* test_data);

    std::string classify(Pitch p);

   private:

    std::map<int, std::string> repertoire;

    double learning_rate;
   
    
  };
}

#endif
