// quanzhen_youfang.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_youfang);

virtual void create()
{
	set_name("游方道人", "youfang daoren");
	set("long","他是一位未通世故的青年道人，脸上挂着孩儿般的微笑。");
	
	set("gender", "男性");
	set("attitude", "heroism");
	set("class", "taoist");
	set("icon",taoist_with_sword);
			set("foolid",42);
	set("age", 20);
	set("shen_type", 1);
	set("str", 15);
	set("int", 30);
	set("con", 30);
	set("dex", 18);
	set("max_hp",  900);
	set("hp", 300);
	set("mp", 380);
	set("max_mp", 380);
	set("mp_factor", 27);
	set("combat_exp", 10000);
	set("shen_type", 1);
	set("chat_chance", 30);
	
	set_skill("force", 41);
	set_skill("strike", 41);
	set_skill("dodge", 41);
	set_skill("parry", 41);
	set_skill("jinyan_gong", 42);
	set_skill("haotian_zhang", 41);
	set_skill("xiantian_qigong", 41);
	
	map_skill("force", "xiantian_qigong");
	map_skill("dodge", "jinyan_gong");
	map_skill("strike", "haotian_zhang");
	map_skill("parry", "haotian_zhang");
	create_family("全真教", 4, "弟子");
	
	carry_object("cloth")->wear();
}

virtual char * chat_msg()
{
	return "游方道人说道: 请这位施主化几两银子给贫道，随喜随喜，造福众生。";
}	
/*
virtual int accept_object(CChar * me, CContainer * ob)
{
	CContainer * ling;
	char msg[255];
	command("smile");
	say(snprintf(msg,255," 无量寿佛，多谢这位%s !" , query_respect(me) ), me);
	
	if( ( (ob->querystr("base_name") ) == "coin" )&& ob->query("value") >= 10000 && DIFFERSTR(me->querystr("class"), "bonze") ) 
	{
		say(snprintf(msg,255,"%s如此乐善好施，兼又身怀绝艺，全真祖师正欲一晤天下豪杰，不知可愿赴重阳宫内一游？", query_respect(me) ), me);
		
		ling=load_item("tie_ling");//没有该物品
		ling->move(me);
		message_vision("游方道人给$N一块铁铸令牌。", me);
		
		say("此牌限时一日，逾时失效，请于限时前离宫，否则多有不便，切记切记！", me); 
	}

	SendMenu(me);	
	return 1;
}
*/
NPC_END;