#ifndef JOINT
#define JOINT
#include <btBulletDynamicsCommon.h>
#include <string>
#include <vector>
#include "StlFile.h"

class Joint{
 public:
  std::string name;
  btTransform trans;
  btVector3 axis;
  /*Points represent the centers of spheres*/
  std::vector<btVector3> points;
  /*Radius of spheres*/
  float radius;
  StlFile mesh;
  Joint() 
    : name(""), trans(btTransform()), axis(btVector3()), 
    points(std::vector<btVector3>()), radius(0.0f), mesh(StlFile()) {};
  Joint(const Joint& orig)
    : name(orig.name), trans(orig.trans), axis(orig.axis),
    points(orig.points), radius(orig.radius), mesh(orig.mesh) {}
  Joint(std::string n, btTransform t, std::vector<btVector3> pts, 
        btVector3 a, float r)
    : name(n), trans(t), axis(a), points(pts), radius(r) {};
  Joint(std::string n, btTransform t, std::vector<btVector3> pts, 
        btVector3 a, float r, const char * filename)
    : name(n), trans(t), axis(a), points(pts), radius(r),mesh(StlFile(filename)) {};
  //~Joint();
};
#endif
