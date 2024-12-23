//was_fanseng.h

NPC_BEGIN(CNwas_fanseng);

virtual void create()
{
	switch(random(4))
	{
	case 0:
		set_name("青衣番僧",  "fan seng");
		set("level",1);
		break;
	case 1:
		set_name("白衣番僧",  "fan seng");
		set("level",2);
		break;
	case 2:
		set_name("黄衣番僧",  "fan seng");
		set("level",3);
		break;
	case 3:
		set_name("红衣番僧",  "fan seng");
		set("level",4);
		break;
	}
	set("gender", "男性");
	set("age", 28);
	set("icon",young_monk);
	set("foolid",156); 
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 25+query("level")*2);
	set("int", 25+query("level")*2);
	set("con", 25+query("level")*2);
	set("dex", 25+query("level")*2);
	set("max_hp", 10000+random(8000)+query("level")*1000);
	set("mp", 4500+random(2000)+query("level")*500);
	set("max_mp", 5500+random(1000)+query("level")*5000);
	set("mp_force", 100+query("level")*10);
	set("combat_exp", 1500000+random(1000000)+query("level")*100000);
	set("score", 200000);
	
	set_skill("force", 150+random(150)+query("level")*10);
	set_skill("xiaowuxiang", 150+random(150)+query("level")*10);
	set_skill("dodge", 150+random(150)+query("level")*10);
	set_skill("shenkong_xing", 150+random(150)+query("level")*10);
	set_skill("unarmed", 150+random(150)+query("level")*10);
	set_skill("yujiamu_quan", 150+random(150)+query("level")*10);
	set_skill("parry", 150+random(150)+query("level")*10);
	set_skill("sword", 150+random(150)+query("level")*10);
	set_skill("mingwang_jian", 150+random(150)+query("level")*10);
	set_skill("mizong_xinfa", 150+random(150)+query("level")*10);
	set_skill("literate", 150+random(150)+query("level")*10);
	set_skill("hammer", 150+random(150)+query("level")*10);
	set_skill("riyue_lun", 150+random(150)+query("level")*10);
	
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("sword", "mingwang_jian");
	map_skill("hammer", "riyue_lun");
	
	set("class", "bonze");
	
	carry_object("jinlun")->wield();
	carry_object("p_jiasha")->wear();
	carry_object("sengmao")->wear();

	set("chat_chance_combat", 30+query("level")*3);

	set("no_kill",1);
	set("no_缠字决",1);
	set_temp("apply/no_相思无用",1);
	set_temp("apply/no_势合形离",1);
	set_temp("apply/no_天外飞龙",1);
	set_temp("apply/no_拼命",1);
	set_temp("apply/no_祭血神刀",1);
	
	set("bigboss",1);

};

virtual char * chat_msg_combat()
{
	switch(random(3))
	{
	case 0:
		perform_action("hammer feilun", 0);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
		perform_action("force shield", 1);
		break;
	}

	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("was/renwu2_5") && !me->query_temp("was/renwu3_1") )
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问有关十大门派的事","liupai",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "liupai") )
		{
			message_vision("$HIR番僧对$N大喊道：“想救人？问过我的拳头先。”",me);
			me->set_temp("was/renwu3_1",1);//开始闯塔
			
			char msg[255];
			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set("room_locked", FIGHT_NO_FLEE);
			obj->set_name(snprintf(msg, 255,"%s的战斗", name(1)),"fight_room");		
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
			
			move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
			obj->Begin_Fight(0);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting() && me->query_temp("was/renwu3_1")) 
	{
        if(!random(2))
		{ 
			char msg[255];
			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set("room_locked", FIGHT_NO_FLEE);
			obj->set_name(snprintf(msg, 255,"%s的战斗", name(1)),"fight_room");		
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
			
			move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
			obj->Begin_Fight(0);
		}
	}
}
NPC_END;
