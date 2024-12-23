// Container.cpp: implementation of the CContainer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Container.h"
#include "Room.h"
#include "User.h"
#include "Item.h"
#include "Npc.h"
#include "CmdHandle.h"
#include "../std/FightRoom.h"
#include "Channel.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
int		g_bDebug = 0;
void Set_Heart_Beat(CContainer * obj, int nFlag);

LONG	g_ObjectID = 1;							//房间，物品，NPC，玩家等物件的统一编号。

CContainer::CContainer()
{
	m_pEnvironment = NULL;
	m_lObjectID = g_ObjectID ++;
	m_lWeight = max_encumb = encumb = 0;
	m_lUpdate = 1;
	m_bBeginMenu = 1;
}

CContainer::~CContainer()	//环境毁灭，物品毁灭，但玩家将落入外部空间
{
	//毁灭延迟函式
	POSITION p;
	CALLOUTNODE * pNode;

	p = m_CalloutList.GetHeadPosition();
	while(p)
	{
		pNode = m_CalloutList.GetNext(p);
		delete pNode;
	}

	m_CalloutList.RemoveAll();
}

LONG CContainer::Query(int nAttr)
{
	switch(nAttr)
	{
	case IS_CONTAINER:
		return 1;
	case UPDATE:
		return m_lUpdate;
	}
	return CMudObject::Query(nAttr);
}

//从一个容器移动到另一个容器。
//此间有一个很复杂的通讯指令
int CContainer::move(CContainer * pMe)
{
	CContainer * env;

	char env_old[40] = "(NULL)";
	char env_new[40] = "(NULL)";
	if(environment()) strncpy(env_old, environment()->name(1), 30)[30] = 0;
	if(pMe) snprintf(env_new, 40, "%s(%s)", pMe->name(1), pMe->id(1));
	
	if(query("value") >= 500000 && userp(pMe))
	{		
		char msg[255];
		char color[10];

		color[0] = 0;
		if(query("value") >= 5000000)
			strcpy(color, "$HIR");

		g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s价值%ld的%s从%s移动到%s。", color, query("value"), name(1), env_old, env_new));
		output_error(msg);
	}
	//output_error("MOVE: #OBJ=%ld, NAME=%s, %s -> %s", object_id(), name(), env_old, env_new);
	

	if( query("equipped") && ! Do_Action(DO_UNWIELD) )
	{
		output_error("物件%s移入失败：解除装备失败。", name());
		//return 0;
	}

	//向NULL和标准房间中移动必须成功，否则在销毁物件时，会出现内存访问错误。
	if(pMe)
	{
		/*
		if( pMe->Query(IS_ITEM) && ! pMe->Query(INFINITY) && t->GetCount() >= pMe->Query(MAX_ITEMS) )
		{
			ERROROUT((tmp, "物件%s移入%s失败：太拥挤了。\n", name(), pMe->name()));
			return 0;			//已经太拥挤了
		}
		*/

		if(pMe == this)
			return 0;			//不能自己放自己

		env = this;
		while((env = env->environment())) if( env==pMe ) break;

		if( !env )
		{
			 if( ! pMe->query("infinity") && pMe->query_encumb() + weight() > pMe->query_max_encumbrance() )
			 {
				output_error("物件%s移入%s失败：太重了。重：%ld 负重: %ld / %ld", name(), pMe->name(),
				weight(), pMe->query_encumb(), pMe->query_max_encumbrance() );
				//为了预防玩家不停的移动造成复制，在移动失败后强制忙乱
				//秦波 2004、10、9
				if(userp(pMe))
					((CChar *)pMe)->start_busy(4);
				return 0;			//太重了。
			 }
		}
	}

	//Move_Object:
	if( m_pEnvironment )
	{
		m_pEnvironment->OnLeave(this);
		m_pEnvironment = NULL;
	}

	if(pMe)		//进入新环境 
	{
		m_pEnvironment = pMe;
		
		//对于移动者本身而言，是切换场景
		pMe->ChangeRoom(this);
		
		//未切换场景直接进入
		if(! query_temp("client/loading"))
			pMe->OnEnter(this);
	}
	else
		m_pEnvironment = NULL;

	return 1;
}

DTItemList * CContainer::Get_ItemList()
{
	return & m_ItemList;
}

void CContainer::heart_beat()
{
	POSITION prep, p;
	//执行延迟函式
	CALLOUTNODE * pNode;
	LONG object_id = m_lObjectID;

	p = m_CalloutList.GetHeadPosition();
	while(p)
	{
		prep = p;
		pNode = m_CalloutList.GetNext(p);

		if(pNode->nType == 1 && ! pNode->delay) continue;		//1.72 版增加。delay为0的表示无限长时间，战斗结束时呼叫 lanwood 2001-03-26

		if( -- pNode->delay > 0) continue;

		if(g_bDebug) output_error("%s call_out!", name(1));

		//执行
		if(pNode->pFunc)
			(* pNode->pFunc)(this, pNode->param1, pNode->param2);

		//判断本物件是否在函式中销毁
		if(g_LastDestructObject == object_id) return;

		if(g_bDebug) output_error(">>");
		//此句放后面。如果销毁了，就不能执行了！！ lanwood 2001-03-30

		m_CalloutList.RemoveAt(prep);	//此句改在后面，否则内存泄露。
		delete pNode;		
	}
}

CContainer * CContainer::environment()
{
	return m_pEnvironment;
}

void CContainer::set_weight(LONG nValue)
{
	if( !environment() ) 
 	{
 		m_lWeight = nValue;
		return;
 	}

	if( nValue != m_lWeight )
		environment()->add_encumbrance( nValue - m_lWeight );
 
 	m_lWeight = nValue;
}

int CContainer::Do_Action(int nAct, CChar *me)
{
	return 0;
}

//加入/移除心跳链表
void CContainer::set_heart_beat(int nFlag)
{
	Set_Heart_Beat(this, nFlag);
}

//更新自身
void CContainer::UpdateMe()
{
	char msg[255];

	m_lUpdate ++;

	if( !environment()) return;

	//通知谁呢？先通知自己吧。
	if(Query(IS_USER) || Query(IS_SPRITE))
	{
		((CChar *)this)->FlushMyInfo();
	}

	snprintf(msg, 255, "downloadobject %ld", object_id());

	//再通知环境
	if(environment()->Query(IS_CHAR))
	{
		((CChar *)environment())->command(msg);
	}

	//加入新人需要通知环境内其他角色下载该物件
	MessageVision(this, "execute", msg);
}

//是否存在于物品列表
CContainer * CContainer::Present(LONG nObj, int flag)
{
	POSITION p;
	CContainer * ob;

	p = m_ItemList.GetHeadPosition();
	while(p)
	{
		ob = m_ItemList.GetNext(p);
		if(!flag && ! ob->visible()) continue;
		if(ob->object_id() == nObj) return ob;
	}
	return 0;
}

void CContainer::SendCommand(const char *msg, int wait)
{
	
}

//找到物品中满足基本名的物件。nType可以是IS_CHAR
CContainer * CContainer::PresentName(const char * base_name, int nType, int flag)
{
	POSITION p;
	CContainer * obj;

	p = m_ItemList.GetHeadPosition();
	while(p)
	{
		obj = m_ItemList.GetNext(p);
		if(! flag && ! obj->visible()) continue;
		if( EQUALSTR(obj->querystr("base_name"), base_name) && obj->Query(nType) )
			return obj;
	}

	return 0;
}

//找到id一致的物件 "xiao er"
CContainer * CContainer::present(const char * id, int flag)
{
	POSITION p;
	CContainer * obj;

	p = m_ItemList.GetHeadPosition();
	while(p)
	{
		obj = m_ItemList.GetNext(p);
		if(! flag && ! obj->visible()) continue;
		if( EQUALSTR(obj->querystr("id"), id))
		{	
			return obj;
		}
	}

	return 0;
}

//离开场景
void CContainer::OnLeave(CContainer * me)
{
	POSITION p;
	CContainer * obj;

	if(! (p = m_ItemList.Find(me)) ) return;
	
	add_encumbrance( - me->weight());
	m_ItemList.RemoveAt(p);

	OnRemObject(me, this);				//对场景而言,是少了个东西

	p = m_ItemList.GetHeadPosition();

	while(p)
	{
		obj = m_ItemList.GetNext(p);
		if(obj == me) continue;
		if(obj->Query(IS_USER)) obj->OnRemObject(me, this);		//对其他人,是我走了.
	}
}

//进入场景
void CContainer::OnEnter(CContainer * me)
{
	CContainer * obj;
	
	POSITION p;
	DTItemList search;
				
	CopyList(&search, &m_ItemList);
		
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
		if(obj == me) continue;
		if(obj->environment() != this) continue;	//此玩家已经移动了。
		if(obj->query_temp("client/loading")) continue;	//该物件尚未进入地图

		if(obj->Query(IS_USER))	
			obj->OnAddObject(me, this);		//对其他人,是我进来了.
	
		if(me->Query(IS_USER))
		{
			me->OnAddObject(obj, this);		//对我来说,是其他人进来了.
			
			if(obj->is_character() )		//角色在人物进入房间的时候初始化
			{
				obj->init((CChar *)me);

				//如人物在init时被转移.则不再执行下面的init
				if(me->environment() != this)
					return;
			}
		}
	}

	search.RemoveAll();	

	//房间初始化
	if(me->Query(IS_CHAR))
		init((CChar *)me);
	else if(me->Query(IS_ITEM))
		((CItem *)me)->init();

//	if(! Query(IS_ROOM) && me->Query(IS_USER))  
//		((CUser *)me)->SendOff();
}

//增加一个物件的通讯
void CContainer::OnAddObject(CContainer * obj, CContainer * env)
{
	char cmd[480];
	
	if(! userp(this)) return;

	snprintf(cmd, 480, "&C=%d&E=%ld&T=%ld&U=%ld&",
		ADDOBJECT, env->object_id(), obj->object_id(), 
		obj->Query(CChar::UPDATE));

	if(obj->Query(IS_CHAR))	//接上状态描述
		((CChar *)obj)->GetStateMsg(cmd);
	
	if(obj->Query(IS_ITEM) || obj->Query(IS_CORPSE))
		strcat(cmd, "i=1&");
	if(obj->Query(IS_USER))
		strcat(cmd, "u=1&");
	
	SendCommand(cmd, 1);

	//再发物件详细资料
	obj->DownLoad((CChar *)this);

	//再发物件位置
	((CUser *)this)->LocationObject(obj);
}

//移除一个物件的通讯
void CContainer::OnRemObject(CContainer *obj, CContainer *env)
{
	char cmd[480];

	snprintf(cmd, 480, "&C=%d&E=%ld&T=%ld&", 
				REMOVEOBJECT, env->object_id(), obj->object_id());

	SendCommand(cmd, 1);
}

//下载本物件
void CContainer::DownLoad(CChar * me)
{
	char str[512];
	
	snprintf(str, 512, "&C=%d&O=%ld&", DOWNOBJECT, object_id());
	GetInfo(str, me);

	me->SendCommand(str, 1);
}

//虚拟函式：获得本物件信息。
void CContainer::GetInfo(char * str, CChar * me)
{
	char tmp[512], msg[255];

	snprintf(tmp, 255, "N=%s&I=%s&P=%ld&a=%ld&U=%ld&W=%ld&", 
		name(), 
		id(), 
		query("icon"), 
		Query_Amount(), 
		Query(CChar::UPDATE), weight());
	
	//NPC角色传活动范围坐标
	if(Query(IS_CHAR) && ! Query(IS_USER))
	{
		snprintf(msg, 255, "bx=%ld&by=%ld&ex=%ld&ey=%ld&dr=%d&ac=%d&",
			query("map/bx"), query("map/by"),
			query("map/ex"), query("map/ey"),
			query("map/dir"), query("map/active"));
		strcat(tmp, msg);
	}

	if(Query(CAN_GET)) strcat(tmp, "g=1&");
	if(Query(IS_BOX)) strcat(tmp, "x=1&"); 		
	
	if(EQUALSTR(querystr("status"), "locked"))
	{
		strcat(tmp, snprintf(msg, 40, "l=%s&", querystr("reason")));
	}

	if(Query(IS_VENDOR)) strcat(tmp, "v=1&");
	if(Query(IS_BANKER)) strcat(tmp, "b=1&");

	if(querymap("skill")) strcat(tmp, "bk=1&");	//可读的书
	
	if(Query(IS_CHAR) && 
		(me->is_apprentice_of((CChar *)this)
		|| ((CChar *)this)->recognize_apprentice(me)) )
		strcat(tmp, "m=1&");
	if(Query(CAN_USE)) strcat(tmp, "f=1&");

	if(Query(CAN_EQUIPPED))
	{
		snprintf(msg, 40, "w=%ld&", query("wield_position"));
		strcat(tmp, msg);
	}

	strcat(tmp, snprintf(msg, 40, "t=%s&", title()));
		
	strcat(str, tmp);
}

void CContainer::create(int nFlag)
{
	
}

//清除内部物件。
void CContainer::Clean_Up()
{
	POSITION p;
	CContainer * obj;
	DTItemList search;
	char msg[80];

	CRoom * room = load_room("room_void");

	CopyList(&search, &m_ItemList);
	
	p = search.GetHeadPosition();
	while(p)
	{
		obj = search.GetNext(p);
//		obj->move(room);			//物品落入空房间
		if(userp(obj))
			obj->move(room);
		else 
			DESTRUCT_OB(obj, snprintf(msg, 80, "%s->Clean_Up", name(1)) );
	}
}

LONG CContainer::Query_Weight()
{
	return m_lWeight;
}

int CContainer::handle_action(char *comm, CChar *me, char * arg)
{
	return 0;
}

int CContainer::handle_action(char *comm, CChar *me, char * arg, char * target)
{
	//包括环境内的物件都有反应
	POSITION p = m_ItemList.GetHeadPosition();
	while(p)
	{
		CContainer * obj = m_ItemList.GetNext(p);
		if(obj == me) continue;
		if(obj->handle_action(comm, me, arg, target))
			return 1;
	}

	return 0;
}

LONG CContainer::Query_Amount()
{
	return 1;
}

void CContainer::set_amount(LONG nAmount)
{

}

const char * CContainer::Query_Short()
{
	const char * m_sShort = querystr("short");
	if(m_sShort[0]) return m_sShort;
	return name();
}

int CContainer::is_character()
{
	return Query(IS_CHAR);
}

const char * CContainer::hit_ob(CChar *me, CChar *victim, LONG damage_bonus)
{
	return 0;
}

LONG CContainer::query_max_encumbrance()
{
	return max_encumb;
}

void CContainer::set_max_encumbrance(LONG e)
{
	max_encumb = e;
}

void CContainer::add_encumbrance(LONG w)
{
	encumb += w;
	if( encumb < 0 )
	{
		output_error("Object %s(%s) encumbrance underflow. env: %s w: %ld",
			name(1), querystr("id"),
			(environment() ? environment()->name(1) : "NULL"), w);
	}

	if( encumb > max_encumb ) over_encumbrance();
	if( environment() ) environment()->add_encumbrance(w);
}

void CContainer::over_encumbrance()
{
	if(query("infinity") || ! Query(IS_USER) ) return;	
	tell_object((CChar *)this, "你的负荷过重了！");
}


LONG CContainer::query_encumb()
{
	return encumb;
}

int CContainer::query_autoload()
{
	return 0;
}

CMapping * CContainer::query_entire_dbase()
{
	return & _M;
}

CMapping * CContainer::query_entire_temp_dbase()
{
	return & _T;
}

int CContainer::over_encumbranced()
{
	return encumb > max_encumb; 
}

LONG CContainer::weight()
{
	return m_lWeight + encumb;
}

//增加延迟函式
void CContainer::call_out(CALLOUTFUNC pFunc, time_t delay, LONG param1, LONG param2)
{
	CALLOUTNODE * p;

	//放入延迟函式链表
	if(delay <= 0) return;

	p = new CALLOUTNODE;
	p->pFunc = pFunc;
	p->nType = 0;
	p->delay =  delay;
	p->param1 = param1;
	p->param2 = param2;
	
	//output_error("%s增加延迟函式：%ld (%ld, %ld, %ld)", name(),pFunc,delay,param1, param2);

	m_CalloutList.AddHead(p);

	set_heart_beat(1);
}

//战斗结束时强制执行的延迟函式
void CContainer::call_out_combat(CALLOUTFUNC pFunc, time_t delay, LONG param1, LONG param2)
{
	CALLOUTNODE * p;

	//放入延迟函式链表
	//if(delay <= 0) return;

	p = new CALLOUTNODE;
	p->pFunc = pFunc;
	p->nType = 1;
	p->delay =  delay;
	p->param1 = param1;
	p->param2 = param2;
	
	//output_error("%s增加延迟函式：%ld (%ld, %ld, %ld)", name(),pFunc,delay,param1, param2);

	m_CalloutList.AddHead(p);

	set_heart_beat(1);
}

//移除 evalute = 1，执行
void CContainer::remove_call_out(CALLOUTFUNC pFunc, int evalute)
{
	POSITION p, prep;
	CALLOUTNODE * pNode;

	p = m_CalloutList.GetHeadPosition();
	while(p)
	{
		prep = p;
		pNode = m_CalloutList.GetNext(p);
		if(pNode->pFunc == pFunc)
		{
	//		output_error("%s移除延迟函式:%ld (%ld, %ld, %ld)", name(), pFunc, pNode->delay,pNode->param1, pNode->param2);
			m_CalloutList.RemoveAt(prep);

			//执行
			if(evalute && pNode->pFunc)
				(* pNode->pFunc)(this, pNode->param1, pNode->param2);

			delete pNode;
			return;
		}
	}
}

//执行并结束所有战斗延迟呼叫 1.72 版增加。2001-03-26
void CContainer::evaluate_call_out_combat()
{
	POSITION prep, p;
	CALLOUTNODE * pNode;
	LONG object_id = m_lObjectID;

	p = m_CalloutList.GetHeadPosition();
	
	while(p)
	{
		prep = p;
		pNode = m_CalloutList.GetNext(p);

		if(pNode->nType != 1) continue;		

		m_CalloutList.RemoveAt(prep);
		
		//执行
		if(pNode->pFunc)
			(* pNode->pFunc)(this, pNode->param1, pNode->param2);

		delete pNode;
		//判断本物件是否在函式中销毁
		if(g_LastDestructObject == object_id) return;		
	}
}

void CContainer::init(CChar * me)
{

}

int CContainer::wield()
{
	return Do_Action(DO_WIELD);
}

int CContainer::wear()
{
	return Do_Action(DO_WIELD);
}

void CContainer::owner_is_killed(CChar *killer)
{
	return;
}

//菜单处理

//插入菜单
void CContainer::AddMenuItem(string show, string cmd, CChar * me)
{
	char msg[512];

	snprintf(msg, 512, "&C=%d&N=%ld&s=%s&c=%s&", QUESTION, object_id(),	show.c_str(), cmd.c_str());
	if(m_bBeginMenu)
	{
		strcat(msg, "b=1&");
		m_bBeginMenu = 0;
	}

	me->SendCommand(msg, 1);		//等待发送
}

void CContainer::SendMenu(CChar *me)
{
	char msg[255];

	snprintf(msg, 512, "&C=%d&N=%ld&e=1&", QUESTION, object_id());
	me->SendCommand(msg, 1);		//等待发送

	m_bBeginMenu = 0;
//	me->SendOff();					//缓冲区清空
}

//返回外观描述
const char * CContainer::Long(int raw)
{
	const char * des = querystr_temp("apply/long");

	if( raw || ! des[0]) 
	{
		des = querystr("long");
	}
	
	return des;
}

int CContainer::say(const char * arg, CChar * me, const char * tips)
{
	char chat[402];
	char msg[512];

	if(! me)
	{
		strncpy(chat, arg, 400)[400] = 0;
		snprintf(msg, 512, "%s说：%s", name(), chat);
		MessageVision(this, "chat", msg);
	}
	
	else	//显示到DialogBox里
	{
		me->SendCommand(snprintf(msg, 512, "&C=%d&N=%ld&n=%s&m=%s&", 
			QUESTION, object_id(), tips ? tips : name(), arg), 1);		//等待发送

		//if(me != this)
		//	SendCommand(snprintf(msg, 512, "&C=%d&N=%ld&n=%s&m=%s&", 
		//		QUESTION, me->object_id(), name(), arg), 1);		//等待发送
	}

	return 1;
}

const char * CContainer::Short(int raw)
{
	static char msg[255];
	char mask[255];

	strncpy(msg, querystr("short"), 255)[254] = 0;
	if(! msg[0])
	{
		snprintf(msg, 255, "%s(%s)", name(raw), id(raw));
	}

	if( ! is_character() ) return msg;

	strncpy(mask, querystr_temp("apply/short"), 255)[254] = 0;
	if( ! raw && mask[0] )
         strcpy(msg, mask);
	else 
	{
		char nickname[40];

		strcpy(mask, msg);
		
		snprintf(nickname, 40, "「%s」", querystr("nickname"))[39] = 0;
		if(strlen(nickname) < 5) nickname[0] = 0;
				
		if ( querymap("party") ) 
		{
			snprintf(msg, 255, "%s%s %s %s %s %s", 
				querystr("party/party_name"), 
				querystr("party/rank"),
				querystr("title"), querystr_temp("c_title"), nickname, mask);
		}
		else
			snprintf(msg, 255, "%s %s %s %s", querystr("title"), querystr_temp("c_title"), nickname, mask);
	}

	return msg;
}

//观察函式
int CContainer::do_look(CChar *me)
{
	return 1;
}

void CContainer::relay_channel(CChar * me, const char * verb, const char * arg)
{

}

const char * CContainer::title(int raw)
{	
	const char * ti = querystr_temp("apply/title");
	if(raw || ! ti[0])
	{
		//增加对帮派的支持
		const char * c_ti = querystr_temp("c_title");
		if(c_ti[0])
		{
			ti = c_ti;
		}
		else
			ti = querystr("title");
	}
	
	return ti;		
}

LONG CContainer::icon(int raw)
{
	LONG ic = query_temp("apply/icon");
	if(raw || ! ic)
		ic = query("icon");
	return ic;
}

int CContainer::Save()
{
	return _Save(&_M);
}

int CContainer::Load()
{
	CMapping attr;

	if(! _Load(&attr)) return 0;
	_M.copyMapping(&attr);
	return 1;
}

//可存盘之物件
int CContainer::_Save(CMapping * savedata)
{
	char table_name[80];
	const char * attr;

	if(! Query(CAN_SAVE)) return 0;

	attr = savedata->GetBuffer();

#ifdef _SQL_
	MYSQL_RES *result = NULL;
	char * pData = NULL;
	char msg[255];
	//写数据库
	if(Query(IS_ROOM)) 
	{
		if(query("corp"))
			strcpy(table_name, "t_corp");
		else
			strcpy(table_name, "t_room");
	}
	else if(Query(IS_CHAR)) strcpy(table_name, "t_npc");
	else strcpy(table_name, "t_item");

	snprintf(msg, 255, "select obj_name from %s where obj_id='%s'", table_name, querystr("base_name"));
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if(nResult != 0)
	{
		output_error("saveobject: Failed to connect to database: Error: %s(%s)", mysql_error(&mysql), msg);
		return 0;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("saveobject: database fail: store null");
		return 0;
	}
	
	int n = mysql_num_rows(result);
	mysql_free_result(result);

	int len = 255 + strlen(attr);
	pData = new char[len];
	if(! pData)
	{
		output_error("saveobject:new pData is null!");
		return 0;
	}

	if(n)
		snprintf(pData, len, "update %s set obj_name='%s', obj_data='%s' where obj_id='%s'",
			table_name, name(1), attr, querystr("base_name"));
	else
		snprintf(pData, len, "insert %s(obj_id, obj_name, obj_data) values('%s', '%s', '%s')",
			table_name, querystr("base_name"), name(1), attr);
	
	nResult = mysql_real_query(&mysql, pData, strlen(pData));
	delete []pData;

	if(nResult != 0)
	{
		output_error("saveobject: Failed to connect to database: Error: %s", mysql_error(&mysql));
	}
	
	return !nResult;
	
#endif
	FILE * fp;

	if(Query(IS_ROOM)) snprintf(table_name, 80, "data/room/%s.o", querystr("base_name"));
	else if(Query(IS_CHAR)) snprintf(table_name, 80, "data/npc/%s.o", querystr("base_name"));
	else snprintf(table_name, 80, "data/item/%s.o", querystr("base_name"));	
	
	if((fp = fopen(table_name, "wb"))==NULL) return 0;
	fwrite(attr, strlen(attr), 1, fp);
	fclose(fp);
	
	return 1;
}

int CContainer::_Load(CMapping * savedata)
{
	char table_name[80];
	LONG	len;
		
	if(! Query(CAN_SAVE)) return 0;
	
#ifdef _SQL_		//数据库版本

	char msg[255];
	MYSQL_RES *result = NULL;

	//数据库
	if(Query(IS_ROOM)) 
	{
		if(((string)querystr("base_name")).substr(0, 5) == "corp1")
			strcpy(table_name, "t_corp");
		else
			strcpy(table_name, "t_room");
	}
	else if(Query(IS_CHAR)) strcpy(table_name, "t_npc");
	else strcpy(table_name, "t_item");

	snprintf(msg, 255, "select obj_data from %s where obj_id='%s'", table_name, querystr("base_name"));
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("loadobject:query db fail!");
		return 0;
	}
	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("loadobject:database fail: store null");
		return 0;
	}
	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return 0;		
	}

	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL || row[0] == NULL)
	{
		mysql_free_result(result);
		return 0;
	}	

	len = savedata->LoadBuffer(row[0]);
	
	mysql_free_result(result);

#else

	FILE * fp;
	
	if(Query(IS_ROOM)) snprintf(table_name, 80, "data/room/%s.o", querystr("base_name"));
	else if(Query(IS_CHAR)) snprintf(table_name, 80, "data/npc/%s.o", querystr("base_name"));
	else snprintf(table_name, 80, "data/item/%s.o", querystr("base_name"));	

	if((fp = fopen(table_name, "rb")) == NULL) return 0;
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);

	char * pData = new char[len];
	fseek(fp, 0, SEEK_SET);

	fread(pData, len, 1, fp);
	fclose(fp);

	len = savedata->LoadBuffer(pData);
	
	delete []pData;
	
#endif

	if(len == -1)
	{
		set("fail_ob", 2);
		output_error("载入物件%s失败!", querystr("base_name"));
		return 0;
	}
	
	return 1;
}

void CContainer::setup()
{

}

LONG CContainer::object_id()
{
	return m_lObjectID;
}

void CContainer::ChangeRoom(CContainer * me)
{
	char cmd[512];

	if(! m_ItemList.Find(me))		//如果已经存在则不必增加了。如登录时的重新连线呼叫。
	{
		add_encumbrance(me->weight());
		m_ItemList.AddHead(me);					//增加
		OnAddObject(me, this);				//对场景而言,是加了个东西		
	}

	if(! userp(me)) return;

	const char * map = querystr("map");
	
	//切换场景之对玩家发
	snprintf(cmd, 480, "&C=%d&R=%ld&I=%s&N=%s&F=%ld&D=%s&", 
		GOTOROOM, object_id(), map[0] ? map : "玩家民居1", 
		name(),
		Query(CChar::IS_FIGHTROOM), me->querystr_temp("init_door"));
	
	((CUser *)me)->SendCommand(cmd, 1);
	//用户要等待切换场景
	me->set_temp("client/loading", 1);
	
	snprintf(cmd, 255, "&C=%d&R=0&", ADDDOOR);	//将传出口信息标志，告诉客户端切换场景完毕。
	((CUser *)me)->SendCommand(cmd, 1);

	//如果是非房间物件，要求sendoff，不然不能及时刷新	1.73版增加 lanwood 2001-02-28
	if(! Query(IS_ROOM))
		((CUser *)me)->SendOff();
}

int CContainer::visible()
{
	if(query_temp("client/loading")) return 0;
	return 1;	
}

//档案从数据库彻底删除
void CContainer::Remove()
{
	char table_name[80];
	
	if(! Query(CAN_SAVE)) return;
	
#ifdef _SQL_		//数据库版本

	char msg[255];

	//数据库
	if(Query(IS_ROOM)) 
	{
		if(query("corp"))
			strcpy(table_name, "t_corp");
		else
			strcpy(table_name, "t_room");
	}
	else if(Query(IS_CHAR)) strcpy(table_name, "t_npc");
	else strcpy(table_name, "t_item");

	snprintf(msg, 255, "delete from %s where obj_id='%s'", table_name, querystr("base_name"));
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
		output_error("removeobject:query db fail!");
	
#else

	if(Query(IS_ROOM)) snprintf(table_name, 80, "data/room/%s.o", querystr("base_name"));
	else if(Query(IS_CHAR)) snprintf(table_name, 80, "data/npc/%s.o", querystr("base_name"));
	else snprintf(table_name, 80, "data/item/%s.o", querystr("base_name"));	
	
	remove(table_name);

#endif	
}

//返回房间内某频道的听众
MAP2USER * CContainer::GetUsers(const char * channel, MAP2USER * list)
{
	CContainer * obj;
		
	POSITION p = m_ItemList.GetHeadPosition();
	while(p)
	{
		obj = m_ItemList.GetNext(p);
		if(userp(obj) && ! ((CUser *)obj)->refuse_channel(channel))
			(* list)[obj->object_id()] = (CUser *)obj;
	}

	return list;
}

//存储到本地磁盘文件
int CContainer::SaveToLocal(const char * fname, CMapping *save)
{
	FILE * fp;
	const char * attr = save->GetBuffer();

	if((fp = fopen(fname, "wb"))==NULL) 
	{
		output_error("ERROR: SaveToLocal %s error!", fname);
		return 0;
	}
	fwrite(attr, strlen(attr), 1, fp);
	fclose(fp);

	return 1;
}

int CContainer::LoadFromLocal(const char *fname, CMapping *save)
{
	FILE * fp;

	if((fp = fopen(fname, "rb")) == NULL) return 0;
	fseek(fp, 0, SEEK_END);
	long len = ftell(fp);

	char * pData = new char[len];
	fseek(fp, 0, SEEK_SET);

	fread(pData, len, 1, fp);
	fclose(fp);
		
	len = save->LoadBuffer(pData);
	delete []pData;

	if(len == -1) return 0;
	return 1;
}

//锁定数据
int CContainer::LockData(int locked)
{
	int ret = _LockData(locked);
	int wait = 0;
	time_t ct;
	time(&ct);

	while(! ret && ! locked)
	{ 
		time_t t;
		if(time(&t) != ct)
		{
			ct = t;
			if(_LockData(locked))
				return 1;
			if(wait++ > 3)
				return 0;
		}			
	}

	return 1;
}


int CContainer::_LockData(int locked)
{
#ifdef _SQL_		//数据库版本

	char table_name[80], msg[255];	
	MYSQL_RES *result = NULL;

	//数据库
	if(Query(IS_ROOM)) 
	{
		if(query("corp"))
			strcpy(table_name, "t_corp");
		else
			strcpy(table_name, "t_room");
	}
	else if(Query(IS_CHAR)) strcpy(table_name, "t_npc");
	else strcpy(table_name, "t_item");

	snprintf(msg, 255, "select obj_lock from %s where obj_id='%s'", table_name, querystr("base_name"));
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("LockData:query db fail!");
		return 0;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("LockData:database fail: store null");
		return 0;
	}

	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return 0;		
	}

	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL || row[0] == NULL)
	{
		mysql_free_result(result);
		return 0;
	}	

	int haslock = atol(row[0]);
	mysql_free_result(result);

	if( (locked && haslock)
		|| (!locked && !haslock))
	{
		g_Channel.do_channel(&g_Channel, NULL, "sys", 
			snprintf(msg, 255, "%s lock = %d 失败！", name(1), locked) );
		
		return 0;
	}
	
	snprintf(msg, 255, "update %s set obj_lock = %d where obj_id='%s'",
		table_name, locked, querystr("base_name"));

	nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if(nResult != 0)
	{
		output_error("LockData: Failed to connect to database: Error: %s", mysql_error(&mysql));
	}
#endif

	return 1;
}

void CContainer::destructed()
{

}
