#include "perceptron_classifier.h"

#include <iostream>
#include <string>
#include <vector>

#include "math_utils.h"
#include "pitch.h"
#include "pitch_set.h"

using namespace pitch_classifier;

void PerceptronClassifier::train(PitchSet* training_data) {
  // initialize repertoire
  for (size_t i = 0; i < training_data->size(); i++) {
    std::string pitch_label = training_data->at(i).get_label();

    if (this->pitch_index(pitch_label) == -1)
      this->repertoire.push_back(pitch_label);
  }
  
  // initialize perceptron weights including bias
  size_t outer_dim = this->repertoire.size();
  size_t inner_dim = training_data->at(0).vector().size() + 1; // add one for bias term
  for (size_t i = 0; i < outer_dim; i++) {
    std::vector<double> v;
    for (size_t j = 0; j < inner_dim; j++) {
      v.push_back(0.0);
    }
    this->weights.push_back(v);
  }
  
  // train the weight vectors
  double eta = 1;
  const double LEARNING_RATE = .0000005;
  size_t correct_streak = 0;

  size_t i = 0;
  while (eta >= 0) {
    if (i == training_data->size())
      i = 0;
    if (correct_streak == training_data->size())
      return; // found correct boundaries, only happens if data is linearly seperable

    Pitch& p = training_data->at(i);
    size_t classified_index = this->classify_index(p);
    size_t actual_index = this->pitch_index(p.get_label());

    if (classified_index != actual_index) {
      std::vector<double> adjustment = p.vector();
      adjustment.push_back(1.0); // bias
      MathUtils::scale_in_place(adjustment, eta);

      MathUtils::add_in_place(this->weights[actual_index], adjustment);
      MathUtils::subtract_in_place(this->weights[classified_index], adjustment);

      eta -= LEARNING_RATE;
      correct_streak = 0;
    } else {
      correct_streak++;
    }
    i++;
  }

  for (size_t i = 0; i < outer_dim; i++) {
    std::cout << this->repertoire[i] << ": ";
    for (size_t j = 0; j < inner_dim; j++) {
      std::cout << this->weights[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

std::vector<std::string> PerceptronClassifier::test(PitchSet* test_data) const {
  std::vector<std::string> labels;
  for (size_t i = 0; i < test_data->size(); i++)
    labels.push_back(this->classify(test_data->at(i)));

  return labels;
}

std::string PerceptronClassifier::classify(const Pitch& p) const {
  return this->repertoire[this->classify_index(p)];
}

size_t PerceptronClassifier::classify_index(const Pitch& p) const {
  std::vector<double> feature_vector = p.vector();
  feature_vector.push_back(1); // bias term

  size_t best_classification = 0;
  double best_value = 0;
  for (size_t i = 0; i < this->repertoire.size(); i++) {
    double value = MathUtils::dot(feature_vector, this->weights[i]);
    if (value > best_value) {
      best_value = value;
      best_classification = i;
    }
  }
  return best_classification;
}

int PerceptronClassifier::pitch_index(std::string label) const {
  for (size_t i = 0; i < this->repertoire.size(); i++) {
    if (label == this->repertoire[i])
      return i;
  }
  return -1;
}
