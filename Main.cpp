#include <iostream>
#include <Windows.h>
#include "Integrator.h"
#include "Step.h"
#include <vector>
#include "graph.h"
#include "Gain.h"
#include "NV.h"

using namespace std;

int main()
{
	plot p;
	float nv_count = 0;
	float x_value = 1;
	float y_value = 1;
	Integrator x_calka(70);   // poczatkowa pozycja robota
	Integrator y_calka(-400);
	vector<float> x, y;
	vector<float> nv_output;
	vector<float> nv_input;
	nv_input.push_back(-80);
	nv_input.push_back(-80);
	do
	{
		nv_count += 1;
		nv_output = NV(nv_input);
		if (nv_count == 1)
		{
			nv_count = 0;
			x_value = x_calka.integrate(1000 * nv_output[0]);
			y_value = y_calka.integrate(1000 * nv_output[1]);

			x.push_back(x_value); //dodanie wartoœci count do wektora argumentów
			y.push_back(y_value); //dodanie wartoœæi value do wektora wartoœci

			nv_input[0] = x_value;
			nv_input[1] = y_value;

			//p.plot_data(x, y); //wyrysowanie real-time wykresu

			cout << x_value << " " << y_value << endl;

			//Sleep(1);
		}
	} while ((abs(x_value) > 0.1 || abs(y_value) > 0.1));
	p.plot_data(x, y);
	cin.get(); 
	return 0; 
}
