// quanzhen_yelvqi.c 耶律齐

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_yelvqi);

virtual void create()
{
	set_name("耶律平", "Yelv ping");
	set("title", "全真教第二代弟子 丐帮第二十一代帮主");
	set("gender", "男性");
	set("age", 25);
	set("per", 25);
	set("long", "靖哥哥和蓉儿的大女婿，芙妹的丈夫。");
	
	set("combat_exp", 600000);
	set("shen_type", 1);
	set("icon",begger);
	
	set("max_mp", 2000);
	set("mp", 2000);
	set("mp_factor", 0l);
	set("foolid",40);

	set_skill("force", 120);
	set_skill("sword", 120);
	set_skill("dodge", 100);
	set_skill("parry", 120);
	set_skill("unarmed",120);
	set_skill("strike",80);

	set_skill("xiantian_qigong", 120);    //先天气功
	set_skill("quanzhen_jian",120);  //全真剑
	set_skill("jinyan_gong", 100);   //金雁功
	set_skill("haotian_zhang", 120);    //昊天掌

	set_skill("literate",100);
	set_skill("taoism",80);
	
	create_family("全真教", 2, "弟子");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
}
NPC_END;