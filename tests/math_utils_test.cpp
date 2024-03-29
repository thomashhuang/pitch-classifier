#include "catch.hpp"
#include "../src/math_utils.h"

#include <vector>

using namespace pitch_classifier;

TEST_CASE("MATH_UTILS::dot_value") {
  std::vector<double> v1{1, 2, 3};
  std::vector<double> v2{2, 3, 4};
  REQUIRE(MathUtils::dot(v1, v2) == 20);
}

TEST_CASE("MATH_UTILS::dot_invalid_dimensions") {
  std::vector<double> v1{2, 3};
  std::vector<double> v2{2, 3, 4};
  REQUIRE_THROWS(MathUtils::dot(v1, v2));
}

TEST_CASE("MATH_UTILS::add_value") {
  std::vector<double> v1{1, 2, 3};
  std::vector<double> v2{2, 3, 4};
  std::vector<double> sum = MathUtils::add(v1, v2);
  REQUIRE(sum[0] == 3);
  REQUIRE(sum[1] == 5);
  REQUIRE(sum[2] == 7);
}

TEST_CASE("MATH_UTILS::add_invalid_dimensions") {
  std::vector<double> v1{2, 3};
  std::vector<double> v2{2, 3, 4};
  REQUIRE_THROWS(MathUtils::add(v1, v2));
}

TEST_CASE("MATH_UTILS::add_in_place_value") {
  std::vector<double> v1{1, 2, 3};
  std::vector<double> v2{2, 3, 4};
  MathUtils::add_in_place(v1, v2);
  REQUIRE(v1[0] == 3);
  REQUIRE(v1[1] == 5);
  REQUIRE(v1[2] == 7);
}

TEST_CASE("MATH_UTILS::add_in_place_invalid_dimensions") {
  std::vector<double> v1{2, 3};
  std::vector<double> v2{2, 3, 4};
  REQUIRE_THROWS(MathUtils::add_in_place(v1, v2));
}

TEST_CASE("MATH_UTILS::subtract_value") {
  std::vector<double> v1{1, 2, 3};
  std::vector<double> v2{2, 1, 0};
  std::vector<double> diff = MathUtils::subtract(v1, v2);
  REQUIRE(diff[0] == -1);
  REQUIRE(diff[1] == 1);
  REQUIRE(diff[2] == 3);
}

TEST_CASE("MATH_UTILS::subtract_invalid_dimensions") {
  std::vector<double> v1{2, 3};
  std::vector<double> v2{2, 3, 4};
  REQUIRE_THROWS(MathUtils::subtract(v1, v2));
}

TEST_CASE("MATH_UTILS::subtract_in_place_value") {
  std::vector<double> v1{1, 2, 3};
  std::vector<double> v2{2, 1, 0};
  MathUtils::subtract_in_place(v1, v2);
  REQUIRE(v1[0] == -1);
  REQUIRE(v1[1] == 1);
  REQUIRE(v1[2] == 3);
}

TEST_CASE("MATH_UTILS::subtract_in_place_invalid_dimensions") {
  std::vector<double> v1{2, 3};
  std::vector<double> v2{2, 3, 4};
  REQUIRE_THROWS(MathUtils::subtract_in_place(v1, v2));
}

TEST_CASE("MATH_UTILS::scale_value") {
  std::vector<double> v1{1, 2, 3};
  std::vector<double> scaled = MathUtils::scale(v1, 2);
  REQUIRE(scaled[0] == 2);
  REQUIRE(scaled[1] == 4);
  REQUIRE(scaled[2] == 6);
}

TEST_CASE("MATH_UTILS::euclidean_distance_value") {
  std::vector<double> v1{3, 4};
  std::vector<double> v2{0, 0};
  REQUIRE(MathUtils::euclidean_distance(v1, v2) == 5.0);
}

TEST_CASE("MATH_UTILS::euclidean_distance_invalid_dimensions") {
  std::vector<double> v1{2, 3};
  std::vector<double> v2{2, 3, 4};
  REQUIRE_THROWS(MathUtils::euclidean_distance(v1, v2));
}
