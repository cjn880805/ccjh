//wokou.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_wokou);

virtual void create()
{
	set_name("倭寇","wokou");
	
	set("icon", young_man4);
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "入侵我天朝宝岛台湾的日本武人，江湖通称武士。我天朝篾之倭寇。");
	set("combat_exp", 50000);
	set("shen_type", -1);
	set("attitude", "aggressive");
	
	set_temp("apply/attack", 35);
	set_temp("apply/defense", 35);
	set_temp("apply/armor", 35);
	set_temp("apply/damage", 35);
	set_skill("blade", 35);
	set_skill("dodge", 35);
	set_skill("unarmed", 35);
	set_skill("tangshoudao", 35);
	set_skill("dongyangdaofa", 3);
	map_skill("unarmed","tangshoudao");
	map_skill("blade","dongyangdaofa");
	set("chat_chance", 1);
	carry_object("wodao")->wield();
	carry_object("cycle")->wear();
	carry_object("tiebeixin")->wear();
	
	
};

virtual char * chat_msg()
{
	return "倭寇抬眼大怒，牙缝里出声：八格牙路！你的，敢说台湾是你们的？死啦死啦的！";
}


NPC_END;
