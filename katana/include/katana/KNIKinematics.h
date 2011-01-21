/*
 * UOS-ROS packages - Robot Operating System code by the University of Osnabrück
 * Copyright (C) 2011  University of Osnabrück
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * KNIKinematics.h
 *
 *  Created on: 20.01.2011
 *      Author: Martin Günther
 */

#ifndef KNIKINEMATICS_H_
#define KNIKINEMATICS_H_

#include <ros/ros.h>
#include <ros/package.h>
#include <kinematics_msgs/GetKinematicSolverInfo.h>
#include <kinematics_msgs/GetPositionFK.h>
#include <kinematics_msgs/GetPositionIK.h>

#include <KNI_InvKin/ikBase.h>

#include <katana/KNIConverter.h>
#include <katana/EulerTransformationMatrices.hh>

namespace katana
{

static const size_t NUM_JOINTS = 5;


class KNIKinematics
{
public:
  KNIKinematics();
  virtual ~KNIKinematics();

private:
  ros::NodeHandle nh_;
  ros::ServiceServer get_kinematic_solver_info_server_;

  std::vector<std::string> joint_names_;

  CikBase ikBase_;
  KNIConverter* converter_;


  bool get_kinematic_solver_info(kinematics_msgs::GetKinematicSolverInfo::Request &req,
                                 kinematics_msgs::GetKinematicSolverInfo::Response &res);

  bool get_position_fk(kinematics_msgs::GetPositionFK::Request &req, kinematics_msgs::GetPositionFK::Response &res);

  std::vector<double> getCoordinates();
  std::vector<double> getCoordinates(std::vector<double> jointAngles);
};

}

#endif /* KNIKINEMATICS_H_ */
