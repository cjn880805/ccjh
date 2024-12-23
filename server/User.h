// Player.h: interface for the CPlayer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PLAYER_H__DB7CBEE6_64B9_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_PLAYER_H__DB7CBEE6_64B9_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Char.h"

//���
#define		USERONLINE_NORMAL		0
#define		USERONLINE_PARTY		1
#define		USERONLINE_CORPS		2

class CUser : public CChar
{
public:
	int SetOnlineFlag(int online);

	int query_server();
	int  HandleCommand();
	bool On_Receive(const char * pCommandString, int nRet);

	void Ready_PK();
	void ReceiveUserInfo(CUser * me);
	void SendUserOnline(int bBegin, int bEnd, int type = 0);
	void notify_online(CChar * me);
	int is_friend(string id);
	int SetFriend(const char * id, int bRelative);

	void LocationObject(CContainer * obj);
	void DoActive();
	void user_dump();
	int query_idle();
	void update_age();
	virtual void SendOff();
	virtual void setup();
	void Offline(int flag = 0);
	void Online();
	virtual LONG Query(int nAttr);
	virtual void SendCommand(const char * msg, int wait = 0);

	CUser();
	virtual ~CUser();

protected:
	void PushCommand(char * command, int nLen);

	int		m_nStartIdle;
	int		last_age_set;
	char	m_SendBuffer[512];	//���ͻ�����
	int		m_BufferPtr;
	
	int		m_nCmdBufferPtr;
	char	m_szCommandBuffer[1025];		//���ջ�����

	char *	m_CommandList[20];			//�ȴ���������
	int		m_nTailCommandPtr;			//��ǰ����ָ�����β
	int		m_nHeadCommandPtr;			//��ǰ����ָ�����ͷ
};

CUser * find_online(const char * id);

#endif // !defined(AFX_PLAYER_H__DB7CBEE6_64B9_11D4_98AB_0050BABC5212__INCLUDED_)
