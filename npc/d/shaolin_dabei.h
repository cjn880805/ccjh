// shaolin_dabei.c

//code by Fisho
//date:2000-12-21
//inherit F_MASTER;

NPC_BEGIN(CNshaolin_dabei);

virtual void create()
{
	set_name("��ϲ����", "dabei laoren");
	set("long", "���Ǹ��������ߣ��׷����أ�������ΰ��");
	set("title", "�׾�����");
	set("gender", "����");
	set("attitude", "friendly");
 	set("icon",old_man1);
	
	set("age", 70);
	set("shen_type", 1);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("max_hp", 4500);
	set("hp", 1500);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 150);
	set("combat_exp", 1000000);
	set("score", 500000);
	
	set_skill("force", 120);
	set_skill("hunyuan_yiqi", 120);
	set_skill("dodge", 120);
	set_skill("shaolin_shenfa", 120);
	set_skill("hand", 120);
	set_skill("claw", 120);
	set_skill("parry", 120);
	set_skill("qianye_shou", 120);
	set_skill("longzhua_gong", 120);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("hand", "qianye_shou");
	map_skill("claw", "longzhua_gong");
	map_skill("parry", "longzhua_gong");
	
	prepare_skill("hand", "qianye_shou");
	prepare_skill("claw", "longzhua_gong");
	
	carry_object("cloth")->wear();
	carry_object("18niou");
}
NPC_END;