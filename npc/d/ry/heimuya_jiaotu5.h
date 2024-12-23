//heimuya_jiaotu5.h 青衣使者
//秦波 2003、5、29

NPC_BEGIN(CNheimuya_jiaotu5);

virtual void create()
{
	set_name("青衣使者",  "jiao tu" );

	set("gender", "男性");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("日月神教", 4, "弟子");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(28)+18);
    set("int", random(28)+18);
    set("con", random(28)+18);
    set("dex", random(28)+18);
	
	set("max_hp", 16000+random(8000));
	set("hp", query("max_hp"));
	set("max_mp",  9000+random(4000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 45+random(50));

    set("combat_exp", 3000000);
	set("score", 10000);

    set_skill("force", 280);             // 基本内功
    set_skill("hand", 280);					// 基本指法
    set_skill("unarmed", 280);           // 基本拳脚
    set_skill("dodge", 280);             // 基本躲闪
	set_skill("whip", 280);             // 基本剑法
    set_skill("parry", 280);             // 基本招架
    set_skill("changquan", 280);         // 太祖长拳
    set_skill("kuihua_xinfa", 280);      // 葵花心法
	set_skill("pixie_jian", 280);        // 辟邪剑法
	set_skill("wudu_bian", 280);        // 五毒鞭法
	set_skill("wudu_xinfa", 280);        // 五毒心法

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "changquan");
	map_skill("whip", "wudu_bian");
    
    set("apply/armor", 120);
    set("apply/damage",100);

	carry_object("changbian")->wield();
	set("chat_chance_combat", 15);
	
};

virtual char * chat_msg_combat()
{
	perform_action("whip judu", 1);
	return "";
}

NPC_END;




