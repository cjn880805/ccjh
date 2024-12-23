// zhucong.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_zhucong);

virtual void create()
{
	set_name("����", "zhu cong");
	set("title", "��������");
	set("nickname", "��������");
	set("long", 
		"����������һ������ʿ�ˣ�����ЬƤ����̤��̤��ֱ�죬һ·���Ź�Ƿ������һ�����õ���ֽ���ȣ���ҡ���С�ͻ����Ц�������������Ǵ̶���");
	set("gender", "����");
	set("age", 38);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 19);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_man5);
	
	set("hp", 1200);
	set("max_hp", 1200);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 20);
	set("combat_exp", 350000);
	set("score", 6000);

	set_skill("force", 75);
	set_skill("taixuan_gong", 75);
	set_skill("dodge", 75);
	set_skill("lingxu_bu", 75);
	set_skill("unarmed", 75);
	set_skill("changquan", 75);
	set_skill("dagger", 75);
	set_skill("shigu_bifa", 75);
	set_skill("parry", 75);
	set_skill("stealing", 75);

	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("dagger", "shigu_bifa");
	map_skill("parry", "shigu_bifa");

	set_inquiry("����","���������ǵĹ�ͽ����");
	set_inquiry("��������","�����ɲ��ҵ������������ý������и��˺Žн����߹֣�");
	set_inquiry("�����߹�","�߹�Ҳ����еģ���");
	set_inquiry("���ڻ�","������������壬�������ӣ�");
	set_inquiry("�±�а","�����Ҵ�硣");
	set_inquiry("����","�������ˡ�");
	set_inquiry("������","���������硣");
	set_inquiry("������","�������ĸ硣");
	set_inquiry("����","��������ܡ�");
	set_inquiry("ȫ����" ,"���������ܡ�");
	set_inquiry("��С��","���������á�");

	carry_object("zheshan")->wield();
	carry_object("cloth")->wear();
}

NPC_END;