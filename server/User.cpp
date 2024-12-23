// Player.cpp: implementation of the CPlayer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Globle.h"
#include "User.h"
#include "Room.h"
#include "Channel.h"
#include "CodeChange.h"

extern int SendToClient(int Objectid, int nSerial, const char * msg);
extern void OpenClient(int nID, LONG user);
extern void CloseClient(int nSerial);

#ifdef _SQL_
#include "../sql/sql.h"
#endif
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CUser::CUser()
{
	set("grant", GRANT_PLAYER);
	set("title", "普通百姓");
	memset(m_SendBuffer, 0, 512);
	m_BufferPtr = 0;
	last_age_set = 0;
	
	m_nCmdBufferPtr = 0;
	m_nHeadCommandPtr = 0;
	m_nTailCommandPtr = 0;

	for(int i= 0; i < 20; i++)
		m_CommandList[i] = NULL;
}

CUser::~CUser()
{
	for(int i = 0; i < 20; i++)
	{
		if(m_CommandList[i])
			delete [] m_CommandList[i];
	}

}

void CUser::SendCommand(const char *msg, int wait)
{
	static char mem[1024];
	static char tmp[512], na[40];
	int  nComm;
	
	if(! querymap_temp("client") || query_temp("net_dead") ) return;
	nComm = atol(GetValue(msg, "C", mem, 40));
	if( (nComm == NOTIFY || nComm == COMMON_ATTACK ) &&
		query_temp("block_msg/all") ) return;	//通知消息全部阻塞

	if(query_temp("client/snoop"))	//被监听状态
	{
		//在发送前检查，是NOTIFY类型的截获
		if( nComm == NOTIFY || nComm == COMMON_ATTACK )
		{
			g_Channel.do_snooping(this, GetValue(msg, "M", mem, 512));
		}
		else if( nComm == TELLOBJECT )
		{
			g_Channel.do_snooping(this, snprintf(tmp, 400, "$HIG【私聊】%s告诉你：%s", 
				GetValue(msg, "n", na, 40), 
				GetValue(msg, "M", mem, 512)));
		}
		else if( nComm == GOTOROOM )
		{
			g_Channel.do_snooping(this, snprintf(tmp, 400, "$COM你$GRN进入了$COM%s。", 
				GetValue(msg, "N", na, 40)));
		}
		else if( nComm == QUESTION )
		{
			GetValue(msg, "s", mem, 255);
			if(mem[0])
			{
				g_Channel.do_snooping(this, snprintf(tmp, 400, "()%s", mem)); 
			}
			else
			{
				GetValue(msg, "m", mem, 512);
				if(mem[0])
				{
					g_Channel.do_snooping(this, snprintf(tmp, 400, "(%s)%s", 
						GetValue(msg, "n", na, 40), mem));
				}
			}
		}
		else if( nComm == NOTIFY_FAIL )
		{
			g_Channel.do_snooping(this, snprintf(tmp, 400, "(%s)%s", 
				GetValue(msg, "F", na, 40),
				GetValue(msg, "M", mem, 512)));
		}
	}
	
	strncpy(mem, msg, 1024);

	//BG专BIG lanwood 2001-07-30
	if(query_temp("client/big5"))
		gb2big(mem);

	DecodeStr(mem);

	if(wait || m_BufferPtr)
	{
		int p = 0;
		//等待
		while(msg[p])
		{
			m_SendBuffer[m_BufferPtr++] = mem[p++];
			if(m_BufferPtr >= 510) //512字节一发送
			{
				//发送处理
				m_SendBuffer[m_BufferPtr] = 0;
				SendOff();
			}
		}
		m_SendBuffer[m_BufferPtr++] = '\t';	

		//if(wait == 2)	//立即发送
		//	SendOff();
	}
	else
	{
		m_BufferPtr = 512;
		snprintf(m_SendBuffer, 512, "%s\t", mem);
		SendOff();
	}
}

LONG CUser::Query(int nAttr)
{
	switch(nAttr)
	{
	case IS_USER:
		return 1;
	case CAN_SAVE:
		return 1;
	}

	return CChar::Query(nAttr);
}

//设置在线
void CUser::Online()
{
	OpenClient(query_temp("client/sockfd"), object_id());
	delete_temp("net_dead");

	if(SetOnlineFlag(sys_server_id))
		set_temp("online", sys_server_id);
	
	OnSendOnline(this);
}
	

//离线 flag = 0 主动断线 flag = 1 被动断线
void CUser::Offline(int flag)
{
	char msg[80];

	//set_temp("client/serial", -1);
	if(! query_temp("net_dead"))
	{
		if(! flag)	
			CloseClient(query_temp("client/serial"));
		else
		{
//			snprintf(msg, 80, "【%s】%s断线了。", environment()->name(), name());
//			MessageVision(this, "notify", msg);
		}

#ifdef _SQL_
		OnUserOut(this);
#endif

		set_temp("net_dead", current_time);	//网掉了。
		delete_temp("client/loading");	//删掉装入标记
//		delete_temp("client");
	
		if(! environment()) return;

		SendState();

		//发布用户离线信息 修改为1.71版本 lanwood 2001-03-25
		MAP2USER * user = users();
		iterator_user p;
		CUser * obj;
		
		for(p = user->begin(); p != user->end(); p++)
		{
			obj = p->second;
			if(obj == this) continue;
			if( ! obj->is_friend(querystr("id")) )  continue;	//不在好友列表中

			obj->SendCommand(snprintf(msg, 80, "&C=%d&O=0&U=%ld&", SENDUSER, object_id()), 1);
		}

		set_heart_beat(1);		//开始断线计时
	}
}

void CUser::setup()
{
	update_age();
	DoActive();

	CChar::setup();

	set_temp("channel_msg_cnt", 8);
	set_temp("save_to_server", current_time + 3600);
}

void CUser::SendOff()
{
	if(!m_BufferPtr) return;
	m_SendBuffer[m_BufferPtr] = 0;
	SendToClient(object_id(), query_temp("client/serial"), m_SendBuffer);
	m_BufferPtr = 0;
}

void CUser::update_age()
{
	if( ! last_age_set ) last_age_set = current_time;
	add("mud_age", current_time - last_age_set);
	last_age_set = current_time;
	set("age", 14 + query("age_modify") / 172800 + query("mud_age") / 172800);
}

//用户发呆秒数
int CUser::query_idle()
{
	return current_time - m_nStartIdle;
}

void CUser::user_dump()
{
	char msg[255];

	tell_object( this, snprintf(msg, 255, "对不起，您已经发呆超过%ld分钟了，请下次再来。", IDLE_TIMEOUT / 60));
	tell_room( environment(), snprintf(msg, 255, "一阵风吹来，将发呆中的%s化为一堆飞灰，消失了。", name()), this);
	
	command("quit");
}

void CUser::DoActive()
{
	m_nStartIdle = current_time;
}

//定位某物件 C=LOCATION, T=目标 BX BY EX EY AC=跑还是走
void CUser::LocationObject(CContainer * obj)
{
	char msg[512];

	//非房间，无坐标。不用定位
	if(! (obj->environment())->Query(IS_ROOM)) return;

	snprintf(msg, 512, "&C=%ld&T=%ld&bx=%ld&by=%ld&ex=%ld&ey=%ld&ac=%ld&",
		LOCATION,
		obj->object_id(),
		obj->query_temp("map/bx"),
		obj->query_temp("map/by"),
		obj->query_temp("map/ex"),
		obj->query_temp("map/ey"),
		obj->query_temp("map/ac"));

	SendCommand(msg, 1);
}

//设置朋友 1.71版本 lanwood 2001-03-25
int CUser::SetFriend(const char * uid, int bRelative)
{
	const char * name;
	char msg[40];

	if(bRelative)	//非删除，玩家必须在线
	{
		CUser * who = find_online(uid);
		if(! who || who == this) return 0;
		
		name = who->name(1);
	}
	else		//删除，必须在好友名单里。
	{
		if(! friends.query(snprintf(msg, 40, "%s/relative", uid)))
			return 0;

		name = friends.querystr(snprintf(msg, 40, "%s/name", uid));
	}
		
	CMapping m;

	m.set("name", name);
	m.set("relative", bRelative);
	friends.set(uid, m);

	g_Channel.update_friends(id(1), uid, name, bRelative);
	g_Channel.SaveFriends();

	return 1;
}

//返回某人是否在好友名单中的关系 0:不在 1:好友 2:黑名单
int CUser::is_friend(string id)
{
	char msg[40];
	return friends.query(snprintf(msg, 40, "%s/relative", id.c_str()));
}

//通知用户me在线
void CUser::notify_online(CChar *me)
{
	char msg[255];

	snprintf(msg, 255, "&C=%d&O=1&U=%ld&", 
			SENDUSER, me->object_id());
			
	SendCommand(msg, 1);
}

//通知用户me的资料 在线玩家信息 倒序 type = 0 NORMAL type = 1 本派 type = 2 本帮
void CUser::SendUserOnline(int nBegin, int nEnd, int type)
{
	int bEnd = 0;
	char msg[512], tmp[40];
	const char * corps_id = querystr("corps/id");
	const char * party_id = querystr("family/family_name");
	
	MAP2USER * userlist = users();
	iterator_user p;
	CUser * obj;
	int i = 0, count = userlist->size();

	if(! count) return;

	snprintf(msg, 255, "&C=%d&", USERLIST, count);

	p = userlist->end();
	while(1)
	{
		if(bEnd) break;

		p--;
		if(p == userlist->begin()) bEnd = 1;

		obj = p->second;
		
		if(obj->query_temp("net_dead")) continue;
		if(type == USERONLINE_PARTY 
			&& DIFFERSTR(obj->querystr("family/family_name"), party_id) ) continue;

		if(type == USERONLINE_CORPS 
			&& DIFFERSTR(obj->querystr("corps/id"), corps_id) ) continue;
		
		if(i >= nBegin && i < nEnd)
		{
			snprintf(tmp, 40, "i%d=%ld&", i - nBegin, obj->object_id());
			strcat(msg, tmp);
		}

		i++;		
	}
	
	//计算在线人数
	snprintf(tmp, 40, "n=%d&", i);
	strcat(msg, tmp);

	SendCommand(msg, 1);
}

//接受用户详细资料
void CUser::ReceiveUserInfo(CUser *me)
{
	char msg[255];
	
	snprintf(msg, 255, "&C=%d&U=%ld&N=%s&I=%s&r=%s&t=%s&",
		DOWNUSER, 
		me->object_id(), me->name(1), me->id(1), query_rank(me), me->title(1));

	SendCommand(msg, 1);
}

//设置准备PK标记
void CUser::Ready_PK()
{
	//设置PK发起标记	lanwood 2001-04-13
	if(! query_temp("pending/PK"))
	{
		set_temp("pending/PK", current_time);

		CContainer * env = environment();
		while(env->environment())
			env = env->environment();

		if(env->query("city"))
			set_temp("pending/PK_city", env->querystr("base_name"));
	}
}

//接收字符串并处理
bool CUser::On_Receive(const char *pCommandString, int nRet)
{
	int		nAnalysePtr = 0;
	int nStart = m_nCmdBufferPtr;
	LONG	player_id = object_id();

	while( pCommandString[nAnalysePtr] )
	{
		if( pCommandString[nAnalysePtr] == '\t' )	//Command Line End
		{
			m_szCommandBuffer[m_nCmdBufferPtr] = 0;
			
			DecodeStr(&m_szCommandBuffer[nStart]);
			PushCommand(m_szCommandBuffer, m_nCmdBufferPtr + 1);

			//检查是否已经销毁
			if(g_LastDestructObject == player_id)
				return true;

			m_nCmdBufferPtr = 0;
			nStart = 0;
			nAnalysePtr ++;

			if(nAnalysePtr >= nRet) return false;
			continue;
		}

		m_szCommandBuffer[m_nCmdBufferPtr++] = pCommandString[nAnalysePtr++];
			
		if( nAnalysePtr >= nRet )	//越界
		{
			m_szCommandBuffer[m_nCmdBufferPtr] = 0;

			DecodeStr(&m_szCommandBuffer[nStart]);
			PushCommand(m_szCommandBuffer, m_nCmdBufferPtr + 1);
			m_nCmdBufferPtr = 0;

			output_error("接收缓冲越界:用户%ld 字串%s", name(1), m_szCommandBuffer);
			return false;
		}
	}

	//等待下次处理
	m_szCommandBuffer[m_nCmdBufferPtr] = 0;
	DecodeStr(m_szCommandBuffer);	

	return true;
}

void CUser::PushCommand(char * cmd, int nLen)
{	
	//BIG5专BG lanwood 2001-07-30
	if(query_temp("client/big5"))
		big2gb(cmd);

	if( m_nTailCommandPtr + 1 == m_nHeadCommandPtr
		|| m_nTailCommandPtr + 1 == m_nHeadCommandPtr + 20)
	{
		tell_object(this, "对不起，您一次输入的指令太多。");
		return;
	}
	
	if(m_CommandList[m_nTailCommandPtr])
	{
		output_error("用户%s命令泄露! %s.", name(1), m_CommandList[m_nTailCommandPtr]);
		delete []m_CommandList[m_nTailCommandPtr];
	}

	//如果是系统指令，直接执行，不进行排队。
	if(cmd[0] == '0' && cmd[1] == ' ')
	{
	//	TRACE("%s\n", &cmd[2]);
		command(&cmd[2]);
		return;
	}

	m_CommandList[m_nTailCommandPtr] = new char[nLen];
	memcpy(m_CommandList[m_nTailCommandPtr], cmd, nLen);
	m_CommandList[m_nTailCommandPtr][nLen - 1] = 0;

	m_nTailCommandPtr++;	

	if(m_nTailCommandPtr >= 20)
		m_nTailCommandPtr = 0;
}

//处理当前命令
int CUser::HandleCommand()
{
	if(m_nHeadCommandPtr == m_nTailCommandPtr)	//无指令
		return 0;

	if(! m_CommandList[m_nHeadCommandPtr])
	{
		output_error("用户%s命令队列失败!", name(1));
		return 0;
	}

	LONG nActor;
	char msg[512];
		
	analyse_string(m_CommandList[m_nHeadCommandPtr], msg, 512);
	nActor = atol(m_CommandList[m_nHeadCommandPtr]);

	//释放
	delete []m_CommandList[m_nHeadCommandPtr];
	m_CommandList[m_nHeadCommandPtr++] = NULL;

	if(m_nHeadCommandPtr == 20)
		m_nHeadCommandPtr = 0;
		
	//在此判断权限，不可以支配其他人的行为
	if( nActor != object_id()) return 0;

	DoActive();
	command(msg);
		
	//再次查找一次玩家，因为有可能在指令执行时用户被销毁。
	if(g_LastDestructObject != nActor)
		SendOff();

	//未被销毁，在此处发送
	return 1;	
}

int CUser::SetOnlineFlag(int online)
{
	//设置在线标记,防止LOGIN失败的DESTRUCT覆盖连接信息
	if(! online)
	{
		if(! query_temp("online")) return 0;
		delete_temp("online");
	}

#ifdef _SQL_
	char msg[255];
	snprintf(msg, 255, "update ccjhdb set cc_server = %ld where cc_id = %s", online, id(1));
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("SetOnlineFlag:query db fail!");
		return 0;
	}
#endif

	return 1;
}

//返回user所在的服务器
int CUser::query_server()
{
#ifdef _SQL_

	char msg[255];
	MYSQL_RES *result = NULL;

	snprintf(msg, 255, "select cc_server from ccjhdb where cc_id = %s", querystr("id"));
	int nResult = mysql_real_query(&mysql, msg, strlen(msg));
	if( nResult != 0)
	{
		output_error("query_server:query db fail!");
		return -1;
	}

	result = mysql_store_result(&mysql);
	if(result == NULL)
	{
		output_error("query_server:database fail: store null");
		return -1;
	}
	int n = mysql_num_rows(result);
	if(n == 0)
	{
		mysql_free_result(result);
		return -1;		
	}

	MYSQL_ROW row;
	row = mysql_fetch_row(result);
	if(row == NULL || row[0] == NULL)
	{
		mysql_free_result(result);
		return -1;
	}
	
	nResult = atol(row[0]);
	mysql_free_result(result);	

	return nResult;
#endif

	return 0;
}
