// xingxiu_boshou.c ����

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_boshou);

virtual void create()
{
	set_name("����������",  "boshou");
	set("long","���������ɵĴ����֡�����������һ��ͭ�࣬һ����һ�߳���ɤ�ӳ�Щ����Ļ��� ");
	set("gender", "����");
	set("age", 33);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 16);
	set("con", 22);
	set("dex", 24);
        set("icon",young_man6);
	
	set("max_hp", 600);
	set("mp", 200);
	set("max_mp", 200);
	set("mp_factor", 10);
	set("combat_exp", 2000);
	
	set_skill("force", 20);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	
	set("chat_chance", 2);
	
//	carry_object("tongbo")->wield();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "���������ֳ��������ǡ��ޡ��ϡ��ɣ�������御���� ";
	case 1:
		return "���������ֳ��������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء��� ";
	case 2:
		return "���������ֳ��������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ��� ";
	}
	return "";
}

NPC_END;
