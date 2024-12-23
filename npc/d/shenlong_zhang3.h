// shenlong_zhang3.c

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNshenlong_zhang3);

virtual void create()
{
	set_name("章老三",  "zhang laosan");
	set("title", "神龙教小头目");
	set("gender", "男性");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "这是一个干瘦老头,一双小眼睛贼闪发光。 ");
	set("combat_exp", 25000);
	set("score", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");
 	set("icon",old_man1);
	
	set_skill("force", 50);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("yixingbu", 40);
	set_skill("shenlong_bashi", 50);
	map_skill("parry", "shenlong_bashi");
	map_skill("dodge", "yixingbu");
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set("mp", 500); 
	set("max_mp", 500);
	set("mp_factor", 10);
	
	set_inquiry("入教"," 一般人是入不了我神龙教的. ");
	set_inquiry("洪教主"," 教主脾气不好,要讨他欢心才好。 ");
	set_inquiry("口号"," 万年不老!永享仙福!寿与天齐!文武仁圣! ");
	
	carry_object("cloth")->wear();
}
	
virtual char * chat_msg()
{
	switch (random(5))
	{
	case 0:
		return "教主宝训,时刻在心,建功克敌,无事不成! ";
	case 1:
		return "众志齐心可成城,威震天下无比伦! ";
	case 2:
		return "神龙飞天齐仰望,教主声威盖八方! ";
	case 3:
		return "乘风破浪逞英豪,教主如同日月光! ";
	case 4:
		return "教主永享仙福,寿与天齐! ";
	}
	return "";
}
/*
virtual void init(CChar *me)
{
	add_action("do_join","join");
}
*/
virtual int recognize_apprentice(CChar * ob)
{
	if (DIFFERSTR(ob->querystr("party/party_name"), "神龙教") )
		return 0;
	
	return 1;	
}

NPC_END;