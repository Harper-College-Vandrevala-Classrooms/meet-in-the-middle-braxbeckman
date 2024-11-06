#include <cctype>
#include <fstream>
#include <iostream>

double findMedian(std::string filename);

int main()
{
  std::string filename{"data.csv"};
  bool accepted{};
  // while (!accepted)
  // {
  //   std::cout << "Please enter your desired filename: ";
  //   getline(std::cin, filename);
  //
  //   {
  //     std::ifstream test(filename, std::fstream::in);
  //     if (test.fail())
  //     {
  //       std::cerr << "Failed to open file" << std::endl;
  //     }
  //     else
  //     {
  //       accepted = true;
  //       test.close();
  //     }
  //   }
  // }
  std::cout << "Median is: " << findMedian(filename) << std::endl;
}

double findMedian(std::string filename)
{
  std::vector<double> datapoints{};
  std::ifstream inputStream;
  double median{};

  inputStream.open(filename, std::fstream::in);
  if (inputStream.fail())
  {
    std::cerr << "Error opening file!" << std::endl;
    return NAN;
  }

  // std::cout << "File succesfully opened" << std::endl;

  // scan the file and log all integers found under the "datapoints" vector
  while (!inputStream.eof())
  {
    std::string line{};
    std::string tmp{};
    // std::cout << "In the while loop" << std::endl;

    getline(inputStream, line);
    // std::cout << "After the getline()" << std::endl;
    for (char c : line)
    {
      std::cout << "\n--new loop--\n" << std::endl;
      if (isdigit(c))
      {
        tmp += c;
        std::cout << "tmp = " << tmp << std::endl;
        continue;
      }
      else if (c == ',')
      {
        std::cout << "tmp = " << tmp << std::endl;
        datapoints.push_back(stod(tmp));
        tmp = "";
        continue;
      }
      else
      {
        std::cout << "tmp = " << tmp << std::endl;
        continue;
      }
    }
    // datapoints.push_back(stod(tmp));
  }

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
