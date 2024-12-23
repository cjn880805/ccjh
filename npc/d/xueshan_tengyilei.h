// xueshan_tengyilei.c

//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNxueshan_tengyilei);

virtual void create()
{
	set_name("���ŷ�",  "teng yilei");
	set("long","���ǹ�����ħ�еĴ�ħ���ŷ硣������һֻ����ͭ�ˣ����������Ƿ���");
	set("nickname",  "�����ħ" );
	set("gender", "����");
	set("age", 46);
        set("icon",old_man2);

	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 50);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_hp", 4500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 100);
	set("combat_exp", 180000);
	set("score", 20000);
	
	set_skill("force", 80);
	set_skill("xiaowuxiang", 50);
	set_skill("dodge", 50);
	set_skill("shenkong_xing", 60);
	set_skill("unarmed", 90);
	set_skill("yujiamu_quan", 40);
	set_skill("parry", 60);
	set_skill("hammer", 100);
	set_skill("riyue_lun", 100);
	
	map_skill("force", "xiaowuxiang");
	map_skill("dodge", "shenkong_xing");
	map_skill("unarmed", "yujiamu_quan");
	map_skill("parry", "riyue_lun");
	map_skill("hammer", "riyue_lun");
	
	
	carry_object("cloth")->wear();
	carry_object("tongren")->wield();
	add_money(5000);
}

NPC_END;