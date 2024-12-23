//was_hemake.h

NPC_BEGIN(CNwas_hemake);

virtual void create()
{
	set_name("鹤毛客",  "he mao ke");
	set("gender", "男性");
	set("age", 68);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 40);
	set("con", 35);
	set("dex", 35);
	set("icon",old_man2);
	
	set("hp", 30500);
	set("max_hp", 30500);
	
	set("mp", 18500);
	set("max_mp", 18500);
	set("mp_factor", 200);

	set("combat_exp", 70000000);
	set("score", 500000);

	set_skill("cuff", 250);
	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("sword", 400);
	set_skill("strike",250);
	set_skill("unarmed", 250);
	set_skill("zixia_shengong", 250);
	set_skill("poyu_quan", 250);
	set_skill("huashan_sword", 300);
	set_skill("hunyuan_zhang", 250);
	set_skill("lonely_sword", 300);
	set_skill("huashan_shenfa",250);
	set_skill("literate", 220);
	set_skill("zhengqijue", 250);

	map_skill("cuff", "poyu_quan");
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "huashan_shenfa");
	map_skill("parry", "lonely_sword");
	map_skill("sword", "lonely_sword");
	map_skill("strike", "hunyuan_zhang");
	
	create_family("华山派", 13, "弟子");
	set("chat_chance_combat", 60);
	set("family/master_id", "feng qingyang");

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
};

virtual char * chat_msg_combat()
{
	switch(random(5))
	{
	case 0:
		perform_action("force powerup", 0);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	case 2:
		perform_action("sword poqi", 1);
		break;
	case 3:
		perform_action("sword pozhang", 1);
		break;
	case 4:
		perform_action("sword pojian", 1);
		break;
	}

	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("was/renwu3_1"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("询问六大门派","liupai",me);
			SendMenu(me);
		}
		else if(!strcmp(ask, "liupai") )
		{
			message_vision("$HIR鹿棍翁大怒道：“想救人？给我个MM先……sorry，说错对白了，是先问过我们的玄冥神掌先。”",me);
			
			char msg[255];
			CFightRoom * obj;
			CContainer * env = me->environment();
			obj = (CFightRoom *)load_item("fight_room");		
			
			obj->set("room_locked", FIGHT_NO_FLEE);
			obj->set_name(snprintf(msg, 255,"%s的战斗", name(1)),"fight_room");		
			obj->move(env);
			
			me->move(obj);
			obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
			
			CContainer * xiongdi=present("lu gun weng");
			if(xiongdi)
			{
				xiongdi->move(obj);
				obj->Join_Team((CChar *)xiongdi, CFightRoom::FIGHT_TEAM_A);
			}

			this->move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
			obj->Begin_Fight(0);
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;
