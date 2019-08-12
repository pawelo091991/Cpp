#include "clock.h"

std::string date_independent::clock::at(int H, int M) {
	if (M < 0) {
		H -= M / 60;
		M = M % 60;
	}
	if (H < -24) {
		H = H % 24;
	}

	if (H < 0) {
		H = 24 - abs(H);
		H = abs(H);
	}



	if (M > 60) {
		H += M / 60;
		M = M % 60;
	}

	if (H > 24)
		H = H % 24;

	if (H == 24)
		H = 0;

	if (M == 60) {
		M = 0;
		H++;
	}

	std::stringstream ssH;
	std::stringstream ssM;
	ssH << H;
	std::string sH = ssH.str();
	ssM << M;
	std::string sM = ssM.str();

	if (H < 10)
		sH = "0" + sH;
	
	if (M < 10)
		sM = "0" + sM;

	std::string time = sH + ":" + sM;
	return time;
}