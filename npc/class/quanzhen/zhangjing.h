// quanzhen_zhangjing.c 掌经道长

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhangjing);

virtual void create()
{
	set_name("掌经道长", "zhangjing");
	set("gender", "男性");
	set("age", 36);
	set("class", "taoist");
	set("long","这位是全真教里掌管经书的道长。他以前是长安镇上一个私塾的夫子，因为仰慕大道，才拜到了全真门下。不过毕竟因为年岁大了，功夫的根基扎得不牢，这也正合他意，可以安安心心地研读经书了。");
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 18);
	set("int", 18);
	set("con", 20);
	set("dex", 21);
	set("icon",taoist_with_sword);
			set("foolid",44);
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 900);
	set("max_mp", 900);
	set("mp_factor", 0l);
	
	set("combat_exp", 20000);
	set("score", 15000);
	
	set_skill("force", 40);
	set_skill("xiantian_qigong", 40);    //先天气功
	set_skill("sword", 40);
	set_skill("quanzhen_jian",40);  //全真剑
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 40);   //金雁功
	set_skill("parry", 50);
	set_skill("unarmed",50);
	set_skill("strike",50);
	set_skill("haotian_zhang", 50);    //昊天掌
	set_skill("literate",100);
	set_skill("taoism",80);
	
	map_skill("force", "xiantian_qigong");
	map_skill("sword", "quanzhen_jian");
	map_skill("dodge", "jinyan_gong");
	map_skill("parry", "quanzhen_jian");
	map_skill("strike", "haotian_zhang");
	prepare_skill("strike", "haotian_zhang");
	
	create_family("全真教", 4, "弟子");
	
	set("book_count",1);
	set_inquiry("全真教","我全真教是天下道家玄门正宗。");
	set_inquiry("道德经",ask_me);
	set_inquiry("一阳指",ask_zhipu);
	
	carry_object("changjian")->wield();
	carry_object("greyrobe")->wear();
	
}

virtual void attempt_apprentice(CChar * ob)
{
	char msg[255];
	say(" 好吧，我就收下你这个徒弟了。");
	command(snprintf(msg,255,"recruit %ld" , ob->object_id() ));
}

static  char * ask_me(CNpc *who ,CChar *me)
{
	CContainer *obj;
	static char msg[255];
	if (DIFFERSTR(me->querystr("family/family_name"), "全真教"))
		return snprintf(msg,255,"%s与本教毫无瓜葛，你这话可叫我弄不明白了。",query_respect(me) );
	if (who->query("book_count") < 1)
		return "你来晚了，道德经已经被人取走了。";
	who->add("book_count", -1);
	obj = load_item("daodejing_i");//道德经「上卷」
	obj->move(me);
	return "好吧，这本「道德经」你拿回去好好研读，有看不懂的地方来问我。";
	
}

static  char * ask_zhipu(CNpc *me ,CChar *who)
{
	if(who->query_temp("tmark/指")==2) 
	{
		who->add_temp("tmark/指",1);
		return "一阳指的指法谱向来就是由本教祖师亲自收存，从不外传。";
	}
	else 
	{
		who->set_temp("tmark/指",0l);
		return "听说一阳指是天下最王道的指法，我也没有见过。";
	}
	return "";
}

NPC_END;