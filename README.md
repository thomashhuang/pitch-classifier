# pitch_classifier

## Pipeline

PITCHf/x data is scraped from http://www.brooksbaseball.net/ and saved to a local csv file with a Python script. The PITCHf/x data already contains classifications according to the MLBAM's neural net solution to classifying pitches, with manual adjustments made according to other evidence (more at http://www.brooksbaseball.net/about.php).

The csv file is read into the PitchSet C++ object, which can then be partitioned into training and test data.

A classifier (also in C++) is trained on the training data, then we evaluate the accuracy of the classifier against the labels provided in the original data set which we use as ground truth labels.
