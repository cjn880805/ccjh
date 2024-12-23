// hanbaoju.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_hanbaoju);

virtual void create()
{
	set_name("������", "han baoju");
	set("title", "��������");
	set("nickname", "������");
	set("long", 
		"���Ǹ��ְ����ֵ�������ӣ�����һ��������һ�㡣���ֶ���̣�\n"
		"û�в��ӣ�һ��ͷ��ĳ��棬ȴ������˫��֮�С�һ���������\n"
		"����Բ������һֻ������������ϡ�\n");
	set("gender", "����");
	set("age", 35);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 10);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_man2);
	
	set("max_hp", 1200);
	set("hp", 1200);
	set("mp", 1200);
	set("max_mp", 1200);
	set("mp_factor", 20);
	set("combat_exp", 300000);
	set("score", 6000);

	set_skill("force", 70);
	set_skill("taixuan_gong", 70);
	set_skill("dodge", 70);
	set_skill("lingxu_bu", 70);
	set_skill("unarmed", 70);
	set_skill("changquan", 70);
	set_skill("whip", 70);
	set_skill("riyue_bian", 70);

	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "changquan");
	map_skill("whip", "riyue_bian");
	map_skill("parry", "riyue_bian");

	set_inquiry("����","���������ǵĹ�ͽ����");
	set_inquiry("��������","�����ɲ��ҵ������������ý������и��˺Žн����߹֣�");
	set_inquiry("�����߹�","�߹�Ҳ����еģ���");
	set_inquiry("���ڻ�","������������壬�������ӣ�");
	set_inquiry("�±�а","�����Ҵ�硣");
	set_inquiry("����","�����Ҷ��硣");
	set_inquiry("������","�������ˡ�");
	set_inquiry("������","�������ĵܡ�");
	set_inquiry("����","��������ܡ�");
	set_inquiry("ȫ����" ,"���������ܡ�");
	set_inquiry("��С��","�����������ã�������");

	carry_object("changbian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;