// jinbing.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_jinbing);

virtual void create()
{
	set_name("����", "jin bing");
	set("gender", "����");
	set("age", 25);
	set("icon", guarder);
	set("long", "��Щ�󺺸������������������⽡��");
	set("combat_exp", 40000);
        set_skill("dodge", 50);
        set_skill("unarmed", 50);
        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
	set("shen_type", 1);

//	add_money("silver",3);
	carry_object("cloth")->wear();
}

NPC_END;
