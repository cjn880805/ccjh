//fenggongying.h
//Lanwood
//2000-01-09

MINGJIAOTANZHU_BEGIN(CNmingjiao_fenggongying);

virtual void create()
{
	set_name("封杯蛇", "feng beishe");
	set("long","他是一个阴郁的瘦子，身穿一件白布长袍。他脸上阴沉沉的，看什么人都是一副怀疑的眼神。");
	
	set("title", "明教神蛇坛坛主");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighter");
	set("icon",young_man1);
	set_weight(50000000);
	
	set("age", 47);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("max_hp", 1450);
	set("hp",  450);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 50);
	set("combat_exp", 50000);
	set("score", 100);
	
	set_skill("force", 70);
	set_skill("hunyuan_yiqi", 70);
	set_skill("dodge", 70);
	set_skill("shaolin_shenfa", 70);
	set_skill("finger", 68);
	set_skill("nianhua_zhi", 68);
	set_skill("parry", 70);
	set_skill("sword", 80);
	set_skill("damo_jian", 80);
	set_skill("buddhism", 70);
	set_skill("literate", 70);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("parry", "damo_jian");
	map_skill("sword", "damo_jian");
	prepare_skill("finger", "nianhua_zhi");
	
	create_family("明教", 4, "神蛇坛坛主");
	
	set_inquiry("明教",ask_me);

	carry_object("baipao")->wear();
}

MINGJIAOTANZHU_END;



