#include "catch.hpp"
#include "../src/pitch_set.h"

#include <stdio.h>

#include "../src/pitch.h"

using namespace pitch_classifier;

TEST_CASE("PITCH_SET::size_default") {
  PitchSet s;
  REQUIRE(s.size() == 0);
}

TEST_CASE("PITCH_SET::size_small") {
  PitchSet s;
  size_t size = 10;
  for (size_t i = 0; i < size; i++) {
    Pitch p("FF", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    s.add_pitch(p);
  }
  REQUIRE(s.size() == size);
}

TEST_CASE("PITCH_SET::size_large") {
  PitchSet s;
  size_t size = 50000;
  for (size_t i = 0; i < size; i++) {
    Pitch p("FF", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    s.add_pitch(p);
  }
  REQUIRE(s.size() == size);
}

TEST_CASE("PITCH_SET::clear") {
  PitchSet s;
  size_t size = 100;
  for (size_t i = 0; i < size; i++) {
    Pitch p("FF", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    s.add_pitch(p);
  }
  s.clear();
  REQUIRE(s.size() == 0);
}

TEST_CASE("PITCH_SET::test_set_size") {
  PitchSet* s = new PitchSet();
  size_t size = 50000;
  for (size_t i = 0; i < size; i++) {
    Pitch p("FF", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    s->add_pitch(p);
  }
  size_t test_size = 10000;
  PitchSet* t = s->generate_test_set(test_size);
  REQUIRE(t->size() == test_size);
  delete(s);
  delete(t);
}

TEST_CASE("PITCH_SET::test_set_removes_from_original") {
  PitchSet* s = new PitchSet();
  size_t size = 50000;
  for (size_t i = 0; i < size; i++) {
    Pitch p("FF", 0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
    s->add_pitch(p);
  }
  size_t test_size = 10000;
  PitchSet* t = s->generate_test_set(test_size);
  REQUIRE(s->size() == size - test_size);
  delete(s);
  delete(t);
}
