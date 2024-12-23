//yipinwushi.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yipinwushi);

virtual void create()
{
	set_name("һƷ����ʿ","wu shi");
	
	set("icon", general);
	set("gender", "����");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "����һƷ�õĻ�Ժ��ʿ�������ּף���ִ�䵶��");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	
	set_skill("unarmed", 80);
	set_skill("force", 80);
	set_skill("blade", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 50);
	
	set("mp", 1000); 
	set("max_mp", 1000);
	set("mp_factor", 10);
	
	carry_object("tiejia")->wear();
	carry_object("wandao")->wield();
};



NPC_END;
