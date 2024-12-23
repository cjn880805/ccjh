//saodiseng.h
//code by zwb
//12-16

NPC_BEGIN(CNDaLi_saodiseng);

virtual void create()
{
	set_name("扫地僧","sao di seng");

	set("gender", "男性" );
	set("class", "bonze");
	set("age", 100);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
 	set("icon",old_monk);

	set("hp", 1000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 20);
	set("combat_exp", 80000);
	set("score", 10000);

	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 70);
	set_skill("tiannan_step", 80);
	set_skill("kurong_changong", 70);

	map_skill("force", "kurong-changong");
	map_skill("dodge", "tiannan-step");

	set_inquiry("一阳指",ask_me1);
//	set_inquiry("丢失",ask_me2);

	carry_object("c_jiasha")->wear();
};

static char * ask_me1(CNpc * this_object ,CChar * this_player)
{
	this_player->set_temp("marks/ask_tempyyz",1);
	return "你是说一阳指吗？这只有大师们才会知道放在哪，我是不可能知道的。";
/*	if(this_player->query_temp("marks/ask_temp1"))
		return "“那是本寺的镇寺之宝，当年不知为何丢失了。”";
	else
		return "“你胡说八道什么？”";
*/
}

/*
static char * ask_me2(CNpc * this_object , CChar * this_player)
{

	if(this_object->query_temp("marks/ask_temp1"))
	{
		this_object->set_temp("marks/ask_temp2",1);
		return "“那天晚上我只看见一个黑影从塔上飞下，往后寺跑了。";
	}
	else
		return "“你胡说八道什么？”";
}
*/
NPC_END;
