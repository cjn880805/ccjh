// MSilver.cpp: implementation of the CMSilver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MSilver.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMSilver::CMSilver()
{

}

CMSilver::~CMSilver()
{

}

void CMSilver::create(int flag)
{
	set_name("Òø±Ò", "silver");
	set("base_value", 100);
	set("base_weight", 37);
	set_amount(1);
}
