//heimuya_jiaotu2.h 绿衣使者
//秦波 2003、5、29

NPC_BEGIN(CNheimuya_jiaotu4);

virtual void create()
{
	set_name("绿衣使者",  "jiao tu" );

	set("gender", "男性");
	set("attitude", "peaceful");
	set("icon",young_monk);

	create_family("日月神教", 4, "弟子");

	set("no_kill",1);
	set("age", random(20)+20);

	set("per", random(40));
    set("str", random(26)+17);
    set("int", random(26)+17);
    set("con", random(26)+17);
    set("dex", random(26)+17);
	
	set("max_hp", 13000+random(7000));
	set("hp", query("max_hp"));
	set("max_mp",  8000+random(4000));
    set("mp", query("max_mp"));
    
    set("mp_factor", 35+random(50));

    set("combat_exp", 2500000);
	set("score", 10000);

    set_skill("force", 250);             // 基本内功
    set_skill("hand", 250);					// 基本指法
    set_skill("unarmed", 250);           // 基本拳脚
    set_skill("dodge", 250);             // 基本躲闪
	set_skill("blade", 250);             // 基本剑法
    set_skill("parry", 250);             // 基本招架
    set_skill("changquan", 250);         // 太祖长拳
    set_skill("kuihua_xinfa", 250);      // 葵花心法
	set_skill("pixie_jian", 250);        // 辟邪剑法
	set_skill("jinwu_daofa", 250);       // 金乌刀

    map_skill("force", "kuihua_xinfa");
    map_skill("unarmed", "changquan");
    map_skill("dodge", "pixie_jian");
    map_skill("parry", "shengji_blade");
	map_skill("blade", "jinwu_daofa");
    
    set("apply/armor", 110);
    set("apply/damage", 90);

	carry_object("gangdao")->wield();
	
};

NPC_END;




