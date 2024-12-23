//Lanwood 2000-09-17

FIGHTER_BEGIN(CNwiz_fighter4);

void create()
{
	set_name("天神", "tian shen");

	set("title", "老年组登记员");
	set("icon", girl1);
	
	set("gender", "女性");
	set("chname", "天神");
	set("channel", "f3");

	set("wait_time", 10);

	set("grant", 80);
				
	set("judge/attr", "level");
	set("judge/min", 80);
	set("judge/max", 200);
	set("judge/desc", "等级在80级以上。");

	set("biwu/name", "老年比武大会");
	set("biwu/register/0", "空缺");
	set("biwu/turn0/0", "0");

	set("file_name", querystr("base_name"));

//----------------------------------------------------
	set("icon", old_man2);

	set("str", 35);
	set("int", 35);
	set("con", 35);
	set("dex", 35);

	set("hp", 4500);
	set("max_hp", 14500);
	
	set("mp", 5000);
	set("max_mp", 5000);
	set("mp_factor", 150);

	set("combat_exp", 2500000);
	set("score", 300000);

	set_skill("force", 280);
	set_skill("unarmed", 290);
	set_skill("dodge", 270);
	set_skill("parry", 320);
	set_skill("hand",290);
	set_skill("staff", 320);
	set_skill("hamagong", 300);
	set_skill("chanchu_bufa", 300);
	set_skill("shexing_diaoshou", 280);
	set_skill("lingshe_zhangfa", 300);
	set_skill("xunshou_shu",300);

	map_skill("force", "hamagong");
	map_skill("dodge", "chanchu_bufa");
	map_skill("unarmed", "shexing_diaoshou");
	map_skill("hand", "shexing_diaoshou");
	map_skill("parry", "lingshe_zhangfa");
	map_skill("staff", "lingshe_zhangfa");
	  
	carry_object("shezhang")->wield();
	carry_object("zhaohong")->wear();
//----------------------------------------------

	Load();
};

FIGHTER_END;




