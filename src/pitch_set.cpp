#include "pitch_set.h"

#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "pitch.h"

using namespace pitch_classifier;

void PitchSet::add_pitch(const Pitch& p) {
  this->pitches.push_back(p);
}

void PitchSet::clear() {
  this->pitches.clear();
}

size_t PitchSet::size() {
  return this->pitches.size();
}

Pitch& PitchSet::operator[](size_t n) {
  return this->pitches[n];
}
 
PitchSet* PitchSet::generate_test_set(size_t size) {
  PitchSet* test_set = new PitchSet();

  for (size_t i = 0; i < size; i++) {
    size_t index_to_remove = rand() % this->pitches.size();

    Pitch& p = this->pitches[index_to_remove];
    test_set->add_pitch(p);

    this->pitches.erase(this->pitches.begin() + index_to_remove);
  }

  return test_set;
}
  
std::vector<std::string>* PitchSet::get_labels() {
  std::vector<std::string>* labels = new std::vector<std::string>();
  for (size_t i = 0; i < this->size(); i++) {
    labels->push_back(this->pitches[i].get_label());
  }
  return labels;
}
