// xingxiu_gushou.c ����

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxingxiu_gushou);

virtual void create()
{
	set_name("�����ɹ���", "gushou" );
	set("long", "���������ɵĴ����֡� ����ǰ����һֻͭ�ģ�һ����һ�߳���ɤ�ӳ�Щ����Ļ��� ");
	set("gender", "����");
	set("age", 43);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 26);
	set("int", 16);
	set("con", 20);
	set("dex", 20);
        set("icon",old_man1);
	
	set("max_hp", 1200);
	set("mp", 400);
	set("max_mp", 400);
	set("mp_factor", 10);
	set("combat_exp", 4000);
	
	set_skill("force", 40);
	set_skill("dodge", 40);
	set_skill("unarmed", 40);
	set_skill("parry", 40);
	
	set("chat_chance", 2);
	
//	carry_object("tonggu")->wield();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "��������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ�������御���� ";
	case 1:
		return "��������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ��¡��䡫�졫�ء��� ";
	case 2:
		return "��������ͭ�࣬�������������ǡ��ޡ��ϡ��ɣ��š����ޡ��ȡ��� ";
	}
	return "";
}

NPC_END;