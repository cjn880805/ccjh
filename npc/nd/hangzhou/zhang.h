// zhang.h
//zhangdn 2001-07-18

NPC_BEGIN(CNhangzhou_zhangzz);

virtual void create()
{
	set_name("张太重","zhang taizhong");
	set("title", "御林军骁骑营佐领");
	set("nickname", "火手判官");
	set("gender", "男性");
	set("age", 43);
	set("long", "张太重人称“火手判官”，身材魁梧，留一丛短胡子。江湖盛言“宁挨一枪，莫遇一张”就是指他了。他热衷功名利禄，投身朝廷，此人办事卖力，这些年来更是青云直上。");
	set("combat_exp", 750000);
	set("shen_type", -1);
	set("attitude", "heroism");
	set("icon", young_man1);
	set("max_mp", 2000);
	set("mp", 2000);
        set("max_hp", 2000);
        set("hp", 2000);
        set("per", 20);
        set("int", 20);
        set("con", 30);
        set("str", 30);
        set("dex", 30);

	set_skill("unarmed", 100);
	set_skill("sword", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	set_skill("force", 100);
	set_skill("taiji_shengong", 100);
	set_skill("taiji_jian", 100);
	set_skill("taiji_quan", 100);
	set_skill("tiyunzong", 100);
	map_skill("dodge", "tiyunzong");
	map_skill("force", "taiji_shengong");
	map_skill("sword", "taiji_jian");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");

        create_family("武当派", 13, "弟子");
        
 /*       carry_object("green_sword")->wield();
        carry_object("tiejia")->wear();

	add_money("silver", 30);  */

}
NPC_END;