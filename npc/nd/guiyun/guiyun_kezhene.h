// kezhene.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_kezhene);

virtual void create()
{
	set_name("�±�а", "ke zhene");
	set("title", "��������");
	set("nickname", "��������");
	set("long", 
		"����һ���������ڵ�Ϲ�ӣ���������һ���ִ�����ȡ�ֻ����\n"
		"������������ɫ�����˵أ������׶�̬֮��\n");
	set("gender", "����");
	set("age", 44);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 12);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", old_man1);
	
	set("max_hp", 1500);
	set("hp", 1500);
	set("mp", 1500);
	set("max_mp", 1500);
	set("mp_factor", 20);
	set("combat_exp", 400000);
	set("score", 6000);

	set_skill("force", 80);
	set_skill("taixuan_gong", 80);
	set_skill("dodge", 80);
	set_skill("lingxu_bu", 80);
	set_skill("unarmed", 80);
	set_skill("changquan", 80);
	set_skill("staff", 80);
	set_skill("juemen_gun", 80);
	set_skill("parry", 80);
	set_skill("throwing", 80);
	set_skill("feixing_shu", 80);

	map_skill("force", "taixuan_gong");
	map_skill("unarmed", "changquan");
	map_skill("dodge", "lingxu_bu");
	map_skill("staff", "juemen_gun");
	map_skill("parry", "juemen_gun");
	map_skill("blade", "feixing_shu");

	set_inquiry("����","���������ǵĹ�ͽ����");
	set_inquiry("��������","�����ɲ��ҵ������������ý������и��˺Žн����߹֣�");
	set_inquiry("�����߹�","�߹�Ҳ����еģ���");
	set_inquiry("���ڻ�","������������壬�������ӣ�");
	set_inquiry("�±�а","����Ϲ���ң���Ҫ���ģ���");
	set_inquiry("����","�����Ҷ��硣");
	set_inquiry("������","���������硣");
	set_inquiry("������","�������ĸ硣");
	set_inquiry("����","��������ܡ�");
	set_inquiry("ȫ����" ,"���������ܡ�");
	set_inquiry("��С��","���������á�");
	set_inquiry("÷�绨","�����ʬ�����Ҵ�磬�˳�һ��Ҫ����");

	carry_object("gangzhang")->wield();
	carry_object("cloth")->wear();
}

NPC_END;