#ifndef MATH_UTILS_H
#define MATH_UTILS_H

#include <vector>

namespace pitch_classifier {
  class MathUtils {
   public:
    static double dot(const std::vector<double>& v1, const std::vector<double>& v2);

    static std::vector<double> add(const std::vector<double>& v1, const std::vector<double>& v2);
    
    static void add_in_place(std::vector<double>& v1, const std::vector<double>& v2);

    static std::vector<double> subtract(const std::vector<double>& v1, const std::vector<double>& v2);

    static void subtract_in_place(std::vector<double>& v1, const std::vector<double>& v2);

    static std::vector<double> scale(const std::vector<double>& v1, double factor);

    static void scale_in_place(std::vector<double>& v1, double factor);
    
  };
}

#endif
