// jia.h 贾老六 
//zhangdn 2001-07-18

NPC_BEGIN(CNcity2_jialaoliu);
  virtual void create()
{
	
	set_name("贾老七", "jia laoliu");
	set("title", "天地会青木堂会众");
//	set("title", "当铺老板");
	set("shen_type", 1);

	set("gender", "男性");
//	set_max_encumbrance(100000000);
	set("age", 35);
	set("long","他是天地会青木堂会众，当年在扬州之时，曾大骂盐枭，骂他们不敢杀官造反，只会走私漏税，做没胆子的小生意，结果得罪了青龙帮，遭人追杀，茅十八也因此和青龙帮结仇。\n");
	set("no_get_from", 1);
	set("icon",young_man3);

	set_skill("unarmed", 60);
	set_skill("dodge", 60);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	
	set_inquiry("陈近南", "想见总舵主可不容易啊。");
	set_inquiry("天地会",  "只要是英雄好汉，都可以入我天地会(join tiandihui)。");
	set_inquiry("入会", "只要入了我天地会，可以向会中各位好手学武艺。");
	set_inquiry("反清复明", "去屠宰场和棺材店仔细瞧瞧吧！");
//        set_inquiry("威望",  (: ask_weiwang :),
//                "江湖威望" : (: ask_weiwang :),	"天地会" :  "\n只要是英雄好汉，都可以入我天地会(join tiandihui)。\n",
	set_inquiry("入会", "只要入了我天地会，可以向会中各位好手学武艺。");
	set_inquiry("反清复明",  "去屠宰场和棺材店仔细瞧瞧吧！");
 //       set_inquiry("威望",  (: ask_weiwang :),
//                "江湖威望" : (: ask_weiwang :),

	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("chat_chance", 3);
}

	virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(3))
	{
	case 0:
		return 	"贾老七忽然说：扬州盐贩子真可恶。";
	case 1:
		return  "贾老七说: 江湖威望很重要，威望值高大有好处啊。";
        case 2:
		return  "贾老七突然说道: 忠义堂前兄弟在，城中点将百万兵。";
	}
        return 0;
}
/*
void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
	add_action("do_sell", "sell");
	add_action("do_value", "value");
//       add_action("do_join","join");
}

void die()
{
	message_vision("\n$N大叫道：兄弟们会替我报仇的，头一偏，死了。\n", this_object());
	destruct(this_object());
}
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" 你现在的江湖威望是 " +(string)(this_player()->query("weiwang")));
say("\n贾老六说：如果你威望值很高，有些人见了你不但不会杀你，还会教你武功，送你宝贝。\n"
+"而且你还可以加入帮会，率领会众去攻打目标，就连去钱庄取钱也会有利息 。。。。。\n");
say("贾老六又说：杀某些坏人或救某些好人可以提高江湖威望。\n");
return 1;
}
// #include "/kungfu/class/yunlong/tiandihui.h";
*/
NPC_END;