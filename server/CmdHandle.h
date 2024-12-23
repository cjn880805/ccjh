// CmdHandle.h: interface for the CCmdHandle class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CMDHANDLE_H__1B1EAB42_67C5_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_CMDHANDLE_H__1B1EAB42_67C5_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "User.h"

#define DEFINECMD(cmd) static int cmd(CChar * me, LONG target, char * arg)
#define STANDARDCMD(cmd) CCmdStandard::cmd(me, nTarget, arg);
#define USERCMD(cmd) CCmdUser::cmd(me, nTarget, arg);
#define WIZARDCMD(cmd) CCmdWizard::cmd(me, nTarget, arg);

//√¸¡Ó¥¶¿Ì
class CCmdHandle   
{
public:
	int command(char * Comm, CChar * me);
	CCmdHandle();
	virtual ~CCmdHandle();

protected:
	static void do_revive(CContainer * ob, LONG param1, LONG param2);
	static void do_kick(CContainer * me, LONG param1, LONG param2);
	int Handlecommand(char * cmd, CChar * me, LONG target, char * arg);
};

#endif // !defined(AFX_CMDHANDLE_H__1B1EAB42_67C5_11D4_98AB_0050BABC5212__INCLUDED_)


