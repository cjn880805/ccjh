// quanzhen_daotong.c ��ͯ

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_daotong);

virtual void create()
{
	set_name("��ͯ", "dao tong");
	set("gender", "����");
	set("class", "taoist");
	set("age", 14);
	set("long","����һλС��ͯ��������Ͳ������������̴棬����Ц�������������ǡ�" );
	set("attitude", "friendly");
	
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("icon",taoist);
	set("foolid",32);
	set("hp", 300);
	set("max_hp", 900);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 0l);
	
	set("combat_exp", 15000);
	
	set_skill("force", 50);
	set_skill("xiantian_qigong", 40);    //��������
	set_skill("dodge", 50);
	set_skill("jinyan_gong", 50);   //���㹦
	set_skill("parry", 50);
	set_skill("unarmed",50);
	
	map_skill("force", "xiantian_qigong");
	map_skill("dodge", "jinyan_gong");
	
	create_family("ȫ���", 5, "����");

	carry_object("greyrobe")->wear();
	
}

NPC_END;