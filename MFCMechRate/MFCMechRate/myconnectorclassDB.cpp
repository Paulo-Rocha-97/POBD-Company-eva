#include "stdafx.h"
#include "myconnectorclassDB.h"

CString message;

void myconnectorclassDB::connect()
{
connection = mysql_init(NULL); //Initialise the instance
connection = mysql_real_connect(connection, SERVER,
USER, PASSWORD, DATABASE, 0, NULL, 0);
// The command mysql_real_connect is included in the
// libraries
if (connection==NULL){
	message.Format(_T("Unable to connect!"));
	AfxMessageBox(message);

}
else {
	message.Format(_T("Connection successful!"));
	AfxMessageBox(message);
}
}

CString myconnectorclassDB::CheckCity(CString company)
{
	CString value; // Create the object to receive the answer to the query
	CString query = _T("SELECT company.city FROM company WHERE company.company_name = '") + company + _T("'");
	//Create a query by combining CStrings, including an
	//input CString
	Query(query); // Pass the query. The result will be
	//stored in the result object.
	while ((row = mysql_fetch_row(result)) != NULL)
	// Method to fetch rows from result
	{
	value = CPtoUnicode(row[0], 1251);
	}
	return value;
}

void myconnectorclassDB::Query(CString query)
{
	wchar_t *p = query.GetBuffer();
	char bufUTF8[MAX_PATH];
	WideCharToMultiByte(CP_UTF8, 0, p, -1, bufUTF8,
	sizeof(bufUTF8), NULL, NULL);
	/* MySQL uses a different character set from MFC's in
	VS. A weird conversion has to be done. The good newis
	you only have to copy and paste this code once. */
	mysql_query(connection, bufUTF8); // Send a query
	result = mysql_store_result(connection); // Store the result
}

CString myconnectorclassDB::CPtoUnicode(const char* CPString, UINT CodePage)
{
	CString retValue;
	int len = MultiByteToWideChar(CodePage, 0, CPString, -1, NULL, 0);
	if (len == 0) {return retValue;}
	LPWSTR buffer = retValue.GetBuffer(len);
	MultiByteToWideChar(CodePage, 0, CPString, -1, buffer, len);
	retValue.ReleaseBuffer();
	return retValue;
}

myconnectorclassDB::myconnectorclassDB(void)
{
}


myconnectorclassDB::~myconnectorclassDB(void)
{
}
