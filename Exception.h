#pragma once

class Exception
{
private:
	char* m_pStrName;
	int m_nLine;
	char* m_pFileName;
public:
	Exception(char* name, int line,char*filename);
	virtual ~Exception();

public:
	char* GetName();
	int GetLine();
	char* GetFileName();
};