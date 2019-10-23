#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../src/pitch.h"

#include <string>
#include <vector>

using namespace pitch_classifier;

TEST_CASE("PITCH::full_constructor") {

  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  REQUIRE(p.get_label() == "FF");
  REQUIRE(p.get_velocity() == 1.0);
  REQUIRE(p.get_spin() == 2.0);
  REQUIRE(p.get_break_x() == 3.0);
  REQUIRE(p.get_break_z() == 4.0);
  REQUIRE(p.get_release_x() == 5.0);
  REQUIRE(p.get_release_z() == 6.0);
}

TEST_CASE("PITCH::string_constructor") {
  std::string data_file_line = "0,FF,1.0,2.0,3.0,4.0,5.0,6.0";
  Pitch p(data_file_line);
  REQUIRE(p.get_label() == "FF");
  REQUIRE(p.get_velocity() == 1.0);
  REQUIRE(p.get_spin() == 2.0);
  REQUIRE(p.get_break_x() == 3.0);
  REQUIRE(p.get_break_z() == 4.0);
  REQUIRE(p.get_release_x() == 5.0);
  REQUIRE(p.get_release_z() == 6.0);
}

TEST_CASE("PITCH::set_label") {
  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  p.set_label("CH");
  REQUIRE(p.get_label() == "CH");
  REQUIRE(p.get_velocity() == 1.0); // check other fields for this case only
  REQUIRE(p.get_spin() == 2.0);
  REQUIRE(p.get_break_x() == 3.0);
  REQUIRE(p.get_break_z() == 4.0);
  REQUIRE(p.get_release_x() == 5.0);
  REQUIRE(p.get_release_z() == 6.0);
}

TEST_CASE("PITCH::set_velocity") {
  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  p.set_velocity(10.0);
  REQUIRE(p.get_velocity() == 10.0);
}

TEST_CASE("PITCH::set_spin") {
  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  p.set_spin(10.0);
  REQUIRE(p.get_spin() == 10.0);
}

TEST_CASE("PITCH::set_break_x") {
  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  p.set_break_x(10.0);
  REQUIRE(p.get_break_x() == 10.0);
}

TEST_CASE("PITCH::set_break_z") {
  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  p.set_break_z(10.0);
  REQUIRE(p.get_break_z() == 10.0);
}

TEST_CASE("PITCH::set_release_x") {
  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  p.set_release_x(10.0);
  REQUIRE(p.get_release_x() == 10.0);
}

TEST_CASE("PITCH::set_release_z") {
  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  p.set_release_z(10.0);
  REQUIRE(p.get_release_z() == 10.0);
}

TEST_CASE("PITCH::vector") {
  Pitch p("FF", 1.0, 2.0, 3.0, 4.0, 5.0, 6.0);
  std::vector<double> p_vector = p.vector();
  std::vector<double> expected;
  expected.push_back(1.0);
  expected.push_back(2.0);
  expected.push_back(3.0);
  expected.push_back(4.0);
  expected.push_back(5.0);
  expected.push_back(6.0);
  REQUIRE(p_vector.size() == expected.size());
  for (size_t i = 0; i < p_vector.size(); i++) {
    REQUIRE(p_vector[i] == expected[i]);
  }
}

