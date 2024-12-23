// lj_ludinggong.h 鹿鼎公
// dieer 2002-7-31

NPC_BEGIN(CNlj_ludinggong);

virtual void create()
{
	set_name("鹿鼎公", "luding gong");
	set("long", "他头戴红顶带，身穿黄马褂，眉花眼笑，贼忒兮兮，左手轻摇羽扇，宛若诸葛之亮，右手倒拖大刀，俨然关云之长，正乃韦公小宝是也。");
	set("gender", "男性");
	set("age", 21);

	set("attitude", "peaceful");		//设置NPC态度
	set("icon",17);				//设置人物形象
	set("per",20);
	
	set("str", 41);
	set("int", 47);
	set("con", 42);
	set("dex", 41);

	set("combat_exp", 5000000);
	
	set("max_hp", 20000+random(10000));
	set("max_mp", 10000);
	set("no_kill",1);
}

NPC_END;
