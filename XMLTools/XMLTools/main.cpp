
#include "tinyxml2.h"

#include "ParseXML.h"
#include "FileUtil.h"
#include "CreateFile.h"


#include <iostream>
#include <map>
#include <string>


using namespace std;
using namespace tinyxml2;

int main()
{
    XMLDocument xmlDocument;
    XMLError xmlError = xmlDocument.LoadFile("Class.xml");
    if (xmlError != XML_SUCCESS)
    {
        xmlDocument.PrintError();
        system("pause");
        return 0;
    }

    ParseXML parseXml;

    parseXml.Parse("Class.xml");

    const vector<ParseXML::Data>& vecData = parseXml.GetData();

    CreateFile createFile;
    for (unsigned int i = 0; i < vecData.size(); ++i)
    {
        if (!createFile.Create("template2.xml", vecData[i]))
        {
            break;
        }
    }

    system("pause");
    return 0;
}

