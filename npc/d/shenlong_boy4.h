// shenlong_boy4.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNshenlong_boy4);

virtual void create()
{
	set_name("�������", "young boy");
	set("title","������""����ʹ""���µ���");
	set("long","����һ�������̵��ӣ�һϮ���£�����͸��һ��а���� ");
	
	set("gender", "����");
	set("attitude", "peaceful");
 	set("icon",young_man3);
	
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
	set("chat_chance", 3);
	carry_object("duanjian")->wield();
	carry_object("xionghuang")->wield();
        carry_object("cloth")->wear();
}
virtual char * chat_msg()
{
	switch (random(5))
	{
	case 0:
		return "�������˵����������ѵ,ʱ������,�����˵�,���²���! ";
	case 1:
		return "�������˵������־���Ŀɳɳ�,���������ޱ���! ";
	case 2:
		return "�������˵������������������,���������ǰ˷�! ";
	case 3:
		return "�������˵�����˷����˳�Ӣ��,������ͬ���¹�! ";
	case 4:
		return "�������˵�������������ɸ�,��������! ";
	}
	return "";
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