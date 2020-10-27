/*
 * animaly_detection_util.cpp
 *
 * Author: write your ID and name here
 */

#include <math.h>
#include "anomaly_detection_util.h"

/**
 * @brief 
 * 
 * @param x 
 * @param size 
 * @return float 
 */
float avg(float* x, int size){
	float sum = 0;
	for (int i = 0; i < size; i++) {
		sum += x[i];
	}
	
	return sum / size;
}

// returns the variance of X and Y
/**
 * @brief 
 * 
 * @param x 
 * @param size 
 * @return float 
 */
float var(float* x, int size){
	float sum = 0, average = avg(x, size);
	average *= average;
	for (int i = 0; i < size; i++) {
		sum += pow(x[i], 2.0);
	}
	
	return sum / size - average;
}

// returns the covariance of X and Y
/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param size 
 * @return float 
 */
float cov(float* x, float* y, int size){
	float sum = 0, aveargeX = avg(x, size), aveargeY = avg(y, size); 
	for (int i = 0; i < size; i++) {
		sum += (x[i] - aveargeX) * (y[i] - aveargeY);
	}
	return sum / size;
}


// returnsthe Pearson correlation coefficient of X and Y
/**
 * @brief 
 * 
 * @param x 
 * @param y 
 * @param size 
 * @return float 
 */
float pearson(float* x, float* y, int size){
	float rootX = sqrt(var(x, size)), rootY = sqrt(var(y, size));
	float tempo = cov(x, y, size);
	return tempo / (rootX * rootY);
}

// performs a linear regression and returns the line equation
/**
 * @brief 
 * 
 * @param points 
 * @param size 
 * @return Line 
 */
Line linear_reg(Point** points, int size){
	float a = 0, b = 0;
	float *x = new float[size];
	float *y = new float[size];
	for (int i = 0; i < size; i++) {
		x[i] = points[i]->x;
		y[i] = points[i]->y;
	}
	a = cov(x, y, size) / var(x , size);
	b = avg(y, size) - a * avg(x, size);
	return Line(a, b);
}

// returns the deviation between point p and the line equation of the points

/**
 * @brief 
 * 
 * @param p 
 * @param points 
 * @param size 
 * @return float 
 */
float dev(Point p, Point** points, int size){
	Line line = linear_reg(points, size);
	float fx = line.a * p.x + line.b;
	return fabs(fx - p.y);
}

// returns the deviation between point p and the line
/**
 * @brief 
 * 
 * @param p 
 * @param l 
 * @return float 
 */
float dev(Point p,Line l){
	float fx = l.a * p.x + l.b;
	return fabs(fx - p.y);
}
