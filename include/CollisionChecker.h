#ifndef COLLISIONCHECKER_H
#define COLLISIONCHECKER_H
#include "Model.h"
#include "DepthMap.h"
#include "body_pose.h"
#include <btBulletDynamicsCommon.h>

class CollisionChecker {
private:
  std::vector<const ModelTree*> models;
  std::vector<const DepthMap*> depthMaps;
  int numSpheres;
  int numJoints;
  std::vector<int> langleRemap;
  std::vector<int> rangleRemap;
  void init(const int, const ModelTree*);

  // Some structures we don't want to reallocate every iteration
  std::vector<float> myJointAngles;
  std::vector<bool> myCollisions;

  struct Stats {
    int modelNumber;
    int numChecks;
    int numViews;
    double preprocessingTime;
  } stats;
public:
  CollisionChecker(const ModelTree*);
  CollisionChecker(const int, const ModelTree*);
  void addDepthMap(const DepthMap*);
  const DepthMap* getDepthMap(int i);
  const DepthMap* getActiveDepthMap();
  int numDepthMaps() const;
  void makeJointVector(const std::map<std::string,float>&,
                       std::vector<float>&);
  void makeJointMap(const std::vector<float>&,
                    std::map<std::string,float>&);
  void makeCollisionMap(const std::vector<bool>&,
                        std::map<std::string,bool>&);
  bool isColliding(const btTransform& camera,
                   const float sphereRadius, 
                   const std::vector<float>&);
  void getCollisionInfo(const btTransform& camera,
                        const float sphereRadius,
                        const std::vector<float>&, 
                        std::vector<bool>&);
  void getCollisionInfoReference(const btTransform& camera,
                                 const float sphereRadius,
                                 const std::map<std::string,float>&, 
                                 std::map<std::string,bool>&);

  // SBPL-compatibility API
  bool checkCollision(std::vector<double> &langles, 
                      std::vector<double> &rangles, 
                      BodyPose &pose, 
                      bool verbose, 
                      unsigned char &dist, 
                      int &debug_code);
  void getCollisionSpheres(std::vector<double> &langles,
                           std::vector<double> &rangles,
                           BodyPose &pose,
                           std::string group_name,
                           std::vector<std::vector<double> > &spheres);
  void remapJointVector(const std::vector<double>& langles,
                        const std::vector<double>& rangles,
                        const BodyPose& pose,
                        std::vector<float>& jointAngles,
                        btTransform& bodyFrame) const;
  void levineInit();
  vector<float> getDepthPoses();

  void resetStats();
  void getStats(std::vector<std::string>& fieldNames, 
                std::vector<double>& fieldValues);
};
#endif
