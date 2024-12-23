//xiaoshami.h
//code by zwb
//12-16

NPC_BEGIN(CNDaLi_xiaoshami);

virtual void create()
{
	set_name("沙弥","xiao sha mi");

	set("gender", "男性" );
	set("class", "bonze");
	set("age", 15);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
 	set("icon",boy1);

	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 100);
	set("max_mp", 100);
	set("mp_factor", 10);
	set("combat_exp", 8000);
	set("score", 1000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("tiannan_step", 80);
	set_skill("kurong_changong", 70);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");

	set_inquiry("一阳指",ask_me1);
	carry_object("y_jiasha")->wear();
};

static char * ask_me1(CNpc * this_object ,CChar * this_player)
{
	if (this_player->query_temp("marks/ask_tempyyz")==2)
	{
		this_player->add_temp("marks/ask_tempyyz",1);
		return "那天我给师傅送饭时看到师傅房间的桌子上放了一本书。不知道是不是你所说的书？";
	}
	this_player->set_temp("marks/ask_tempyyz",0l);
	return "你问别人去吧，我不知道你在说什么。";

}




NPC_END;
