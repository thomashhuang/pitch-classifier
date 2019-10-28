#include <iostream>
#include <string>

#include "classifier.h"
#include "data_file_reader.h"
#include "perceptron_classifier.h"
#include "pitch.h"
#include "pitch_set.h"

using namespace pitch_classifier;

int main() {
  std::string path = "data/kyle_hendricks.csv";
  DataFileReader d;
  PitchSet* data = d.generate_pitch_set(path);

  std::cout << "Generating test set." << std::endl;
  PitchSet* test_data = data->generate_test_set(1500);

  Classifier* c = new PerceptronClassifier();

  std::cout << "Training classifier" << std::endl;
  c->train(data);

  std::cout << "Testing classifier" << std::endl;
  std::vector<std::string> classifier_output = c->test(test_data);
  std::vector<std::string> actual_labels = test_data->get_labels();

  int correct = 0;
  for (size_t i = 0; i < classifier_output.size(); i++) {
    //std::cout << "Output:" << classifier_output[i] << ", Actual:" << actual_labels[i] << std::endl;
    if (classifier_output[i] == actual_labels[i]) 
      correct++;
  }

  std::cout << correct << "/" << actual_labels.size() << std::endl;

  delete(data);
  delete(test_data);
  delete(c);
  return 0;
}
