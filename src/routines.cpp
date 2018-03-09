/*
 *  routines.cpp
 *
 *  Created on: Mar 8, 2018
 *  Author: lkang
 */

#include "routines.h"

namespace Routines {
/* for-loop tests
  for (int i = 0; i < 11; i++) {
    string input = "testcases/geometry/test_polygon_polygon_" + to_string(i) + ".txt";
    geometryRoutine("polygon-polygon", input);
  }
*/
void pointInPolygonRoutine(const string &address) {
    vector<Point> polygon;
    vector<Point> points;
    FileIO::loadPointPolygonTestCase(address, polygon, points);  // load test cases
    for (int i = 0; i < points.size(); i++) {
        Geometry::isInside(polygon, Point(points[i].x, points[i].y))? cout << "Yes \n": cout << "No \n";
    }
}

void polygonOverlapRoutine(const string &address) {
    vector<Point> polygon1;
    vector<Point> polygon2;
    FileIO::loadPointPolygonTestCase(address, polygon1, polygon2);  // load test cases
    Geometry::hasOverlap(polygon1, polygon2)? cout << "Yes \n": cout << "No \n"; 
}

void convexHullRoutine(const string& directory) {
   string address = directory;
   vector<Point> points, result;
   FileIO::loadConvexHullFile(address, points);  // load test cases
   // FileIO::loadConvexHullFile(address, result);  // load result file 
   vector<Point> hull = Geometry::convexHull(points);
}

void cascadeRoutine(const string &folder) {
  vector<string> fileNameList = utility::GetFileName(folder);
  int cnt = 0;
  /* Advanced method (cascade) to detect objects */
  string model = utility::GetCurrentWorkingDir() + "/params/cascade.xml";
  for (int i = 0; i < (int)fileNameList.size(); i++){
    cout<<fileNameList[i]<<endl;
    string file = fileNameList[i];
    cnt += ObjectDetection::detectObjCascade(model, folder, file);
  }
  cout<< cnt << " objects are detected in "<<fileNameList.size()<<" files"<<endl;
}

void processVideo() {
  VideoCapture cap("/home/lkang/Desktop/video.h264"); // open the default camera
  string output{"/home/lkang/Desktop/images/"};
  if(!cap.isOpened()) { // check if we succeeded
    cout<<"not able to open"<<endl;
    return;
  }
  Mat gray;
  for (;;) {
    Mat frame;
    cap >> frame; // get a new frame from camera
    if(frame.empty()) break;

    // int num = processImage(frame, gray);
    // imshow("gray", frame);
    // waitKey(0);
    // sleep(1);
    // cv::imwrite(output + to_string(counter) + ".png", frame);
  }
}

}
