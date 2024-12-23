// lingjiu_fumy.c

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNlingjiu_fumy);

virtual void create()
{
	set_name("������","fu mingyi");
	set("long","���ǡ����չ�������Ų������첿������.���ųơ�����.");
	set("title", "���첿����");
	set("gender", "Ů��");
	set("nickname",  "����" );
	set("age", 20);
	set("shen_type",1);
	set("attitude", "peaceful");
 	set("icon",young_woman9);
	
	set("str", 25);
	set("int", 25);
	set("con", 30);
	set("dex", 30);
	
	set("hp", 800);
	set("max_hp", 2400);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 20);
	
	set("combat_exp", 100000);
	set("score", 10000);
	set_skill("force", 100);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("hand",100);
	set_skill("strike", 100);
	
	set_skill("zhemei_shou",80);
	set_skill("liuyang_zhang",80);
	set_skill("yueying_wubu",80);
	set_skill("bahuang_gong", 70);
	
	map_skill("force", "bahuang_gong");
	map_skill("strike","liuyang_zhang");
	map_skill("dodge", "yueying_wubu");
	map_skill("unarmed", "liuyang_zhang");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");
	
	create_family("���չ�",3,"����");
	
	
	carry_object("qingyi")->wear();
	carry_object("doupeng")->wear();
	add_money(2000);
}

NPC_END;