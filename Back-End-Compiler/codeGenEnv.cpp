
#include "codeGenEnv.hpp"

#include <sstream>

typedef pair<string, string> objectPair;
typedef pair<string, int> offsetPair;
codeGenEnv::codeGenEnv(codeGenEnv *est)
{       
    enclosingEnv = est;
	currentEnv = new map<string, string>();
	currentEnvOffset = new map<string, int>();
	if (est	!=	NULL){
		scopeLevel = est->getScopeLevel()+1;
	}else{
		scopeLevel = 0;
	}
	varCount = 0;
}

void codeGenEnv::setScopeLabel(string label){
	stringstream ss;
	ss << scopeLevel;
	
	scopeLabel = label + "_" + ss.str() + "_rbp";
}
codeGenEnv* codeGenEnv::getPrevScope(){
	return enclosingEnv;
}
void codeGenEnv::incVarCount(){
	varCount++;
}
int codeGenEnv::getVarCount(){
	return varCount;
}
string codeGenEnv::getScopeLabel(){
	return scopeLabel;
}
int codeGenEnv::getScopeLevel(){
	return scopeLevel;
}
int codeGenEnv::getEnclosingScopeLevel(string name){
	string searchItem;
    codeGenEnv *curr = this;
    
    while(curr != NULL)
    {	          
		 searchItem = curr->searchCurrentForBase(name);
         if(searchItem == name)
        {
            return curr->getScopeLevel();
        }

        curr = curr->enclosingEnv;
    }
    
    return NULL;
}
string codeGenEnv::getPrevScopeLabel(){
	if(enclosingEnv == NULL){
		return getScopeLabel();
	}
	return enclosingEnv->getScopeLabel();
}
string codeGenEnv::getEnclosingLabel(string name){
	string searchItem;
    codeGenEnv *curr = this;
    
    while(curr != NULL)
    {	          
		 searchItem = curr->searchCurrentForBase(name);
         if(searchItem == name)
        {
            return curr->getScopeLabel();
        }

        curr = curr->enclosingEnv;
    }
    
    return NULL;
}
void codeGenEnv::add(string name, string baseAddress,int offset)
{
    currentEnv->insert(objectPair(name, baseAddress));
	currentEnvOffset->insert(offsetPair(name,offset));
}
int codeGenEnv::searchCurrentForOffset(string name){
	int searchItem;
 	map<string,int>::iterator it;
	it = (currentEnvOffset->find(name));
	if(it == currentEnvOffset->end()){
		return NULL;
	}
	searchItem = it->second;
    return searchItem;
}
int codeGenEnv::searchEnclosingForOffset(string name){
	int searchItem;
    codeGenEnv *curr = this;
    
    while(curr != NULL)
    {	          
		 searchItem = curr->searchCurrentForOffset(name);
         if(searchItem != NULL)
        {
            return searchItem;
        }

        curr = curr->enclosingEnv;
    }
    
    return searchItem;
}
string codeGenEnv::searchCurrentForBase(string name)
{
    string searchItem;
 	map<string,string>::iterator it;
	it = (currentEnv->find(name));
	if(it == currentEnv->end()){
		return "";
	}
	searchItem = it->second;
    return searchItem;
}

string codeGenEnv::searchEnclosingForBase(string name)
{
    string searchItem;
    codeGenEnv *curr = this;
    
    while(curr != NULL)
    {	          
		 searchItem = curr->searchCurrentForBase(name);
         if(searchItem != "")
        {
            return searchItem;
        }

        curr = curr->enclosingEnv;
    }
    
    return searchItem;
}
