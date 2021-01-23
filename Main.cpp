#pragma once
#include "Tetrahedron.h"

int main()
{
	Tetrahedron tetra;
	tetra.Input_dots();
	tetra.Planes_equations();
	vector<double> centr = tetra.Centroid();
	cout << "Centroid {" << centr[0] << ", " << centr[1] << ", " << centr[2] << "}\n";
	double x, y, z;
	cout << "Input dot: ";
	cin >> x >> y >> z;
	tetra.Inner_dot(x, y, z);
    return 0;
}
