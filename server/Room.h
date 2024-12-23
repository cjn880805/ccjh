// Room.h: interface for the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROOM_H__0B4E30A3_6536_11D4_98AB_0050BABC5212__INCLUDED_)
#define AFX_ROOM_H__0B4E30A3_6536_11D4_98AB_0050BABC5212__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Item.h"
#include "Globle.h"

#define  ROOM_BEGIN(class_name)	class class_name : public CRoom	{	public:	class_name(){};	virtual ~class_name(){};		
#define  ROOM_END		}


//���ڶ���
class CDoor : public CMudObject
{
public:
	void Bind(const char * next_room, const char * NextDoor);
	int Enter_Door(CChar * me);

	//����
	void Locked()
	{
		set("status", "locked");
	}

	//����
	void UnLocked()
	{
		set("status", "open");
	}

	CDoor(){};
	~CDoor(){};
};

class CBox : public CItem
{
public:
	void RemoveObjects();
	int LoadObject();
	int SaveObject();

	virtual int handle_action(char * comm, CChar * me, char * arg);
	virtual void DownLoad(CChar * me);
	virtual void OnLeave(CContainer * me);
	virtual void OnEnter(CContainer * me);
	void Locked(char * season, LONG duration, CChar * me = NULL);
	int UnLocked(LONG resume = 0)
	{
		int dur = 0;

		if(! resume)
			del("duration");
		else
			dur = add("duration", -resume);

		if(dur <= 0)
		{
			del("owner");
			del("duration");
			set("status", "open"); 
			UpdateMe();
			return 0;
		}

		return dur;
	};

	//�趨Կ��
	void Set_Key(LONG passwd)
	{
		set("password", passwd);
	}
	
	//��������Ŷ���
	CContainer * add_object(const char * obj_name, LONG nAmount = 1);

	virtual LONG Query(int nAttr){
		switch(nAttr)
		{
		case CAN_GET: return 0;
		case IS_BOX: return 1;		
		}
		return CItem::Query(nAttr);
	};

	CBox()
	{ 
		set_name( "����"); 
		set("status", "open");
		set("infinity", 1);		//������������
		set("no_clean_up", 1);
		set("max_items", 10);

		set("no_fight", 1);		//����,��Ȼ������������ս��
		set("no_cast", 1);
	};

	~CBox(){};
};

//�����б�
typedef CList <CDoor *, CDoor *> DTEXITLIST;
typedef CList <CBox *, CBox *> DTBOXLIST;

//��׼����

class CRoom : public CContainer  
{
public:
	virtual int handle_action(char *comm, CChar *me, char * arg, char * tar);

	void remove_all_box();
	virtual void ChangeRoom(CContainer * me);
	virtual int valid_leave(CChar * me, const char * dir);
	virtual void setup();
	void remove_all_doors();
	void remove_doors(const char * arg);
	virtual int do_look(CChar * me);
	CContainer * add_item(const char * item_name);
	DTEXITLIST * query_exits();

	typedef struct{
		string	base_name;	//������
		LONG	object;		//ʵ��ָ��
		int		is_npc;		//�Ƿ�npc

		LONG bx, by, ex, ey;
		int  dir, active;
	}OBJECT_NODE;

	typedef CList <OBJECT_NODE *, OBJECT_NODE *> DTOBJECTLIST;		//��¼NPC�б�
	
	virtual void init(CChar * me);
	CDoor * PresentDoor(const char * id);
	
	CBox * Add_Box(const char * box_type = "box");
	CDoor * add_door(const char * door, const char * next_room, const char * nNextDoor, const char * dir = "");
	virtual void create();
	virtual LONG Query(int nAttr);
	virtual void reset();

	CRoom();
	virtual ~CRoom();
	
protected:
	static void Setup_City(CRoom * city);
	CNpc * add_npc(const char * base_name, LONG bx = 0, LONG by = 0, LONG ex = 0, LONG ey = 0, int dir = 0, int active = 0);

	DTEXITLIST	m_DoorList;		//�����б�
	DTOBJECTLIST	m_ObjectList;		//����б�

	int		m_BoxNum;
};

#endif // !defined(AFX_ROOM_H__0B4E30A3_6536_11D4_98AB_0050BABC5212__INCLUDED_)
