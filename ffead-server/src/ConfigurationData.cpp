/*
	Copyright 2009-2012, Sumeet Chhetri

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/
/*
 * ConfiguartionData.cpp
 *
 *  Created on: 19-Jun-2012
 *      Author: sumeetc
 */

#include "ConfigurationData.h"

ConfigurationData::ConfigurationData() {
	// TODO Auto-generated constructor stub

}

ConfigurationData::~ConfigurationData() {
	// TODO Auto-generated destructor stub
}

Security::Security()
{
	logger = Logger::getLogger("Security");
}

Security::~Security()
{

}

SecureAspect Security::matchesPath(string url)
{
	bool pathval = false;
	SecureAspect aspect;
	for (int var = 0; var < (int)secures.size(); ++var) {
		SecureAspect secureAspect = secures.at(var);
		string pathurl = secureAspect.path;
		logger << ("Checking security path " + pathurl + " against url " + url) << endl;
		if(pathurl=="*")
		{
			aspect = secureAspect;
			continue;
		}
		if(pathurl.find("*")==pathurl.length()-1)
		{
			pathurl = pathurl.substr(0, pathurl.length()-1);
			pathval = true;
		}
		if(pathval && url.find(pathurl)!=string::npos)
		{
			aspect = secureAspect;
		}
		else if(!pathval && pathurl==url)
		{
			aspect = secureAspect;
		}
	}
	return aspect;
}
