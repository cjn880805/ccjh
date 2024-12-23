NPC_BEGIN(CNPub_playboy);

virtual void create()
{
	set_name("花花公子","playboy");

	set("icon", young_man6);
	set("nickname", "采花大盗");
	set("gender", "男性" );
	set("age", 19);
	set("long", "这是个流里流气的花花公子。");
	set("attitude", "friendly");
	set("shen_type", -1);

	set("str", 21);
	set("int", 23);
	set("con", 22);
	set("dex", 20);
	
	set("max_hp", 1200);
	set("mp", 100);
	set("max_mp", 100);
	set("combat_exp", 30000+random(10000));
	set("score", 10000);
	carry_object("male8_cloth")->wear();
	carry_object("menghan_yao")->wear();
	add_money(10);

};

virtual  char * greeting(CChar * me )
{
	static char msg[255];

	if(EQUALSTR(me->querystr("gender"), "女性"))
		return snprintf(msg, 255, " 花花公子色迷迷说：%s干嘛那么着急赶路，陪我玩玩不行吗？", query_respect(me));

	return snprintf(msg, 255, " 花花公子唱道：路边的野花不采白不采~~。这位%s你说是吗？", query_respect(me));
   

}

NPC_END;




