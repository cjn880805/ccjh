// pub_yuzu.c
// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_yuzu);

virtual void create()
{
	set_name("刑部狱卒",  "yu zu");

	set("icon", tipstaff);
	set("title", "八品带刀侍卫" );
	set("gender", "男性" );
	set("age", 32);
	set("str", 22);
	set("con", 25);
	set("dex", 20);
	set("int", 30);
	set("long","天子脚下北京城的刑部红顶狱卒，满脸横肉，刁狠苛毒。你看来要小心了。");
	set("combat_exp", 2000000);
	set("attitude", "heroism");
	
	set("max_hp", 3000);
	set("max_mp", 2000);
	set("mp", 2000);
	set("mp_factor", 100);
	set_skill("unarmed",200);
	set_skill("parry", 200);
	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("blade", 200);
	
	set_inquiry("出狱","嘿嘿嘿嘿！想出狱啊？没圣上的旨意，今生没指望喽。");

	carry_object("yayi_cloth")->wear();
	carry_object("gangdao")->wield();
}

/*
virtual char * greeting(CChar * ob)
{
	char msg[255];
	command(snprintf(msg,255,"rumor 江洋大盗%s已被刑部锦衣卫籍拿归案！",ob->name() ));
	ob->set("startroom","/d/city2/jail");
	return "";
}


virtual void init(CChar *me)
{
	CChar * ob;
	CNpc::init(me);
	add_action("do_chat","chat");
	add_action("do_chat","rumor");
	add_action("do_chat","party");
	add_action("do_chat","xkx");
	add_action("do_chat","sing");
	add_action("do_chat","to");
	add_action("do_chat","chat*");
	add_action("do_chat","tell");
	add_action("do_chat","reply");
	add_action("do_chat","exert");
	add_action("do_chat","yun");
	add_action("do_chat","dazuo");
	add_action("do_chat","exercise");
	add_action("do_chat","tuna");
	add_action("do_chat","meditate");
	add_action("do_chat","lian");
	add_action("do_chat","practice");
	add_action("do_chat","du");
	add_action("do_chat","study");
	add_action("do_chat","xue");
	add_action("do_chat","learn");
	add_action("do_chat","vote");
	add_action("do_chat","finger");
	add_action("do_chat","suicide");
}

int do_chat(string arg)
{
	CChar * ob = me;
	switch(random(3))
	{
	case 1:
        say(" "+ob->query("name")+"！你敢再动一动！再动就给你一桶马尿！");
		break;
	case 2:
        say(" "+ob->query("name")+"！你是皮痒还是哪里不爽？");
        message_vision("刑部狱卒劈头盖脑就是一阵皮鞭，抽得$N皮开肉绽，好不清爽！" ,ob);
		ob -> receive_damage("hp",10);
		break;
	default:
        say(" "+me->query("name")+"！你是不是觉得这里很舒服想多开心几天？");
		break;
	}
	return 0;
}
*/
NPC_END;