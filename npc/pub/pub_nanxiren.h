// pub_nanxiren.c
//code by Fisho
//date : 2000-12-14
//inherit F_MASTER;

NPC_BEGIN(CNpub_nanxiren);

virtual void create()
{
	set_name("������", "nan wangyi" );

	set("icon", young_man2);
	set("title", "��������");
	set("nickname", "��ɽ����");
	set("long", "���Ǹ�����ģ���ĺ��ӣ���ʮ��������ͣ�һ���಼�¿㣬�������˸��ֲ������㴩��Ь�����ִ�ţ�����ľګ��");
	set("gender", "����");
	set("age", 30);
	set("attitude", "peaceful");
	set("class", "fighter");
	set("shen_type", 1);
	set("per", 15);
	set("str", 28);
	set("int", 28);
	set("con", 28);
	set("dex", 28);
	set("max_hp", 3600);
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
	set_skill("staff", 70);
	set_skill("juemen_gun", 70);
	set_skill("axe", 70);
	set_skill("duanyun_fu", 70);
	map_skill("force", "taixuan_gong");
	map_skill("dodge", "lingxu_bu");
	map_skill("unarmed", "changquan");
	map_skill("staff", "juemen_gun");
	map_skill("parry", "juemen_gun");
	map_skill("axe", "duanyun_fu");
	
	carry_object("biandan");
	carry_object("axe")->wield();
	carry_object("green_cloth")->wear();

	set_inquiry("�����","���������ǵĹ�ͽ����");
	set_inquiry("��������","�����ɲ��ҵ������������ý������и��˺Žн����߹֣�");
	set_inquiry("�����߹�","�߹�Ҳ����еģ���");
	set_inquiry("�𴦻�","������������壬�������ӣ�");
	set_inquiry("�±�а","�����Ҵ�硣");
	set_inquiry("����","�����Ҷ��硣");
	set_inquiry("������","���������硣");
	set_inquiry("������","�������ˡ�");
	set_inquiry("����","��������ܡ�");
	set_inquiry("ȫ����" ,"���������ܡ�");
	set_inquiry("��С��","�����������ã�������");
	
}
NPC_END;