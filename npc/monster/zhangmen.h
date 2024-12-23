//zhangmen.h
//code by Lanwood
//2001-2-26

#define ZHANGMEN_BEGIN(npc_name)	class npc_name : public CNmonster_zhangmen	{	public:	npc_name(){};	virtual ~npc_name(){};
#define ZHANGMEN_END		};	

//掌门NPC
NPC_BEGIN(CNmonster_zhangmen);

void create()
{
	set_name("掌门大弟子", "zhang men");
		
	set("age", 30);
	set("gender", "男性");

	set("max_hp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 15);
	set("combat_exp", 2000000);

    set_skill("force",   150);
	set_skill("unarmed", 150);
	set_skill("sword",   150);
	set_skill("changquan",   150);
	set_skill("hunyuan_yiqi", 150);
	set_skill("jinshe_jian", 150);
	set("nkgain", 1);

	set_weight(50000000);
			
	map_skill("unarmed", "changquan");
	map_skill("force", "hunyuan_yiqi");
	map_skill("sword", "jinshe_jian");

	restore();
};

void setup()
{
	CNpc::setup();

	char msg[80];
	set("title", snprintf(msg, 80, "%s掌门", querystr("family/family_name")));
	set("eff_hp", query("max_hp"));
	set("hp", query("max_hp"));
	set("mp", query("max_mp"));
	set("repute", 0l);
}

void carry_equip(const char * equip)
{
	char name[80];

	strncpy(name, equip, 80);
	
	char * ptr = strstr(name, ",");
	if(! ptr) return;
	(* ptr) = 0;

	CContainer * ob = carry_object(name, 1, atol(ptr + 1));
	ob->wield();
	if(! ob->querystr("owner")[0])
		ob->set("owner", "zhang men");

	ob->set("no_sell", 1);	
	ob->set("no_drop", 1);
}

//恢复
void restore()
{	
	if(! Load())
	{
		carry_object("sword_1")->wield();
		return;
	}

	setup();

	Clean_Up();

	//恢复武器
	const char * weapon = querystr("equip/weapon");
	
	if(weapon[0])
	{
		carry_equip(weapon);
	}

	CVector * v = queryvec("equip/armor");
	if(v)
	{
		for(int i=0; i < v->count(); i++)
		{
			carry_equip((* v)[i]);
		}
	}
}

int accept_fight(CChar * me)
{
	char msg[255];
	
	if(EQUALSTR(me->querystr("id"), querystr("owner_id")))
	{
		say("掌门好。让您见笑了。", me);
		SendMenu(me);
		return 0;
	}
	else if(me->query("zhangmen") 
		&& EQUALSTR(me->querystr("family/family_name"), querystr("family/family_name")))
		me->del("zhangmen");

	restore();

	
	if(EQUALSTR(me->querystr("family/family_name"), querystr("family/family_name"))
		&& me->query_temp("fight_zhangmen"))
	{
		set("hp", query("max_hp"));
		set("eff_hp", query("max_hp"));
		set("mp", query("max_mp"));

		snprintf(msg, 255, "%s掌门争夺擂", querystr("family/family_name"));
		CContainer * ob = Do_BiShi(this, me, msg, 1);
		
		//擂台上不允许偷窃、施法
		ob->set("no_steal", 1);
		ob->set("no_cast", 1);

		g_Channel.do_channel(this, 0, "chat", snprintf(msg, 255, "%s今日挑战%s掌门之位！", me->name(1), querystr("family/family_name")));
		return notify_fail("掌门比试开始！");
	}
	
	say(snprintf(msg, 255, "%s略一抱拳，谦逊道：在下哪里是%s的对手呢！", name(), query_respect(me)), me);
	SendMenu(me);
	return 0;
}

//比试结束时呼叫。
void is_defeated(CChar * winner, CChar * failer)
{
	char msg[255];

	if(winner->query_temp("fight_zhangmen"))
	{
		const char * family = winner->querystr("family/family_name");

		//赢了！
		g_Channel.do_channel(this, 0, "chat", 
			snprintf(msg, 255, "恭喜%s赢得%s掌门之位！", winner->name(1), family));

		//消除原掌门的头衔
		char id[40];
		
		strncpy(id, querystr("owner_id"), 40)[39] = 0;
		if(id[0])
		{
			CUser * user = find_online(id);
			if(user)
			{
				user->del("zhangmen");
				user->Save();
				user->UpdateMe();
			}
			else
			{
				//不在线，改之档案
				user = add_user();	
				
				user->set_name("noname", id);
				user->LoadFromServer();
				user->del("zhangmen");
				user->Save();
				destruct(user);
			}
		}

		//记录现在玩家的数据
		skills.copyMapping(winner->query_skills());
		skill_map.copyMapping(winner->query_skill_map());
		skill_prepare.copyMapping(winner->query_skill_prepare());

		Clean_Up();	//清空装备

		//查询装备：
		CContainer * weapon = winner->query_weapon();

		//记录武器
		if(weapon)
		{
			set("equip/weapon", snprintf(msg, 255, "%s,%ld", weapon->querystr("base_name"), weapon->query("index")));
			carry_equip(msg);
		}

		POSITION p;
		CContainer * obj;		
		DTItemList * list = winner->Get_ItemList();
		CVector v;

		p = list->GetHeadPosition();
		while(p)
		{
			obj = list->GetNext(p);
			if(! obj->query("equipped") ) continue;		//非装备不记录
			if(obj == weapon) continue;		//不记录武器
			v.append(snprintf(msg, 255, "%s,%ld", obj->querystr("base_name"), obj->query("index")));
			
			carry_equip(msg);
		}
	
		if(v.count())
			set("equip/armor", v);

		set("owner_id", winner->querystr("id"));
		set("icon", winner->query("icon"));
		set_name(winner->name(1), "zhang men");		
		set("age", winner->query("age"));
		set("gender", winner->querystr("gender"));
		set("combat_exp", winner->query("combat_exp"));
		set("level", winner->query("level"));

		set("str", winner->query("str"));
		set("con", winner->query("con"));
		set("dex", winner->query("dex"));
		set("int", winner->query("int"));

		set("max_hp", winner->query("max_hp"));
		set("hp", winner->query("max_hp"));
		set("max_mp", winner->query("max_mp"));

		set("family/family_name", family);
		set("family/generation", winner->query("family/generation"));
		
		set("nickname", winner->querystr("nickname"));
				
		Save();		

		UpdateMe();

		winner->delete_temp("fight_zhangmen");
		winner->set_temp("apply/title", querystr("title"));
		winner->set("zhangmen", 1);
		winner->UpdateMe();

		return;
	}
	
	say("哈哈！看来你还得继续努力啊！");	
}

LONG Query(int nAttr)
{
	if(nAttr == CAN_SAVE)
		return 1;

	return CNpc::Query(nAttr);
}

void die()
{
	message_vision("$N恨恨的说道：君子报仇，十年不晚！话音未落，人已纵身跳走。", this);
	destruct(this);
}

NPC_END;
