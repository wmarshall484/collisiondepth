#include <XnCppWrapper.h>
#include <fstream>
#include <iostream>
#include <string>

class MapMaker{
 public:
  xn::Context context;
  xn::DepthGenerator depth;
  XnStatus nRetVal;
  MapMaker();
  void init();
  void stop();
  void grabFrame();
 private:
  void checkError(std::string where, XnStatus what);
};
