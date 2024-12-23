// lingjiu_yupopo.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_yupopo);

virtual void create()
{
	set_name("������", "yu popo");
	set("long","���ǡ����չ�������Ų�����첿������.���������Ѷ���, ��������,������˪.");
	set("title", "��첿����");
	set("gender", "Ů��");
	set("age", 60);
	set("shen_type",1);
	set("attitude", "peaceful");
 	set("icon",old_woman);
	
	set("str", 20);
	set("int", 25);
	set("con", 30);
	set("dex", 30);
	
	set("hp", 2000);
	set("max_hp", 6000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 50);
	
	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	set_skill("sword",100);
	
	set_skill("tianyu_qijian",100);
	set_skill("zhemei_shou",100);
	set_skill("liuyang_zhang",100);
	set_skill("yueying_wubu",100);
	set_skill("bahuang_gong", 100);
	
	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
   	map_skill("sword", "tianyu_qijian");
	create_family("���չ�",2,"����");
	
	carry_object("qingyi")->wear();
	carry_object("doupeng")->wear();
	carry_object("changjian")->wield();
	add_money(4000);
}
NPC_END;