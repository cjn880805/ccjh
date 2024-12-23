#include "../server/Room.h"
#include "../server/Npc.h"

#define XiaoYao_BEGIN(room_name)	class room_name : public CRxiaoyao	{	public:	room_name(){};	virtual ~room_name(){};
#define XiaoYao_END		};	

ROOM_BEGIN(CRxiaoyao);

//当角色进入时执行
//非做任务的玩家一旦进入就将踢出
//做任务玩家将随时将自己的存盘点设置在该场景，以备下线后自动继续任务
virtual void init(CChar *me)
{
	if(userp(me) )
	{
		CContainer * yinyue_si;
		yinyue_si=me->present("yingyue si");
		if(me->query("xy/renwu6_lost")<3 && !me->query("xy/renwu_lost"))
		{
			if((!me->querymap("xy") || !yinyue_si) && !wizardp(me) )
			{
				me->move(load_room("佛山北帝庙"));
				return ;
			}
			if(me->querymap("xy") && !me->query("xy/renwu2") && !query("层数") && !query("no_autosave"))
			{
				me->set("start_city", querystr("base_name"));
				me->set("xy/save", 1);
			}
			if(!me->query("xy/renwu4"))
			{
				int chance = query("monster_chance");
				if(chance && chance>50)
					chance=50;
				if(chance && random(100) < chance )
				{
					remove_call_out(present_npc);
					call_out(present_npc, 1, me->object_id());
				}
			}
		}
		else
		{
			//破解九宫之术失败三次后任务失败
			//任务失败
			message_vision("$N突然觉得头疼欲裂，恍忽间，发现自己正傻傻地站在逍遥林石屋，似乎什么事也没有发生。", me);
			me->move(load_room("逍遥林石屋"));
			me->set("start_city", START_ROOM);
			
			//销毁银月之匙
			if(yinyue_si)
				destruct(yinyue_si);
			
			//扣除任务中奖励的逍遥剑法、
			if(me->query_skill("xiaoyao_jianfa",1) )
				me->delete_skill("xiaoyao_jianfa");

			//除任务中奖励的凌波微步之洛神凌波熟练度
			if(me->query("pro/skill/lingbo_weibu")>me->query("xkd/xy"))
			{
				me->add("pro/skill/lingbo_weibu",-1);
				if(me->query("pro/skill/lingbo_weibu")<=0)
					me->del("pro/skill/lingbo_weibu");
			}

			//扣除任务中奖励的一级北冥神功或1000点经验
			if(me->query("xy/renwu3_1"))
			{
				if(EQUALSTR(me->querystr("family/family_name"), "逍遥派"))
				{
					if(me->query_skill("beiming_shengong",1))
					{
						me->add("pro/skill/beiming_shengong",-1);
						if(me->query("pro/skill/beiming_shengong"))
							me->set_skill("beiming_shengong",300+me->query("pro/skill/beiming_shengong"));
						else
						{
							me->set_skill("beiming_shengong",300);
							me->del("pro/skill/beiming_shengong");
						}
					}
					me->FlushMySkill(me);
				}
				else
					me->add("combat_exp",-1000);
			}
			//扣除任务中奖励的10点内力上限
			if(me->query("xy/renwu4_1"))
			{
				me->add("max_mp",-10);
				me->add("mp",-10);
			}
			//清除任务中所有的标志
			me->del("xy");
			me->delete_temp("xy");
		}
	}
}

virtual void setup()
{
	CRoom::setup();
	if(query("层数"))
	{
		CContainer * env;
		char msg[255];
		switch(query("层数"))
		{
		case 2:
			snprintf(msg, 255,"逍遥谷%s塔塔底17",querystr("名称"));
			break;
		case 3:
			snprintf(msg, 255,"逍遥谷%s塔二层26",querystr("名称"));
			break;
		case 4:
			snprintf(msg, 255,"逍遥谷%s塔三层35",querystr("名称"));
			break;
		case 5:
			snprintf(msg, 255,"逍遥谷%s塔四层44",querystr("名称"));
			break;
		case 6:
			snprintf(msg, 255,"逍遥谷%s塔五层53",querystr("名称"));
			break;
		case 7:
			snprintf(msg, 255,"逍遥谷%s塔六层62",querystr("名称"));
			break;
		}
		env = load_room(msg);
		if(env->query("count")>=6)
		{
			del("层数");
			del("位置");
		}
		else
			env->add("count",1);
	}
}

virtual int do_look(CChar * me)
{
	if(query("层数"))
	{
		say("墙上有一个生铁铸成的机关，看样子好像能扳动。", me);
		AddMenuItem("压下", "$0xia $1", me);
		AddMenuItem("推上", "$0shang $1", me);
		SendMenu(me);
	}
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	if(query("层数"))
	{
		if (me->query_temp("xy/renwu4_1")  && me->query("xy/renwu4_3")  )
		{
			char msg[255];
			if(!strcmp(comm, "xia"))
			{
				snprintf(msg, 255,"\n$YEL%s塔的第%d层远远传来一阵隆隆响声。",querystr("名称"),query("层数"));
				tell_object(me,msg);
				tell_object(me,"你将机关压下。\n");
				snprintf(msg, 255,"xy/ta/%s/%s",querystr("名称"),querystr("base_name"));
				if(!me->query_temp(msg)||me->query_temp(msg)!=1)
				{
					me->set_temp(msg,1);
					snprintf(msg, 255,"xy/ta/%s/%d",querystr("名称"),query("层数"));
					if(query("位置")==1)
						me->add_temp(msg,1);
					else
					{
						if(me->query_temp(msg))
							me->add_temp(msg,-1);
						else
							me->delete_temp(msg);
					}
				}
				return 1;
			}
			if(!strcmp(comm, "shang"))
			{
				snprintf(msg, 255,"\n$YEL%s塔的第%d层远远传来一阵隆隆响声。",querystr("名称"),query("层数"));
				tell_object(me,msg);
				tell_object(me,"你将机关推了上去。\n");
				snprintf(msg, 255,"xy/ta/%s/%s",querystr("名称"),querystr("base_name"));
				if(!me->query_temp(msg)||me->query_temp(msg)!=2)
				{
					me->set_temp(msg,2);
					snprintf(msg, 255,"xy/ta/%s/%d",querystr("名称"),query("层数"));
					if(query("位置")==2)
						me->add_temp(msg,1);
					else
					{
						if(me->query_temp(msg))
							me->add_temp(msg,-1);
						else
							me->delete_temp(msg);
					}
				}
				return 1;
			}
		}
	}
	return CRoom::handle_action(comm, me, arg, tar);
}

static void present_npc(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob->Present(param1);
	if(! me) return;
	CNpc * DuWu;
	static char yeshou[8][20]={"animal_bear","animal_eagle","animal_fushe",
		"animal_jinshe","animal_shachong","animal_wubushe","animal_xiezi",
		"animal_yezhu"};
	DuWu = load_npc(yeshou[random(8)]);
	DuWu->move(ob);
	
	message_vision("一阵沙沙声响，草丛中窜出几只怪兽,闪电般向$N扑来。", me);
	
	CFightRoom * obj =  (CFightRoom *)load_item("fight_room");	
	obj->set("room_locked", FIGHT_LOCKED);
	obj->set_name("逍遥谷的战斗", "fight_room");
	obj->move(ob);

	DuWu->move(obj);
	obj->Join_Team(DuWu, CFightRoom::FIGHT_TEAM_A);
	for(int i=0;i<random(2)+1;i++)
	{
		DuWu = load_npc(yeshou[random(8)]);
		DuWu->move(obj);
		obj->Join_Team(DuWu, CFightRoom::FIGHT_TEAM_A);
	}

	me->move(obj);
	obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
	obj->Begin_Fight(0);
	
}

ROOM_END;



