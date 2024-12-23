// huashan_yuzhenzi.c

//code by Fisho
//date:2000-12-21
//inherit F_UNIQUE;

NPC_BEGIN(CNhuashan_yuzhenzi);

virtual void create()
{
	set_name("������", "yuzhen zi");
	set("gender", "����");
	set("title", "������������");
	set("nickname", "��������");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "����һλ�����ɷ���ǵ�������ʿ�����ճ�����Ŀ��ǰ����������ľ����˵�ʦ�ܣ�������Ѱ�ñ��Ź�ͭ������Ϊ���ţ�������ˣ�������ֹȷʮ�ֲ��ˡ�");
	set("combat_exp", 900000);
	set("score", 10000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("hp", 3000);
	set("max_hp", 9000);
 	set("icon",young_man4);
	
	set_skill("sword", 150);
	set_skill("force", 90);
	set_skill("unarmed", 90);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("huashan_sword", 150);
//	set_skill("shenxing_baibian", 150);
	map_skill("whip",  "huashan_sword");
	map_skill("parry", "huashan_sword");
//	map_skill("dodge", "shenxing_baibian");
	
	set("mp", 1500); 
	set("max_mp", 1500);
	set("mp_factor", 100);
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money( 2000);
}

NPC_END;