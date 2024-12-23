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
	set("title", "��ͨ����");
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
		query_temp("block_msg/all") ) return;	//֪ͨ��Ϣȫ������

	if(query_temp("client/snoop"))	//������״̬
	{
		//�ڷ���ǰ��飬��NOTIFY���͵Ľػ�
		if( nComm == NOTIFY || nComm == COMMON_ATTACK )
		{
			g_Channel.do_snooping(this, GetValue(msg, "M", mem, 512));
		}
		else if( nComm == TELLOBJECT )
		{
			g_Channel.do_snooping(this, snprintf(tmp, 400, "$HIG��˽�ġ�%s�����㣺%s", 
				GetValue(msg, "n", na, 40), 
				GetValue(msg, "M", mem, 512)));
		}
		else if( nComm == GOTOROOM )
		{
			g_Channel.do_snooping(this, snprintf(tmp, 400, "$COM��$GRN������$COM%s��", 
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

	//BGרBIG lanwood 2001-07-30
	if(query_temp("client/big5"))
		gb2big(mem);

	DecodeStr(mem);

	if(wait || m_BufferPtr)
	{
		int p = 0;
		//�ȴ�
		while(msg[p])
		{
			m_SendBuffer[m_BufferPtr++] = mem[p++];
			if(m_BufferPtr >= 510) //512�ֽ�һ����
			{
				//���ʹ���
				m_SendBuffer[m_BufferPtr] = 0;
				SendOff();
			}
		}
		m_SendBuffer[m_BufferPtr++] = '\t';	

		//if(wait == 2)	//��������
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

//��������
void CUser::Online()
{
	OpenClient(query_temp("client/sockfd"), object_id());
	delete_temp("net_dead");

	if(SetOnlineFlag(sys_server_id))
		set_temp("online", sys_server_id);
	
	OnSendOnline(this);
}
	

//���� flag = 0 �������� flag = 1 ��������
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
//			snprintf(msg, 80, "��%s��%s�����ˡ�", environment()->name(), name());
//			MessageVision(this, "notify", msg);
		}

#ifdef _SQL_
		OnUserOut(this);
#endif

		set_temp("net_dead", current_time);	//�����ˡ�
		delete_temp("client/loading");	//ɾ��װ����
//		delete_temp("client");
	
		if(! environment()) return;

		SendState();

		//�����û�������Ϣ �޸�Ϊ1.71�汾 lanwood 2001-03-25
		MAP2USER * user = users();
		iterator_user p;
		CUser * obj;
		
		for(p = user->begin(); p != user->end(); p++)
		{
			obj = p->second;
			if(obj == this) continue;
			if( ! obj->is_friend(querystr("id")) )  continue;	//���ں����б���

			obj->SendCommand(snprintf(msg, 80, "&C=%d&O=0&U=%ld&", SENDUSER, object_id()), 1);
		}

		set_heart_beat(1);		//��ʼ���߼�ʱ
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

//�û���������
int CUser::query_idle()
{
	return current_time - m_nStartIdle;
}

void CUser::user_dump()
{
	char msg[255];

	tell_object( this, snprintf(msg, 255, "�Բ������Ѿ���������%ld�����ˣ����´�������", IDLE_TIMEOUT / 60));
	tell_room( environment(), snprintf(msg, 255, "һ��紵�����������е�%s��Ϊһ�ѷɻң���ʧ�ˡ�", name()), this);
	
	command("quit");
}

void CUser::DoActive()
{
	m_nStartIdle = current_time;
}

//��λĳ��� C=LOCATION, T=Ŀ�� BX BY EX EY AC=�ܻ�����
void CUser::LocationObject(CContainer * obj)
{
	char msg[512];

	//�Ƿ��䣬�����ꡣ���ö�λ
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

//�������� 1.71�汾 lanwood 2001-03-25
int CUser::SetFriend(const char * uid, int bRelative)
{
	const char * name;
	char msg[40];

	if(bRelative)	//��ɾ������ұ�������
	{
		CUser * who = find_online(uid);
		if(! who || who == this) return 0;
		
		name = who->name(1);
	}
	else		//ɾ���������ں��������
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

//����ĳ���Ƿ��ں��������еĹ�ϵ 0:���� 1:���� 2:������
int CUser::is_friend(string id)
{
	char msg[40];
	return friends.query(snprintf(msg, 40, "%s/relative", id.c_str()));
}

//֪ͨ�û�me����
void CUser::notify_online(CChar *me)
{
	char msg[255];

	snprintf(msg, 255, "&C=%d&O=1&U=%ld&", 
			SENDUSER, me->object_id());
			
	SendCommand(msg, 1);
}

//֪ͨ�û�me������ ���������Ϣ ���� type = 0 NORMAL type = 1 ���� type = 2 ����
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
	
	//������������
	snprintf(tmp, 40, "n=%d&", i);
	strcat(msg, tmp);

	SendCommand(msg, 1);
}

//�����û���ϸ����
void CUser::ReceiveUserInfo(CUser *me)
{
	char msg[255];
	
	snprintf(msg, 255, "&C=%d&U=%ld&N=%s&I=%s&r=%s&t=%s&",
		DOWNUSER, 
		me->object_id(), me->name(1), me->id(1), query_rank(me), me->title(1));

	SendCommand(msg, 1);
}

//����׼��PK���
void CUser::Ready_PK()
{
	//����PK������	lanwood 2001-04-13
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

//�����ַ���������
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

			//����Ƿ��Ѿ�����
			if(g_LastDestructObject == player_id)
				return true;

			m_nCmdBufferPtr = 0;
			nStart = 0;
			nAnalysePtr ++;

			if(nAnalysePtr >= nRet) return false;
			continue;
		}

		m_szCommandBuffer[m_nCmdBufferPtr++] = pCommandString[nAnalysePtr++];
			
		if( nAnalysePtr >= nRet )	//Խ��
		{
			m_szCommandBuffer[m_nCmdBufferPtr] = 0;

			DecodeStr(&m_szCommandBuffer[nStart]);
			PushCommand(m_szCommandBuffer, m_nCmdBufferPtr + 1);
			m_nCmdBufferPtr = 0;

			output_error("���ջ���Խ��:�û�%ld �ִ�%s", name(1), m_szCommandBuffer);
			return false;
		}
	}

	//�ȴ��´δ���
	m_szCommandBuffer[m_nCmdBufferPtr] = 0;
	DecodeStr(m_szCommandBuffer);	

	return true;
}

void CUser::PushCommand(char * cmd, int nLen)
{	
	//BIG5רBG lanwood 2001-07-30
	if(query_temp("client/big5"))
		big2gb(cmd);

	if( m_nTailCommandPtr + 1 == m_nHeadCommandPtr
		|| m_nTailCommandPtr + 1 == m_nHeadCommandPtr + 20)
	{
		tell_object(this, "�Բ�����һ�������ָ��̫�ࡣ");
		return;
	}
	
	if(m_CommandList[m_nTailCommandPtr])
	{
		output_error("�û�%s����й¶! %s.", name(1), m_CommandList[m_nTailCommandPtr]);
		delete []m_CommandList[m_nTailCommandPtr];
	}

	//�����ϵͳָ�ֱ��ִ�У��������Ŷӡ�
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

//����ǰ����
int CUser::HandleCommand()
{
	if(m_nHeadCommandPtr == m_nTailCommandPtr)	//��ָ��
		return 0;

	if(! m_CommandList[m_nHeadCommandPtr])
	{
		output_error("�û�%s�������ʧ��!", name(1));
		return 0;
	}

	LONG nActor;
	char msg[512];
		
	analyse_string(m_CommandList[m_nHeadCommandPtr], msg, 512);
	nActor = atol(m_CommandList[m_nHeadCommandPtr]);

	//�ͷ�
	delete []m_CommandList[m_nHeadCommandPtr];
	m_CommandList[m_nHeadCommandPtr++] = NULL;

	if(m_nHeadCommandPtr == 20)
		m_nHeadCommandPtr = 0;
		
	//�ڴ��ж�Ȩ�ޣ�������֧�������˵���Ϊ
	if( nActor != object_id()) return 0;

	DoActive();
	command(msg);
		
	//�ٴβ���һ����ң���Ϊ�п�����ָ��ִ��ʱ�û������١�
	if(g_LastDestructObject != nActor)
		SendOff();

	//δ�����٣��ڴ˴�����
	return 1;	
}

int CUser::SetOnlineFlag(int online)
{
	//�������߱��,��ֹLOGINʧ�ܵ�DESTRUCT����������Ϣ
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

//����user���ڵķ�����
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
