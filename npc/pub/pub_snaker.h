// pub_snaker.c
// code by Fisho
// date:2000-12-17
//inherit F_DEALER;

VENDOR_BEGIN(CNpub_snaker);

virtual void create()
{
	set_name("舞蛇人",  "snaker" );

	set("icon", young_man6);
	set("long", "他是一个西域来的舞蛇人。");
	set("title", "西域蛇王");
	set("nickname",  "蛇见怕"  );
	set("gender", "男性");
	set("age", 33);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 24);
	set("con", 25);
	set("dex", 26);
	
	set_skill("unarmed", 75);
	set_skill("dodge", 65);
	set_skill("parry", 65);
	set_skill("force", 60);
	
	set("mp", 400);
	set("max_mp", 400);
	set("mp_factor", 20);
	set("combat_exp", 30000);
	set("snake_mount" ,3);
	set("score", 10000);
	
	set("chat_chance",5);
	
	set_inquiry("白驼山","我这里的蛇胆粉就是用白驼山的蛇精心制作的。");
	set_inquiry("蛇胆粉","我的蛇胆粉能治各种外伤，疗效不凡！");
	
	carry_good("fen",500);
	
	carry_object("baipao")->wear();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return "舞蛇人吆喝道:停一停，看一看，有上好的蛇胆粉出售了￣";
	case 1:
		return "舞蛇人把手腕划出一道口子，又敷上蛇胆粉，咦，流血立即停止了。";
	case 2:
		return "舞蛇人把手里的蛇舞来舞去道：货真价实的啦，别错过好机会￣";
	}
	return "";
}

/*
virtual char * greeting(CChar * ob)
{     
	CContainer * obn;
	char msg[255];
	if ( EQUALSTR(ob->querystr("family/family_name"), "白驼山派"))
	{
		if(!(ob->present("shenshe") )&&random(2)==1)
		{
			tell_object(ob,snprintf(msg,255,"这位%s，我这里有「引路神蛇」，你先拿去用，不用担心，我是真心帮你啦￣",query_respect(ob) ));
			obn=load_item("shenshe");//没有该物品
			obn->move(ob);
			return "";
		}
	}
	say(snprintf(msg,255,"舞蛇人殷勤地说：这位%s，买我的蛇胆粉吧，包您满意。",query_respect(ob) ));
	return "";
}

virtual int accept_fight(CChar * ob)
{
	CContainer * obn;
	if(!( (ob->environment() )->present("mang she") ) )
	{
		add("snake_mount", -1);
		if(!query("snake_mount")) 
		{
			message_vision("舞蛇人怒道 你还想骗老子的蛇吗？呸！！ ",ob);  
			return 1; 
		}
		message_vision("舞蛇人大叫一声：小子竟敢跟老子过不去，尝尝蛇的厉害。", ob);
		obn=load_item("mangshe");//没有该物品
		obn->move(ob->environment());
		kill_ob(ob);
		return 0;
	}
	message_vision("舞蛇人大怒道：让你小子尝尝老子的厉害。", ob);
	return 1;
}
*/

VENDOR_END;