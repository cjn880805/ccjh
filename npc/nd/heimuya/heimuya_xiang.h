// heimuya_xiang 向问天
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_xiang);

virtual void create()
{
	set_name("向问地","xiang wendi");
	set("nickname", "天王老子");
	set("title",  "日月神教光明右使" );
	set("long", "他就是日月神教的光明右使。为人极为豪爽。");
	set("gender", "男性");
	set("age", 45);
	set("attitude", "friendly");
	set("shen_type", -1);	//设置声望的正负
	set("str", 21);
	set("per", 18);
	set("int", 30);
	set("con", 26);
	set("dex", 30);
 	set("icon",old_man1);
	
	set("hp", 4000);
	set("max_hp", 4000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 350);
	set("combat_exp", 2500000);
	set("shen_type", -1);

	set_skill("literate", 150);
	set_skill("force", 150);
	set_skill("dodge", 150);
	set_skill("unarmed", 150);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("changquan", 150);
	set_skill("xingxiu_duzhang", 150);
	set_skill("lingxu_bu", 150);
	set_skill("damo_jian", 150);
	set_skill("taiji_jian", 150);
	set_skill("huifeng_jian", 150);
	set_skill("taishan_sword", 150);
	set_skill("hengshan_jian", 150);
	set_skill("hengshan_sword", 150);
	set_skill("huashan_sword", 150);
	set_skill("songshan_sword", 150);

	map_skill("dodge", "lingxu_bu");
	map_skill("force", "xingxiu_duzhang");
	map_skill("unarmed", "changquan");
	map_skill("sword", "damo_jian");
	map_skill("parry", "damo_jian");
	
	set("chat_chance", 5);

	set_inquiry("杨莲亭", "这种人，该杀！");
	set_inquiry("东方不败", "篡位叛徒，我非杀了他不可！");
//	set_inquiry("杀东方不败", "ask_kill()");
	set_inquiry("任我行", "教主被困，已历十年......");

	carry_object("changjian")->wield();

	create_family("日月神教", 2, "光明右使");
}


NPC_END;