#include <cstring>
#include "../server/Room.h"
#include "../server/User.h"
#include "../std/Money.h"
#include "../server/Channel.h"
#include "../std/npcmirror.h"

char * check_legal_name(const char * name);

#define RESIDENT_BEGIN(room_name)	class room_name : public CRresident	{	public:	room_name(){};	virtual ~room_name(){};
#define RESIDENT_END		};	

//标准居民区
//Lanwood 2001-03-12

//设置城市标记
//set("resident", "襄阳");
//set("capacity", 50);	//申请规模 //delete
//set("price", 100);	//价格		//delete

//house->set("owner", "1010");		//second owner
//house->set_name( "月楼");
//house->set("short", "房主描述");
//house->set("time", 付款时间);
//house->set("size", 1);		//单人间标记

//住户列表：set("house/lanwood", house);

//增加可以卖房。lanwood 2001-03-25

/*

1.83 版 lanwood 2001-04-26

每户资料给0.1K空间 7K
最大可居住70户。全国有15处住宅，也仅能住1050户。
因此，为节约资源：规定，每户房产每天缴纳地价的%1。

上次付款时间。在居民区reset的时候会自动计算一次。! random(10)的时候。不需要每次都算。
当前时间 - 上次付款时间 
每天 * 当地房价 / 100;
100W的房子，一周要支付7万的税金。
如果欠费超过房价的一半，就要强制回收。
大约拖欠7周时间，房子就自动回收了。

房主每次回家，如拖欠税金，要有提示。由仆人自动问候的时候说。每次上线只说一次。
房主可与仆人对话查看帐单和交纳税金。

卖房只能卖房价的一半 - 拖欠税金。

*/

ROOM_BEGIN(CRresident);

//被巫师通缉的人进入此场景后将会被NPC进行追杀
//秦波 2003、3、20
virtual void init(CChar *me)
{
	CRoom::init(me);
	if(userp(me) && !query_temp("is_fighting") )
	{
		if(me->query("tongji"))
		{
			char msg[255];
			tell_object(me,snprintf(msg, 255,"$HIR你发现%s的气氛很古怪，每个人都用很不友善的眼光看着你。",querystr("base_name")));
			remove_call_out(do_killer);
			call_out(do_killer, 3, me->object_id());
		}
	}
}

//计算拖欠天数
int count_days(const char * owner)
{
	char msg[80];

	CMapping * r = querymap(snprintf(msg, 80, "house/%s", owner) );
	if(! r ) return 0;
/*
	if(! r->query("time"))	//还没有注册的老用户
	{		
		CRoom * room = get_local_house(owner);
		room->set("pay_time", current_time);
		room->Save();

		r->set("time", current_time);
		Save();	
	}
*/	
	return (current_time - r->query("time")) / 86400;
}

//计算税金
void clear_house()
{
	char msg[255];

	CMapping * house = querymap("house");
	if(! house) return;

	CMapping * r;
	CRoom * room;

	CVector v;

	house->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		const char * key = v[i];
		r = house->querymap(key);
		if(! r) continue;

		int days = count_days(key);

		if(days >= 30)	//超过30天，房子被自动吊销
		{
			room = get_local_house(key);

			if(! room)	//该房间已不存在
			{
				set_house(key, 0);
				DESTRUCT_OB(room, "CRresident::clear_house");
				return;
			}
			
			snprintf(msg, 255, "%s由于房主%s(%s)长期拖欠物业管理费，被%s政府抵押收回。",
				r->querystr("name"), r->querystr("short"),
				key, _M.querystr("resident"));

			g_Channel.do_channel(&g_Channel, 0, "news", msg);

			remove_house(room);
			return;				//必须返回.因为物件销毁,链表出错.一次只收回一座房屋.
		}
	}
}

//删掉一处住房
void remove_house(CRoom * house)
{
	char msg[255];
	CUser * owner = find_online(snprintf(msg, 255, "%s", house->querystr("owner")));
	int flag1 = 0;

	if(! owner)
	{
		flag1 = 1;
		owner = add_user();
	
		owner->set("id", house->querystr("owner"));
		owner->LoadFromServer();
	}

	owner->del("resident");
	owner->set("start_city", START_ROOM);
	owner->Save();

	if(flag1)
		DESTRUCT_OB(owner, "CRresident::remove_house");
	
	set_house(house->querystr("owner"), 0);
	
	house->remove_all_box();
	house->Remove();
	DESTRUCT_OB(house, "CRresident::remove_house");
}

void reset()
{
	CRoom::reset();

	if(wait_clear --)
		return;
		
	Load();

	wait_clear = 40 + random(40);
	clear_house();
}

//房产价格
LONG house_price()
{
	static int price[15] = 
	{	
		50,			//0
		60,			//5
		72,			//10
		85,			//15
		100,		//20
		125,		//25
		150,		//30
		180,		//35
		216,		//40
		260,		//45
		312,		//50
		375,		//55
		450,		//60
		540,		//65
		650,		//70
	};

	CMapping * house = querymap("house");
	if(! house) return 500000;

	int lv = house->GetCount() / 5;

	if(lv > 14) return 6500000;
	return price[lv] * 10000;
}

void check_second_owner(CChar * me)	//增加第二房主的菜单
{
	char msg[255], tmp[80];

	CMapping * house = querymap("house");
	if(! house) return;
	
	CMapping * r;
	const char * owner = me->id(1);

	CVector v;

	house->keys(v);

	for(int i=0; i<v.count(); i++)
	{
		const char * key = v[i];
		r = house->querymap(key);

		if( strcmp(r->querystr("owner"), owner) == 0 && strcmp(key, owner) != 0) 
		{
			AddMenuItem(snprintf(msg, 255, "进入%s", r->querystr("name")),
				snprintf(tmp, 80, "$0enter 0 %s", key), me);
		}
	}	
}

int do_look(CChar *me)
{
	char msg[255], master[40];
	CMapping * house = querymap("house");

	if(house)
		snprintf(msg, 255, "这里是%s城的住宅区。目前这里有%ld家住户。", querystr("resident"), house->GetCount());
	else
	{
		snprintf(msg, 255, "这里是%s城的住宅区。目前这里没有任何住户。", querystr("resident"));		
	}

	say(msg, me);

	if(EQUALSTR(me->querystr("resident"), querystr("resident")))
		AddMenuItem("回家", snprintf(msg, 255, "$0enter 0 %s", me->id(1)), me);
	else if(can_apply_house())
		AddMenuItem(snprintf(msg, 255, "申请成为%s居民", querystr("resident")), "$0applyhouse", me);

	check_second_owner(me);	//增加第二房主的菜单

	if(me->querystr_temp("invite")[0])
	{
		strncpy(master, me->querystr_temp("invite"), 40);
		CChar * u = find_online(master);
		if(u) AddMenuItem(snprintf(msg, 255, "去%s的家", u->name()), snprintf(master, 40, "$0enter 0 %s", u->id(1)), me);
	}

	if(house)
		AddMenuItem("查看有哪些住户", "$0checkhouse", me);
			
	if(EQUALSTR(me->querystr("resident"), querystr("resident")) )
	{
		CRoom * r = get_my_house(me);
		if(r) AddMenuItem(snprintf(msg, 255, "卖掉%s",  r->name()), "$0sellhouse 0 0", me);
	}

	SendMenu(me);
	return 1;
}

//是否可以申请住房
int can_apply_house()
{
	CMapping * house = querymap("house");
	if(! house) return 1;
	if(house->GetCount() < 70) return 1;
	return 0;
}

int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(strcmp(comm, "enter") == 0)
		return backhome(me, arg);
	else if(strcmp(comm, "applyhouse") == 0)
		return applyhouse(me);
	else if(strcmp(comm, "applyroom") == 0)
		return applyroom(me, arg);
	else if(strcmp(comm, "housename") == 0)
		return housename(me, arg);
	else if(strcmp(comm, "housedesc") == 0)
		return housedesc(me, arg);
	else if(strcmp(comm, "registerhouse") == 0)
		return registerhouse(me);			
	else if(strcmp(comm, "addmaster") == 0)
		return addmaster(me, arg);
	else if(strcmp(comm, "checkhouse") == 0)
		return checkhouse(me);
	else if(strcmp(comm, "sellhouse") == 0)	
		return sellhouse(me, arg);			
	
	return CRoom::handle_action(comm, me, arg, tar);
}

//针对房间列表的修改均在此
int set_house(const char * menpai, CMapping * m)
{
	char msg[80];
	if(! LockData(1)) return 0;
	Load();

	if(m)
	{
		set(snprintf(msg, 80, "house/%s", menpai), (* m));		
	}
	else
	{
		del(snprintf(msg, 80, "house/%s", menpai));
	}

	Save();
	LockData(0);
	return 1;
}

//卖掉自己的住房
int sellhouse(CChar * me, const char * arg)
{
	char msg[255];

	//判断房间是否存在本qu 
	 if(! querymap(snprintf(msg, 255, "house/%s", me->id(1))) )
	{
		say("你要卖掉的房间不在本区！", me);
		SendMenu(me);
		return 1;
	}

	CRoom * house = get_my_house(me);

	if(! house || ! house->Load())
	{
		DESTRUCT_OB(house, "CRresident::sellhouse");
		return notify_fail("你的房子已经卖掉了．");
	}	
	
	if(DIFFERSTR(house->querystr("owner"), me->querystr("id")))
		return notify_fail("这不是你的房子。");

	LONG price = house_price();			
	if(house->query("size") == 1) price /= 2;	//单人房的折半
	
	price /= 2; 	//卖房只值原价的一半

	LONG shui = price * count_days(me->querystr("id")) / 500;
	price -= shui;

	if(price < 0)
		price = 1;

	if(EQUALSTR(arg, "0"))
	{
		say(snprintf(msg, 255, "%s目前价值%ld。卖掉房子意味着你从本市迁出。真的要卖吗？", house->name(), price), me);
		AddMenuItem("决定卖了", "$0sellhouse 0 1", me);
		AddMenuItem("离开", "", me);
		SendMenu(me);
		return 1;
	}

	say(snprintf(msg, 255, "你卖掉了%s，获得%ld。", house->name(), price), me);
	SendMenu(me);

	//真的卖了。
	CMoney::Pay_Player(me, price);

	//写入日志
	output_error("%s(%s)在%s卖掉房子%s(%s)，获利%ld。From (%s)", me->name(1), me->id(1), name(1), house->name(1), house->querystr("base_name"), price, GetIP(me));

	remove_house(house);
	return 1;
}

//返回玩家的房间 这是有可能返回0的函式。0表示玩家尚无住宅。
static CRoom * get_my_house(CChar * me)
{
	char msg[255];

	if(! me->querystr("resident")[0]) return 0;
	CRoom * r = load_room(snprintf(msg, 255, "house_%s_%s", me->querystr("resident"), me->id(1)));	
	if(r->query("fail_ob")) return 0;
	return r;
}

CRoom * get_local_house(const char * menpai, int force = 0)
{
	char msg[255];
	CRoom * r = load_room(snprintf(msg, 255, "house_%s_%s", querystr("resident"), menpai));	
	if(! force && ! r->Load()) return 0;
	return r;
}

int backhome(CChar * me, char * arg)
{
	char msg[255];

	//判断要闯入的房间是否存在
	CMapping * house = querymap(snprintf(msg, 255, "house/%s", arg));

	if(! house)
	{
		say("你要进入的房间不在本区！", me);
		SendMenu(me);
		return 1;
	}

	if(EQUALSTR(arg, me->querystr("id") )
		|| EQUALSTR(house->querystr("owner"), me->querystr("id"))
		|| EQUALSTR(arg, me->querystr_temp("invite")) )
	{
		CRoom * r = get_local_house(arg);
		if(! r)
		{
			say("此房间不存在!", me);
			SendMenu(me);			
			return 1;
		}

		if(DIFFERSTR(arg, me->querystr("id")) && DIFFERSTR(house->querystr("owner"), me->querystr("id")) )
		{
			if(! r->present(arg) )
			{
				say("主人不在家，不能闯入！", me);
				SendMenu(me);
				return 1;
			}
		}
		MessageVision(me, "chat", snprintf(msg, 255, "%s进入了%s。", me->name(), house->querystr("name")), me);
		me->move(r);
		MessageVision(me, "chat", snprintf(msg, 255, "%s走了进来。", me->name()), me);
		return 1;
	}

	say(snprintf(msg, 255, "你试图闯入%s，结果没有成功！", house->querystr("name")), me);
	SendMenu(me);
	return 1;
}

int applyhouse(CChar * me)
{
	char msg[255];

	if(me->querystr("resident")[0])
	{
		say(snprintf(msg, 255, "你已经申请成为%s人了。", me->querystr("resident")), me);
		SendMenu(me);
		return 1;
	}

	if(me->query("age") < 16)
	{
		say(snprintf(msg, 255, "你还没成年，做不了房主。"), me);
		SendMenu(me);
		return 1;
	}
	
	AddMenuItem("申请单人间", "$0applyroom 0 1", me);
	AddMenuItem("申请双人套房", "$0applyroom 0 2", me);	//可以有两个主人
	SendMenu(me);
	return 1;
}

LONG need_money(CChar * me)
{
	LONG money = house_price();
	
	if(me->query_temp("house/size") == 1)
		money /= 2;

	return money;
}

int applyroom(CChar * me, const char * arg)
{
	char msg[255];
	CContainer * coin = me->present("coin");
	
	me->set_temp("house/size", 2);
	if(EQUALSTR(arg, "1"))
	{
		me->set_temp("house/size", 1);
	}

	LONG money = need_money(me);

	if(! coin || coin->query("value") < money)
	{
		say(snprintf(msg, 255, "申请房间需要%ld金，请备好现金再来。", money), me);
		SendMenu(me);
		return 1;
	}

	menulist(me);	
	return 1;
}

void menulist(CChar * me)
{
	AddMenuItem("设置房间名称", "$2housename 0 $2", me);
	AddMenuItem("设置房间描述", "$2housedesc 0 $2", me);

	if(me->query_temp("house/size") > 1)
		AddMenuItem("设置第二房主", "$2addmaster 0 $2", me);
	
	if(me->querystr_temp("house/name")[0])
	{
		AddMenuItem("申请房间", "$0registerhouse", me);
	}

	SendMenu(me);
}

//设置第二房主
int addmaster(CChar * me, char * arg)
{
	CUser * owner = find_online(arg);
	if(! owner)
	{
		say("对不起，请这个人在线时再来注册房主。", me);		
	}
	else
		me->set_temp("house/owner", arg);

	menulist(me);
	return 1;
}

//设置房间名称
int housename(CChar * me, char * arg)
{
	const char * msg = check_legal_name(arg);
	if(msg[0])
	{
		say(msg, me);
	}
	else
		me->set_temp("house/name", arg);

	menulist(me);
	return 1;
}

//设置房间描述
int housedesc(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 500)
	{
		say("给您的房间描述写得简洁漂亮点。", me);
	}
	else
		me->set_temp("house/desc", arg);

	menulist(me);
	return 1;
}

//更新注册
void update_register(CRoom * house)
{
	CMapping m;
	char msg[255];

	m.set("name", house->querystr("name"));
	m.set("owner", house->querystr("second_owner"));
	m.set("time", house->query("pay_time"));		//上次付费时间
	
	CUser * owner = find_online(snprintf(msg, 255, "%s", house->querystr("owner")));
	int flag1 = 0;

	if(! owner)
	{
		flag1 = 1;
		owner = add_user();
	
		owner->set("id", house->querystr("owner"));
		owner->LoadFromServer();
	}

	if(house->querystr("second_owner")[0])
	{
		CUser * owner2 = find_online(snprintf(msg, 255, "%s", house->querystr("second_owner")));
		int flag2 = 0;

		if(! owner2)
		{
			flag2 = 1;
			owner2 = add_user();
			owner2->set("id", house->querystr("second_owner"));
			owner2->LoadFromServer();
		}

		house->set("long", snprintf(msg, 255, "这里是%s和%s的共享房间。", owner->name(1), owner2->name(1)));
		m.set("short", snprintf(msg, 255, "%s和%s", owner->name(1), owner2->name(1)));
		if(flag2) DESTRUCT_OB(owner2, "CRresident::update_register");
	}
	else
	{
		house->set("long", snprintf(msg, 255, "这里是%s的私人房间。", owner->name()));
		m.set("short", snprintf(msg, 255, "%s", owner->name(1)));
	}

	if(flag1) DESTRUCT_OB(owner, "CRresident::update_register");
	
	set_house(house->querystr("owner"), &m);	
}

//注册房间
int registerhouse(CChar * me)
{
	char msg[255];

	const char * house_name = me->querystr_temp("house/name");
	if(! house_name[0])
	{
		AddMenuItem("请给您的房间起个名字", "$1housename 0 $2", me);
		SendMenu(me);
		return 1;
	}

	if(! can_apply_house())
	{
		say("对不起，本居民区已无空房，不能办理申请手续！", me);
		SendMenu(me);
		return 1;
	}

	LONG money = need_money(me);
	if(! CMoney::Player_Pay(me, money))
	{
		say("对不起，你的现金不足！", me);
		SendMenu(me);
		return 1;
	}

	CRoom * r = get_local_house(me->querystr("id"), 1);

	if(! r)
	{
		say("此房间不存在!", me);
		SendMenu(me);			
		return 1;
	}

	time_t t;

	r->set_name(me->querystr_temp("house/name"));
	r->set("desc", me->querystr_temp("house/desc"));
	r->set("size", me->query_temp("house/size"));
	r->set("owner", me->id(1));
	r->set("belong", querystr("base_name"));
	r->set("second_owner", me->querystr_temp("house/owner"));
	r->set("pay_time", time(&t));	//管理费开始时间 lanwood 2001/04/27
	r->del("fail_ob");
	
	r->remove_all_doors();
	r->setup();
	//r->add_door(querystr("base_name"), querystr("base_name"), r->querystr("owner"));

	r->Save();
		
	me->set("resident", querystr("resident"));
	me->delete_temp("house");
	
	if(EQUALSTR(me->querystr("title"), "普通百姓"))
	{
		me->set("title", snprintf(msg, 255, "%s百姓", querystr("resident")));
		me->UpdateMe();
	}

	//设置起始房间
	me->set("start_city", r->querystr("base_name"));
	me->Save();
	
	//注册
	update_register(r);
		
	char tmp[40];

	AddMenuItem(snprintf(msg, 255, "进入%s。", r->name()), 
		snprintf(tmp, 40, "$0enter 0 %s", me->id(1)), me);

	SendMenu(me);

	//记日志
	output_error("%s(%s)在%s申请住房%s(%s)，花费%ld。", me->name(1), me->id(1), name(1), r->name(1), r->querystr("base_name"), money);

	return 1;
}

//列出住户名单
int checkhouse(CChar * me)
{
	CMapping * house = querymap("house");
	CMapping * r;
	char msg[255];

	if(! house) return 0;
	
	CVector v;

	house->keys(v);

	for(int i=0; i<v.count(); i++)
	{
		const char * key = v[i];
		r = house->querymap(key);

		char tmp[40];
		AddMenuItem(snprintf(msg, 255, "%s(%s)", r->querystr("name"), r->querystr("short")), 
			snprintf(tmp, 40, "$0enter 0 %s", key), me);
	}

	SendMenu(me);
	return 1;
}

void setup()
{
	wait_clear = 40 + random(40);

	Load();	
	CRoom::setup();
}

virtual LONG Query(int nAttr)
{
	if(nAttr == CAN_SAVE)
		return 1;
	if(nAttr == IS_RESIDENT)
		return 1;

	return CRoom::Query(nAttr);
}


static void do_killer(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob->Present(param1);
	if(!me) return;

	DTItemList * list = (me->environment())->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;
	
	while(p)
	{
		obj = list->GetNext(p);
		if( ! obj->Query(IS_LIVING) || obj==me || userp(obj) )
			continue;
		
		CChar * who = (CChar *)obj;
	
		//创建一个怪物。这里将设置NPC增强能力以对付被通缉者
		if(who->query("combat_exp")<me->query("combat_exp"))
		{
			int flag = 11 + random(9);	//难度系数
			CNnpcmirror * monster = (CNnpcmirror *)load_npc("monster_jieyu");
			monster->make_mirror(me, flag);
			monster->set_name(who->name(),who->id(1));
			monster->set_weight(50000000);
			
			monster->set("max_hp",me->query("max_hp")*2);
			monster->set("eff_hp",me->query("max_hp")*2);
			monster->set("hp", me->query("max_hp")*2);
			monster->set("max_mp", me->query("max_mp"));
			monster->set("mp",  me->query("max_mp"));
			monster->set("mp_factor", me->query("mp_factor"));
			monster->set("combat_exp", int(me->query("combat_exp")*1.2));
			monster->set("level",me->query("level"));
			
			int i=me->query("level");
			if((me->query("level")<30 && me->query_skill("force", 1) < 110 && me->query_skill("dodge", 1) < 110 && me->query_skill("parry", 1) < 110)|| (me->query("level")>=30 && me->query("level")<60 && me->query_skill("force", 1) < 220 && me->query_skill("dodge", 1) < 220 && me->query_skill("parry", 1) < 220)|| (me->query("level")>=60 && me->query("level")<80 && me->query_skill("force", 1) < 285 && me->query_skill("dodge", 1) < 285 && me->query_skill("parry", 1) < 285) || me->query("level")>=80)
			{
				if(i>150)i=150;
			}
			else
				i=160;
			
			int lev=2;
			int leveldiff=int(i*lev);
			switch(random(15)+1)
			{
			case 1:
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("taiji_shengong", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("tiyunzong", 50+leveldiff);
				monster->set_skill("unarmed", 50+leveldiff);
				monster->set_skill("taiji_quan", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("sword", 50+leveldiff);
				monster->set_skill("taiji_jian", 50+leveldiff);
				monster->set_skill("blade", 50+leveldiff);
				monster->set_skill("taiji_dao", 50+leveldiff);
				monster->set_skill("taoism", 50+leveldiff);
				monster->set_skill("literate", 50+leveldiff);
				
				monster->map_skill("force", "taiji_shengong");
				monster->map_skill("dodge", "tiyunzong");
				monster->map_skill("unarmed", "taiji_quan");
				monster->map_skill("parry", "taiji_jian");
				monster->map_skill("sword", "taiji_jian");
				monster->map_skill("blade", "taiji_dao");
				break;
			case 2:
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("cuff", 50+leveldiff);
				monster->set_skill("strike", 50+leveldiff);
				monster->set_skill("sword", 50+leveldiff);
				monster->set_skill("staff", 50+leveldiff);
				monster->set_skill("finger", 50+leveldiff);
				monster->set_skill("kurong_changong", 50+leveldiff);
				monster->set_skill("tiannan_step", 50+leveldiff);
				monster->set_skill("jinyu_quan", 50+leveldiff);
				monster->set_skill("wuluo_zhang", 50+leveldiff);
				monster->set_skill("duanjia_sword", 50+leveldiff);
				monster->set_skill("sun_finger", 50+leveldiff);
				monster->set_skill("lm_shangyang", 50+leveldiff);	
				monster->set_skill("literate", 50+leveldiff);
				
				monster->map_skill("force", "kurong_changong");
				monster->map_skill("dodge", "tiannan_step");
				monster->map_skill("finger", "sun_finger");
				monster->map_skill("cuff", "jinyu_quan");
				monster->map_skill("strike", "wuluo_zhang");
				monster->map_skill("parry", "sun_finger");
				monster->map_skill("sword", "duanjia_sword");
				monster->map_skill("staff", "duanjia_sword");
				
				monster->prepare_skill("cuff", "jinyu_quan");
				monster->prepare_skill("strike", "wuluo_zhang");
				break;
			case 3:
				monster->set_skill("persuading", 50+leveldiff);
				monster->set_skill("throwing", 50+leveldiff);
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("finger", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("strike", 50+leveldiff);
				monster->set_skill("sword", 50+leveldiff);
				monster->set_skill("blade", 50+leveldiff);
				monster->set_skill("literate", 50+leveldiff);
				monster->set_skill("mahayana", 50+leveldiff);
				monster->set_skill("buddhism", 50+leveldiff);
				monster->set_skill("jinding_zhang", 50+leveldiff);
				monster->set_skill("tiangang_zhi", 50+leveldiff);
				monster->set_skill("huifeng_jian", 50+leveldiff);
				monster->set_skill("yanxing_dao", 50+leveldiff);
				monster->set_skill("zhutian_bu", 50+leveldiff);
				monster->set_skill("linji_zhuang", 50+leveldiff);
				
				monster->map_skill("force","linji_zhuang");
				monster->map_skill("finger","tiangang_zhi");
				monster->map_skill("dodge","zhutian_bu");
				monster->map_skill("strike","jinding_zhang");
				monster->map_skill("sword","huifeng_jian");
				monster->map_skill("blade","yanxing_dao");
				monster->map_skill("parry","huifeng_jian");
				break;
			case 4:
				monster->set_skill("persuading", 50+leveldiff);
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("unarmed", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("hand",50+leveldiff);
				monster->set_skill("staff", 50+leveldiff);
				monster->set_skill("hamagong", 50+leveldiff);
				monster->set_skill("chanchu_bufa", 50+leveldiff);
				monster->set_skill("shexing_diaoshou", 50+leveldiff);
				monster->set_skill("lingshe_zhangfa", 50+leveldiff);
				monster->set_skill("xunshou_shu",50+leveldiff);
				
				monster->map_skill("force", "hamagong");
				monster->map_skill("dodge", "chanchu_bufa");
				monster->map_skill("unarmed", "shexing_diaoshou");
				monster->map_skill("hand", "shexing_diaoshou");
				monster->map_skill("parry", "lingshe_zhangfa");
				monster->map_skill("staff", "lingshe_zhangfa");
				break;
			case 5:
				monster->set_skill("force", 50+leveldiff);           
				monster->set_skill("huntian_qigong", 50+leveldiff);    
				monster->set_skill("unarmed", 50+leveldiff);           
				monster->set_skill("xianglong_zhang", 50+leveldiff);   
				monster->set_skill("dodge", 50+leveldiff);      	     
				monster->set_skill("xiaoyaoyou", 50+leveldiff);      
				monster->set_skill("parry", 50+leveldiff);           
				monster->set_skill("staff", 50+leveldiff);            
				monster->set_skill("dagou_bang", 50+leveldiff);        
				monster->set_skill("begging", 50+leveldiff);           
				monster->set_skill("xunshou_shu", 50+leveldiff);
				
				monster->map_skill("force", "huntian_qigong");
				monster->map_skill("unarmed", "xianglong_zhang");
				monster->map_skill("dodge", "xiaoyaoyou");
				monster->map_skill("parry", "xianglong_zhang");
				monster->map_skill("staff", "dagou_bang");
				
				monster->prepare_skill("unarmed", "xianglong_zhang");
				break;
			case 6:
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("yunv_xinfa", 50+leveldiff);	
				monster->set_skill("seaforce", 50+leveldiff);		
				monster->set_skill("sword", 50+leveldiff);
				monster->set_skill("yunv_jian", 50+leveldiff);
				monster->set_skill("smithsword",50+leveldiff);	
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("xianyun_bufa", 50+leveldiff);	
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("unarmed", 50+leveldiff);
				monster->set_skill("meinv_quan", 50+leveldiff);    
				monster->set_skill("anranxiaohun_zhang", 50+leveldiff);
				monster->set_skill("tianluo_diwang", 50+leveldiff);
				monster->set_skill("literate", 50+leveldiff);
				
				monster->map_skill("force", "seaforce");
				monster->map_skill("sword", "smithsword");
				monster->map_skill("dodge", "xianyun_bufa");
				monster->map_skill("parry", "anranxiaohun_zhang");
				monster->map_skill("unarmed", "anranxiaohun_zhang");
				break;
			case 7:
				monster->set_skill("cuff", 50+leveldiff);
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("sword", 50+leveldiff);
				monster->set_skill("strike",50+leveldiff);
				monster->set_skill("unarmed", 50+leveldiff);
				monster->set_skill("zixia_shengong", 50+leveldiff);
				monster->set_skill("poyu_quan", 50+leveldiff);
				monster->set_skill("huashan_sword", 50+leveldiff);
				monster->set_skill("hunyuan_zhang", 50+leveldiff);
				monster->set_skill("lonely_sword", 50+leveldiff);
				monster->set_skill("huashan_shenfa",50+leveldiff);
				monster->set_skill("literate", 50+leveldiff);
				monster->set_skill("zhengqijue", 50+leveldiff);
				
				monster->map_skill("cuff", "poyu_quan");
				monster->map_skill("force", "zixia_shengong");
				monster->map_skill("dodge", "huashan_shenfa");
				monster->map_skill("parry", "lonely_sword");
				monster->map_skill("sword", "lonely_sword");
				monster->map_skill("strike", "hunyuan_zhang");
				break;
			case 8:
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("unarmed", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("hand",50+leveldiff);
				monster->set_skill("strike", 50+leveldiff);
				monster->set_skill("sword",50+leveldiff);
				
				monster->set_skill("zhemei_shou",50+leveldiff);
				monster->set_skill("liuyang_zhang",50+leveldiff);
				monster->set_skill("tianyu_qijian",50+leveldiff);
				monster->set_skill("yueying_wubu",50+leveldiff);
				monster->set_skill("bahuang_gong", 50+leveldiff);
				
				monster->map_skill("force", "bahuang_gong");
				monster->map_skill("strike","liuyang_zhang");
				monster->map_skill("dodge", "yueying_wubu");
				monster->map_skill("unarmed", "liuyang_zhang");
				monster->map_skill("strike","liuyang_zhang");
				monster->map_skill("hand", "zhemei_shou");
				monster->map_skill("parry", "liuyang_zhang");
				monster->map_skill("sword","tianyu_qijian");
				
				monster->prepare_skill("strike","liuyang_zhang");
				monster->prepare_skill("hand","zhemei_shou");
				break;
			case 9:
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("unarmed", 50+leveldiff);
				monster->set_skill("jiuyang_shengong", 50+leveldiff);
				monster->set_skill("lingfa", 50+leveldiff);
				monster->set_skill("shenghuo_lingfa", 50+leveldiff);
				monster->set_skill("qiankun_danuoyi", 50+leveldiff);
				monster->set_skill("shenghuo_xinfa", 50+leveldiff);
				
				monster->map_skill("parry", "qiankun_danuoyi");
				monster->map_skill("force", "jiuyang_shengong");
				monster->map_skill("dodge", "qiankun_danuoyi");
				monster->map_skill("lingfa", "shenghuo_lingfa");
				break;
			case 10:
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("sword", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("unarmed",50+leveldiff);
				monster->set_skill("strike",50+leveldiff);
				monster->set_skill("finger",50+leveldiff);
				monster->set_skill("literate",50+leveldiff);
				monster->set_skill("taoism",50+leveldiff);
				monster->set_skill("xiantian_qigong", 50+leveldiff);
				monster->set_skill("xiantian_gong", 50+leveldiff);
				monster->set_skill("quanzhen_jianfa",50+leveldiff);  
				monster->set_skill("quanzhen_jian",50+leveldiff);  
				monster->set_skill("jinyan_gong", 50+leveldiff);   
				monster->set_skill("haotian_zhang", 50+leveldiff);   
				monster->set_skill("sun_finger",50+leveldiff); 
				
				monster->map_skill("force", "xiantian_qigong");
				monster->map_skill("sword", "quanzhen_jianfa");
				monster->map_skill("dodge", "jinyan_gong");
				monster->map_skill("parry", "quanzhen_jianfa");
				monster->map_skill("strike", "haotian_zhang");
				monster->map_skill("finger","sun_finger");
				
				monster->prepare_skill("finger","sun_finger");
				monster->prepare_skill("strike","haotian_zhang");
				break;
			case 11:
				monster->set_skill("buddhism", 50+leveldiff);
				monster->set_skill("literate", 50+leveldiff);
				monster->set_skill("blade", 50+leveldiff);
				monster->set_skill("claw", 50+leveldiff);
				monster->set_skill("club", 50+leveldiff);
				monster->set_skill("cuff", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("finger", 50+leveldiff);
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("hand", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("staff", 50+leveldiff);
				monster->set_skill("strike", 50+leveldiff);
				monster->set_skill("sword", 50+leveldiff);
				monster->set_skill("whip", 50+leveldiff);
				
				monster->set_skill("banruo_zhang", 50+leveldiff);
				monster->set_skill("cibei_dao", 50+leveldiff);
				monster->set_skill("damo_jian", 50+leveldiff);
				monster->set_skill("fengyun_shou", 50+leveldiff);
				monster->set_skill("fumo_jian", 50+leveldiff);
				monster->set_skill("hunyuan_yiqi", 50+leveldiff);
				monster->set_skill("jingang_quan", 50+leveldiff);
				monster->set_skill("longzhua_gong", 50+leveldiff);
				monster->set_skill("luohan_quan", 50+leveldiff);
				monster->set_skill("nianhua_zhi", 50+leveldiff);
				monster->set_skill("pudu_zhang", 50+leveldiff);
				monster->set_skill("qianye_shou", 50+leveldiff);
				monster->set_skill("sanhua_zhang", 50+leveldiff);
				monster->set_skill("riyue_bian", 50+leveldiff);
				monster->set_skill("shaolin_shenfa", 50+leveldiff);
				monster->set_skill("weituo_gun", 50+leveldiff);
				monster->set_skill("wuchang_zhang", 50+leveldiff);
				monster->set_skill("xiuluo_dao", 50+leveldiff);
				monster->set_skill("yingzhua_gong", 50+leveldiff);
				monster->set_skill("yijinjing", 50+leveldiff);
				monster->set_skill("yizhi_chan", 50+leveldiff);
				monster->set_skill("zui_gun", 50+leveldiff);
				
				monster->map_skill("blade", "cibei_dao");
				monster->map_skill("claw", "longzhua_gong");
				monster->map_skill("club", "wuchang_zhang");
				monster->map_skill("cuff", "luohan_quan");
				monster->map_skill("dodge", "shaolin_shenfa");
				monster->map_skill("finger", "yizhi_chan");
				monster->map_skill("force", "yijinjing");
				monster->map_skill("hand", "fengyun_shou");
				monster->map_skill("parry", "nianhua_zhi");
				monster->map_skill("staff", "weituo_gun");
				monster->map_skill("strike", "banruo_zhang");
				monster->map_skill("sword", "fumo_jian");
				monster->map_skill("whip", "riyue_bian");
				
				monster->prepare_skill("finger", "yizhi_chan");
				monster->prepare_skill("strike", "banruo_zhang");
				break;
			case 12:
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("unarmed", 50+leveldiff);
				monster->set_skill("strike", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("staff", 50+leveldiff);
				monster->set_skill("sword", 50+leveldiff);
				monster->set_skill("literate", 50+leveldiff);
				
				monster->set_skill("shenlong_xinfa", 50+leveldiff);
				monster->set_skill("yixingbu", 50+leveldiff);
				monster->set_skill("shenlong_bashi", 50+leveldiff);
				monster->set_skill("huagu_mianzhang", 50+leveldiff);
				monster->set_skill("shedao_qigong", 50+leveldiff);
				
				monster->map_skill("force", "shenlong_xinfa");
				monster->map_skill("dodge", "yixingbu");
				monster->map_skill("unarmed", "shenlong_bashi");
				monster->map_skill("strike", "huagu_mianzhang");
				monster->map_skill("parry", "shedao_qigong");
				monster->map_skill("sword", "shedao_qigong");
				
				monster->prepare_skill("strike", "huagu_mianzhang");
				monster->prepare_skill("unarmed", "shenlong_bashi");
				break;
			case 13:
				monster->set_skill("force", 50+leveldiff);            
				monster->set_skill("claw", 50+leveldiff);              
				monster->set_skill("hand", 50+leveldiff);            
				monster->set_skill("finger", 50+leveldiff);          
				monster->set_skill("unarmed", 50+leveldiff);         
				monster->set_skill("strike", 50+leveldiff);          
				monster->set_skill("leg",50+leveldiff);	           
				monster->set_skill("dodge", 50+leveldiff);           
				monster->set_skill("parry", 50+leveldiff);            
				monster->set_skill("sword", 50+leveldiff);           
				
				monster->set_skill("anying_fuxiang", 50+leveldiff);    
				monster->set_skill("tanzhi_shentong", 50+leveldiff);   
				monster->set_skill("xuanfeng_leg", 50+leveldiff);      
				monster->set_skill("luoying_shenzhang", 50+leveldiff);     
				monster->set_skill("bibo_shengong", 50+leveldiff);     
				monster->set_skill("luoying_shenjian", 50+leveldiff);  
				monster->set_skill("yuxiao_jianfa", 50+leveldiff);       
				monster->set_skill("lanhua_shou", 50+leveldiff);       
				monster->set_skill("qimen_wuxing",50+leveldiff);       
				monster->set_skill("literate", 50+leveldiff);           
				
				monster->map_skill("force"  , "bibo_shengong");
				monster->map_skill("finger" , "tanzhi_shentong");
				monster->map_skill("hand"   , "lanhua_shou");
				monster->map_skill("unarmed", "luoying_shenzhang");
				monster->map_skill("strike", "luoying_shenzhang");
				monster->map_skill("leg", "xuanfeng_leg");
				monster->map_skill("dodge"  , "anying_fuxiang");
				monster->map_skill("parry"  , "tanzhi_shentong");
				monster->map_skill("sword"  , "tanzhi_shentong");
				
				monster->prepare_skill("finger", "tanzhi_shentong");
				monster->prepare_skill("hand", "lanhua_shou");
				break;
			case 14:
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("beiming_shengong", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("lingboweibu", 50+leveldiff);
				monster->set_skill("unarmed", 50+leveldiff);
				monster->set_skill("liuyang_zhang", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("blade", 50+leveldiff);
				monster->set_skill("xiaoyao_dao", 50+leveldiff);
				monster->set_skill("zhemei_shou", 50+leveldiff);
				monster->set_skill("hand", 50+leveldiff);
				monster->set_skill("literate", 50+leveldiff);
				
				monster->map_skill("force", "beiming_shengong");
				monster->map_skill("dodge", "lingboweibu");      
				monster->map_skill("hand", "zhemei_shou");
				monster->map_skill("unarmed", "liuyang_zhang");
				monster->map_skill("parry", "xiaoyao_dao");
				monster->map_skill("blade", "xiaoyao_dao");
				
				monster->prepare_skill("hand","zhemei_shou");
				monster->prepare_skill("unarmed","liuyang_zhang");
				break;
			case 15:
				monster->set_skill("throwing", 50+leveldiff);
				monster->set_skill("feixing_shu", 50+leveldiff);        
				monster->set_skill("force", 50+leveldiff);
				monster->set_skill("huagong_dafa", 50+leveldiff);
				monster->set_skill("dodge", 50+leveldiff);
				monster->set_skill("zhaixinggong", 50+leveldiff);
				monster->set_skill("strike",50+leveldiff);
				monster->set_skill("xingxiu_duzhang", 50+leveldiff);
				monster->set_skill("parry", 50+leveldiff);
				monster->set_skill("staff", 50+leveldiff);
				monster->set_skill("tianshan_zhang", 50+leveldiff);
				monster->set_skill("literate", 50+leveldiff);
				monster->set_skill("sanyin_wugongzhao", 50+leveldiff);
				monster->set_skill("claw", 50+leveldiff);
				monster->set_skill("poison", 50+leveldiff);
				
				monster->map_skill("force", "huagong_dafa");
				monster->map_skill("dodge", "zhaixinggong");
				monster->map_skill("strike", "xingxiu_duzhang");
				monster->map_skill("parry", "feixing_shu");
				monster->map_skill("staff", "tianshan_zhang");
				monster->map_skill("unarmed", "xingxiu_duzhang");
				monster->map_skill("claw", "sanyin_wugongzhao");
				
				monster->prepare_skill("unarmed", "xingxiu_duzhang");
				monster->prepare_skill("claw", "sanyin_wugongzhao");
				break;
			}
			monster->set("no_keep",1);
			monster->set("int",me->query("int")+20);
			monster->set("con",me->query("con")+20);
			monster->set("dex",me->query("dex")+20);
			monster->set("str",me->query("str")+20);
			monster->set("bigboss",1);
			monster->set("repute", 1000);
			
			monster->set("no_kill",1);
			monster->set("no_缠字决",1);
			monster->set_temp("apply/no_连字诀",1);
			monster->set_temp("apply/no_千环套狗",1);
			monster->set_temp("apply/no_相思无用",1);
			monster->set_temp("apply/no_势合形离",1);
			monster->set_temp("apply/no_黯然消魂",1);
			monster->set_temp("apply/no_奔潮诀",1);
			monster->set_temp("apply/no_相思无用",1);
			
			monster->move(me->environment());
			monster->kill_ob(me);
			me->kill_ob(monster);
			//销毁原来的NPC
			destruct(who);
		}
		else
		{
			((CUser *)who)->Ready_PK();
			((CUser *)me)->Ready_PK();
			who->kill_ob(me);
			me->kill_ob(who);	
		}
		break;
	}
}


protected:

int		wait_clear;

ROOM_END;
