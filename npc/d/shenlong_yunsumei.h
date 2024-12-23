// shenlong_yunsumei.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNshenlong_yunsumei);

virtual void create()
{
	set_name("����÷", "yun sumei");
	set("title","������""����ʹ""���µ���");
	set("long","����һ��������Ů���ӣ�һϮ���£�������Ϊ�ɰ���");
	
	set("gender", "Ů��");
	set("attitude", "peaceful");
 	set("icon",young_woman1);
	
	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_hp", 600);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 5+random(5));
	set("combat_exp", 20000+random(10000));
	
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	set_skill("sword", 60);
	set_skill("shedao_qigong", 30);
	map_skill("sword","shedao_qigong");
	
	carry_object("duanjian")->wield();
	carry_object("xionghuang")->wield();
	carry_object("cloth")->wear();
	add_money(500);
}

virtual char * greeting(CChar * ob)
{
	if (userp(ob))
	{
		if (ob->present("usedgao"))          
			unconcious();
	}
	return "";
}
NPC_END;