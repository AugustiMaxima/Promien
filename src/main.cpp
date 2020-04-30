#include "castIron.hpp"
#include "Harness.hpp"
using namespace Phrame;
#include <iostream>
using namespace std;
int main(){
	cout<<"Beginning"<<endl;
	castIron plate;
	cout<<"Beginning"<<endl;
	Harness harness;
	cout<<"Beginning"<<endl;
	return harness.assemble("settings.ini", "appManifest", &plate);
}
