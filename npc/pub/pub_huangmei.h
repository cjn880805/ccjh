// pub_huangmei.c
//code by Fisho
//date : 2000-12-14
 
NPC_BEGIN(CNpub_huangmei);

virtual void create()
{
	set_name("赤眉大师", "chi mei"  );

	set("icon", old_monk);
	set("age", 69);
	set("gender", "男性");
	set("long", "这是一个满脸皱纹、身形高大的老僧。这老僧两道火红长眉，眉尾竖起，是拈花寺主持。 ");
	set("attitude", "peaceful");
	set("class", "bonze");
	
	set("age", 69);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_hp", 4500);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 150);
	set("combat_exp", 1000000);
	
	set_skill("force", 110);
	set_skill("hunyuan_yiqi", 110);
	set_skill("dodge", 110);
	set_skill("shaolin_shenfa", 110);
	set_skill("finger", 110);
	set_skill("strike", 110);
	set_skill("hand", 110);
	set_skill("claw", 110);
	set_skill("parry", 110);
	set_skill("nianhua_zhi", 110);
	set_skill("sanhua_zhang", 110);
	set_skill("fengyun_shou", 110);
	set_skill("longzhua_gong", 110);
	set_skill("buddhism", 110);
	set_skill("literate", 110);
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("finger", "nianhua_zhi");
	map_skill("strike", "sanhua_zhang");
	map_skill("hand", "fengyun_shou");
	map_skill("claw", "longzhua_gong");
	map_skill("parry", "nianhua_zhi");
	
	prepare_skill("finger", "nianhua_zhi");
	prepare_skill("strike", "sanhua_zhang");

	carry_object("xuan_cloth")->wear();
}

NPC_END;