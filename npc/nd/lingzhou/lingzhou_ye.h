// ye.c
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_ye);

virtual void create()
{
	set_name("Ҷ��ɩ", "ye erniang");
	set("gender", "Ů��");
	set("nickname", "�޶���");
	set("age", 43);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("icon",old_woman);
	set("long", "һ������Ů�ӣ�������ɫ���ۣ����������ϸ�������Ѫ�ۡ�");
	set("combat_exp", 300000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("mp", 2000); 
	set("max_mp", 2000);
	set("mp_factor", 100);
	
	set_skill("strike", 100);
	set_skill("claw", 100);
	set_skill("force", 100);
	set_skill("blade", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sanyin_wugongzhao", 100);
	set_skill("chousui_zhang", 100);
	set_skill("huagong_dafa", 100);
	set_skill("kuangfeng_blade", 100);
	set_skill("shaolin_shenfa", 100);
	map_skill("dodge", "shaolin_shenfa");
	map_skill("force", "huagong_dafa");
	map_skill("blade", "kuangfeng_blade");
	map_skill("parry", "kuangfeng_blade");
	map_skill("claw", "sanyin_wugongzhao");
	map_skill("strike", "chousui_zhang");
	prepare_skill("claw", "sanyin_wugongzhao");
	prepare_skill("strike", "chousui_zhang");
	
//	carry_object("bupao")->wear();
	carry_object("gangdao")->wield();
}

NPC_END;