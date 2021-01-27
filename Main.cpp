#pragma once
#include "Tetrahedron.h"

int main()
{
	Tetrahedron tetra;
	tetra.Input_dots();
	tetra.Planes_equations();
	double x, y, z;
	cout << "Input dot: ";
	cin >> x >> y >> z;
	tetra.Inner_dot(x, y, z);
	tetra.Sphere_Center();
    return 0;
}
