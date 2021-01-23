#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Tetrahedron
{
public:
	void Planes_equations();
	void Input_dots();
	vector<double> Centroid();
	void Inner_dot(double x, double y, double z);
private:
	vector<vector<double>> planes;
	vector<vector<double>> dots;
	vector<double> Plane(vector<double> a, vector<double> b, vector<double> c);
};
