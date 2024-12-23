//heimuya_jiaotu2.h 橙衣使者
//秦波 2003、5、29

NPC_BEGIN(CNheimuya_jiaotu2);

virtual void create()
{
	set_name("橙衣使者",  "jiao tu" );

	set("gender", "男性");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("日月神教", 6, "弟子");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(22)+12);
    set("int", random(22)+12);
    set("con", random(22)+12);
    set("dex", random(22)+12);
	
	set("max_hp", 6000+random(4000));
	set("hp", query("max_hp"));
	set("max_mp",  6000+random(4000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 15+random(50));

    set("combat_exp", 1500000);
	set("score", 10000);

    set_skill("force", 180);             // 基本内功
    set_skill("hand", 180);					// 基本指法
    set_skill("unarmed", 180);           // 基本拳脚
    set_skill("dodge", 180);             // 基本躲闪
	set_skill("sword", 180);             // 基本剑法
    set_skill("parry", 180);             // 基本招架
    set_skill("changquan", 180);         // 太祖长拳
    set_skill("kuihua_xinfa", 180);      // 葵花心法
	set_skill("pixie_jian", 180);        // 辟邪剑法

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");
	map_skill("sword", "pixie_jian");
    
    set("apply/armor", 100);
    set("apply/damage", 80);

	carry_object("changjian")->wield();
	
};

NPC_END;




