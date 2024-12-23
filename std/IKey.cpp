// IKey_Baoxian.cpp: implementation of the CIKey_Baoxian class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "IKey.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CIKey::CIKey()
{

}

CIKey::~CIKey()
{

}

void CIKey::create(int flag)
{
	set_name("Ô¿³×", "key");
	set("value", 100);
	set_weight(200);
}
