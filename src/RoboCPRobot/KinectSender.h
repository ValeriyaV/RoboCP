#pragma once
#include "SenderBase.h"
#include "KinectData.h"
#include "KinectBuffer.h"
#include "XMLConfig.h"
#include <boost/asio.hpp>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>
#include <boost/interprocess/sync/interprocess_semaphore.hpp>
#include "pcl/compression/octree_pointcloud_compression.h"

#define GLOG_NO_ABBREVIATED_SEVERITIES
#include <glog/logging.h>
#include <glog/raw_logging.h>

using boost::asio::ip::tcp;
using namespace pcl;
using namespace pcl::octree;
using namespace std;

//Class purpose: taking KinectData object from buffer and sending it via TCP-IP
class KinectSender :
  public SenderBase
{
public:
  void Start();
  KinectSender(XMLConfig * x, KinectBuffer * buf);
  ~KinectSender(void);
private:
  PointCloudCompression<PointXYZ>* octreeCoder;
  KinectBuffer * buffer;
  int port;
};

