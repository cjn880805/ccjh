NPC_BEGIN(CNPub_girl);

virtual void create()
{
	set_name( "Ů��", "gril");

	set("icon", girl1);
	set("gender", "Ů��");
	set("age", 12);

    set("long", "���Ǹ�ƽ����Ů��ֻ��ʮ�������꣬����Ѿ��ܳ����ˡ�");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("dex", 10);
	set("con", 10);
	set("int", 15);
	set("attitude", "friendly");

	set("nkgain", 30);
	
	add_money(5);
};

NPC_END;
