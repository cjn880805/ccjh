//heimuya_jiaotu1.h 红衣使者
//秦波 2002、4、25

NPC_BEGIN(CNheimuya_jiaotu1);

virtual void create()
{
	set_name("红衣使者",  "jiao tu" );

	set("gender", "男性");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("日月神教", 6, "弟子");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(20)+10);
    set("int", random(20)+10);
    set("con", random(20)+10);
    set("dex", random(20)+10);
	
	set("max_hp", 5000+random(3000));
	set("hp", query("max_hp"));
	set("max_mp",  5000+random(3000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 10+random(50));

    set("combat_exp", 1000000);
	set("score", 10000);

    set_skill("force", 150);             // 基本内功
    set_skill("hand", 150);					// 基本指法
    set_skill("unarmed", 150);           // 基本拳脚
    set_skill("dodge", 150);             // 基本躲闪
	set_skill("sword", 150);             // 基本剑法
    set_skill("parry", 150);             // 基本招架
    set_skill("changquan", 150);         // 太祖长拳
    set_skill("kuihua_xinfa", 150);      // 葵花心法
	set_skill("pixie_jian", 150);        // 辟邪剑法

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "pixie_jian");
	map_skill("sword", "pixie_jian");
    
    set("apply/armor", 80);
    set("apply/damage", 60);
	
};

NPC_END;




