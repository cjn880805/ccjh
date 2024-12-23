//heimuya_jiaotu2.h 黄衣使者
//秦波 2003、5、29

NPC_BEGIN(CNheimuya_jiaotu3);

virtual void create()
{
	set_name("黄衣使者",  "jiao tu" );

	set("gender", "男性");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("日月神教", 5, "弟子");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(25)+15);
    set("int", random(25)+15);
    set("con", random(25)+15);
    set("dex", random(25)+15);
	
	set("max_hp", 10000+random(6000));
	set("hp", query("max_hp"));
	set("max_mp",  7000+random(6000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 30+random(50));

    set("combat_exp", 2000000);
	set("score", 10000);

    set_skill("force", 220);             // 基本内功
    set_skill("unarmed", 220);           // 基本拳脚
    set_skill("dodge", 220);             // 基本躲闪
	set_skill("club", 220);             // 基本刀法
    set_skill("parry", 220);             // 基本招架
    set_skill("changquan", 220);         // 太祖长拳
    set_skill("kuihua_xinfa", 220);      // 葵花心法
	set_skill("pixie_jian", 220);        // 辟邪剑法
	set_skill("duanhun_qiang", 220);       // 断魂枪法

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "duanhun_qiang");
	map_skill("club", "duanhun_qiang");
    
    set("apply/armor", 120);
    set("apply/damage", 100);

	carry_object("changqiang")->wield();
	
};

NPC_END;




