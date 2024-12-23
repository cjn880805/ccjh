// wangwu.c ����

//code by sound
//date:2000-07-12

NPC_BEGIN(CNxiakedao_wangwu);

virtual void create()
{
	set_name("�ƻ�",  "zhang san" );
	set("long", "����Լ��ʮ���꣬�����ܸɣ�Ц�����ĺͰ����ס���ȴ������������һ� ");
	set("gender", "����");
	set("age", 25);

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 30);
	set("int", 35);
	set("con", 27);
	set("dex", 28);
	
	set_inquiry("������"," ȥ���������������Ե�ְɡ� ");
	set_inquiry("ʯ�쾪"," �����ҵĽ���ֵ�ѽ����Ҳ�����ء� ");
	set_inquiry("���Ʒ�����"," ���������ֵܵ���� ");
	
	set("max_hp", 6000);
	set("hp", 2000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 3000000);
	set("score", 60000);
	
	set_skill("force", 150);
	set_skill("taiji_shengong", 150);
	set_skill("dodge", 150);
	set_skill("tiyunzong", 150);
	set_skill("unarmed", 150);
	set_skill("taiji_quan", 200);
	set_skill("parry", 150);
	set_skill("sword", 150);
	set_skill("taiji_jian", 200);
	set_skill("taoism", 100);
	set_skill("literate", 100);
	
	map_skill("force", "taiji_shengong");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji_quan");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	
 	carry_object("changjian")->wield();
	carry_object("white_robe")->wear();
}

NPC_END;