// heimuya_laozhe 老者
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_laozhe);

virtual void create()
{
	set_name("老者", "lao zhe");
	set("gender", "男性" );
	set("age", 70);
	set("long","这个老头正抽旱烟抽得上瘾呢,怎样才能和他搭上话呢?");
	set("combat_exp", 1000);
	set("attitude", "friendly");
 	set("icon",old_man1);
//	set("rank_info/respect", "老大爷");

	set("chat_chance", 5);
	
	set_inquiry("黑木崖","黑木崖上有一个穿女人衣裳的吃人恶魔，你可千万不能去！");
	set_inquiry("旱烟","青年人,难得你有这份孝心,你若替我买包上好的烟草,我就给你一样东西。");
	set_inquiry("东西","我所说的东西就是上黑木崖的令牌啦,快去买上好烟草,我等不及了...");
	
//	carry_object(__DIR__"obj/card4");
}

virtual char * chat_msg()		//NPC自动聊天
{
	switch(random(2))
	{
	case 0:
//		return 	"老人家头也不回说道：这位" + RANK_D->query_respect(ob)+ "，不要乱跑,小心野兽。";
		return 	"老人家头也不回说道：“不要乱跑,小心野兽。”";
	case 1:
		return 	"老人家对你说到:我也一大把年纪了,就好那一口,你就行行好吧。";
	}

	return 0;
}
/* 
void init()
{
	object ob,me,what;
 
	::init();
	ob = this_player();
	me = this_object();
//	what=new(__DIR__"obj/yancao");
//	sprintf("%s aaa\n",what);
//	command("give yancao to",me);  
	if( interactive(ob) && !is_fighting() ) {
		remove_call_out("greeting");
	call_out("greeting", 1, ob);
	}
}
 
int accept_object(object who, object ob)
{ 
	if (ob->query("money_id") && ob->value() >= 5000)
	{
	tell_object(who, "老头对你说:好，好，真是个好孩子。\n");
	
	who->set_temp("rent_paid",1);
   
	treturn 1;
	}
 
	return 0;
}
*/
NPC_END;