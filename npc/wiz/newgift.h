//newgift.h
//code by zwb
//12-25

NPC_BEGIN(CNnewgift);


virtual void create()
{
	
	set_name("礼物使者","liwu shizhe");

	set("icon", young_woman1);
	set("title", "礼物使者");
	set("gender", "男性" );
	set("age", 43);
	set("per", 3);
	set("long","赠送在线用户礼物的使者");
	
	set("max_hp", 2400);
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("grant", 99);
	set_inquiry("发放新年礼物","送我一个金币,我就帮你给所有的在线用户送出礼物。");
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	set("wait_time", 60);
	set("no_huan",1);
//	carry_object("cloth")->wear();
}

virtual int accept_object(CChar * who, CContainer * ob)
{

	if (EQUALSTR(ob->querystr("id"), "coin") )
	{
		destruct(ob);
		g_Channel.do_channel(&g_Channel, 0, "wiz", "$HIR新年的钟声即将敲响！！在这新的一年即将来临之际，我们将向所有的在线朋友赠送一件神秘的物品！");
		g_player();
		g_lost();

		return 1;
	}

/*static char * do_doom(CNpc * me, CChar * who)
{
	if(! wizardp(who)) return "只有巫师才有权限发放礼物";

	if(me->query("newyear")) return "我的记性没这么差的，说一次就够了吧！";
	me->set("newyear", 1);
	g_Channel.do_channel(me, NULL, "wiz", "$HIR\n\n\n              新年的钟声即将敲响！！\n\n\n              在这新的一年即将来临之际，我们将向所有的在线朋友\n\n\n              赠送一件神秘的物品！\n\n\n\n");
	me->call_out(do_liwu, 6);

	me->command("force_save 0 all");
	return 0;
}

static void do_liwu(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
		
	if(me->query("wait_time") <= 0)
	{
		g_Channel.do_channel(me, NULL, "wiz", "$HIR\n\n\n              金智塔公司全体员工\n\n\n              恭祝所有朋友新年快乐！\n\n\n");
		g_player();
		g_lost();
		return;
	}

//	char msg[255], tmp[40];

//	g_Channel.do_channel(me, NULL, "wiz", snprintf(msg, 255, "$HIR\n\n\n            新年的还有%s分钟！你们交是不交！！！\n\n\n", chinese_number(me->query("wait_time"), tmp)));
	me->add("wait_time", -1);

	me->call_out(do_liwu, 600);
}*/

int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
	
		char msg[255];
		
		CContainer * gift;

		snprintf(msg, 255, "天上飘扬着落下一个袋子，不偏不倚落在你的怀中……\n你打开一看，看到了一件美丽的新年礼服。");
		
        tell_object(obj,msg);

		if (EQUALSTR(obj->querystr("gender"), "男性"))	//竹叶青
		{
			gift=load_item("newyear");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "女性"))	//女儿红
		{
			gift=load_item("newyear");
			gift->move(obj);
		}
		
		if (EQUALSTR(obj->querystr("gender"), "无性"))	//壮阳酒
		{
			gift=load_item("newyear");
			gift->move(obj);
		}
    }
    
	return 1;
}

int g_lost()
{
	return 1;
}

NPC_END;