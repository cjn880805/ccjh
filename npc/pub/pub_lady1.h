//lady1.h
//code by zwb
//12-14

NPC_BEGIN(CNPub_lady1);

virtual void create()
{
	set_name("����Ů��","lady");
	
	set("icon", young_woman4);
	set("gender", "Ů��" );
	set("age", 16);
	set("long","���Ǹ�ʮ�������������Ů�����������ף�һ���������ɫ��"); 
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
