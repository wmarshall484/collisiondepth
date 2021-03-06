#ifndef STLFILE
#define STLFILE
#include <vector>
#include <stdio.h>

using namespace std;

struct Point {
  float xyz[3];
  Point(){}
  Point(float *pts){
    xyz[0]=(*(pts)); xyz[1]=(*(pts+1)); xyz[2]=(*(pts+2));
  }
  Point(float a, float b, float c){
    xyz[0]=a; xyz[1]=b;xyz[2]=c;
  }

};

struct Triangle {
  Point pts[3];
  Triangle(Point a, Point b, Point c){ 
    pts[0]=a; pts[1]=b; pts[2]=c;
  }
};

class StlFile {
 public:
  void * header;
  unsigned int numTriangles;
  vector<Point> normals;
  vector<Triangle> triangles;
  
  StlFile();
  StlFile(const char * filename);
  StlFile(const StlFile * stl);
  ~StlFile();
  void ReadFile(const char *filename);
  void StlReadFile(const char *filename);
  void DaeReadFile(const char *filename);
 private:
  void StlReadBinaryFile(const char * filename);
  void StlReadAsciiFile(const char * filename);
};

#endif
