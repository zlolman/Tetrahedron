#pragma once
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Tetrahedron
{
public:
	void Planes_equations();
	void Input_dots();
	void Inner_dot(double x, double y, double z);
	void Sphere_Center();
private:
	vector<vector<double>> planes;
	vector<vector<double>> dots;
	vector<double> Plane(vector<double> a, vector<double> b, vector<double> c);
	vector<double> Areas();
	vector<double> Centroid();
};
