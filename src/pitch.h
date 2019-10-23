#ifndef PITCH_H
#define PITCH_H

#include <string>
#include <fstream>

namespace pitch_classifier {
  class Pitch {
   public:

    Pitch(const std::string& label, double velocity, double spin,
          double break_x, double break_z, 
          double release_x, double release_z);

    Pitch(const std::string& data_file_line);

    std::string get_label();
    void set_label(const std::string& label);

    double get_velocity();
    void set_velocity(double velocity);

    double get_spin();
    void set_spin(double spin);

    double get_break_x();
    void set_break_x(double break_x);

    double get_break_z();
    void set_break_z(double break_z);

    double get_release_x();
    void set_release_x(double release_x);

    double get_release_z();
    void set_release_z(double release_z);

    std::vector<double> vector();

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
