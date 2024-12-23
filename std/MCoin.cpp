// MCoin.cpp: implementation of the CMCoin class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MCoin.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMCoin::CMCoin()
{

}

CMCoin::~CMCoin()
{

}

void CMCoin::create(int flag)
{
	set_name("½ð±Ò", "coin");
	set("base_value", 1);
	set("base_weight", 0l);
	set_amount(1);
}
