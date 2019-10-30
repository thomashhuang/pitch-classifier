#include "math_utils.h"

#include <math.h>
#include <iostream>
#include <vector>

using namespace pitch_classifier;

double MathUtils::dot(const std::vector<double>& v1, const std::vector<double>& v2) {
  if (v1.size() != v2.size()) {
    std::cerr << "Invalid dimensions for dot product" << std::endl;
    throw 0;
  }
  double dot_product = 0.0;
  for (size_t i = 0; i < v1.size(); i++) {
    dot_product += v1[i] * v2[i];
  }
  return dot_product;
}

std::vector<double> MathUtils::add(const std::vector<double>& v1, const std::vector<double>& v2) {
  if (v1.size() != v2.size()) {
    std::cerr << "Invalid dimensions for vector addition" << std::endl;
    throw 0;
  }
  std::vector<double> sum;
  for (size_t i = 0; i < v1.size(); i++) {
    sum.push_back(v1[i] + v2[i]);
  }
  return sum;
}

void MathUtils::add_in_place(std::vector<double>& v1, const std::vector<double>& v2) {
  if (v1.size() != v2.size()) {
    std::cerr << "Invalid dimensions for vector addition" << std::endl;
    throw 0;
  }
  for (size_t i = 0; i < v1.size(); i++) {
    v1[i] += v2[i];
  }
}

std::vector<double> MathUtils::subtract(const std::vector<double>& v1, const std::vector<double>& v2) {
  if (v1.size() != v2.size()) {
    std::cerr << "Invalid dimensions for vector subtraction" << std::endl;
    throw 0;
  }
  std::vector<double> sum;
  for (size_t i = 0; i < v1.size(); i++) {
    sum.push_back(v1[i] - v2[i]);
  }
  return sum;
}

void MathUtils::subtract_in_place(std::vector<double>& v1, const std::vector<double>& v2) {
  if (v1.size() != v2.size()) {
    std::cerr << "Invalid dimensions for vector subtraction" << std::endl;
    throw 0;
  }
  for (size_t i = 0; i < v1.size(); i++) {
    v1[i] -= v2[i];
  }
}

std::vector<double> MathUtils::scale(const std::vector<double>& v1, double factor) {
  std::vector<double> scaled;
  for (size_t i = 0; i < v1.size(); i++) {
    scaled.push_back(v1[i] * factor);
  }
  return scaled;
}

void MathUtils::scale_in_place(std::vector<double>& v1, double factor) {
  for (size_t i = 0; i < v1.size(); i++) {
    v1[i] *= factor;
  }
}

double MathUtils::euclidean_distance(const std::vector<double>& v1, const std::vector<double>& v2) {
  if (v1.size() != v2.size()) {
    std::cerr << "Invalid dimensions for vector euclidean distance." << std::endl;
    throw 0;
  }
  double distance = 0.0;
  for (size_t i = 0; i < v1.size(); i++) {
    distance += (v1[i] - v2[i]) * (v1[i] - v2[i]);
  }
  return sqrt(distance);
}
