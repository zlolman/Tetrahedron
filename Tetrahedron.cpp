#pragma once
#include "Tetrahedron.h"

void Tetrahedron::Planes_equations()
{
	planes.push_back(Plane(dots[0], dots[1], dots[2]));
	planes.push_back(Plane(dots[1], dots[2], dots[3]));
	planes.push_back(Plane(dots[2], dots[3], dots[0]));
	planes.push_back(Plane(dots[3], dots[0], dots[1]));
	vector<double> centroid = Centroid();
	for (int i = 1; i < 4; i++)
	{
		if (((planes[i - 1][0] * centroid[0] + planes[i - 1][1] * centroid[1] + planes[i - 1][2] * centroid[2] + planes[i - 1][3]) *
			(planes[i][0] * centroid[0] + planes[i][1] * centroid[1] + planes[i][2] * centroid[2] + planes[i][3])) < 0)
		{
			for (int j = 0; j < 4; j++)
			{
				planes[i][j] = planes[i][j] * -1;
			}
		}
	}
}

void Tetrahedron::Input_dots()
{
	for (int i = 0; i < 4; i++)
	{
		double x, y, z;
		cout << "Enter " << i + 1 << " dot:";
		cin >> x >> y >> z;
		vector<double> dot = { x, y, z };
		dots.push_back(dot);
	}
}

vector<double> Tetrahedron::Centroid()
{
	double x = 0, y = 0, z = 0;
	for (int i = 0; i < 4; i++)
	{
		x = x + dots[i][0];
		y = y + dots[i][1];
		z = z + dots[i][2];
	};
	x = x / 4;
	y = y / 4;
	z = z / 4;
	vector<double> result = { x, y, z };
	return result;
}

void Tetrahedron::Inner_dot(double x, double y, double z)
{
	vector<double> dot_sign;
	for (int i = 0; i < 4; i++)
	{
		dot_sign.push_back(planes[i][0] * x + planes[i][1] * y + planes[i][2] * z + planes[i][3]);
	}
	if (((dot_sign[0] < 0) && (dot_sign[1] < 0) && (dot_sign[2] < 0) && (dot_sign[3] < 0))
		|| ((dot_sign[0] > 0) && (dot_sign[1] > 0) && (dot_sign[2] > 0) && (dot_sign[3] > 0)))
	{
		cout << "inside the figure\n";
	}
	else
	{
		cout << "not inside the figure\n";
	}
}

vector<double> Tetrahedron::Plane(vector<double> a, vector<double> b, vector<double> c)
{
	double a1 = b[0] - a[0];
	double b1 = b[1] - a[1];
	double c1 = b[2] - a[2];
	double a2 = c[0] - a[0];
	double b2 = c[1] - a[1];
	double c2 = c[2] - a[2];
	double A = b1 * c2 - b2 * c1;
	double B = a2 * c1 - a1 * c2;
	double C = a1 * b2 - b1 * a2;
	double D = (-A * a[0] - B * a[1] - C * a[2]);
	vector<double> result = { A, B, C, D };
	return result;
};

vector<double> Tetrahedron::Areas()
{	
	vector<double> areas;
	for (int i = 0; i < 4; i++) 
	{
		vector<double> vec1;
		vector<double> vec2;
		for (int j = 0; j < 3; j++)
		{
			vec1.push_back(dots[(i + 1) % 4][j] - dots[i][j]);
			vec2.push_back(dots[(i + 2) % 4][j] - dots[i][j]);
		};
		double a = vec1[1] * vec2[2] - vec1[2] * vec2[1];
		double b = vec1[0] * vec2[2] - vec1[2] * vec2[0];
		double c = vec1[0] * vec2[1] - vec1[1] * vec2[0];
		double area = sqrt(a * a + b * b + c * c) / 2;
		areas.push_back(area);		
	}
	return areas;
}

void Tetrahedron::Sphere_Center() 
{
	vector<double> areas = Areas();
	double x = 0, y = 0, z = 0;
	x = (dots[0][0] * areas[1] + dots[1][0] * areas[2] + dots[2][0] * areas[3] + dots[3][0] * areas[0]) / (areas[0] + areas[1] + areas[2] + areas[3]);
	y = (dots[0][1] * areas[1] + dots[1][1] * areas[2] + dots[2][1] * areas[3] + dots[3][1] * areas[0]) / (areas[0] + areas[1] + areas[2] + areas[3]);
	z = (dots[0][2] * areas[1] + dots[1][2] * areas[2] + dots[2][2] * areas[3] + dots[3][2] * areas[0]) / (areas[0] + areas[1] + areas[2] + areas[3]);
	cout << "Sphere center {" << x << "; " << y << "; " << z << "}";
}