//lady2.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_lady2);

virtual void create()
{
	set_name("������Ů","lady");
	
	set("icon", young_woman3);
	set("gender", "Ů��" );
	set("age", 21);
	set("long","��һ���������ɣ������������ݡ���������΢ʾ�⣬���ȥ�Ӳ赹ˮ��");
	set_temp("apply/defense", 5);
	set("combat_exp", 70);
	set("shen_type", 1);
	set("str", 14);
	set("per", 28);
	set("dex", 15);
	set("con", 16);
	set("int", 15);
	set("attitude", "friendly");
	carry_object("cloth")->wear();
	
};


NPC_END;
