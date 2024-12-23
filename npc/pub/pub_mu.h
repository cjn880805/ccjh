//pub_mu.c

// code by Fisho
// date:2000-12-17
//inherit F_MASTER;
//Lanwood 检查于2001-01-02
//该NPC和龙岛主重了。

NPC_BEGIN(CNpub_mu);

virtual void create()
{
	set_name("木下惠", "mu");

	set("icon", young_man6);
	set("long", "他就是天下闻之色变的侠客岛岛主，号称“坐怀不乱”。只见他长须稀稀落落，兀自黑多白少，但一张脸却满是皱纹。看不出他的实际年纪。");
	set("title", "侠客岛主");
	set("gender", "男性");
	set("age", 75);
	set("nickname",  "坐怀不乱"  );
	set("shen_type",1);
	set("attitude", "peaceful");
	
	set("str", 30);
	set("int", 29);
	set("con", 30);
	set("dex", 28);
	
	set("hp", 900);
	set("max_hp", 2700);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 50);
	
	set("combat_exp", 1500000);
	set("score", 200000);
	set_skill("force", 170);
	set_skill("unarmed", 100);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("hand",170);
	set_skill("staff", 170);
	set_skill("jinwu_daofa", 150);
	set_skill("lingxu_bu", 150);
	//  set_skill("yanyangong", 200);
	//  set_skill("xiake_zhangfa", 100);
	//  map_skill("force", "yanyangong");
	//  map_skill("unarmed", "xiake_zhangfa");
	//  map_skill("hand", "xiake_zhangfa");
//	map_skill("dodge", "lingbo_weibu");
	map_skill("parry", "jinwu_daofa");
	map_skill("staff", "jinwu_daofa");
	
	create_family("侠客岛",1, "岛主");
	set_inquiry("腊八粥","腊八粥只赠有缘人，不知你是否满足条件。？");
	set_inquiry("铜牌","我这可没有这玩艺，你如想要的话，可找别人问一问。");
	
	carry_object("gangdao")->wield();
	add_money(2000);
}

virtual void attempt_apprentice(CChar * ob)
{
	message_vision("木岛主拍拍$N的头，微微摇了摇头。",ob);
	return;
}
/*
virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obn;
	CContainer * room;
	CContainer * key;
	char msg[255];

	command("smile");
	if(  ob->querystr("name") == "罚恶铜牌" )
	{
		if(  ob->querystr_temp("own") !=  who->querystr("name") )
			return notify_fail("这不是你的东西。");
		
		say(snprintf(msg,255," 原来是 %s大侠欢迎光临本岛。",who->name() ));
		
		obn=load_item("labazhou");//腊八粥
		obn->move(who);
		say(snprintf(msg,255," 这是本岛特产腊八粥，外边可不易喝到，其中最主要的一味是<断肠蚀骨腐心草>， 瞧%s也是有缘之人，快乘热喝，这样效力方著。",query_respect(who) ));
		message_vision("木岛主给了你一碗腊八粥",who);
		if( who->query_temp("zhou") == 1)
		{
			say("  看来居士福缘深厚，有机会一睹武林绝技，请进吧！");
			message_vision("只听得一阵隆隆的响声由远及近。", who);
			who->set_temp("zhou", 0);
			message_vision("只见岛主身后的石板缓缓移了开来，露出一条长长的甬道。", who);
			(who->environment())->set("exits/enter", "/d/xiakedao/mishi");
			
			room=who->environment();
			remove_call_out(close);
			key = load_item("key");//没有该物品
			message_vision("这是我身后石门的钥匙，也是侠客岛上的凭证，希望你妥善保管，不可随意丢弃，更不可交付他人，离岛时应与归还。", who);
			key->move(who);
			call_out(close, 15, room->object_id());
			return 1;
		}
		who->set_temp("zhou", 2);
		return 1;
	}
	else
	{
		message_vision("我不需要这东西。",who);
		return 0;
	}
}

static void close(CContainer *ob,LONG param1,LONG param2)
{
	CChar *me = (CChar *)(ob->environment())->Present(param1);
	
	if (!me) return ;
	tell_room(me->environment(),"轰隆隆的响声响过之后，石板又合上了。", me);
	me->del("exits/enter");
}
*/
NPC_END;