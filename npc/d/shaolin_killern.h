// shaolin_killern.c ,No greeting, ���ֹ���, ����
//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNshaolin_killern);

virtual void create()
{
	set_name("ɱ��", "killer");
	set("long","����һ����ĸߴ�Ľ����ˣ����۴�׳��������Բ���������ƺ��������⡣");
	
	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "bonze");
	
	set("age", 20+random(30));
	
        set("icon",old_man1);
	
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("int", 25+random(10));
	set("con", 25+random(10));
	
	set("hp", 1500);
	set("max_hp", 4500);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50+random(100));
	
	set("combat_exp", 10000+random(100000));
	set("score", 1);
	set("startroom","/d/city/beimen");
	
	set_skill("force", 20+random(80));
	set_skill("hunyuan_yiqi", 20+random(80));
	set_skill("dodge", 20+random(60));
	set_skill("shaolin_shenfa", 20+random(60));
	set_skill("unarmed", 20+random(150));
	set_skill("parry", 20+random(80));
	set_skill("finger", 20+random(100));
	set_skill("yizhi_chan", 10+random(110));
	set_skill("strike", 20+random(100));
	set_skill("banruo_zhang", 10+random(110));
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "yizhi_chan");
	map_skill("finger", "yizhi_chan");
	map_skill("strike", "banruo_zhang");
	
	prepare_skill("finger", "yizhi_chan");
	prepare_skill("strike", "banruo_zhang");
	
	set("chat_chance", 20);
}

virtual char * chat_msg()
{
	switch(random(2))
	{
	case 0:
		return "ɱ��˵��: ��ο���Щ��������Ķ��ܡ�";
	case 1:
		return "ɱ��˵��: ɱ! ɱ! ɱ!!!��";
	}
	return "";
}	

virtual void init(CChar *me)
{
	call_out(want_to_kill, 5, me->object_id());	
}

static void want_to_kill(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CContainer * room = me->environment();
	CChar * who = (CChar *)room->Present(param1);

	if(! who) return;

	
  	if (room->query("no_fight"))
		room->set("no_fight", 0l);
	
	if (userp(who))
	{
		me->say("����һﲻҪ�ܣ��ô�ү�������㣡����");
		me->kill_ob(who);
	}
	
	return;
}

NPC_END;