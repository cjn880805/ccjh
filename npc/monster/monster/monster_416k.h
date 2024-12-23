NPC_BEGIN(CNmonster_416k);

virtual void create()
{
	// static char xunbuname[3][9]={"百夫长","十夫长","分队队长"};
	 static char xunbuname[3][9]={"卖花姑娘","卖艺女","村女"};

	 set_name(xunbuname[random(3)],"girl");

	
	set("icon", girl1);
	set("gender", "女性");
	set("attitude", "peaceful");

		
	set("combat_exp", 4000+random(12000));
	
	
	set_temp("apply/attack", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
	set_temp("apply/defense", 20);

	
	set("max_hp", 1000);

	set("shen_type", 1);

	set("mp", 200);
	set("max_mp", 200);

//    carry_object("cloth")->wear();

	add_money(180 + random(200));
};

NPC_END;
