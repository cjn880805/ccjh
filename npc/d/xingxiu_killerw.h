// xingxiu_killerw.c ,No greeting, ���޹���, ����
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_killerw);

virtual void create()
{
	set_name("ɱ��", "killer");
	set("long","����һ����ĸߴ�Ľ����ˣ����۴�׳��������Բ���������ƺ��������⡣ ");
	
	set("gender", "����");
	set("attitude", "aggressive");
	set("class", "shaman");
	
	set("age", 20+random(30));
        set("icon",old_man1);

	set("shen_type", -1);
	
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
	
	set("startroom","/d/city/ximen");
	
	set_skill("force", 20+random(80));
	set_skill("huagong_dafa", 20+random(80));
	set_skill("dodge", 20+random(60));
	set_skill("zhaixinggong", 20+random(60));
	set_skill("unarmed", 20+random(100));
	set_skill("xingxiu_duzhang", 10+random(110));
	set_skill("parry", 20+random(80));
	set_skill("staff", 20+random(100));
	set_skill("tianshan_zhang", 10+random(110));
	
	map_skill("force", "huagong_dafa");
	map_skill("dodge", "zhaixinggong");
	map_skill("parry", "tianshan_zhang");
	map_skill("staff", "tianshan_zhang");
	map_skill("unarmed", "xinxiu_duzhang");
	
	set("chat_chance", 20);
	
	carry_object("tiegun")->wield();
}

virtual char * chat_msg()
{
	switch (random(2))
	{
	case 0:
		return "ɱ��˵��: ��ο���Щ��������Ķ��ܡ� ";
	case 1:
		return "ɱ��˵��: ɱ! ɱ! ɱ!!!�� ";
	}
	return "";
}

NPC_END;