/*
 *    Copyright (C) 2015 by YOUR NAME HERE
 *
 *    This file is part of RoboComp
 *
 *    RoboComp is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    RoboComp is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with RoboComp.  If not, see <http://www.gnu.org/licenses/>.
 */

/**
       \brief
       @author authorname
*/

#ifndef SPECIFICWORKER_H
#define SPECIFICWORKER_H

#include <genericworker.h>
#include <innermodel/innermodel.h>
#include <innermodel/innermodelviewer.h>
#include <osgviewer/osgview.h>
#include <stdio.h>
#include "plane_filtering.h"


class SpecificWorker : public GenericWorker
{
Q_OBJECT
public:
	SpecificWorker(MapPrx& mprx);	
	~SpecificWorker();
	bool setParams(RoboCompCommonBehavior::ParameterList params);
	RoboCompRGBD::PointSeq getFilteredPoints();

public slots:
	void compute(); 	

private:
	InnerModel *innerModel;
	InnerModelViewer *innerModelViewer;
	OsgView 			*osgView;			
	IMVPointCloud *imvPointCloud;
	
	void loadLines();
	void updatePointCloud(const PointSeq &points);	
	void updatePointCloud2( const vector< vector3f > &points,vector< PlanePolygon > polygons);
	bool addPlane_notExisting(InnerModelViewer *innerViewer, const QString &item, const QString &base, const QVec &p, const QVec &n, const QString &texture, const QVec &size);
	bool removeNode(InnerModelViewer *innerViewer, const QString &item);
	PlaneFilter *planeFilter;
	RoboCompRGBD::PointSeq points;
	

};

#endif

