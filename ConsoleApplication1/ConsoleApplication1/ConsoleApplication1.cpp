// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <occi.h>
using namespace oracle::occi;
using namespace std;
class occidml
{
private:
	Environment *env;
	Connection *conn;
	Statement *stmt;

public:
	occidml(string user, string passwd, string db)
	{
		env = Environment::createEnvironment(Environment::DEFAULT);
		conn = env->createConnection(user, passwd, db);


	}
	occidml()
	{
		env->terminateConnection(conn);
		Environment::terminateEnvironment(env);
	}

	void displayAllRows()
	{
		string sqlStmt = "SELECT SOURCE_ID,BATCH_ID FROM CIA.CP_DATA_BATCH";
		stmt = conn->createStatement(sqlStmt);
		ResultSet *rset = stmt->executeQuery();
		try {
			while (rset->next())
			{
				cout << "Source: " << rset->getString(1) << "  Batch: "
					<< rset->getString(2) << endl;
			}
		}
		catch (SQLException ex)
		{
			cout << "Exception thrown for displayAllRows" << endl;
			cout << "Error number: " << ex.getErrorCode() << endl;
			cout << ex.getMessage() << endl;
		}
		catch (exception e)
		{
			
		}
		stmt->closeResultSet(rset);
		conn->terminateStatement(stmt);
	}

};
int main()
{
	string user = "GDEVARAJ";
	string passwd = "password5Ganesh";
	string db = "PURSTEST";
	string input;
	cout << "occidml - Exhibiting simple insert, delete & update operations"
		<< endl;
	occidml *demo = new occidml(user, passwd, db);

	cout << "Displaying all records before any operation" << endl;
	demo->displayAllRows();
	delete(demo);
	cout << "occidml - done" << endl;
	cin >> input;
    return 0;
}

