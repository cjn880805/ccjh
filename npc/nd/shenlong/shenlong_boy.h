// boy.c
//code by sound
//2001-07-12

NPC_BEGIN(CNshenlong_boy);

virtual void create()
{
	set_name("�������", "young boy");
 	set("icon",young_man2);
	set("title","�����̻���ʹ���µ���");
	set("long", "����һ�������̵��ӣ�һϮ���£�����͸��һ��а����");
	
	set("gender", "����");
	set("attitude", "peaceful");
	
	set("age", 10+random(10));
	set("shen_type", -1);
	set("str", 25+random(10));
	set("dex", 25+random(10));
	set("max_hp", 200);
	set("hp", 200);
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

	carry_object("xionghuang")->wield();
	carry_object("duanjian")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg()						//NPC�Զ�����
{
	switch(random(5))
	{
	case 0:
		return 	"������Ӻ�Ȼ�����е�:������ѵ,ʱ������,�����˵�,���²��ɣ���";
	case 1:
		return 	"������Ӻ�Ȼ�����е�:��־���Ŀɳɳ�,���������ޱ��ף�";
	case 2:
		return 	"������Ӻ�Ȼ�����е�:��������������,���������ǰ˷���";
	case 3:
		return 	"������Ӻ�Ȼ�����е�:�˷����˳�Ӣ��,������ͬ���¹⣡";
	case 4:
		return 	"������������е�:���������ɸ�,�������룡";
	}
	
	return 0;
}
/*
void init()
{
	object ob;
	
	::init();
	
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 10, ob);
	}
}

void greeting(object ob)
{
	object obj;
	if (interactive(ob))
	{
		if (obj = present("usedgao", ob))          
			unconcious();
	}
	return;
}
*/
NPC_END;