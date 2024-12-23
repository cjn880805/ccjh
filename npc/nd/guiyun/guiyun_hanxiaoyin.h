// hanxiaoyin.c
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_hanxiaoyin);

virtual void create()
{
	set_name("��С��", "han xiaoyin");
	set("title", "��������");
	set("nickname", "ԽŮ��");
	set("long", 
		"����Լʮ�˾�����ͣ��������������۾���Ƥ����ѩ��¶��һͷ���ư���㷢�����ǽ���ˮ������");
	set("gender", "Ů��");
	set("age", 18);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 18);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("icon", young_woman5);
	
	set("max_hp", 1000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 20);
	set("combat_exp", 200000);
	set("score", 6000);

	set_skill("force", 60);
	set_skill("taixuan_gong", 60);
	set_skill("dodge", 60);
	set_skill("lingxu_bu", 60);
	set_skill("unarmed", 60);
	set_skill("changquan", 60);
	set_skill("sword", 60);
	set_skill("yunv_jian", 60);

	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "changquan");
	map_skill("sword", "yunv_jian");
	map_skill("parry", "yunv_jian");

	set_inquiry("����","���������ǵĹ�ͽ����");
	set_inquiry("��������","�����ɲ��ҵ������������ý������и��˺Žн����߹֣�");
	set_inquiry("�����߹�","�߹�Ҳ����еģ���");
	set_inquiry("���ڻ�","������������壬�������ӣ�");
	set_inquiry("�±�а","�����Ҵ�硣");
	set_inquiry("����","�����Ҷ��硣");
	set_inquiry("������","���������硣");
	set_inquiry("������","�������ĸ硣");
	set_inquiry("����","��������ܡ�");
	set_inquiry("ȫ����" ,"���������ܡ�");
	set_inquiry("��С��","�������ˡ�");

	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
}

NPC_END;