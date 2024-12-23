// MGold.cpp: implementation of the CMGold class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MGold.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMGold::CMGold()
{

}

CMGold::~CMGold()
{

}

void CMGold::create(int flag)
{
	set_name("½ð±Ò", "gold");
	set("base_value", 10000);
	set("base_weight", 37);
	set_amount(1);
}
