//huangbailiu.h
//code by zwb
//12-16
//inherit F_MASTER;


NPC_BEGIN(CNHeiMUYa_huangbailiu);

virtual void create()
{

	set_name("�ư���","huang bai liu");

	set("gender", "����" );
	set("title", "������̷���������");
	set("nickname", "������");
	set("age", 85);
	set("long", "һ�����룬ֱ�����أ���Ŀ���֮����");
	set("attitude", "friendly");
	set("shen_type", 1);
 	set("icon",old_man2);

	set("per", 21);
	set("str", 23);
	set("int", 23);
	set("con", 22);
	set("dex", 20);

	set("max_hp", 3000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("combat_exp", 350000);
	set("mp_factor", 100);
	set("score", 30000);

	set_skill("force", 100);
	set_skill("dodge", 90);
	set_skill("unarmed", 100);
	set_skill("parry", 80);
	set_skill("changquan",70);
	set_skill("tiyunzong", 80);

	map_skill("dodge", "tiyunzong");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");

	create_family("�������",2,"���� ����������");

    carry_object("cloth")->wear();
}

NPC_END;