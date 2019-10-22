#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "pitch.h"

using namespace pitch_classifier;

Pitch::Pitch(){
  
}

Pitch::Pitch(const std::string label, const double velocity, const double spin,
             const double break_x, const double break_z,
             const double release_x, const double release_z) : 
    label(label), velocity(velocity), spin(spin), 
    break_x(break_x), break_z(break_z), 
    release_x(release_x), release_z(release_z) {}

Pitch::Pitch(std::string data_file_line) {
  std::istringstream iss(data_file_line);
  std::string input_buffer;
  std::string label;
  double velocity;
  double spin;
  double break_x;
  double break_z;
  double release_x;
  double release_z;

  getline(iss, input_buffer, ',');
  // ignore pitch number
    
  getline(iss, input_buffer, ',');
  this->label = std::string(input_buffer);

  getline(iss, input_buffer, ',');
  this->velocity = std::stod(input_buffer);

  getline(iss, input_buffer, ',');
  this->spin = std::stod(input_buffer);

  getline(iss, input_buffer, ',');
  this->break_x = std::stod(input_buffer);
  
  getline(iss, input_buffer, ',');
  this->break_z = std::stod(input_buffer);

  getline(iss, input_buffer, ',');
  this->release_x = std::stod(input_buffer);

  getline(iss, input_buffer, ',');
  this->release_z = std::stod(input_buffer);
}

// getters and setters
const std::string Pitch::get_label() {
  return this->label;
}

void Pitch::set_label(const std::string label) {
  this->label = label;
}

const double Pitch::get_velocity() {
  return this->velocity;
}

void Pitch::set_velocity(const double velocity) {
  this->velocity = velocity;
}

const double Pitch::get_spin() {
  return this->spin;
}

void Pitch::set_spin(const double spin) {
  this->spin = spin;
}

const double Pitch::get_break_x() {
  return this->break_x;
}

void Pitch::set_break_x(const double break_x) {
  this->break_x = break_x;
}


const double Pitch::get_break_z() {
  return this->break_z;
}

void Pitch::set_break_z(const double break_z) {
  this->break_z = break_z;
}


const double Pitch::get_release_x() {
  return this->release_x;
}

void Pitch::set_release_x(const double release_x) {
  this->release_x = release_x;
}

const double Pitch::get_release_z() {
  return this->release_z;
}

void Pitch::set_release_z(const double release_z) {
  this->release_z = release_z;
}

const std::vector<double> Pitch::vector() {
  std::vector<double> v;
  v.push_back(this->velocity);
  v.push_back(this->spin);
  v.push_back(this->break_x);
  v.push_back(this->break_z);
  v.push_back(this->release_x);
  v.push_back(this->release_z);
  return v;
}

std::ifstream& pitch_classifier::operator>>(std::ifstream& input, Pitch& p) {
  std::string input_buffer;

  getline(input, input_buffer, ',');
  // ignore pitch number
    
  getline(input, input_buffer, ',');
  p.label = std::string(input_buffer);

  getline(input, input_buffer, ',');
  p.velocity = std::stod(input_buffer);

  getline(input, input_buffer, ',');
  p.spin = std::stod(input_buffer);

  getline(input, input_buffer, ',');
  p.break_x = std::stod(input_buffer);
  
  getline(input, input_buffer, ',');
  p.break_z = std::stod(input_buffer);

  getline(input, input_buffer, ',');
  p.release_x = std::stod(input_buffer);

  getline(input, input_buffer, ',');
  p.release_z = std::stod(input_buffer);
  
  return input;
}

