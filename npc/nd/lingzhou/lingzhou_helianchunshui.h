//helianchunshui.c 玄武堂的护法
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_helianchunshui);

virtual void create()
{
	set_name( "赫连秋波" , "helian chunshui");
	set("gender", "男性" );
	set("age", 29 );
	set("long",
		"赫连秋波是一品堂堂主赫连铜树的侄子，天资聪颖，十二岁时便领\n"
		"悟了家传“赫连神枪”的精髓。后化名白笑江混入大宋禁军，积功\n"
		"至统带。因少年有为，被禁军教头杨铁枪看中，得授杨家枪法并神\n"
		"枪三绝中的两招。若仅以枪法论，西夏不作第二人想，人称“神枪\n"
		"小侯爷”。更兼通多门中原工夫，隐隐然已是一品堂年轻一代的第\n"
		"一高手。\n");
	
	set("str", 33 );
	set("cor", 34 );
	set("int", 43 );
	set("per", 33 );
	set("dex", 25 );
	set("con", 30 );
	set("icon",general);
	
	set("force", 1500); 
	set("max_force", 1500); 
	set("mp_factor", 100);
	
	set_skill("yanxing_dao", 140);
	set_skill("fuhu_quan", 120);
	set_skill("duanshi_xinfa", 60);
	set_skill("dodge", 1300);
	set_skill("unarmed", 1500);
	set_skill("long", 2000);
	set("combat_exp", 30000);
//	set("social_exp", 50000);
	
//	carry_object("baizhu_sipao")->wear();
//	carry_object("kaijia1")->wear();
//	carry_object("zhanpao")->wear();
//	carry_object("qiang")->wield();
//	JoinZuzhi("yipin", "护国将军", "玄武堂");
}
/*
int welcome_visitor( object me )
{
	object npc = this_object(), cloth, ling;
	
	foreach( object inv in deep_inventory( me ) )
	{
		if ( ( inv->name() == "$YEL玄武令$COM" ) && inv->id( "ling pai" ) )
			ling = inv;
		if ( ( inv->name() == "号坎" ) && inv->id( "hao kan" ) )
			cloth = inv;
	}
	
	if ( !cloth && !ling )
	{
		message_vision( "$CYN$N看了$n一眼，喝道：“阁下闯关杀人，莫非当我大夏无人吗？！”$COM\n", npc, me );
		kill_ob( me );
	}
}

int refuse_killing( object me )
{
	set("force_factor", 100);
	return 0;
}

int accept_fight( object me )
{
	if ( me->ZuzhiTouxianJibie("yipin") < 6 )
	{
		message_vision( "$CYN$N瞟了你一眼，道：“我很忙，你去找那些卫士吧。”$COM\n",
			this_object() );
		return 0;
	}
	else
	{
		message_vision( "$CYN$N看了$n一眼，脸色忽然大变：“咦？你是什么人？"
			"怎么闯上来的？”$COM\n" 
			,this_object() ,me);
		kill_ob( me );
		return notify_fail("");
	}
}

int valid_teach( object me, string skill )
{
	return 0;
}
*/
NPC_END;