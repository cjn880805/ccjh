// Container.h: interface for the CContainer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTAINER_H__DB7CBEE3_64B9_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_CONTAINER_H__DB7CBEE3_64B9_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CObject.h"
#include "Globle.h"

#ifdef _SQL_
#include <mysql/mysql.h>
#include <mysql/mysqld_error.h>

extern MYSQL mysql;
#endif

class CChar;

//容器类
class CContainer;

typedef void (* CALLOUTFUNC)(CContainer * me, LONG param1, LONG param2);
typedef CList< CContainer *, CContainer * > DTItemList;
void CopyList(DTItemList * dest, DTItemList * src);

class CContainer : public CMudObject  
{
public:
	virtual void destructed();

	int LockData(int locked);

	MAP2USER * GetUsers(const char * channel, MAP2USER * list);
	void evaluate_call_out_combat();
	void call_out_combat(CALLOUTFUNC pFunc, time_t delay, LONG param1 = 0, LONG param2 = 0);
	void Remove();
	int visible();
	virtual void ChangeRoom(CContainer * me);
	LONG object_id();
	virtual void setup();
	virtual int Load();
	virtual int Save();

	int _Save(CMapping * savedata);
	int _Load(CMapping * savedata);

	LONG icon(int raw = 0);
	const char * title(int raw = 0);
	virtual void relay_channel(CChar * me, const char * verb, const char * arg);
	virtual int do_look(CChar * me);
	const char * Short(int raw = 0);
	const char * Long(int raw = 0);

	int say(const char * msg, CChar * me = NULL, const char * tips = 0);
	void SendMenu(CChar * me);
	void AddMenuItem(string show, string cmd, CChar * me);

	virtual void owner_is_killed(CChar * killer);
	CContainer * present(const char * id, int flag = 0);
	int wear();
	int wield();
	virtual void init(CChar * me);
	void remove_call_out(CALLOUTFUNC pFunc, int evalute = 0);
	void call_out(CALLOUTFUNC pFunc, time_t delay, LONG param1 = 0, LONG param2 = 0);

	LONG weight();
	int over_encumbranced();

	CMapping * query_entire_dbase();
	CMapping * query_entire_temp_dbase();

	virtual int query_autoload();
	LONG query_encumb();
	void over_encumbrance();
	void add_encumbrance(LONG w);
	void set_max_encumbrance(LONG e);
	LONG query_max_encumbrance();

	virtual const char * hit_ob(CChar * me, CChar * victim, LONG damage_bonus);
	int is_character();
	virtual const char * Query_Short();
	virtual void set_amount(LONG nAmount);
	virtual LONG Query_Amount();
	virtual int handle_action(char *comm, CChar *me, char * arg);
	virtual int handle_action(char *comm, CChar *me, char * arg, char * tar);
	LONG Query_Weight();
	void set_weight(LONG nWeight);
	void UpdateMe();
	void Clean_Up();
	virtual void create(int nFlag = 0);
	virtual void GetInfo(char * str, CChar * me);
	virtual void DownLoad(CChar * me);
	void OnRemObject(CContainer * obj, CContainer * env);
	virtual void OnLeave(CContainer * me);
	void OnAddObject(CContainer * obj, CContainer * env);
	virtual void OnEnter(CContainer * me);
	CContainer * PresentName(const char * base_name, int nType, int flag = 0);
	virtual void SendCommand(const char * msg, int wait = 0);
	CContainer * Present(LONG nObj, int flag = 0);
	virtual void heart_beat();
	void set_heart_beat(int nFlag);
	virtual int Do_Action(int nAct, CChar * me = NULL);
	CContainer * environment();
	virtual int move(CContainer * pMe);
	DTItemList * Get_ItemList();

	virtual LONG Query(int nAttr);
	CContainer();
	virtual ~CContainer();

	//Action
	enum{
		DO_WIELD,
		DO_UNWIELD,
		DO_USE,
		DO_LIST,
		DO_TALK,
	};

protected:
	int _LockData(int lock);
		int LoadFromLocal(const char * fname, CMapping * save);
		int SaveToLocal(const char * filename, CMapping * save);


		LONG	m_lObjectID;
		LONG	max_encumb;				//最大容积
		LONG	encumb;					//当前容积
		LONG	m_lWeight;				//自身重量
		LONG	m_lUpdate;				//更新
	
		int m_bBeginMenu;

		DTItemList	m_ItemList;			//物件列表
		CContainer * m_pEnvironment;		//环境

		typedef struct{
			CALLOUTFUNC			pFunc;
			int					nType;		//函式类型:0:普通 1:战斗结束强制呼叫
			time_t				delay;
			LONG				param1;
			LONG				param2;
		}CALLOUTNODE;

		CList <CALLOUTNODE *, CALLOUTNODE *> m_CalloutList;		//延迟函式链表		
};

extern int		g_bDebug;

#endif // !defined(AFX_CONTAINER_H__DB7CBEE3_64B9_11D4_98AB_0050BABC5212__INCLUDED_)
