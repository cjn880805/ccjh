//woman.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_woman);

virtual void create()
{
	set_name("维吾尔族妇女","woman");
	
	set("icon", young_woman8);
	set("gender", "女性" );
	set("age", 40);
	set("long", "一个很胖的维吾尔族中年妇女。");
	
	set("repute", 1000);
	set("combat_exp", 150);
	set("nkgain", 40);
	set("env/wimpy", 60);
	set("chat_chance_combat", 50 );
	set("str", 13);
	set("dex", 12);
	set("con", 14);
	set("int", 13);
	set("attitude", "friendly");
	set("chat_chance", 10);
	
	carry_object("wcloth")->wear();
	add_money(100);
	
};

virtual char * chat_msg(CChar * me)
{
	switch(random(3))
	{
	case 0:
		return "维吾尔族妇女看着你笑了起来";
	case 1:
		return "维吾尔族妇女说道：小波郎子呀克西。";
	case 2:
		return "维吾尔族妇女向你努了努嘴，又指了指北边。";
	}
	return "";
}

NPC_END;
