#ifndef IA32_H
#define IA32_H
#include <string>
using namespace std;
class IA32Nodes{
	public:
	virtual string printSelf()=0;
	virtual bool removable()=0;
};
#endif
