// yun.c
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_yun);

virtual void create()
{	
	set_name("������", "yun zhonghe");
	set("gender", "����");
	set("nickname", "���׼���");
	set("age", 34);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("icon",cateran);
	set("long", 
		"���˳����ָ�������һ�˴���ͣ�˵������������֣�ʮ����\n"
		"��������һ��������һ��ɫ����ģ����\n");
	
	set("combat_exp", 150000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor", 50);
	
	set_skill("strike", 80);
	set_skill("claw", 80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sanyin_wugongzhao", 80);
	set_skill("chousui_zhang", 80);
	set_skill("huagong_dafa", 80);
	set_skill("shaolin_shenfa", 80);
	map_skill("dodge", "shaolin_shenfa");
	map_skill("force", "huagong_dafa");
	map_skill("parry", "chousui_zhang");
	map_skill("claw", "sanyin_wugongzhao");
	map_skill("strike", "chousui_zhang");
	prepare_skill("claw", "sanyin_wugongzhao");
	prepare_skill("strike", "chousui_zhang");
	
//	carry_object("bupao")->wear();
}

NPC_END;