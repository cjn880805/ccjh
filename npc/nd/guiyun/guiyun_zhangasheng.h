// zhangasheng.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_zhangasheng);

virtual void create()
{
	set_name("����", "zhang asheng");
	set("title", "��������");
	set("nickname", "Ц����");
	set("long", 
		"һ����Ŀ��࣬��˵Ҳ�ж�������ʮ�Χ��һ����Χȹ��ȫ\n"
		"�����壬�����½�¶��ë���׵����ţ����Ӿ�ø߸ߵģ���\n"
		"����ȫ�Ǵ����ĺ�ë������Ƥ���ϱ��ű��������ļ⵶����\n"
		"ģ���Ǹ�ɱ�����������\n");
	set("gender", "����");
	set("age", 28);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 18);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_man4);
	
	set("hp", 1200);
	set("max_hp", 1200);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 20);
	set("combat_exp", 250000);
	set("score", 6000);

	set_skill("force", 65);
	set_skill("taixuan_gong", 65);
	set_skill("dodge", 65);
	set_skill("lingxu_bu", 65);
	set_skill("unarmed", 65);
	set_skill("changquan", 65);
	set_skill("blade", 65);
	set_skill("hujia_daofa", 65);

	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "changquan");
	map_skill("blade", "hujia_daofa");
	map_skill("parry", "hujia_daofa");

	set_inquiry("����","���������ǵĹ�ͽ����");
	set_inquiry("��������","�����ɲ��ҵ������������ý������и��˺Žн����߹֣�");
	set_inquiry("�����߹�","�߹�Ҳ����еģ���");
	set_inquiry("���ڻ�","������������壬�������ӣ�");
	set_inquiry("�±�а","�����Ҵ�硣");
	set_inquiry("����","�����Ҷ��硣");
	set_inquiry("������","���������硣");
	set_inquiry("������","�������ĸ硣");
	set_inquiry("����","�������ˡ�");
	set_inquiry("ȫ����" ,"���������ܡ�");
	set_inquiry("��С��","���������á�");

	carry_object("jiandao")->wield();
	carry_object("cloth")->wear();
}

NPC_END;