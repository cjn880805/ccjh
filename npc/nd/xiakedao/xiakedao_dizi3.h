// pub_dizi3.h ����
//code by Fisho
//date : 2000-12-13

//inherit F_MASTER;

NPC_BEGIN(CNxiakedao_dizi3);

virtual void create()
{
	set_name("���µ���","di zi3");
	set("long", "������ʮ�����׳���������Բ���ǵ�������ԭ��ļ���ġ�");
	
	set("icon", triggerman1);
	set("gender", "����");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "peaceful");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("hp", 500);
	set("max_hp", 1500);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 30);
	set("combat_exp", 30000);
	set("score", 10);

	set_skill("force", 70);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("hand", 70);
	set_skill("staff", 50);

	create_family("���͵�", 2, "����");
	
	carry_object("cloth")->wear();
}

virtual char * greeting(CChar * ob)
{
	return "���µ���˵������Ҳ��֪�����͵���ʲô���ã���˵�����к��������书��";
}

NPC_END;