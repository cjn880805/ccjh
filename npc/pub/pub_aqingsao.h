// pub_aqingsao.c 阿庆嫂
//code by Fisho
//date : 2000-12-13

//inherit F_DEALER;

VENDOR_BEGIN(CNpub_aqingsao);

virtual void create()
{
	set_name("阿庆嫂","qing sao");

	set("icon", young_woman9);
	set("title", "茶馆老板娘");
	set("nickname", "扬州一支花");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
	set("age", 25);
	set("long","阿庆嫂是扬州城里有名的大美人，因为爷儿们总喜欢往她这儿逛，所以她对城里的一举一动都了如指掌。");
	set("combat_exp", 500);
	set("attitude", "friendly");

	carry_good("peanut",500);
	carry_good("tofu",500);

	carry_object("cloth")->wear();

	set_inquiry("阿庆" , "我们家阿庆去北边做生意去了耶。");
	set_inquiry("生意" , "这个么……。");
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	switch(random(2))
	{
	case 0 :
		return snprintf(msg,255,"这位%s，快请进来喝杯热茶。",query_respect(ob));

	case 1 :
		return snprintf(msg,255,"哟！这位%s您来了啊！本店有刚炸好的五香花生出售。",query_respect(ob));
		
	}

	return "";
}

VENDOR_END;