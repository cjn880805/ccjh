//manxiangke.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_manxiangke);

virtual void create()
{
	
	set_name("���","xiang ke");
	
	set("icon", young_man4);
	set("gender", "����" );
	set("age", random(20)+10);
	set("long", "����һλ��ɽ�Ͻ������͡�");
	
	set_temp("apply/attack", 35);
	set_temp("apply/defense", 25);
	set("combat_exp", 3500);
	set("shen_type", 1);
	set("str", 24);
	set("dex", 20);
	set("con", 20);
	set("int", 18);
	set("attitude","friendly");
	
	carry_object("cloth")->wear();
	add_money(8);
	
};

NPC_END;
