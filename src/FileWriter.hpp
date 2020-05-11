/**
 * @file FileWriter.hpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2020-05-11
 * 
 * @copyright Copyright (c) 2020
 * 
 */
#ifndef FILEWRITER_HPP
#define FILEWRITER_HPP

#include <fstream>

namespace IoTApp
{
/**
 * @brief 
 * 
 */
class FileWriter final
{
 public:
  FileWriter(std::string path, bool append = false)
  {
    mFilestream.open(path, (append ? std::ios::app : std::ios::out));
  }
  ~FileWriter()
  {
    mFilestream.close();
  }
  template <class T>
  FileWriter& operator<<(const T& content)
  {
    mFilestream << content;
    return *this;
  }

 private:
  std::ofstream mFilestream;
};
}

#endif