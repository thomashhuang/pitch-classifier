#ifndef KNN_CLASSIFIER_H
#define KNN_CLASSIFIER_H

#include <map>
#include <string>
#include <vector>

#include "pitch.h"
#include "classifier.h"

namespace pitch_classifier {
  class KnnClassifier : public Classifier {
   public:
    KnnClassifier(size_t k);

    virtual void train(PitchSet* training_data);

    virtual std::vector<std::string> test(PitchSet* test_data) const;

    virtual std::string classify(const Pitch& p) const;

   private:
    size_t k;

    std::vector<std::vector<double> > pitch_vectors;
    
    std::vector<std::string> labels;

    std::string naive_classify(const Pitch& p) const;

  };
}


#endif
