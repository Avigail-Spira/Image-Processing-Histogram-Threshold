#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Image {
  public:
    int numRows;
    int numCols;
    int minVal;
    int maxVal;
    int* histAry;
    int thresholdValue;

  void computeHist(ifstream& inFile) {
    std::string line;
    while (std::getline(inFile, line)) {
        stringstream ssin(line);
        int number;
        while (ssin >> number) {
          histAry[number]++;
        }
    }  
  }

  void printHist(ofstream& outFile) {
    outFile << numRows << " " << numCols << " " << minVal << " " << maxVal;
    for (int i = 0; i < maxVal; i++) {
      outFile << endl << i << " " << histAry[i];
    }
  }

  void dispHist(ofstream& outFile) {
    outFile << numRows << " " << numCols << " " << minVal << " " << maxVal;
    for (int i = 0; i < maxVal; i++) {
      outFile << endl << i << " (" << histAry[i] << "): ";
      for (int j = 0; j < histAry[i] && j <= 70; j++) {
        outFile << "+";
      }
    }
  }

  void threshold(ifstream& inFile, ofstream& outFile3, ofstream& outFile4, int thrVal) {
    minVal = 0;
    maxVal = 1;

    outFile3 << numRows << " " << numCols << " " << minVal << " " << maxVal;
    outFile4 << numRows << " " << numCols << " " << minVal << " " << maxVal;

    std::string line;
    getline(inFile, line);

    while (std::getline(inFile, line)) {
      outFile3 << endl;
      outFile4 << endl;
      stringstream ssin(line);
      int number;
      while (ssin >> number) {
        int pixelVal = number;
        if (pixelVal >= thrVal) {
          outFile3 << maxVal << " ";
          outFile4 << maxVal << " ";
        } else {
          outFile3 << minVal << " ";
          outFile4 << ". ";
        }
      }
    }
  }

};

int main(int argc, char* argv[]) {
  ifstream inFile(argv[1]);
  ofstream outFile1(argv[3]);
  ofstream outFile2(argv[4]);
  ofstream outFile3(argv[5]);
  ofstream outFile4(argv[6]);

  Image image;
  std::string line;

  getline(inFile, line);
  stringstream ssin(line);
  ssin >> image.numRows >> image.numCols >> image.minVal >> image.maxVal;

  image.histAry = new int[image.maxVal+1]();

  image.computeHist(inFile);
  image.printHist(outFile1);
  image.dispHist(outFile2);

  inFile.close();
  inFile.open(argv[1]);

  image.thresholdValue =  std::atoi(argv[2]);

  outFile3 << "The threshold value uses is " << image.thresholdValue << endl;
  outFile4 << "The threshold value uses is " << image.thresholdValue << endl;

  image.threshold(inFile, outFile3, outFile4, image.thresholdValue);

  inFile.close();
  outFile1.close();
  outFile2.close();
  outFile3.close();
  outFile4.close();
  
}