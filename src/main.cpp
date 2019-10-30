#include <iostream>
#include <string>

#include "classifier.h"
#include "data_file_reader.h"
#include "perceptron_classifier.h"
#include "pitch.h"
#include "pitch_set.h"

using namespace pitch_classifier;

int main(int argc, const char* argv[]) {

  if (argc != 3) {
    return -1;
  }
  std::string first_name = std::string(argv[1]);
  std::string last_name = std::string(argv[2]);
  for (size_t i = 0; i < first_name.length(); i++) {
    first_name[i] = tolower(first_name[i]);
  }
  for (size_t i = 0; i < last_name.length(); i++) {
    last_name[i] = tolower(last_name[i]);
  }

  std::string path = "data/" + first_name + "_" + last_name + ".csv";
  DataFileReader d;
  PitchSet* data = d.generate_pitch_set(path);

  std::cout << "Generating test set." << std::endl;
  PitchSet* test_data = data->generate_test_set(data->size() / 10);

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

  double accuracy = (double) correct / double(actual_labels.size()) * 100.0;
  std::cout << correct << "/" << actual_labels.size() << std::endl;
  std::cout << accuracy << "%" << std::endl;

  delete(data);
  delete(test_data);
  delete(c);
  return 0;
}
