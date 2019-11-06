#include "knn_classifier.h"

#include <map>
#include <string>
#include <vector>

#include "math_utils.h"
#include "pitch.h"
#include "pitch_set.h"

using namespace pitch_classifier;

KnnClassifier::KnnClassifier(size_t k) : k(k) {
}

void KnnClassifier::train(PitchSet* training_data) {
  for (size_t i = 0; i < training_data->size(); i++) {
    this->pitch_vectors.push_back(training_data->at(i).vector());
    this->labels.push_back(training_data->at(i).get_label());
  }
}

std::vector<std::string> KnnClassifier::test(PitchSet* test_data) const {
  std::vector<std::string> labels;
  for (size_t i = 0; i < test_data->size(); i++)
    labels.push_back(this->classify(test_data->at(i)));

  return labels;
}

std::string KnnClassifier::classify(const Pitch& p) const {
  return this->naive_classify(p);
}


std::string KnnClassifier::naive_classify(const Pitch& p) const {
  std::map<size_t, double> nearest_neighbors;
  for (size_t i = 0; i < this->pitch_vectors.size(); i++) {

    double distance_from_p = MathUtils::euclidean_distance(p.vector(), this->pitch_vectors[i]);
    if (nearest_neighbors.size() < this->k) {
      nearest_neighbors[i] = distance_from_p;

    } else {
      size_t furthest_vector_index;
      double furthest_distance = -1.0;

      std::map<size_t, double>::iterator it;
      for (it = nearest_neighbors.begin(); it != nearest_neighbors.end(); ++it) {

        if (it->second > furthest_distance) {
          furthest_vector_index = it->first;
          furthest_distance = it->second;
        }
      }
      if (furthest_distance > distance_from_p) {
        nearest_neighbors.erase(nearest_neighbors.find(furthest_vector_index));
        nearest_neighbors[i] = distance_from_p;
      }
    }
  }
  std::map<size_t, double>::iterator nn_it;
  std::map<std::string, size_t> sample_counts;
  for (nn_it = nearest_neighbors.begin(); nn_it != nearest_neighbors.end(); ++nn_it) {
    std::string label = this->labels[nn_it->first];
    sample_counts[label]++;
  }

  std::map<std::string, size_t>::iterator sc_it;
  std::string most_common_label;
  size_t highest_count = 0;
  for (sc_it = sample_counts.begin(); sc_it != sample_counts.end(); ++sc_it) {
    if (sc_it->second > highest_count) {
      most_common_label = sc_it->first;
      highest_count = sc_it->second;
    }
  }
  return most_common_label;
  }
