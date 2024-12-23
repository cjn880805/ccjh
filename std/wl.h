#include "../server/Room.h"
#include "../server/Npc.h"

#define WL_BEGIN(room_name)	class room_name : public CRwl	{	public:	room_name(){};	virtual ~room_name(){};
#define WL_END		};	

ROOM_BEGIN(CRwl);

virtual void setup()
{
	CRoom::setup();

	CContainer * env = load_room("jy");
	if(query("yuandan") && env->query("活动")&& !query("start"))
	{
		add_item("cai");
		add_item("cai");
		add_item("cai");
		add_item("cai");
		add_item("tang");
		add_item("guo");
		add_item("jiu1");
		set("start",1);
	}
}

virtual void init(CChar *me)
{
	if(userp(me))
	{
		DTItemList * list = me->Get_ItemList();
		POSITION p = list->GetHeadPosition();
		CContainer * obj;
		while(p)
		{
			obj = list->GetNext(p);
			if(userp(obj) )
			{
				tell_object(me, "这里并不欢迎非法潜入者。");
				obj->move(load_room("佛山北帝庙"));

			}
			else if(EQUALSTR(obj->querystr("id"), "fight_room"))
			{
				tell_object(me, "这里并不欢迎非法潜入者。");
				me->move(load_room("泰山玉皇顶"));
			}
		}
	}
}

int handle_action(char *comm, CChar *me, char * arg, char * target)
{
	if(me->query("grant") < 50)
	{
		if(me->query_temp("jy/no_say"))
		{
			tell_object(me, "由于你的一些行为扰乱了游戏的秩序，这里已经不再欢迎你了！");
			me->move(load_room("佛山北帝庙"));
			return 1;
		}
		else 
		{
			if(query("biwu"))
			{
				if( !strcmp(comm, "go")||!strcmp(comm, "talk") )
					return 0;
				tell_object(me, "$HIR比赛重地，严禁喧哗!\n如索取战报，请先选定相应比赛登记员，输入/talk命令再领取。");
				return 1;
			}
			else
			{
				CContainer * obj = Present(atol(target));
				if(userp(obj))
				{
					if(!strcmp(comm, "kill")||!strcmp(comm, "look")||!strcmp(comm, "fight")||!strcmp(comm, "cast")
						||!strcmp(comm, "invite")||!strcmp(comm, "talk"))
					{
						tell_object(me, "你不可以在这里进行这些危险动作。");
						return 1;
					}
				}
				if(!strcmp(comm, "guard"))
				{
					tell_object(me, "练你自己的，看别人的做什么！");
					return 1;
				}
				if(!strcmp(comm, "ad")||!strcmp(comm, "makelove")||!strcmp(comm, "rumor")||!strcmp(comm, "chat")
					||!strcmp(comm, "party")||!strcmp(comm, "corps")||!strcmp(comm, "wakeup"))
				{
					tell_object(me, "安安静静的练功有什么不好，要吵要闹出去呆着。");
					return 1;
				}
				if(!strcmp(comm, "cast"))
				{
					tell_object(me, "你不可以在这里进行这些危险动作。");
					return 1;
				}
			}
		}
		return 0;
	}

	if(strcmp(comm, "chblk") == 0)
	{
		CContainer * obj = Present(atol(target));
		if(! obj) return notify_fail("请选中当前房间目标.");
		obj->set_temp("jy/no_say", 1);
		message_vision("$N丢出一块胶布，啪的一声贴在$n嘴上。", me, obj); 
		return 1;
	}
	
	return CRoom::handle_action(comm, me, arg, target);
}

virtual void reset()
{
	CRoom::reset();

	CContainer * env = load_room("jy");
	if(query("yuandan") && env->query("活动")&& !query("start"))
	{
		add_item("cai");
		add_item("cai");
		add_item("cai");
		add_item("cai");
		add_item("tang");
		add_item("guo");
		add_item("jiu1");
		set("start",1);
	}
}

ROOM_END;



