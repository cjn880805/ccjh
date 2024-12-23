// Npc.h: interface for the CNpc class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_NPC_H__C1831027_63A6_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_NPC_H__C1831027_63A6_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Char.h"

#define NPC_BEGIN(npc_name)		class npc_name : public CNpc	{	public:			npc_name(){};		virtual ~npc_name(){};	
#define NPC_END		};	

class CNpc : public CChar
{
public:
	virtual int accept_fight(CChar * me);
	int perform_action(char * magic, int target = 1);
	void random_move();
	virtual int recognize_apprentice(CChar * me);
	void add_money(LONG amount);
	virtual int accept_object(CChar * me, CContainer * item);
	virtual int do_talk(CChar * me, char * ask = NULL);
	CContainer * carry_object(const char * base_name, LONG nAmount = 1, int idx = 0);
	int return_home(CContainer * home);
	int Self_Action();
	
	virtual void create();
	virtual LONG Query(int nAttr);
	virtual char * chat_msg_combat();
	virtual char * chat_msg();

	CNpc()
	{
		set("grant", GRANT_NPC); 
	};
	virtual ~CNpc();

protected:
	void unwield_weapon(char * weapon);
	void wield_weapon(char * weapon);
	typedef char * (* INQUERYFUNC)(CNpc * this_object, CChar * this_player);

	typedef struct _tagInquiry
	{	
		string			topic;
		string			answer;
		INQUERYFUNC	pFunc;

	}Inquiry_t;

	typedef map<string, Inquiry_t *, less<string> > LISTINQUIRY;
	LISTINQUIRY m_listInquiry;

	virtual char * greeting(CChar * me);
	void set_inquiry(const char *msg, INQUERYFUNC pFunc, const char * topic = NULL);
	void set_inquiry(const char *ask, const char *answer, const char * topic = NULL);


friend class CNfighter_t;
};

#endif // !defined(AFX_NPC_H__C1831027_63A6_11D4_98AB_0050BABC5212__INCLUDED_)
