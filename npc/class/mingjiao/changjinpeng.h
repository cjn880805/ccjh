//changjinpeng.h
//Lanwood
//2000-01-09

MINGJIAOTANZHU_BEGIN(CNmingjiao_changjinpeng);

virtual void create()
{
	set_name("常金雕", "chang jindiao");
	set("long","他是一位体健如牛的大汉，身穿一件白布长袍。他脸上手上的肌肉凹凹凸凸，盘根错节，看来武功修为不浅。");
	
	set("title", "明教朱雀坛坛主");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "fighter");
	set("icon",young_man1);
	set_weight(50000000);
	
	set("age", 45);
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
	create_family("明教", 4, "朱雀坛坛主");
	
	set_inquiry("明教",ask_me);
	
	carry_object("baipao")->wear();
}

MINGJIAOTANZHU_END;



