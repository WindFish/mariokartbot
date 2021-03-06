/*
 * util.cpp
 * 
 * Copyright 2012 Florian Jung <florian.a.jung@web.de>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License Version 3
 * as published by the Free Software Foundation.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 */


#include "util.h"

float flopow(float b, float e)
{
	return (b>=0.0) ? (powf(b,e)) : (-powf(-b,e));
}

Mat circle_mat(int radius)
{
  Mat result(radius*2+1, radius*2+1, CV_8U);
  for (int x=0; x<=result.cols/2; x++)
    for (int y=0; y<=result.rows/2; y++)
    {
      unsigned char& p1 = result.at<unsigned char>(result.cols/2 + x, result.rows/2 + y);
      unsigned char& p2 = result.at<unsigned char>(result.cols/2 - x, result.rows/2 + y);
      unsigned char& p3 = result.at<unsigned char>(result.cols/2 + x, result.rows/2 - y);
      unsigned char& p4 = result.at<unsigned char>(result.cols/2 - x, result.rows/2 - y);
      
      if ( x*x + y*y < radius*radius )
        p1=p2=p3=p4=255;
      else
        p1=p2=p3=p4=0;
    }
    
  return result;
}

