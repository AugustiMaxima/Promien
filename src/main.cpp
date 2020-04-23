#include "harness.hpp"
#include "plate.hpp"
using namespace phrame;

int main(){
	Harness harness{};
	Plate plate{harness};
	return plate.assemble("settings.ini", "appManifest");
}
