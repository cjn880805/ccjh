//wiz_newgift.h
//code by zwb
//12-25

NPC_BEGIN(CNwiz_newgift);


virtual void create()
{
	
	set_name("散财童子","liwu shizhe");

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
	set_inquiry("发放新年礼物","送我一把倚天剑,我就帮你给所有的在线用户送出礼物。");
	set_skill("literate", 70);
	set_skill("dodge", 200);
	set_skill("unarmed", 100);
	set("msg","《重出江湖》全体巫师恭祝大家游戏开心！");
	set("礼物","zhuguo");
	set("no_huan",1);
//	carry_object("cloth")->wear();
}
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "ytjian") )
	{
		destruct(ob);
		//g_Channel.do_channel(&g_Channel, 0, "wiz", "$HIR新年的钟声敲响了，全体巫师给大家来拜年了！");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR新年的钟声敲响了，全体巫师给大家来拜年了！");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR祝大家在新的一年里，身体健康、心想事成、马年行大运。");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR祝大家在江湖中，money多多，经验多多，朋友多多，每天一个好心情。");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR恭喜发财，红包送来！见者有份，宝贝多多！");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR┬┴┬┌─　●─┬─　　│─┼─┐　●├─┤○ ");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR┴┬┴├┬　┌─┼─　│◎　│　│　○└┬┘● ");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR─┼─││　│　│　　││─┴─┴　──┼──  ");
		g_Channel.do_channel(who, NULL, "wiz",  "$HIR●│○││　┴─┼─　　│○　　●　／　│ ＼  ");
		g_player();
		g_lost();
		return 1;
	}
	return 0;
}
*/

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "ytjian") )
	{
		char msg[255];
		destruct(ob);
		snprintf(msg, 255, "wiz 0 $HIR%s",querystr("msg"));
		command(msg);
//		g_Channel.do_channel(who, NULL, "wiz", snprintf(msg, 255, "$HIR%s",querystr("msg")));
		g_player();
		g_lost();
		return 1;
	}
	return 0;
}

int g_player()
{
	MAP2USER * user;
	iterator_user p;
	CUser * obj;

	user = users();
    for ( p=user->begin(); p!=user->end(); p++)
    {
		obj = p->second;
		if(query("年龄小于") && obj->query("age")>=query("年龄"))
			continue;
		if(query("年龄大于") && obj->query("age")<=query("年龄"))
			continue;
		if(querystr("性别")[0]&& DIFFERSTR(obj->querystr("gender"), querystr("性别")))
			continue;
		if(query("等级小于")&& obj->query("level")>=query("等级"))
			continue;
		if(query("等级大于")&& obj->query("level")<=query("等级"))
			continue;
		if(query("经验小于")&& obj->query("combat_exp")>=query("经验"))
			continue;
		if(query("经验大于")&& obj->query("combat_exp")<=query("经验"))
			continue;
        tell_object(obj,"天上飘扬着落下一个红包，不偏不倚落在你的怀中……");

		load_item(querystr("礼物"))->move(obj);

//		load_item("hongbao")->move(obj);
    }
    
	return 1;
}

int g_lost()
{
	return 1;
}

NPC_END;




