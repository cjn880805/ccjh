// guigongzi.c
//sound 2001-07-16

NPC_BEGIN(CNdali_guigongzi);

virtual void create()
{
	set_name("����", "gongzi");
	set("gender", "����" );
	set("age", 29);
	set("long", "����һ��������ӣ����õ�Ҳ�������ٷ硢һ���˲ţ���ƫƫһ˫�۾�ȴ��б����ˡ�");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("per", 26);
	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	set("icon",young_man4);	

	set("hp", 400);
	set("max_hp", 400);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
//	add_money("silver", 10);
}

NPC_END;