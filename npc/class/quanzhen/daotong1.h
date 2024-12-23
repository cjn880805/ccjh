// quanzhen_daotong1.c 道童

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_daotong1);

virtual void create()
{
	set_name("小道童",  "dao tong");
	set("gender", "男性");
	set("class", "taoist");
	set("age", 14);
	set("long","这是一位小道童，看来年纪不大，脸上稚气犹存，整天笑嘻嘻的无忧无虑。");
	set("attitude", "friendly");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("icon",taoist);
	set("foolid",31);
	set("hp", 300);
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 0l);
	
	set("combat_exp", 15000);
	
	set_skill("force", 50);
	set_skill("xiantian_qigong", 40);    //先天气功
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 50);   //金雁功
	set_skill("parry", 50);
	set_skill("unarmed",50);
	
	map_skill("force", "xiantian_qigong");
	map_skill("dodge", "jinyan_gong");
	
	create_family("全真教", 5, "弟子");
	
	carry_object("greyrobe")->wear();
	carry_object("xiongdan");

	set_inquiry("祖师爷爷",ask_zhipu);
}
static  char * ask_zhipu(CNpc *me ,CChar *who)
{
	if(who->query_temp("tmark/指")==3) 
	{
		who->add_temp("tmark/指",1);
		return "祖师爷和大理段皇爷交情很深，段皇爷把家传的一阳指谱都交给祖师爷保管了。";
	}
	else 
	{
		who->set_temp("tmark/指",0l);
		return "听说一阳指是天下最王道的指法，我也没有见过。";
	}
	return "";
}
NPC_END;