#include "data_file_reader.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "pitch.h"
#include "pitch_set.h"

using namespace pitch_classifier;

PitchSet* DataFileReader::generate_pitch_set(const std::string& path) {
  std::ifstream input(path);
  std::string line;
  std::getline(input, line);

  if (line != ",mlbam_pitch_name,start_speed,spin,pfx_x,pfx_z,x0,z0") {
    std::cout << "Invalid data file format for path " << path << std::endl;
    return nullptr;

  } else {
    std::cout << "Valid data file found for path " << path << std::endl;
  }

  PitchSet* pitch_set = new PitchSet();
  
  while (std::getline(input, line)) {
    Pitch p(line);
    pitch_set->add_pitch(p);
  }
  return pitch_set;
}


