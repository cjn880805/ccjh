//muguniang.h
//code by zwb
//12-16

NPC_BEGIN(CNDaLi_muguniang);

virtual void create()
{
	set_name("木姑娘","mu gu niang");

    set("gender", "女性" );
    set("age", 17);
    set("long", "她长得似新月清晕，如花树堆雪，一张脸秀丽绝俗，只是过于苍白，没半点血色，想是她长时面幕蒙脸之故，两片薄薄的嘴唇，也是血色极淡，神情楚楚可怜，娇柔婉转。");
 	set("icon",girl2);

	set("combat_exp", 200000);
	set("shen_type", 1);
    set("per", 29);
    set("str", 30);
    set("dex", 30);
    set("con", 30);
    set("int", 30);
    set("attitude", "friendly");
	set("max_hp", 1500);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 100);

	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("cuff", 100);
	set_skill("strike", 100);
	set_skill("whip", 100);
	set_skill("sword", 100);
	set_skill("kurong_changong", 100);
	set_skill("tiannan_step", 100);
	set_skill("jinyu_quan", 100);
	set_skill("duanjia_sword", 100);
	set_skill("wuluo_zhang", 100);
	set_skill("feifeng_whip", 100);

	map_skill("force", "kurong_changong");
	map_skill("dodge", "tiannan_step");
	map_skill("whip", "feifeng_whip");
	map_skill("cuff", "jinyu_quan");
	map_skill("strike", "wuluo_zhang");
	map_skill("sword", "duanjia_sword");
	map_skill("parry", "duanjia_sword");
	prepare_skill("cuff", "jinyu_quan");
	prepare_skill("strike", "wuluo_zhang");

    carry_object("whitecloth1")->wear();
    carry_object("changjian")->wield();
};




NPC_END;
