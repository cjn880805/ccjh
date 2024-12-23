// girldizi.c
//code by sound
//date:2001-07-19

NPC_BEGIN(CNhuashan_girldizi);

virtual void create()
{
	set("icon",young_woman7);
	set_name("Сʦ��", "xiao shimei");
	set("long", "���ǻ�ɽ�ɵ�Ů���ӡ�");
	set("gender", "Ů��");
	set("age", 15);
	set("attitude", "peaceful");
	set("shen_type", 1);
	
	set("str", 20);
	set("int", 20);
	set("con", 22);
	set("dex", 25);
	
	set("hp", 150);
	set("max_hp", 150);
	set("mp", 150);
	set("max_mp", 150);
	
	set("combat_exp", 2000);
	set("score", 1000);
	
	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 5);
	
	create_family("��ɽ��", 14, "����");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;