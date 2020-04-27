#include "Harness.hpp"
#include "Plate.hpp"
using namespace Phrame;

int main(){
	Harness harness{};
	Plate plate{harness};
	return plate.assemble("settings.ini", "appManifest");
}
