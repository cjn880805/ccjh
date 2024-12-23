// gaogenming.c
//code by sound
//date:2001-07-19

NPC_BEGIN(CNhuashan_gaogenming);

virtual void create()
{
	set("icon",young_man4);
	set_name("�߹���", "gao genming");
	set("nickname", "�о�����");
	set("gender", "����");
	set("age", 24);
	set("long", "�߹���������Ⱥ�ĵ���λ���ӡ�");
	set("attitude", "peaceful");
	
	set("str", 26);
	set("con", 30);
	set("int", 24);
	set("dex", 30);
	
	set("mp", 300);
	set("max_mp", 300);
	
	set("combat_exp", 30000);
	set("score", 20000);
	set("shen_type", 1);
/*
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
	(: exert_function, "powerup" :),
	(: exert_function, "recover" :)
	}) );
*/
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("force", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);
	set_skill("literate", 30);
	
	set_skill("huashan_sword", 50);
	set_skill("zixia_shengong", 50);
	set_skill("hunyuan_zhang", 50);
	set_skill("feiyan_huixiang", 50);
	
	map_skill("sword", "huashan_sword");
	map_skill("parry", "huashan_sword");
	map_skill("force", "zixia_shengong");
	map_skill("unarmed", "hunyuan_zhang");
	map_skill("dodge", "feiyan_huixiang");
	
	create_family("��ɽ��", 14, "����");
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;