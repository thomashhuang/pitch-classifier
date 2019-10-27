#include "catch.hpp"
#include "../src/data_file_reader.h"

#include <string>
#include <vector>

#include "../src/pitch.h"
#include "../src/pitch_set.h"

using namespace pitch_classifier;

TEST_CASE("DATA_FILE_READER::accepts_valid_file") {
  DataFileReader r;
  // The data from this is a small sample from Max Scherzer's pitch history
  PitchSet* s = r.generate_pitch_set("data/sample.csv");
  REQUIRE(s != nullptr);
  delete(s);
}

TEST_CASE("DATA_FILE_READER::rejects_invalid_file") {
  DataFileReader r;
  PitchSet* s = r.generate_pitch_set("src/pitch.h");
  REQUIRE(s == nullptr);
  delete(s);
}

TEST_CASE("DATA_FILE_READER::correct_size") {
  DataFileReader r;
  // This is a manually written file for testing purposes only
  PitchSet* s = r.generate_pitch_set("data/reader_test_data.csv");
  REQUIRE(s->size() == 4);
  delete(s);
}

TEST_CASE("DATA_FILE_READER::correct_labels") {
  DataFileReader r;
  PitchSet* s = r.generate_pitch_set("data/reader_test_data.csv");
  std::vector<std::string> labels = s->get_labels();
  REQUIRE(labels[0] == "FF");
  REQUIRE(labels[1] == "SI");
  REQUIRE(labels[2] == "SL");
  REQUIRE(labels[3] == "CH");
  delete(s);
}

TEST_CASE("DATA_FILE_READER::correct_data") {
  DataFileReader r;
  PitchSet* s = r.generate_pitch_set("data/reader_test_data.csv");
  for (size_t i = 0; i < s->size(); i++) {
    int offset = 10 * i;
    Pitch p = s->at(i);
    REQUIRE(p.get_velocity() == 0.0 + offset);
    REQUIRE(p.get_spin() == 1.0 + offset);
    REQUIRE(p.get_break_x() == 2.0 + offset);
    REQUIRE(p.get_break_z() == 3.0 + offset);
    REQUIRE(p.get_release_x() == 4.0 + offset);
    REQUIRE(p.get_release_z() == 5.0 + offset);
  }
  delete(s);
}
