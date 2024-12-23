// huatiegan.c

//code by sound
//date:2001-07-11

NPC_BEGIN(CNxuedao_huatiegan);

virtual void create()
{
	set_name("��ͭ��", "hua tiegan");
	set("long", 
		"�����������桰�仨��ˮ���е��϶�����������н��ϣ��������壬һ����ƽǹ���ų���ƽ�޵С���������Ϊ��ȴ��զ�ġ�");
	set("gender", "����");
	set("nickname", "��ƽ�޵�");
	set("age", 45);
	set("attitude", "peaceful");
	set("shen_type", 0l);
	set("str", 35);
	set("int", 38);
	set("con", 35);
	set("dex", 35);
	set("icon",young_man5);
	
	set("max_hp", 2000);
	set("hp", 2000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 30);
	set("combat_exp", 700000);
	set("shen_type", 0l);
	
	set_skill("force", 100);
	set_skill("zixia_shengong", 100);
	set_skill("dodge", 100);
	set_skill("lingxu_bu", 100);
	set_skill("unarmed", 100);
	set_skill("poyu_quan", 100);
	set_skill("parry", 100);
	set_skill("club", 100);
	set_skill("zhongpingqiang", 100);
	set_skill("literate", 40);
	
	map_skill("force", "zixia_shengong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "poyu_quan");
	map_skill("club", "zhongpingqiang");
	map_skill("parry", "zhongpingqiang");
	set("chat_chance", 20);
	
	
	carry_object("changqiang")->wield();
}

virtual char * chat_msg()
{
	return "��ͭ�˼���������Х����磺���仨��ˮ�������������ƾ�����ԶԶ������";
}

NPC_END;