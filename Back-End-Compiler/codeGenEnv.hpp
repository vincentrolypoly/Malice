
#include <string>
#include <map>

using namespace std;


class codeGenEnv{
	private:
		codeGenEnv* enclosingEnv;
		map<string, string>* currentEnv;
		map<string, int>* currentEnvOffset;
		string scopeLabel;
		int scopeLevel;
		int varCount;
	public:
		codeGenEnv(codeGenEnv* enc);
		void add(string name, string address, int offset);
		int getEnclosingScopeLevel(string name);
   		string searchCurrentForBase(string name);
    	string searchEnclosingForBase(string name);
		int searchCurrentForOffset(string name);
		int searchEnclosingForOffset(string name);
		void setScopeLabel(string label);
		string getScopeLabel();
		string getEnclosingLabel(string name);
		string getPrevScopeLabel();
		int getScopeLevel();
		void incVarCount();
		int getVarCount();
		codeGenEnv* getPrevScope();
};
		

