//house.h
//玩家房间
//lanwood 2001-03-12

//set_name( "闲人居");
//set("long", "装修词汇");
//set("owner", "1010");
//set("second_owner", "2010");
//set("size", 2);
//set("belong", "佛山");
//set("pay_time", 上次缴费时间);

int valid_string(const char * msg);

#include "resident.h"
#include "../server/Channel.h"
#include "../server/Npc.h"
#include "../combat/Combatd.h"

ROOM_BEGIN(CRhouse);

void create()	
{
	if(_M.undefinedp("name"))
		set_name("房间", "house");	

	set("sleep_room", 1);
	set("area", "house");
	
	set("saveobjects", 1);
	set("max_items", 20);

	CBox * box = Add_Box();
	box->set_name("柜子", "box");
	box->set("max_items", 14);
	box->set("no_drop_man",1);//箱子里不可以装人
		
	make_yongren(querymap("yongren"));
}

void setup()
{
	CDoor * door = add_door("出口", querystr("belong"), querystr("name"), "out");
	door->set_name( querystr("belong"));

	if(query("size") < 2)
		set("map", "玩家民居1");
	else
		set("map", "玩家民居2");

	if(! query("fail_ob"))
		check_pays();
}

static void remove_me(CContainer * ob, LONG param1, LONG param2)
{
	DESTRUCT_OB(ob, "CRhouse::remove_me");
}

void reset()
{
	if(! g_Combatd.query("no_check_house")) 
	{
		if(! Load())	//此房间已经不存在
		{
			call_out(remove_me, 1);
			return;
		}
	}

	CNpc * npc = find_npc(query_temp("yongren"));
	if(! npc) make_yongren(querymap("yongren"));

	//检查拖欠的管理费
	check_pays();
}

void make_yongren(CMapping * yongren)
{
	CNpc * npc = load_npc("monster_yongren");

	if(yongren)
	{
		npc->set_name( yongren->querystr("name"));
		npc->set("welcome", yongren->querystr("welcome"));
		npc->set("long", yongren->querystr("long"));
		npc->set("welcome_master", yongren->querystr("welcome_master"));
		npc->set("combat_exp", yongren->query("combat_exp"));
	}

	if(! npc->query("combat_exp"))
		npc->set("combat_exp", 20000);

	setup_char(npc);

	npc->move(this);

	set_temp("yongren", npc->object_id());
}

LONG Query(int nAttr)
{
	if(nAttr == CAN_SAVE)
		return 1;
	
	return CRoom::Query(nAttr);
}

int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	CChar * yongren = (CChar *)PresentName("monster_yongren", IS_NPC);
	char msg[255];

	//任何时候都不可以使用roar
	if(yongren && strcmp(comm, "cast") == 0 && strcmp(arg, "force roar") == 0)
	{
		message_vision("$N拦住$n道：“想抢书？出去！”", yongren, me);
		return 1;
	}

	//不是主人
	if(DIFFERSTR(querystr("owner"), me->id(1))
		&& DIFFERSTR(querystr("second_owner"), me->id(1)))
	{
		if(yongren)
		{
			//截获使用时空贴的指令！
			if(strcmp(comm, "trans") == 0 || strcmp(comm, "use") ==0)
			{
				CContainer * obj = me->Present(atol(tar));
				if(! obj) return 0;

				if(EQUALSTR(obj->querystr("base_name"), "transfer_tie")
					|| EQUALSTR(obj->querystr("base_name"), "huicheng_juanzhou"))
				{
					if(check_rent(me))
					{
						message_vision("$N偷偷拿出$n，结果被仆人拦住：“请把借的东西留下！”", me, obj);
						return 1;
					}
				}
			}

			//截获hit，kill，fight，cast，join的指令
			if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0
				|| strcmp(comm, "cast") == 0 || strcmp(comm, "join") == 0||strcmp(comm, "guard") == 0)			
			{
				CContainer * obj = Present(atol(tar));
				if(! obj) return 0;
				
//				if(! obj->is_character()) return 0;
				if( check_rent(me) || check_rent((CChar *)obj) )
				{
					message_vision("$N拦住$n道：“不行，想搞什么出去搞！”", yongren, me);
					return 1;
				}
			}

			//截获drop指令
			if(strcmp(comm, "drop") == 0)
			{
				CContainer * obj = me->Present(atol(tar));
				if(! obj) return 0;
				
				if(obj->query_temp("yongren/rent"))
				{
					message_vision("$N偷偷摸摸的拿出$n，想丢在地上。", me, obj);
					message_vision("$N见状喝道：想干什么！不想要的话还给我！", yongren, me);
					return 1;
				}
			}

			//截获give指令
			if(strcmp(comm, "give") == 0)
			{
				CContainer * obj = me->Present(atol(tar));
				if(! obj) return 0;

				//寻找目标
				LONG target = 0;

				if(sscanf(arg, "to %ld", &target) != 1)
					return 0;

				CContainer * who = Present(target);
				if(who == yongren) return 0;	//可以给用人

				if(obj->query_temp("yongren/rent"))
				{
					message_vision("$N偷偷摸摸的拿出$n，想转手给人。", me, obj);
					message_vision("$N见状喝道：想干什么！不想要的话还给我！", yongren, me);
					return 1;
				}
			}

			//截获get指令
			if(strcmp(comm, "get") == 0 )
			{
				//判断物品是否合法
				CContainer * obj = Present(atol(tar));
				if(! obj) return 0;

				if(obj->query_temp("yongren/rent"))
				{
					message_vision(snprintf(msg, 255, "$N弯腰去拣%s，结果被$n一脚踩到了手指上！", obj->name()), me, yongren);
					return 1;
				}

				if(obj->is_character() && check_rent((CChar *)obj))
				{
					message_vision("$N忽然拦住$n，笑道：还是算了吧！", yongren, me);
					return 1;
				}
				if(userp(obj))
				{
					message_vision("$N疑惑的问着$n：你想拣什么？", yongren, me);
					return 1;
				}
			}			

			//截获sell指令
			if(strcmp(comm, "sell") == 0)
			{
				//判断是否能卖
				CContainer * obj = me->Present(atol(arg));
				if(! obj) return 0;

				if(obj->query_temp("yongren/rent"))
				{
					message_vision(snprintf(msg, 255, "$N想卖掉%s，结果被$n伸手拦住：借的东西快还！", obj->name()), me, yongren);
					return 1;
				}				
			}
		}
	}
	else
	{
		if(strcmp(comm, "housename") == 0)
			return housename(me, arg);
		else if(strcmp(comm, "housedesc") == 0)
			return housedesc(me, arg);
		else if(strcmp(comm, "addmaster") == 0)
			return addmaster(me, arg);
		else if(strcmp(comm, "findbaby") == 0)
			return findbaby(me);
		else if(strcmp(comm, "kickout") == 0)
			return do_kick(me, arg);
		else if(strcmp(comm, "paymoney") == 0)
			return do_paymoney(me, arg);
	}

	return CRoom::handle_action(comm, me, arg, tar);
}

CContainer * check_rent(CChar * me)
{
	if( EQUALSTR(querystr("owner"), me->id(1) )
		|| EQUALSTR(querystr("second_owner"), me->id(1)))
		return 0;

	//搜身
	DTItemList * list = me->Get_ItemList();
	POSITION p = list->GetHeadPosition();
	CContainer * obj;

	while(p)
	{
		obj = list->GetNext(p);
		if(obj->query_temp("yongren/rent"))
			return obj;		
	}
	
	return 0;
}

int valid_leave(CChar * me, const char * dir)
{
	//租借的物品不允许带出房间
	if(EQUALSTR(dir, "出口"))
	{
		CChar * who = (CChar *)PresentName("monster_yongren", IS_NPC);
		CContainer * obj = check_rent(me);
		if(who && obj)
			return notify_fail("%s伸手拦住你，说：把%s留下！！", who->name(), obj->name());
	}

	return CRoom::valid_leave(me, dir);
}

//设置第二房主
int addmaster(CChar * me, char * arg)
{
	if(DIFFERSTR(querystr("owner"), me->id(1)))
	{
		say("对不起，只有户主才邀请其他人同住。", me);
		SendMenu(me);
		return 1;
	}

	if(query("size") < 2)
	{
		say("对不起，这个房间不能再住其他人了。", me);
		SendMenu(me);
		return 1;
	}

	CUser * owner = find_online(arg);
	if(! owner)
	{
		say("对不起，请这个人在线时再来注册房主。", me);		
		SendMenu(me);
		return 1;
	}
	
	set("second_owner", arg);
	update_register();

	tell_object(me, "OK.");
	return 1;
}

//赶出去
int do_kick(CChar * me, char * arg)
{
	char msg[255];
	CUser * who = find_online(arg);
	if(! who) return notify_fail("你想踢谁？");

	if( EQUALSTR(querystr("owner"), who->id(1) ))
		return notify_fail("没搞错，人家可是房主哎！！");

	if(who->environment() == this)
	{
		message_vision("$HIY$N飞起一脚，将$n踢出了门外！", me, who);

		//先把身上的租用品留下！
		DTItemList list;
		CContainer * obj;

		CopyList(&list, who->Get_ItemList());
		POSITION p = list.GetHeadPosition();

		while(p)
		{
			obj = list.GetNext(p);
			if(obj->query_temp("yongren/rent"))
			{
				obj->move(this);
				message_vision("$n从$N身上掉落下来。", who, obj); 
			}
		}

		list.RemoveAll();

		who->move(load_room(querystr("belong")));
	}
	else
	{
		tell_object(me, snprintf(msg, 255, "你拒绝让%s登门造访！", who->name(1)));
	}
	
	if(EQUALSTR(who->querystr_temp("invite"), querystr("owner") ))
		who->delete_temp("invite");

	return 1;
}

//设置房间名称
int housename(CChar * me, char * arg)
{
	string msg;
	
	msg = check_legal_name(arg);
	if(msg.length())
	{
		say(msg.c_str(), me);
		SendMenu(me);
		return 1;
	}
	
	if(! LockData(1)) return 0;
	
	if(! Load())	//此房间已经不存在
	{
		call_out(remove_me, 1);
		return 1;
	}

	set_name(arg);

	update_register();
	LockData(0);
	
	tell_object(me, "OK.");
	
	return 1;
}

//设置房间描述
int housedesc(CChar * me, char * arg)
{
	int len = strlen(arg);
	if(len < 1 || len > 500)
	{
		say("给您的房间描述写得简洁漂亮点。", me);
		SendMenu(me);
		return 1;
	}

	if(! valid_string(arg))
		return 0;
	
	if(! LockData(1)) return 0;
	
	if(! Load())	//此房间已经不存在
	{
		call_out(remove_me, 1);
		return 1;
	}

	set("desc", arg);

	Save();	
	LockData(0);
	
	return 1;
}

//更新注册信息
void update_register()
{
	char msg[255];
	CRoom * r = load_room(querystr("belong"));
	
	if(! r->Query(IS_RESIDENT))
	{
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "update:房间%s所注册的区域%s不是可利用的居住区！", name(1), r->name(1)));
		return;
	}
		
	((CRresident *)r)->update_register(this);

	Save();
}

virtual int do_look(CChar *me)
{
	say(Long(), me);
	say(querystr("desc"), me);
	
	if(EQUALSTR(querystr("owner"), me->id(1))
		|| EQUALSTR(querystr("second_owner"), me->id(1)))
	{
		AddMenuItem("拒绝客人来访", "$2kickout 0 $2", me);
		AddMenuItem("修改房间名称", "$2housename 0 $2", me);
		AddMenuItem("修改房间描述", "$2housedesc 0 $2", me);

		if(EQUALSTR(querystr("owner"), me->id(1)) && query("size") > 1)
			AddMenuItem("邀请其他人同住", "$2addmaster 0 $2", me);

		if(EQUALSTR(me->querystr("gender"), "女性") && me->query("child"))
			AddMenuItem("找宝宝", "$0findbaby", me);
	}

	SendMenu(me);
	return 1;
}

int findbaby(CChar * me)
{
	if(DIFFERSTR(me->querystr("gender"), "女性"))
	{
		say("小宝贝去哪了，让你的妻子帮你找找。", me);
		SendMenu(me);
		return 1;
	}
		
	CChar * baby;
	char msg[255];

	for(int i=1; i<= me->query("child"); i++)
	{
		//必须在孩子的父亲找
		if(DIFFERSTR(me->querystr(snprintf(msg, 255, "child_%ld/father", i)), querystr("owner")))
			 continue;			

		baby = NULL;
		LONG baby_id = query_temp(snprintf(msg, 255, "baby_%ld", i));

		if(baby_id)
			baby = find_npc(baby_id);
		
		if(! baby)
		{
			baby = load_npc("monster_baby");

			set_temp(msg, baby->object_id());
					
			baby->set("gender", me->querystr(snprintf(msg, 255, "child_%ld/gender", i)));
			baby->set("long", me->querystr(snprintf(msg, 255, "child_%ld/long", i)));
			baby->set_name( me->querystr(snprintf(msg, 255, "child_%ld/name", i)));
			baby->set("father", me->querystr(snprintf(msg, 255, "child_%ld/father", i)));
			baby->set("mother", me->querystr("id"));
			baby->set("icon", CChar::boy1);
			if(EQUALSTR(baby->querystr("gender"), "女性") )
				baby->set("icon", CChar::girl1);
		
			baby->move(this);
			message_vision("$N从床下钻了出来。", baby);			
		}
		
		if(baby->environment())
			AddMenuItem(snprintf(msg, 255, "%s位于%s里。", baby->name(), (baby->environment())->name()), "", me);		
	}

	SendMenu(me);
	return 1;
}

//检查拖欠管理费
void check_pays()
{
	char msg[255];

	CRoom * r = load_room(querystr("belong"));

	if(! r->Query(IS_RESIDENT))
	{
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "check_pays:房间%s所注册的区域%s不是可利用的居住区！", name(1), r->name(1)));
		return;
	}
	
	int days = ((CRresident *)r)->count_days(querystr("owner"));
	LONG price = ((CRresident *)r)->house_price();

	if(query("size") < 2) price /= 2;
	set("need_pays", days * price / 500);
}

//交纳帐单
//交纳房屋帐单
int do_paymoney(CChar * me, char * arg)
{
	char msg[255];
	LONG pay = query("need_pays");
	if(! pay) return 0;

	if(! strlen(arg))
	{
		say(snprintf(msg, 255, "一张%s的管理费用结算单。\n\n截止今日累计费用合计%ld金。\n\n注意：当拖欠时间超过一个月，您将失去本房间的居住权。", 
			name(), pay),	me, "房屋帐单");
		AddMenuItem("结算", "$0paymoney 0 1", me);
		AddMenuItem("不予理会", "", me);
	}
	else
	{
		if(! LockData(1)) return 0;
		
		if(! Load())	//此房间已经不存在
		{
			call_out(remove_me, 1);
			return 0;
		}
		
		check_pays();
		pay = query("need_pays");

		if(! CMoney::Player_Pay(me, pay))
		{
			say("对不起，现金不足！", me);
		}
		else
		{
			del("need_pays");
			set("pay_time", current_time);
			update_register();
		}

		LockData(0);
		say(snprintf(msg, 255, "支付了%ld金结算帐单！", pay), me);		
	}

	SendMenu(me);
	return 1;
}


ROOM_END;




