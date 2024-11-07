#include <cctype>
#include <fstream>
#include <iostream>
#include <sstream>

std::vector<double> datapoints{};

void logFile(std::string filename);
double findMedian();
double findMean();

int main()
{
  std::string filename{"data.csv"};
  bool accepted{};
  while (!accepted)
  {
    std::cout << "Please enter your desired filename: ";
    getline(std::cin, filename);

    {
      std::ifstream test(filename, std::fstream::in);
      if (test.fail())
      {
        std::cerr << "Failed to open file" << std::endl;
      }
      else
      {
        accepted = true;
        test.close();
      }
    }
  }

  logFile(filename);
  std::cout << "Median is: " << findMedian() << std::endl;
  std::cout << "Mean is: " << findMean() << std::endl;
}

void logFile(std::string filename)
{
  std::ifstream inputStream;
  inputStream.open(filename, std::fstream::in);
  if (inputStream.fail())
  {
    std::cerr << "Error opening file!" << std::endl;
  }

  // std::cout << "File succesfully opened" << std::endl;

  // scan the file and log all integers found under the "datapoints" vector
  while (!inputStream.eof())
  {
    std::string line{};
    std::string number{};

    getline(inputStream, line);
    std::stringstream sstream(line);

    while (sstream >> number)
    {
      if (number.back() == ',')
        number.pop_back();
      datapoints.push_back(stod(number));
    }
  }
}

double findMedian()
{
  float median{};

  int vSize = datapoints.size();
  if (vSize % 2 == 0)
  {
    median = (datapoints.at(vSize / 2) + datapoints.at((vSize / 2) - 1)) / 2;
    return median;
  }
  else if (vSize % 2 == 1)
  {
    median = datapoints.at(vSize / 2);
    return median;
  }
  else
  {
    std::cerr << "Error grabbing median numbers, it grabbed more than two?" << std::endl;
    return NAN;
  }
}

double findMean()
{
  double total{};
  int dSize = datapoints.size();
  for (double d : datapoints)
  {
    total += d;
  }
  return (total / dSize);
}
