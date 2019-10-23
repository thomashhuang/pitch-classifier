#include "pitch.h"

#include <fstream>
#include <sstream>
#include <string>
#include <vector>


using namespace pitch_classifier;

Pitch::Pitch(const std::string& label, double velocity, double spin,
             double break_x, double break_z,
             double release_x, double release_z) : 
    label(label), velocity(velocity), spin(spin), 
    break_x(break_x), break_z(break_z), 
    release_x(release_x), release_z(release_z) {}

Pitch::Pitch(const std::string& data_file_line) {
  std::istringstream iss(data_file_line);
  std::string input_buffer;

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
std::string Pitch::get_label() {
  return this->label;
}

void Pitch::set_label(const std::string& label) {
  this->label = label;
}

double Pitch::get_velocity() {
  return this->velocity;
}

void Pitch::set_velocity(double velocity) {
  this->velocity = velocity;
}

double Pitch::get_spin() {
  return this->spin;
}

void Pitch::set_spin(double spin) {
  this->spin = spin;
}

double Pitch::get_break_x() {
  return this->break_x;
}

void Pitch::set_break_x(double break_x) {
  this->break_x = break_x;
}


double Pitch::get_break_z() {
  return this->break_z;
}

void Pitch::set_break_z(double break_z) {
  this->break_z = break_z;
}


double Pitch::get_release_x() {
  return this->release_x;
}

void Pitch::set_release_x(double release_x) {
  this->release_x = release_x;
}

double Pitch::get_release_z() {
  return this->release_z;
}

void Pitch::set_release_z(const double release_z) {
  this->release_z = release_z;
}

std::vector<double> Pitch::vector() {
  std::vector<double> v;
  v.push_back(this->velocity);
  v.push_back(this->spin);
  v.push_back(this->break_x);
  v.push_back(this->break_z);
  v.push_back(this->release_x);
  v.push_back(this->release_z);
  return v;
}

