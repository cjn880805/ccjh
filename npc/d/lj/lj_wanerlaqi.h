//wuaer.h
//wq
//2002-07-19
NPC_BEGIN(CNlj_wanerlaqi);

virtual void create()
{
	set_name("�߶�����", "wuaer laqi");
	set("long", "������װ��Ū����߶����롣�����ݿ��£����ڳ��ڲ������⣬Ƥ���Ұס�");
	set("gender", "����");
	set("age", 45);

	set("str", 45);
	set("int", 45);
	set("con", 45);
	set("dex", 45);
	set("per",10);

	set("max_hp", 20000);
	set("mp", 10000);
	set("max_mp", 10000);
	set("mp_force", 100);
	set("combat_exp", 5000000);
	set("score", 120000);

	set_skill("force", 320);
	set_skill("dodge", 300);
	set_skill("unarmed", 350);
	set_skill("parry", 300);
	set("no_kill",1);

}

NPC_END;