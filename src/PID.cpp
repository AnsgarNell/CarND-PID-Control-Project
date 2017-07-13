#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
	this->Kp = Kp;
	this->Ki = Ki;
	this->Kd = Kd;
	cte = 0;
	diff_cte = 0;
	prev_cte = 0;
	int_cte = 0;
	p_error = 0;
	i_error = 0;
	d_error = 0;
	dp = {1,1,1};
}

void PID::UpdateError(double cte) {
	this->cte = cte;
	diff_cte = cte - prev_cte;
	prev_cte = cte;
	int_cte = int_cte + cte;
}

double PID::TotalError() {
	return - Kp * cte - Kd * diff_cte - Ki * int_cte;
}

double PID::TotalError(double speed) {
	double rate;
	if(speed > 10)
		rate = speed/100.0;
	else
		rate = 1.0;
	return (- Kp * cte - Kd * diff_cte - Ki * int_cte) / rate;
}

