#ifndef PITCH_H
#define PITCH_H

#include <string>
#include <fstream>

namespace pitch_classifier {
  class Pitch {
   public:

    Pitch(const std::string label, const double velocity, const double spin,
          const double break_x, const double break_y, 
          const double release_x, const double release_y);

    Pitch(std::string data_file_line);

    const std::string get_label();
    void set_label(std::string label);

    const double get_velocity();
    void set_velocity(const double velocity);

    const double get_spin();
    void set_spin(const double spin);

    const double get_break_x();
    void set_break_x(const double break_x);

    const double get_break_z();
    void set_break_z(const double break_z);

    const double get_release_x();
    void set_release_x(const double release_x);

    const double get_release_z();
    void set_release_z(const double release_z);

    const std::vector<double> vector();

    friend std::ifstream& operator>>(std::ifstream& input, Pitch& p);

   private:
    std::string label;
    double velocity;
    double spin;
    double break_x;
    double break_z;
    double release_x;
    double release_z;
  };
}

#endif
