// pub_chen.c
//code by Fisho
//date : 2000-12-13

//inherit F_DEALER;

VENDOR_BEGIN(CNpub_chen);

virtual void create()
{
	set_name("陈阿婆", "chen apo");

	set("icon", young_woman1);
	set("title", "杂货铺老板娘");
	set("shen_type", 1);
	
	set("str", 20);
	set("gender", "女性");
	set("age", 55);
	set("long",		"陈阿婆久居泉州城，据说她年轻时很有几分风韵，福威镖局当时的少镖头林威南还追求过她。");
	set("combat_exp", 800);
	set("attitude", "friendly");
	
	carry_good("xiuhua", 10);
	carry_good("shoes", 10);
	carry_good("pink_cloth", 10);
	carry_good("goldring", 10);
	carry_good("necklace", 10);
	
	set_inquiry("林威南" ,"阿南生着那俊，那会琢一个河南七子婆，唉。");
	set_inquiry("name", "婆婆我夫家姓陈。陈林半边天嘛。");
	set_inquiry("here","泉州是个港口，会行船的人很多。");
	
}

virtual char * greeting(CChar * ob)
{
	switch(random(2))
	{
	case 0 :
		return "人客来坐。";

	case 1 :
		return "可嘴的，你要买什？";

	}
	return "";
}

VENDOR_END;