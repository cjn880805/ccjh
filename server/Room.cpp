// Room.cpp: implementation of the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Globle.h"
#include "Room.h"
#include "Npc.h"
#include "User.h"

extern BOOL	g_bReboot;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
void CBox::Locked(char * reason, LONG duration, CChar * me)
	{ 
		set("status", "locked"); 
		
		set("reason", reason);
		set("duration", duration);			//耐久度
		if(me)
			set("owner", me->querystr("id"));		//上锁的主人

		UpdateMe();
	};

CContainer * CBox:: add_object(const char * obj_name, LONG nAmount)
{
	CContainer * item = load_item(obj_name);	//载入物件
	if(nAmount > 1)
		item->set_amount(nAmount);

	item->move(this);
	item->set("no_drop_man",1);//箱子里不可以装人

	return item;
}

void CBox::DownLoad(CChar *me)
{
	POSITION p;
	CContainer * item;

	CContainer::DownLoad(me);

	if(EQUALSTR(querystr("status"), "locked") ) return;		//上锁的箱子看不到内部物品。

	p = m_ItemList.GetHeadPosition();
	while(p)
	{
		item = m_ItemList.GetNext(p);
		me->OnAddObject(item, this);
	}
}

//处理动作
int CBox::handle_action(char *comm, CChar *me, char *arg)
{
	if( strcmp(comm, "open") == 0)
	{
		//如果箱子是某人封上的，钥匙无法打开。
		if(querystr("owner")[0] && DIFFERSTR(querystr("owner"), me->querystr("id")) )
		{
			MessageVision(me, "tell", "你无法打开。");
			return 0;
		}

		//检查me身上是否有钥匙
		DTItemList * t = me->Get_ItemList();
		POSITION p;
		CContainer * key;

		p = t->GetHeadPosition();
		while(p)
		{
			key = t->GetNext(p);
			if(EQUALSTR(key->querystr("base_name"),"key"))
			{
				//试开
				if(key->query("password") == query("password"))
				{
					char msg[255];

					UnLocked();
					snprintf(msg, 255, "只听咔的一响，%s用手中的%s打开了%s。", me->name(), key->name(), name());
					MessageVision(me, "chat", msg);
					return 1;
				}
			}
		}

		MessageVision(me, "tell", "你无法打开。");
	}

	return 0;
}

void CBox::OnEnter(CContainer *me)
{
	CContainer::OnEnter(me);

	m_lUpdate++;

	//通知同一环境内玩家，增加了物件。
	POSITION p;
	DTItemList * t;
	CContainer * obj;

	if(! m_pEnvironment)
	{
		output_error("当%s移入%s时，发现箱子没有环境！", me->name(), name());
		return;
	}

	t = m_pEnvironment->Get_ItemList();
	p = t->GetHeadPosition();
	while(p)
	{
		obj = t->GetNext(p);
		if(obj->Query(IS_USER)) obj->OnAddObject(me, this);
	}

	//存盘
	if(m_pEnvironment->query("saveobjects"))
		SaveObject();
}


void CBox::OnLeave(CContainer *me)
{
	CContainer::OnLeave(me);
	
	m_lUpdate++;

	if(! m_pEnvironment) return;		//当Destruct时,是没有环境的。

	//通知同一环境内玩家，增加了物件。
	POSITION p;
	DTItemList * t;
	CContainer * obj;
	
	t = environment()->Get_ItemList();
	p = t->GetHeadPosition();
	while(p)
	{
		obj = t->GetNext(p);
		if(obj->Query(IS_USER)) obj->OnRemObject(me, this);
	}

	if(m_pEnvironment->query("saveobjects") && ! g_bReboot)	//当重起时,销毁物件移出不算.
		SaveObject();	
}

int CBox::LoadObject()
{
	CMapping m;
	int count = 0;
	char msg[20];

	if(! m_pEnvironment || ! m_pEnvironment->query("saveobjects")) return 0;
	
	LoadFromLocal(querystr("filename"), &m);

	count = m.query("count");
	
	for(int i=0; i<count; i++)
	{
		CMapping * ptr = m.querymap(snprintf(msg, 20, "%ld", i));

		if(! ptr) return 0;

		CContainer * obj = load_item(ptr->querystr("name"));
		obj->create(ptr->query("index"));
		obj->set_amount(ptr->query("amount"));
		obj->move(this);
	}

	return 1;
}

int CBox::SaveObject()
{
	CMapping m;
	char msg[80];

	if(! m_pEnvironment || ! m_pEnvironment->query("saveobjects")) return 0;
	
	//将箱子内的物件存盘
	POSITION p = m_ItemList.GetHeadPosition();
	int count = 0;

	while(p)
	{
		CContainer * obj = m_ItemList.GetNext(p);
		if(obj->is_character()) continue;
		if(obj->Query(IS_MONEY)) continue;		//钱不能放到箱子里存盘

		m.set(snprintf(msg, 80, "%ld/name", count), obj->querystr("base_name"));
		m.set(snprintf(msg, 80, "%ld/index", count), obj->query("index"));
		m.set(snprintf(msg, 80, "%ld/amount", count), obj->Query_Amount());

		count++;
	}

	m.set("count", count);
	
	SaveToLocal(querystr("filename"), &m);
	return 1;
}

void CBox::RemoveObjects()
{
	remove(querystr("filename"));
}

int CDoor::Enter_Door(CChar * me)
{
	//CChar * sprite;
	CRoom * r = load_room(querystr("next_room"));
	if(! r) return 0;

	//sprite = (CChar *)(me->environment())->Present(me->query("sprite"));

	//在me身上做一个下一房间门的标识
	me->set_temp("init_door", querystr("next_door"));
	if(! me->move(r))
	{
		me->delete_temp("init_door");
		return 0;
	}
	me->delete_temp("init_door");

	//if(sprite) sprite->move(r);

	return 1;
}

CRoom::CRoom()
{
	set_name("标准房间");
	set("infinity", 1);		//不受容量限制
	set("max_items", 30);

	m_BoxNum = 0;
}

CRoom::~CRoom()
{
	//释放出口、箱子
	
	remove_all_doors();

	POSITION p;
	OBJECT_NODE * obj;

	p = m_ObjectList.GetHeadPosition();
	while(p)
	{
		obj = m_ObjectList.GetNext(p);
		delete obj;
	}
	m_ObjectList.RemoveAll();
}

//Update时呼叫。
void CRoom::reset()
{
	CNpc * npc;
	CContainer * item;
	OBJECT_NODE * obj;
	POSITION p;

	if(! query("no_clean_up"))
	{
		//将房间内的物品清除
		p = m_ItemList.GetHeadPosition();
		while(p)
		{
			item = m_ItemList.GetNext(p);
			if(item->is_character()) continue;	//不清人

			//设置本房间的等待清除标志，换房间不算
			if(EQUALSTR(querystr("base_name"), "room_void")
				|| (! item->query("no_clean_up") && EQUALSTR(item->querystr_temp("wait_clean"), querystr("base_name")) ) )
			{
				DESTRUCT_OB(item, "CRoom::reset");
			}
			else
				item->set_temp("wait_clean", querystr("base_name"));
		}
	}
	if(query("no_reset_npc")) return;	//不复位NPC

	//查找物件列表，将物件复位
	p = m_ObjectList.GetHeadPosition();
	while(p)
	{
		obj = m_ObjectList.GetNext(p);

		if(obj->is_npc)
		{
			npc = (CNpc *)Present(obj->object);
			if(! npc) npc = find_npc(obj->object);
			if(! npc)
			{
				npc = load_npc(obj->base_name.c_str());
				npc->move(this);
				obj->object = npc->object_id();

				npc->set("map/bx", obj->bx);
				npc->set("map/by", obj->by);
				npc->set("map/ex", obj->ex);
				npc->set("map/ey", obj->ey);
				npc->set("map/dir", obj->dir);
				npc->set("map/active", obj->active);
			}
			else
			{
				if(npc->environment() != this)
					npc->return_home(this);
			}
		}
		else
		{
			item = Present(obj->object);
			if(! item)
			{
				item = load_item(obj->base_name.c_str());
				item->move(this);
				obj->object = item->object_id();
			}
		}
	}
}

//增加NPC
CNpc * CRoom::add_npc(const char * base_name, LONG bx, LONG by, LONG ex, LONG ey, int dir, int active)
{
	CNpc * obj;
	OBJECT_NODE * npc = new OBJECT_NODE;

	obj = load_npc(base_name);
	obj->move(this);
	npc->object = obj->object_id();
	npc->base_name = base_name;
	npc->is_npc = 1;
	npc->bx = bx;
	npc->by = by;
	npc->ex = ex;
	npc->ey = ey;
	npc->dir = dir;
	npc->active = active;

	m_ObjectList.AddHead(npc);
	obj->set("start_city", querystr("base_name"));
	obj->set("map/bx", bx);
	obj->set("map/by", by);
	obj->set("map/ex", ex);
	obj->set("map/ey", ey);
	obj->set("map/dir", dir);
	obj->set("map/active", active);

	return obj;
}

//房间在此创建
void CRoom::create()
{

}

//增加出口，给房间内物件下载入口信息
CDoor * CRoom::add_door(const char * id, const char * next_room, const char * NextDoor, const char * dir)
{
	CDoor * door = new CDoor();
	
	m_DoorList.AddHead(door);
	door->set_name(id, id);
		
	door->set("dir", dir);	//方向
	door->set("next_room", next_room);
	door->set("next_door", NextDoor);
	door->UnLocked();

	//下载出口信息：动态填加时有用。暂时不加此功能
	return door;
}

//增加箱子
CBox * CRoom::Add_Box(const char * box_type)
{
	CBox * box;

	m_BoxNum ++;

	box = (CBox *)load_item(box_type);
	box->move(this);

	//如果本房间是可存盘的，箱子里的物件应该可以被保留
	if(query("saveobjects"))
	{
		char fname[80];
		box->set("filename", snprintf(fname, 80, "data/box/%s_%ld.o", querystr("base_name"), m_BoxNum));
		box->LoadObject();
	}

	return box;
}

LONG CRoom::Query(int nAttr)
{
	switch( nAttr )
	{
	case IS_ROOM:	return 1;
	}

	return CContainer::Query(nAttr);
}

void CRoom::ChangeRoom(CContainer * me)
{
	POSITION p;
	CDoor * door;
	char msg[255];

	CContainer::ChangeRoom(me);

	if(userp(me))
	{
		//传送出口信息
		p = m_DoorList.GetHeadPosition();
		
		while(p)
		{
			door = m_DoorList.GetNext(p);
			snprintf(msg, 255, "&C=%d&R=%ld&D=%s&N=%s&A=%s&",
				ADDDOOR, object_id(), door->querystr("id"), door->name(1), door->querystr("dir"));
			((CUser *)me)->SendCommand(msg, 1);
		}
	
		((CUser *)me)->SendOff();	
	}
}

//通过某号出口  //id也可以是方向
CDoor * CRoom::PresentDoor(const char * id)
{
	POSITION p;
	CDoor * door;

	p = m_DoorList.GetHeadPosition();
	while(p)
	{
		door = m_DoorList.GetNext(p);
		if( EQUALSTR(door->querystr("id"), id) || EQUALSTR(door->querystr("dir"), id) )
		{
			return door;
		}
	}

	return 0;
}

//当角色进入时执行
void CRoom::init(CChar *me)
{
}

DTEXITLIST * CRoom::query_exits()
{
	return & m_DoorList;
}

CContainer * CRoom::add_item(const char * item_name)
{
	CContainer * item;
	OBJECT_NODE * obj = new OBJECT_NODE;

	item = load_item(item_name);
	item->move(this);
	obj->object = item->object_id();
	obj->base_name = item_name;
	obj->is_npc = 0;
	m_ObjectList.AddHead(obj);
	
	return item;	
}

int CRoom::do_look(CChar *me)
{
	if(querystr("long")[0])
	{
		char msg[1024];
		snprintf(msg, 1024, "%s", querystr("long"));
		say(msg, me);
	}
	else
		say("这里没有什么特别的。", me);
	return 0;
}


void CRoom::remove_all_doors()
{
	POSITION p;
	CDoor * door;
	
	p = m_DoorList.GetHeadPosition();
	while(p)
	{
		door = m_DoorList.GetNext(p);
		delete door;
	}
	m_DoorList.RemoveAll();	
}

void CRoom::remove_doors(const char * arg)
{
	POSITION p, prep;
	CDoor * door;
	
	p = m_DoorList.GetHeadPosition();
	while(p)
	{
		prep = p;
		door = m_DoorList.GetNext(p);
		if(EQUALSTR(door->querystr("next_room"),arg))
		{
			m_DoorList.RemoveAt(prep);
			delete door;
			break;
		}
	}
}

void CRoom::setup()
{
	if(_M.undefinedp("map"))
		_M.set("map", _M.querystr("base_name"));

	if(_M.undefinedp("area"))
	{
		char area_name[5];
		strncpy(area_name, _M.querystr("base_name"), 4)[4] = 0;
		set("area", area_name);	//区域名
	}

	//设置城市标记
	Setup_City(this);
}

int CRoom::valid_leave(CChar *me, const char * dir)
{	
	return 1;
}

void CRoom::Setup_City(CRoom *city)
{
	static CMapping room_decode;

		room_decode.set("北京", 1);
		room_decode.set("长安", 1);
		room_decode.set("成都", 1);
		room_decode.set("大理", 1);
		room_decode.set("佛山", 1);
		room_decode.set("福州", 1);
		room_decode.set("杭州", 1);
		room_decode.set("衡阳", 1);
		room_decode.set("嘉兴", 1);
		room_decode.set("灵州", 1);
		room_decode.set("南阳", 1);
		room_decode.set("泉州", 1);
		room_decode.set("苏州", 1);
		room_decode.set("武功", 1);
		room_decode.set("襄阳", 1);
		room_decode.set("扬州", 1);
				
		city->set("city", room_decode.query(city->querystr("area")));
}

void CRoom::remove_all_box()
{
	DTItemList list;
	CopyList(&list, &m_ItemList);

	POSITION p = list.GetHeadPosition();

	while(p)
	{
		CContainer * obj = list.GetNext(p);
		if(! obj->Query(IS_BOX)) continue;

		((CBox *)obj)->RemoveObjects();
		DESTRUCT_OB(obj, "CRoom::remove_all_box");
	}

	m_BoxNum = 0;
}

int CRoom::handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "back") == 0)
	{
		char msg[80];
		//检查是否返回总部
		CMapping * ptr = querymap("corps");
		if(! ptr) return 0;

		CVector v;
		ptr->keys(v);

		const char * corps = me->querystr("corps/id");

		if(v.find(corps) == v.end())
			return 0;

		message_vision("$N左右看看，突然矮身一跃，便消失了影踪。", me);
		me->move(load_room(corps));
		tell_room((me->environment()), snprintf(msg, 80, "%s走了进来。", me->name()), me);
		return 1;
	}

	return CContainer::handle_action(comm, me, arg, tar);
}

void CDoor::Bind(const char *next_room, const char *NextDoor)
{
	if(next_room != NULL)
	{
		set("next_room", next_room);
		if(NextDoor != NULL)set("next_door", NextDoor);
	}
}
