// nan.c
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_nan);

virtual void create()
{
	
	set_name("�Ϻ���ħ", "nanhai eshen");
	set("gender", "����");
	set("nickname", "�����ɷ");
	set("age", 34);
	set("str", 25);
	set("dex", 16);
	set("per", 21);
	set("icon",banditi);
	set("long", 
		"���˵�һ���Դ�������Ѱ����һ��������¶����ɭɭ�����ݣ�\n"
		"һ���۾�ȴ����Բ��С��\n");
	set("combat_exp", 250000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("mp", 2000); 
	set("max_mp", 2000);
	set("mp_factor", 100);
	
	set_skill("strike", 100);
	set_skill("claw", 100);
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sanyin_wugongzhao", 100);
	set_skill("chousui_zhang", 100);
	set_skill("huagong_dafa", 100);
	set_skill("shaolin_shenfa", 100);
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